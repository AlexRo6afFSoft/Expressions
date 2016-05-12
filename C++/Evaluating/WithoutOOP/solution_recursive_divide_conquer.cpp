#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <stdlib.h>
#include <math.h>

using namespace std;

string transform (string expr)
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

int quickpow (int a, int b, int mod)
{
	if (b == 0) return 1;
	if (b == 1) return a % mod;
	if (b & 1)
	{
		int haha = quickpow (a, b / 2, mod) % mod;
		return ((a % mod) * (haha * haha) % mod) % mod;
	}
	else
	{
		int haha = quickpow (a, b / 2, mod) % mod;
		return (haha * haha) % mod;
	}
}	

int PLUS (int a, int b) { return a + b;}
int MINUS (int a, int b) { return a - b;}
int MUL (int a, int b) { return a * b;}
int DIV (int a, int b) { return a / b;}
int POW (int a, int b) { return quickpow (a, b, 30011); }
int negative (int a, int b) { return a+(~b); }
int shift_left (int a, int b) { return a << b;}
int shift_right (int a, int b) { return a >> b;}

map <char, int (*)(int, int)> op = 
{
	{'+', &PLUS},
	{'-', &MINUS},
	{'*', &MUL},
	{'/', &DIV},
	{'^', &POW},
	{'~', &negative},
	{'<', &shift_left},
	{'>', &shift_right},
	{' ', NULL}
};

pair <string, bool> clean (string expr)
{
	stack < pair <pair < int, int>, bool > > pairs_brackets;
	stack < int > open;
	for (int i = 0 ; i < (int)expr.size () ; i ++)
	{
		if (expr [i] == '(')
		{
			open.push (i);
		}
		if (expr [i] == ')')
		{
			pairs_brackets.push ({{open.top (), i}, true});
			open.pop ();
		}
		if (expr [i] == '{')
		{
			open.push (i);
		}
		if (expr [i] == '}')
		{
			pairs_brackets.push ({{open.top (), i}, false});
			open.pop ();
		}
	}
	int last_open = 0;
	bool abs = false;
	while (!pairs_brackets.empty ())
	{
		int opened = pairs_brackets.top ().first.first;
		int closed = pairs_brackets.top ().first.second;
		bool brackets = pairs_brackets.top ().second;
		pairs_brackets.pop ();
		if (opened - last_open == 0 and closed - last_open == (int)expr.size () - 1)
		{
			expr.erase (0, 1);
			expr.erase (expr.size () - 1, 1);
			last_open = opened;
			abs = abs or (!brackets);
		}
		else
		{
			break;
		}
	}
	return {expr, abs};
}

int priority (char a)
{
	switch (a)
	{
		case '+': return  1;
		case '-': return  1;
		case '*': return  2;
		case '/': return  2;
		case '^': return  3;
		case '<': return  4;
		case '>': return  4;
		case '~': return  5;
		case '(': return  6;
		case '{': return  6;
		case '}': return -6;
		case ')': return -6;
		default: return 10000;//digit
	}
}

int eval (string expr)
{
	auto cleaned = clean (expr);
	expr = cleaned.first;
	//cout << "Cleaned: " << expr << "\n";
	if (expr == "")
	{
		return 0;
	}
////int start_ind = 0;
////if (expr [0] == '-')
////	start_ind = 1;
	int min_priority = 1000, pos = -1;
	int bonux = 0;
	for (int i = 0/*start_ind*/ ; i < (int)expr.size () ; i ++)
	{
		if (expr [i] == '(' or expr [i] == '{' or expr [i] == '}' or expr [i] == ')')
			bonux += priority (expr [i]);
		else
		{
			int curr_priority = priority (expr [i]) + bonux;
			if (curr_priority == min_priority)
			{
				if (expr [pos] == '^' and expr [i] == '^')
				{
					pos = pos;
				}
				else
					pos = i;
			}
			else if (curr_priority < min_priority)
			{
				min_priority = curr_priority;
				pos = i;
			}
		}
	}
	if (min_priority == 1000)
	{
		while (expr [0] == '(' or expr [0] == '{')
		{
			expr.erase (0, 1);
			expr.erase (expr.size () - 1, 1);
		}
		//cout << expr << " = " << atoi (expr.c_str ()) << "\n";
		int ans = atoi (expr.c_str ());
		if (cleaned.second)
			ans = abs (ans);
		return ans;
	}
	else
	{
		//cout << "\nOperator: " << expr [pos] << " Sample for (1, 2): " << (*op [expr [pos]])(1, 2) << "\n";
		int ans = (*op [expr [pos]])(eval (expr.substr (0, pos)), eval (expr.substr (pos + 1)));
		if (cleaned.second)
			ans = abs (ans);
		return ans;
	}
	//throw "Undefine function \'eval\' yet";
}

int main ()
{
	string expr;
	try
	{
		cin >> expr;
	}
	catch (...)
	{
		cout << "std::cin crash\n";
		return -1;
	}
	try
	{
		expr = transform (expr);
	}
	catch (const char* error)
	{
		cout << "Transformation crash: " << error << "\n";
		return -1;
	}
////try
////{
////	cout << expr << "\n";
////}
////catch (...)
////{
////	cout << "std::cout crash: " << "\n";
////	return -1;
////}
	try
	{
		cout << eval (expr) << "\n";
	}
	catch (const char* error)
	{
		cout << "Eval crash: " << error << "\n";
		return -1;
	}
////getline (cin, expr);
////cout << "Press Enter to exit!\n";
////getline (cin, expr);
	return 0;
}
