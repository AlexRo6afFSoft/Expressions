using System;
using System.Collections.Generic;
using expr;

namespace expr_example
{
	public delegate T function<T>(T param1, T param2);
	public delegate T ufunction<T>(T param1);

	public class plus_type <T> : Operation <T>
	{
		function<T> F;
		public override T f (params T[] args)
		{
			if (args.Length < 2) //binary operator
				throw new SystemException ("Bad Arguments! ;(");
			return F (args [0], args [1]);
		}
		public plus_type (function<T> action, char s = '+', int p = 1)
		{
			this.operands = 2;
			this.symbol = s;
			this.priority = p;
			this.F = action;
		}
	};

	public class brackets_type<T> : Bracket<T>
	{
		ufunction<T> F;
		public override T f (T a)
		{
			return F (a);
		}
		public brackets_type (ufunction<T> action, char open = '(', char close = ')')
		{
			this.open = open;
			this.close = close;
			this.F = action;
		}
	};

	public class module_type<T> : Bracket <T>
	{
		ufunction<T> F;
		public override T f (T a)
		{
			return F (a);
		}
		public module_type (ufunction<T> action, char open = '{', char close = '}')
		{
			this.open = open;
			this.close = close;
			this.F = action;
		}
	};
}