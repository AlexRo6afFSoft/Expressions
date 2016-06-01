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
			expression<int> my_expr = new expression<int> ();
			plus_type<int> instance = new plus_type<int> (adding);
			my_expr.addOperation (new plus_type<int>(adding));
			Console.WriteLine ("{0} = {1} = {2}", adding (1,2), instance.f (1,2), my_expr.operations [0].f (1, 2));
			for (int i = 0; i < 200000000; i++) {
				i++;
			}
			return ;
		}
	}
}