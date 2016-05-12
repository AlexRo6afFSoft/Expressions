using System;
using System.Collections.Generic;

namespace expr
{
	public abstract class Bracket<T>
	{
		public char open;
		public char close;
		public abstract T f (T a);
	}
}

