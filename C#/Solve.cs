using System;
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
		public T solve (string expr)
		{
			return default (T);
		}
	}
}
