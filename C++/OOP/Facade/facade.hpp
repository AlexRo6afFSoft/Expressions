#include <map>
#include <vector>

namespace expr
{
	template <typename T>
	class bracket
	{
	public:
		char open;
		char close;
		int P;
		int M;
		virtual T operator() (T) const = 0;
	};

	template <typename T>
	class operation
	{
	public:
		int operands;
		int priority;
		char symbol;
		bool right_asociation; ////!!!! to constructor
		virtual T operator() (std::vector <T>) const = 0;
	};

	template <typename T>
	class expression
	{
	private:
	public:
		int number_priority = 0;
		std::vector < operation <T>* > operations;
		std::vector <   bracket <T>* >   brackets;
		std::map <char, operation <T>* > oper;
		std::map <char, int > opened;
		std::map <char, int > closed;
		expression (const int a = 1e9)
		{
			number_priority = a;
		}
		expression (const expression <T>& a)
		{
			number_priority = a.number_priority;
			operations = a.operations;
			brackets = a.brackets;
			oper = a.oper;
			opened = a.opened;
			closed = a.closed;
		}
		void addBrackets (bracket <T>* b)
		{
			opened [b->open] = brackets.size ();
			closed [b->close] = brackets.size ();
			brackets.push_back (b);
		}
		void addOperation (operation <T>* op)
		{
			oper [op->symbol] = op;
			operations.push_back (op);
		}
		const operation <T>* operator [] (std::size_t ind)
		{
			return (operations [ind]);
		}
		const bracket <T>* operator () (std::size_t ind)
		{
			return (brackets [ind]);
		}
		bool isClosed (char a)
		{
			return closed.find (a) != closed.end ();
		}
		bool isOpened (char a)
		{
			return opened.find (a) != opened.end ();
		}
		bool isBracket (char a)
		{
			return opened.find (a) != opened.end () or closed.find (a) != closed.end ();
		}
		bool isOper (char a)
		{
			return oper.find (a) != oper.end ();
		}
	};
}
