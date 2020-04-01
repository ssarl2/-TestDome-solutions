#include <iostream>
#include <string>

class TextInput
{
	std::string res;
public:
	virtual void add(char c) { res += c; }
	std::string getValue() { return res; }
};

class NumericInput : public TextInput
{
public:
	void add(char c)
	{
		if ((c + 0) >= 48 && (c + 0) <= 57)
		{
			TextInput::add(c);
		}
	}
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