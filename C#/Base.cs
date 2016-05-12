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
		public override T f (List<T> v)
		{
			Console.WriteLine ("BLQQQQQ");
			if (v.Count < 2) //binary operator
				throw new SystemException ("Bad Arguments! ;(");
			return F (v [0], v [1]);
		}
		public plus_type (function<T> action, char s = '+', int p = 1)
		{
			Console.WriteLine ("Blq");
			this.operands = 2;
			Console.WriteLine ("Blq");
			this.symbol = s;
			Console.WriteLine ("Blq");
			this.priority = p;
			Console.WriteLine ("Blq");
			this.F = action;
			Console.WriteLine ("Blq");
		}
	};
	public class minus_type<T> : Operation <T>
	{
		function<T> F;
		public override T f (List <T> v)
		{
			if (v.Count < 2) //binary operator
				throw new SystemException ("Bad Arguments! ;(");
			return F (v [0], v [1]);
		}
		public minus_type (function<T> action, char s = '-', int p = 1)
		{
			this.operands = 2;
			this.symbol = s;
			this.priority = p;
			this.F = action;
		}
	};
	public class mul_type<T> : Operation <T>
	{
		function<T> F;
		public override T f (List <T> v)
		{
			if (v.Count < 2) //binary operator
				throw new SystemException ("Bad Arguments! ;(");
			return F (v [0], v [1]);
		}
		public mul_type (function<T> action, char s = '*', int p = 2)
		{
			this.operands = 2;
			this.symbol = s;
			this.priority = p;
			this.F = action;
		}
	};
	public class div_type <T> : Operation <T>
	{
		function<T> F;
		public override T f (List <T> v)
		{
			if (v.Count < 2) //binary operator
				throw new SystemException ("Bad Arguments! ;(");
			return F (v [0], v [1]);
		}
		public div_type (function<T> action, char s = '/', int p = 2)
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

