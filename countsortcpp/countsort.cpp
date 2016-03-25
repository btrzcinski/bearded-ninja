#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <random>

struct student
{
	unsigned id;
	std::string name;

	operator std::string() const
	{
        std::ostringstream strRep;
        strRep << "id = " << id << ", name=" << name;
        return strRep.str();
	}
};

void printclass(std::vector<student>& c)
{
	for(auto const& s : c)
	{
		std::cout << static_cast<std::string>(s) << std::endl;
	}
}

unsigned countsort(std::vector<student>& c)
{
	auto swaps = 0U;
	for(auto i = 0; i < c.size(); i++)
	{
		// keep swapping students until we are aligned
		while(c[i].id != i)
		{
			auto dest = c[i].id;
			std::swap(c[i], c[dest]);
			++swaps;
		}
	}
	return swaps;
}

void shuffle(std::vector<student>& c)
{
	static auto rando = std::minstd_rand{std::random_device{}()};
	for(auto i = 0U; i < c.size(); ++i)
	{
		std::swap(c[i],c[rando() % c.size()]);
	}
}

int main(int argc, char *argv[])
{
	auto c = std::vector<student>{};
	for(auto i = 0U; i < 50; ++i)
	{
		auto name = std::string{"Student"} + std::to_string(i);
		c.push_back(student{i, name});
	}

	printclass(c);
	std::cout << std::endl;
	shuffle(c);
	printclass(c);
	std::cout << std::endl;

	std::cout << "swaps = " << countsort(c) << std::endl;
	printclass(c);

	return 0;
}
