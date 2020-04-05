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
	Egg(std::function<Bird* ()> createBird) : createBird(createBird)
	{
		hatched = false;
	}

	Bird* hatch()
	{
		if (hatched)
		{
			throw std::logic_error("Already hatched.");
		}
		else
			hatched = true;

		return createBird();
	}
private:
	bool hatched;
	std::function<Bird* ()> createBird;
};

Bird* chicken();

class Chicken : public Bird
{
public:
	Chicken()
	{

	}

	Egg* lay()
	{
		Egg* egg = new Egg(chicken);
		return egg;
	}
};

Bird* chicken()
{
	return new Chicken();
}

#ifndef RunTests
int main()
{
	Bird* chicken = new Chicken();

	Egg* egg1 = chicken->lay();
	Bird* childChicken1 = egg1->hatch();
}
#endif

/*

1. Prevent to hatching an egg for the second time
2. A chicken lays an egg
3. Create a new chicken outside of class
4. Insert a created chicken to lay() to make eggs

*/