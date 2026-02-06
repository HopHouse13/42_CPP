#include <iostream>
#include <list>
#include <vector>

int main()
{
	//std::list<int> testList;

	//testList.push_back(42);
	//std::cout << testList.size() << std::endl;
	//std::cout << testList[0] << std::endl;

	std::vector<int> testList;
	testList.push_back(1);
	testList.push_back(2);
	testList.push_back(3);
	testList.push_back(4);
	testList.push_back(5);

	std::vector<int>::iterator it;

	for (it = testList.begin(); it != testList.end(); it++) {
		*it = 42;
	}

	for (it = testList.begin(); it != testList.end(); it++) {
		std::cout << *it << std::endl;
	}
	
}