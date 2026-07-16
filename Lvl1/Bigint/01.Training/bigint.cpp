#include "bigint.hpp"

		//! Addition Operators (+=) (+)
		bigint &bigint::operator+=(const bigint &other)
		{
			std::string result = "";
			int carry = 0;
			int thisSize = _value.size() - 1;
			int otherSize = other._value.size() - 1;

			while (thisSize >= 0 || otherSize >= 0 || carry)
			{
				int thisLastDigit = thisSize >= 0 ? _value[thisSize] - '0' : 0;
				int otherLastDigit = otherSize >= 0 ? other._value[otherSize] - '0' : 0;

				int sum = thisLastDigit + otherLastDigit + carry;
				carry = sum / 10;
				result += (sum % 10) + '0';
				--thisSize;
				--otherSize;
			}

			std::string reversedResult = "";
			for (int lastIndex = result.size() - 1; lastIndex >= 0; --lastIndex)
			{
				reversedResult += result[lastIndex];
			}

			_value = reversedResult;

			return *this;

		}

		bigint bigint::operator+(const bigint &other) const
		{
			bigint copy(*this);

			copy += other;

			return copy;
		}



		//! Shifting Operators (<<=) (>>=) (<<) (>>)
		bigint &bigint::operator>>=(const bigint &other)
		{
			bigint bigBase(0);
			bigint otherCopy(other);

			if (bigint(_value.size()) <= otherCopy)
			{
				_value = "0";
			}
			else
			{
				while (bigBase < otherCopy)
				{
					int lastIndex = _value.size() - 1;
					_value.erase(lastIndex);
					++bigBase;
				}
			}

			return *this;
		}

		bigint &bigint::operator<<=(const bigint &other)
		{
			bigint bigBase(0);
			bigint otherCopy(other);

			if (_value != "0")
			{
				while (bigBase < otherCopy)
				{
					_value += '0';
					++bigBase;
				}
			}

			return *this;
		}

		bigint bigint::operator>>(const bigint &other) const
		{
			bigint copy(*this);

			copy >>= other;

			return copy;
		}

		bigint bigint::operator<<(const bigint &other) const
		{
			bigint copy(*this);

			copy <<= other;

			return copy;
		}


		//! Comparision Operators < > <= >= == !=
		bool bigint::operator<(const bigint &other) const
		{
			if (_value.size() != other._value.size())
			{
				return _value.size() < other._value.size();
			}
			else
			{
				return _value < other._value;
			}
		}


		bool bigint::operator>(const bigint &other) const
		{
			return other < *this;
		}


		bool bigint::operator<=(const bigint &other) const
		{
			if (*this < other || *this == other)
			{
				return true;
			}
			else
			{
				return false;
			}
		}


		bool bigint::operator>=(const bigint &other) const
		{
			return (other <= *this);
		}


		bool bigint::operator==(const bigint &other) const
		{
			return _value == other._value;
		}


		bool bigint::operator!=(const bigint &other) const
		{
			return _value != other._value;
		}



		//!  Increment Operators Pre/Post
		bigint &bigint::operator++()
		{
			*this += bigint(1);

			return *this;
		}

		bigint bigint::operator++(int)
		{
			bigint copy(*this);

			++(*this);

			return copy;
		}

		std::ostream &operator<<(std::ostream &os, const bigint &bigInt)
		{
			os << bigInt.getValue();
			return os;
		}