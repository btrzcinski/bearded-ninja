#include <iostream>
#include <string>
#include <vector>
#include <random>

struct student
{
	unsigned id;
	std::wstring name;

	operator std::wstring() 
	{
		auto strRep = std::wstring{L"id = "} + std::to_wstring(id) + L", name=" + name;
		return strRep;
	}
};

void printclass(std::vector<student>& c)
{
	for(auto&& s : c)
	{
		std::wcout << static_cast<std::wstring>(s) << std::endl;
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
	for(auto i = 0U; i < 50; ++i)
	{
		std::swap(c[i],c[rando() % 50]);
	}
}

int main(int argc, char *argv[])
{
	auto c = std::vector<student>{};
	for(auto i = 0U; i < 50; ++i)
	{
		auto name = std::wstring{L"Student"} + std::to_wstring(i);
		c.push_back(student{i, name});
	}

	printclass(c);
	std::wcout << std::endl;
	shuffle(c);
	printclass(c);
	std::wcout << std::endl;

	std::wcout << L"swaps = " << countsort(c) << std::endl;
	printclass(c);

	return 0;
}
