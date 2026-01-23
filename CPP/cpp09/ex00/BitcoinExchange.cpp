#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <cctype>

//___________________________Helper  Functions___________________________//

static std::map<std::string, double> loadcsv(const std::string& filename)
{
    std::map<std::string, double> data;
	std::ifstream file;
	file.open(filename.c_str());
	if (!file.is_open()) {
		throw BitcoinExchange::noDatabaseFile();
	}
	std::string line;
	std::getline(file, line);

	    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string key;
        std::string valueStr;
        
        if (std::getline(ss, key, ',') && std::getline(ss, valueStr)) {
            
			double value = atof(valueStr.c_str());
            data[key] = value;
        }
    }
    
    file.close();
	return data;
}

// Helper: trim whitespace from both ends
static void trim(std::string &s)
{
	size_t start = s.find_first_not_of(" \t\r\n");
	if (start == std::string::npos) { s.clear(); return; }
	size_t end = s.find_last_not_of(" \t\r\n");
	s = s.substr(start, end - start + 1);
}

// Helper: parse and validate date and value fields; returns parsed value
static double parseAndValidateInput(std::string date, std::string valueStr)
{
	trim(date);
	trim(valueStr);

	// Validate date format YYYY-MM-DD and ranges
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		throw BitcoinExchange::invalidDate();
	}
	for (size_t i = 0; i < date.size(); ++i) {
		if (i==4 || i==7) continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			throw BitcoinExchange::invalidDate();
	}
	int year = atoi(date.substr(0,4).c_str());
	int month = atoi(date.substr(5,2).c_str());
	int day = atoi(date.substr(8,2).c_str());
	if (month < 1 || month > 12) throw BitcoinExchange::invalidDate();
	int mdays = 31;
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		mdays = 30;
	} else if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			mdays = 29;
		else
			mdays = 28;
	} else {
		mdays = 31;
	}
	if (day < 1 || day > mdays) throw BitcoinExchange::invalidDate();

	// Parse value robustly and check range
	char *endptr = NULL;
	errno = 0;
	double value = strtod(valueStr.c_str(), &endptr);
	if (endptr == valueStr.c_str() || *endptr != '\0') {
		throw BitcoinExchange::invalidFormat();
	}
	if (errno == ERANGE || !std::isfinite(value)) {
		throw BitcoinExchange::tooLargeNumber();
	}
	// Check for negative numbers first
	if (value < 0) {
		throw BitcoinExchange::notPositiveNumber();
	}
	// Then check for too large numbers
	if (value > 1000) {
		throw BitcoinExchange::tooLargeNumber();
	}
	return value;
}

//___________________________Contructor/Destructor___________________________//
BitcoinExchange::BitcoinExchange()
{
	_exchangeRates = loadcsv("data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string& filename)
{
	_exchangeRates = loadcsv(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	_exchangeRates = other._exchangeRates;
}

BitcoinExchange::~BitcoinExchange()
{}

//___________________________Operator Overloads___________________________//
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other) {
		_exchangeRates = other._exchangeRates;
	}
	return *this;
}

//___________________________Exception Messages___________________________//
const char* BitcoinExchange::noDatabaseFile::what() const throw() 
{
	return ("Error: Could not open database file.");
}

const char* BitcoinExchange::amountOutOfRange::what() const throw() 
{
	return ("Error: Amount is out of range.");
}

const char* BitcoinExchange::notPositiveNumber::what() const throw() 
{
	return ("Error: not a positive number.");
}

const char* BitcoinExchange::tooLargeNumber::what() const throw() 
{
	return ("Error: too large of a number.");
}

const char* BitcoinExchange::invalidDate::what() const throw() 
{
	return ("Error: Invalid date format.");
}

const char* BitcoinExchange::invalidFormat::what() const throw()
{
	return ("Error: Invalid format in input file.");
}

const char* BitcoinExchange::wrongHeader::what() const throw() 
{
	return ("Error: Wrong header in input file.");
}

const char* BitcoinExchange::nothingToRead::what() const throw()
{
	return ("Error: Nothing to read from input file.");
}

//___________________________Private Functions___________________________//
double BitcoinExchange::getExchangeRateDate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _exchangeRates.find(date);
	if (it != _exchangeRates.end()) {
		return it->second;
	} else {
		// If the exact date is not found, find the closest previous date
		it = _exchangeRates.lower_bound(date);
		if (it == _exchangeRates.begin()) {
			throw invalidDate();
		}
		--it; // Move to the closest previous date
		return it->second;
	}
}

double BitcoinExchange::getExchangeRateValue(const std::string& date, double value) const
{
	double rate = getExchangeRateDate(date);
	return rate * value;
}


//___________________________Member  Functions___________________________//


void BitcoinExchange::printExchangeRates() const
{
	for (std::map<std::string, double>::const_iterator it = _exchangeRates.begin(); it != _exchangeRates.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
}

void BitcoinExchange::printExchange(const std::string& filename) const
{
	std::ifstream file;
	file.open(filename.c_str());
	if (!file.is_open()) {
		throw BitcoinExchange::noDatabaseFile();
		return;
	}
	std::string line;
	std::getline(file, line);
	trim(line);
	if (line != "date | value") {
		throw BitcoinExchange::wrongHeader();
	}

	while (std::getline(file, line)) {
		try {
			std::stringstream ss(line);
			std::string date;
			std::string valueStr;
			
			if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
				double value = parseAndValidateInput(date, valueStr);
				double exchangedValue = getExchangeRateValue(date, value);
				std::cout << date << " => " << value << " = " << exchangedValue << std::endl;
			} else {
				std::cerr << "Error: bad input => " << line << std::endl;
			}
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	file.close();
}