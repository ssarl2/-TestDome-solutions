#include <stdexcept>
#include <functional>

class Egg;

class Bird
{
public:
	virtual ~Bird() {};
	virtual Egg* lay() = 0;
};

class Egg
{
public:
	Egg(std::function<Bird* ()> createBird)
	{
		throw std::logic_error("Waiting to be implemented");
	}

	Bird* hatch()
	{
		throw std::logic_error("Waiting to be implemented");
	}
};

class Chicken : public Bird
{
public:
	Chicken()
	{

	}

	Egg* lay()
	{
		throw std::logic_error("Waiting to be implemented");
	}
};

#ifndef RunTests
int main()
{
	Bird* chicken = new Chicken();

	Egg* egg1 = chicken->lay();
	Bird* childChicken1 = egg1->hatch();
}
#endif
