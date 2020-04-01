#include <iostream>
#include <string>

class TextInput
{
	std::string res;
public:
	TextInput()
	{
		res = "NULL";
	}
	void add(char c)
	{
		//if ((c + 0) >= 48 && (c + 0) <= 57)
		//{
		//	//std::cout << c;
		//	res = res + c;
		//}
	}

	std::string getValue() { return res; }
};

class NumericInput : public TextInput
{
	std::string rea;
public:
	NumericInput()
	{
		rea = "";
	}
	void add(char c)
	{
		if ((c + 0) >= 48 && (c + 0) <= 57)
		{
			//std::cout << c;
			rea = rea + c;
		}
	}

	std::string getValue() { return rea; }
};

#ifndef RunTests
int main()
{
	TextInput* input = new NumericInput();
	input->add('1');
	input->add('a');
	input->add('0');
	std::cout << input->getValue();
}
#endif