#include <cmath>

namespace expr
{
	template <typename T>
	class plus_type : public operation <T>
	{
	public:
		T operator() (std::vector <T> v) const
		{
			if (v.size () < 2) //binary operator
				throw "Bad Arguments! ;(";
			return v [0] + v [1];
		}
		plus_type (char s = '+', int p = 1)
		{
			this->operands = 2;
			this->symbol = s;
			this->priority = p;
		}
	};
	template <typename T>
	class minus_type : public operation <T>
	{
	public:
		T operator() (std::vector <T> v) const
		{
			if (v.size () < 2) //binary operator
				throw "Bad Arguments! ;(";
			return v [0] - v [1];
		}
		minus_type (char s = '-', int p = 1)
		{
			this->operands = 2;
			this->symbol = s;
			this->priority = p;
		}
	};
	//template <typename T>
	//class minus_prefix_type : public operation <T>
	//{
	//public:
	//	T operator() (std::vector <T> v) const
	//	{
	//		if (v.size () < 1) //unary operator
	//			throw "Bad Arguments! ;(";
	//		return -v [0];
	//	}
	//	minus_prefix_type (char s = '#', int p = 8)
	//	{
	//		this->operands = 1;
	//		this->symbol = s;
	//		this->priority = p;
	//	}
	//};
	template <typename T>
	class mul_type : public operation <T>
	{
	public:
		T operator() (std::vector <T> v) const
		{
			if (v.size () < 2) //binary operator
				throw "Bad Arguments! ;(";
			return v [0] * v [1];
		}
		mul_type (char s = '*', int p = 2)
		{
			this->operands = 2;
			this->symbol = s;
			this->priority = p;
		}
	};
	template <typename T>
	class div_type : public operation <T>
	{
	public:
		T operator() (std::vector <T> v) const
		{
			if (v.size () < 2) //binary operator
				throw "Bad Arguments! ;(";
			return v [0] / v [1];
		}
		div_type (char s = '/', int p = 2)
		{
			this->operands = 2;
			this->symbol = s;
			this->priority = p;
		}
	};
	template <typename T>
	class negative_type : public operation <T>
	{
	public:
		T operator() (std::vector <T> v) const
		{
			if (v.size () < 2) //binary operator
				throw "Bad Arguments! ;(";
			return v [0] + (~v [1]);
		}
		negative_type (char s = '~', int p = 3)
		{
			this->operands = 2;
			this->symbol = s;
			this->priority = p;
		}
	};

	template <typename T>
	class brackets_type : public bracket <T>
	{
	public:
		T operator() (T a) const
		{
			return a;
		}
		brackets_type (char open = '(', char close = ')')
		{
			this->open = open;
			this->close = close;
			this->P = 4;
			this->M = -4;
		}
	};

	template <typename T>
	class module_type : public bracket <T>
	{
	public:
		T operator() (T a) const
		{
			return std::abs (a);
		}
		module_type (char open = '{', char close = '}')
		{
			this->open = open;
			this->close = close;
			this->P = 4;
			this->M = -4;
		}
	};
}
