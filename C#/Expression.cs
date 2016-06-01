using System;
using System.Collections.Generic;
using expr;

namespace expr
{
	public class expression<T>
	{
		public int number_priority;
		public List < Operation<T> > operations;
		public List < Bracket<T> >   brackets;
		public expression (int n = int.MaxValue)
		{
			number_priority = n;
		}
		public void addBrackets (Bracket<T> b)
		{
			brackets.Add (b);
		}
		public void addOperation (Operation<T> op)
		{
			operations.Add (op); //NullPointer exeption -> runtime error
			Console.WriteLine ("add OP2");
		}
		public Operation<T> get_op (int ind)
		{
			return (operations [ind]);
		}
		public Bracket<T> get_br (int ind)
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

