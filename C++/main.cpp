#include "OOP/Facade/facade.hpp"
#include "OOP/Base/base_operations.hpp"

#include <iostream>
#include <string>

using namespace expr;
#include "Evaluating/solve.hpp"

string Transform (string expr)
{
	if (expr [0] == '|')
		expr [0] = '{';
	for (int i = 1 ; i < (int)expr.size () ; i ++)
	{
		if (expr [i] == '|')
		{
			switch (expr [i - 1])
			{
				case '+': expr [i] = '{'; break;
				case '-': expr [i] = '{'; break;
				case '*': expr [i] = '{'; break;
				case '/': expr [i] = '{'; break;
				case '^': expr [i] = '{'; break;
				case '~': expr [i] = '{'; break;
				case '>': expr [i] = '{'; break;
				case '<': expr [i] = '{'; break;
				case '(': expr [i] = '{'; break;
				case '|': expr [i] = '{'; break;
				default:  expr [i] = '}';
			}
		}
	}
	return expr;
}

int parser (std::string a)
{
	return atoi (a.c_str ());
}

int main ()
{
	expression <int> expr;
	expr.number_priority = 1000000;
	expr.addOperation (new plus_type <int> ());
	expr.addOperation (new minus_type <int> ());
//	expr.addOperation (new minus_prefix_type <int> ());
	expr.addOperation (new mul_type <int> ());
	expr.addOperation (new div_type <int> ());
	expr.addOperation (new negative_type <int> ());
	expr.addBrackets  (new brackets_type <int> ());
	expr.addBrackets  (new module_type <int> ());
	std::cout << (*expr [0])({1, 2}) << std::endl;
	std::cout << (*expr [1])({1, 2}) << std::endl;
	std::cout << (*expr [1])({0,2}) << std::endl; //unary minus with binary operation
	std::cout << (*expr [1])({0,2,5,67}) << std::endl; // all values after second will be ignored in binary operators
//	std::cout << (*expr [2])({2}) << std::endl;
//	std::cout << (*expr [2])({2,5,67}) << std::endl; // all values after first will be ignored in unary operators
	std::cout << (*expr [2])({1, 2}) << std::endl;
	std::cout << (*expr [3])({1, 2}) << std::endl;
	std::cout << (*expr (0))(-3) << std::endl;
	std::cout << (*expr (1))(-3) << std::endl;
	std::cout << "Creating Solver";
	for (int i = 0 ; i < 69 ; i ++)
	{
		std::cout << ".";
		std::cout.flush ();
		system ("sleep 0.002s");
	}
	solve <int> solver (expr, parser);
	std::cout << "Created Solver 😃" << std::endl;
	std::string to_solve;

	to_solve = "({1*(2-3)}+{7-9})/{6/6-7*0+9-10+2}";
	while (true)
	{
		std::cout << "Calculated: " << to_solve << " = " << solver.calc (to_solve) << std::endl;
		std::cout << "😕 😭 \n";
		std::cin >> to_solve; 
	}
}
