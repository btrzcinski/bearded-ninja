#include <iostream>

template<int I>
struct FibonacciSeries
{
	enum { Value = FibonacciSeries<I-2>::Value + FibonacciSeries<I-1>::Value };
};

template<>
struct FibonacciSeries<0>
{
	enum { Value = 1 };
};

template<>
struct FibonacciSeries<1>
{
	enum { Value = 1 };
};

int main()
{
	std::cout << FibonacciSeries<0>::Value << std::endl;
	std::cout << FibonacciSeries<1>::Value << std::endl;
	std::cout << FibonacciSeries<2>::Value << std::endl;
	std::cout << FibonacciSeries<3>::Value << std::endl;
	std::cout << FibonacciSeries<4>::Value << std::endl;
	std::cout << FibonacciSeries<5>::Value << std::endl;
	std::cout << FibonacciSeries<6>::Value << std::endl;
	std::cout << FibonacciSeries<7>::Value << std::endl;
	std::cout << FibonacciSeries<8>::Value << std::endl;
	std::cout << FibonacciSeries<9>::Value << std::endl;

	return 0;
}