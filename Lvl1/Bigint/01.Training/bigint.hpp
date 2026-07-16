#pragma once

#include <string>
#include <iostream>
#include <ostream>
#include <sstream>


class bigint
{

	private:
		std::string _value;

	public:
		bigint(unsigned int n = 0)
		{
			std::ostringstream oss;

			oss << n;

			_value = oss.str();
		}


		bigint(const bigint &other)
		{
			_value = other._value;
		}

		//! Addition Operators (+=) (+)
		bigint &operator+=(const bigint &other);
		bigint operator+(const bigint &other) const;

		//! Shifting Operators (<<=) (>>=) (<<) (>>)
		bigint &operator>>=(const bigint &other);
		bigint &operator<<=(const bigint &other);
		bigint operator>>(const bigint &other) const;
		bigint operator<<(const bigint &other) const;

		//! Comparision Operators < > <= >= == !=
		bool operator<(const bigint &other) const;
		bool operator>(const bigint &other) const;
		bool operator<=(const bigint &other) const;
		bool operator>=(const bigint &other) const;
		bool operator==(const bigint &other) const;
		bool operator!=(const bigint &other) const;

		//!  Increment Operators Pre/Post
		bigint &operator++();
		bigint operator++(int);

		//! Getter
		std::string getValue() const
		{
			return _value;
		}
};

std::ostream &operator<<(std::ostream &os, const bigint &bigInt);