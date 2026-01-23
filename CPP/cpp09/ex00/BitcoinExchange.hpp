#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>
class BitcoinExchange {
	private:
		std::map<std::string, double> _exchangeRates;
		double getExchangeRateDate(const std::string& date) const;
		double getExchangeRateValue(const std::string& date, double value) const;
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void printExchange(const std::string& filename) const;
		void printExchangeRates() const;
		// Exception classes
		class noDatabaseFile : public std::exception {
			const char *what() const throw();
		};

		class amountOutOfRange : public std::exception {
			const char *what() const throw();
		};

		class notPositiveNumber : public std::exception {
			const char *what() const throw();
		};

		class tooLargeNumber : public std::exception {
			const char *what() const throw();
		};

		class invalidDate : public std::exception {
			const char *what() const throw();
		};

		class invalidFormat : public std::exception {
			const char *what() const throw();
		};

		class wrongHeader : public std::exception {
			const char *what() const throw();
		};

		class nothingToRead : public std::exception {
			const char *what() const throw();
		};
};

#endif