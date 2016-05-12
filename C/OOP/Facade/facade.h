typedef void* (*func2) (void* a, void* b);
typedef void* (*func1) (void* a);

typedef struct 
{
	func2* operations;
	size_t n1;
	func1*   brackets;
	size_t n2;
} x;
x expression;

void addOp (func2 op)
{
	func2* N = malloc (sizeof (func2) * (++ expression.n1));
	for (size_t i = 0 ; i < expression.n1 - 1 ; i ++)
	{
		N [i] = expression.operations [i];
	}
	N [expression.n1 - 1] = op;
	free (expression.operations);
	expression.operations = N;
}

func2 getOp (size_t ind)
{
	return expression.operations [ind];
}

void addBr (func1 op)
{
	func1* N = malloc (sizeof (func1) * (++ expression.n2));
	for (size_t i = 0 ; i < expression.n2 - 1 ; i ++)
	{
		N [i] = expression.brackets [i];
	}
	N [expression.n2 - 1] = op;
	free (expression.brackets);
	expression.brackets = N;
}

func1 getBr (size_t ind)
{
	return expression.brackets [ind];
}
