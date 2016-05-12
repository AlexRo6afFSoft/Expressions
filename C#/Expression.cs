using System;
using System.Collections.Generic;
using expr;

namespace expr
{
	public delegate T functype1<T> (T a);
	public delegate T functype2<T> (T a, T b);
	public class expression<T>
	{
		public int number_priority;
		public List < functype2<T> > operations;
		public List < functype1<T> >   brackets;
		public expression (int n = int.MaxValue)
		{
			number_priority = n;
		}
		public void addBrackets (functype1<T> b)
		{
			brackets.Add ((functype1<T>) b.Clone ());
		}
		public void addOperation (functype2<T> op, T a, T b)
		{
			Console.WriteLine ("add OP = {0} {1} {2} {3}", op (a, b), op, op.Clone (), (functype2<T>)(op.Clone ()));
			operations.Add ((functype2<T>) op.Clone ()); // runtime error -> NullPointer Exeption
			Console.WriteLine ("add OP2");
		}
		public functype2<T> get_op (int ind)
		{
			return (operations [ind]);
		}
		public functype1<T> get_br (int ind)
		{
			return (brackets [ind]);
		}
		public List <T> calc (string expr)
		{
			if (number_priority == 1)
				throw new SystemException ("Idiot!! ;@");
			List<T> a = new List<T> ();
			return a;
		}
	}
}

