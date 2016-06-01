using System;
using System.Collections.Generic;

namespace expr
{
	public abstract class Operation<T>
	{
		public int operands;
		public int priority;
		public char symbol;
		public abstract T f (params T[] args);
	}
}

