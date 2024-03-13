#include <iostream>

#include <vector>
#include <set>
#include <algorithm>


int main() {
	setlocale(LC_ALL, "ru");

	std::vector <int> collection(10);
	std::vector <int> collection2(20);

	for(auto &i : collection)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	auto b_ins = std::back_inserter(collection);

	b_ins.operator=	(5);
	b_ins.operator=	(6);

	std::for_each(collection.begin(), collection.end(), [](int& a)->void {static int i{ 1 }; a = i++; });
	for (auto& i : collection)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';



	std::for_each(collection2.begin(), collection2.end(), [](int& a)->void {static int i{ 1 }; a = i++; });
	for (auto& i : collection2)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';


	if (std::equal(collection2.begin(), collection2.end(), collection.begin(), collection.end()))
	{
		std::cout << "equal collections\n";
	}
	else
	{
		std::cout << "not equal collections\n";
	}


	std::vector<int> evens;
	std::copy_if(collection.begin(), collection.end(), std::back_inserter(evens), [](const int& a)->bool {return a % 2 == 0; }); 

	for (auto& i : evens)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';


	return 0;
}