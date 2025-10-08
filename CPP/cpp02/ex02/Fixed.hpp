#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

#include <iostream>
#include <ostream>
#include <string>
#include <iomanip>
#include <cmath>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int _raw;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int val);
		Fixed(const float val);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);

		float toFloat() const;
		int toInt() const;

		Fixed &operator=( Fixed const & src);

		bool	operator>( Fixed const & rhs ) const;
		bool	operator<( Fixed const & rhs ) const;
		bool	operator>=( Fixed const & rhs ) const;
		bool	operator<=( Fixed const & rhs ) const;
		bool	operator==( Fixed const & rhs ) const;
		bool	operator!=( Fixed const & rhs ) const;

		Fixed	operator+( Fixed const & rhs ) const;
		Fixed	operator-( Fixed const & rhs ) const;
		Fixed	operator*( Fixed const & rhs ) const;
		Fixed	operator/( Fixed const & rhs ) const;

		Fixed &	operator++( void );
		Fixed	operator++( int	);
		Fixed &	operator--( void );
		Fixed	operator--( int );

		static Fixed &			min( Fixed & lhs, Fixed & rhs );
		static Fixed &			max( Fixed & lhs, Fixed & rhs );
		static Fixed const &	min( Fixed const & lhs, Fixed const & rhs );
		static Fixed const &	max( Fixed const & lhs, Fixed const & rhs );
};

std::ostream& operator<<( std::ostream& os, const Fixed& number );



#endif