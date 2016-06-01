using System;
using System.Collections.Generic;
using expr;
using expr_example;
using solve;

namespace Expressions
{
	class MainClass
	{
		public static int adding (int a, int b)
		{
			return a + b;
		}
		public class str_to_int : parser_t <int>
		{
			public override int to_T (string a)
			{
				if (a == "")
					return 0;
				return int.Parse (a);
			}
		}
		public static void Main (string[] args)
		{
			expression<int> my_expr = new expression<int> ();
			plus_type<int> instance = new plus_type<int> (adding);
			my_expr.addOperation (new plus_type<int>(adding));
			Console.WriteLine ("{0} = {1} = {2}", adding (1,2), instance.f (1,2), my_expr.operations [0].f (1, 2));
			solver_t <int> solver = new solver_t <int> (new str_to_int ());
			Console.WriteLine (solver.solve (""));
			return ;
		}
	}
}