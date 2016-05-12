## Usage:
```cpp
expression <TYPE> NAME; // Where TYPE is valid data type (int, string, char... and your structures) and NAME is valid id (name) of variable

NAME.addOperation (new YOUR_OPERATION_STRUCTURE_NAME <TYPE> (PARAMS_OF_CONSTRUCTOR));
```
## Define Your Operator
```cpp
template <typename T>
class YOUR_OPERATION_STRUCTURE_NAME : public operation <T>
{
	public:
		T operator() (std::vector <T> v) const
		{
			if (v.size () < 2) throw "Bad Arguments! ;(";
			return YOUR_OPERATION_RETURN_STATEMENT; 
		}
		YOUR_OPERATION_STRUCTURE_NAME (char s = DEFAULT_VALUE, int p = DEFAULT_VALUE)
		{
			this->symbol = s;
			this->priority = p;
		}
};
```
## For example look OOP/Base/base_operations.hpp
## TODO:
1. Graphical interface and dynamic operations definitions
