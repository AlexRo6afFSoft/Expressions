using System;
using System.Collections.Generic;
using expr;
using expr_example;

namespace Expressions
{
	class MainClass
	{
		public static int adding (int a, int b)
		{
			return a + b;
		}
		public static void Main (string[] args)
		{
			functype2<int> c = adding;
			expression<int> my_expr = new expression<int> ();
			my_expr.addOperation (ref c, 1, 2); // runtime error -> NullPtr. Exeption
			Console.WriteLine ("{0} = {1} = {2}", adding (1,2), c (1,2), my_expr.operations [0] (1, 2));
			for (int i = 0; i < 200000000; i++) {
				i++;
			}
			return ;
			//Console.WriteLine ("{0}", my_expr.get_op (0) (1, 2));
		}
	}
}
