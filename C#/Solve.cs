using System;
using System.Collections.Generic;
using expr;

namespace solve
{
	abstract class parser_t<T>
	{
		public abstract T to_T (string a);
	}
	class solver_t<T>
	{
		expression<T> opers;
		parser_t<T> parser;
		public solver_t (parser_t<T> parse)
		{
			parser = parse;
		}
		private class Pair<T1, U>
		{
			public Pair() 
			{
			}

			public Pair(T1 first, U second)
			{
				this.First = first;
				this.Second = second;
			}

			public T1 First { get; set; }
			public U Second { get; set; }
		};
		private Pair < string, List <int> > clean (string expr)
		{
			return new Pair < string, List < int > > ();
		}
		public T solve (string expr)
		{
			return default (T);
		}
	}
}
