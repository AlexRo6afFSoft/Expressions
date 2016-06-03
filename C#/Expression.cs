using System;
using System.Collections.Generic;
using expr;

namespace expr
{
	public class expression<T>
	{
		public int number_priority;
		public List < Operation<T> > operations = new List <Operation<T>> ();
		public List < Bracket<T> >   brackets   = new List <Bracket<T>> ();
		public Dictionary <char, Operation <T> > oper = new Dictionary <char, Operation <T>> ();
		public Dictionary <char, int > opened = new Dictionary <char, int> ();
		public Dictionary <char, int > closed = new Dictionary <char, int> ();

		public expression (int n = int.MaxValue)
		{
			number_priority = n;
		}
		public void addBrackets (Bracket<T> b)
		{
			brackets.Add (b);
			opened [b.open] = brackets.Count;
			closed [b.close] = brackets.Count;
		}
		public void addOperation (Operation<T> op)
		{
			operations.Add (op);
			oper [op.symbol] = op;
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

