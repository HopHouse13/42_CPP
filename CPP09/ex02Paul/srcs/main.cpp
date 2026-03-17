#include "../include/PMergeMeVector.hpp"
#include "../include/PMergeMeDeque.hpp"

int main(int argc, char **argv)
{
	if (argc < 3) {
		std::cout << "[-] Usage: ./PMergeMe <number sequence (space seperated)>" << std::endl;
		return (-1);
	}
	if (parsing(argv) == -1) {
		std::cout << "[-] An error has occured while parsing input. Please check you number sequence." << std::endl;
		return (-1);
	}

	int n_elems = count_elem(argv);

	//Vector way
	std::vector<int> main;
	std::vector<int> pend;
	int max_depth = how_many(count_elem(argv)) + 1;
	int i = 0;
	while (argv[++i])
		main.push_back(atoi(argv[i]));

	std::cout << "Before: ";
	for (size_t i = 0; i < main.size(); i++)
		std::cout << main[i] << " ";
	std::cout << std::endl;

	const std::clock_t cv_start = std::clock();
	recursive(main, pend, 1, max_depth);
	const std::clock_t cv_end = std::clock();

	std::cout << "After: ";
	for (size_t i = 0; i < main.size(); i++)
		std::cout << main[i] << " ";
	std::cout << std::endl;


	//Deque way
	std::deque<int> main2;
	std::deque<int> pend2;
	int max_depth2 = how_many(count_elem(argv)) + 1;
	int i2 = 0;
	while (argv[++i2])
		main2.push_back(atoi(argv[i2]));

	std::cout << "Before: ";
	for (size_t i = 0; i < main2.size(); i++)
		std::cout << main2[i] << " ";
	std::cout << std::endl;

	const std::clock_t cd_start = std::clock();
	recursive(main2, pend2, 1, max_depth2);
	const std::clock_t cd_end = std::clock();

	std::cout << "After: ";
	for (size_t i = 0; i < main2.size(); i++)
		std::cout << main2[i] << " ";
	std::cout << std::endl;

	//Result Time
	std::cout << "\nTime to process a range of " << n_elems << " with std::vector: "
	<< std::fixed << std::setprecision(2) << 1000.0 * (cv_end - cv_start) / CLOCKS_PER_SEC << "ms" << std::endl;
	std::cout << "Time to process a range of " << n_elems << " with std::deque: "
	<< std::fixed << std::setprecision(2) << 1000.0 * (cd_end - cd_start) / CLOCKS_PER_SEC << "ms" << std::endl;

	return (0);
}
