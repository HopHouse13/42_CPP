#include "../include/PMergeMeVector.hpp"

int parsing(char **argv)
{
	int i = 0;
	while (argv[++i]) {
		int j = -1;
		while (argv[i][++j]) {
			if (!isdigit(argv[i][j]))
			return (-1);
		}
	}
	return (0);
}

int count_elem(char **argv)
{
	int i = 1;
	while (argv[i])
		i++;
	return (i - 1);
}

int rec_how_many(int &count, int n)
{
	if (n / 2 >= 2)
	{
		count++;
		rec_how_many(count, n / 2);
	}
	return (count);
}

int how_many(int n)
{
	if (n % 2 != 0)
	n--;
	int count = 0;
	rec_how_many(count, n);
	return (count);
}

// Genere les elements de la suite de jacobsthal inferieurs a N
//  N = pend.size() + 1
std::vector<int> jacobSeq(int N)
{
	std::vector<int> sequence;
	for (int i = 0; i < N; ++i)
	{
		// Calcul de 2^i
		long power = 1L << i; // plus rapide que pow(2, i)
		// Calcul de (-1)^i
		int sign = (i % 2 == 0) ? 1 : -1;
		// Formule : (2^i - (-1)^i) / 3
		int value = static_cast<int>((power - sign) / 3);
		if (value >= N) break;
		if (i != 0 && i != 1)
			sequence.push_back(value);
	}
	return (sequence);
}

elem::elem(char letter, int label, std::vector<int> value) : _letter(letter), _label(label), _value(value)
{
}

elem::~elem()
{
}

std::ostream    &operator<<(std::ostream &os, elem &rhs)
{
	for (size_t i = 0; i < rhs.getValue().size(); i++)
		os << rhs.getValue()[i] << " ";
	os << "/" << rhs.getLetter() << rhs.getLabel();
	return (os);
}

void print_vec(std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "[" << i << "] " << vec[i] << std::endl;
	std::cout << std::endl << std::endl;
}

void push_front(std::vector<int> &vec, int elem)
{
	vec.resize(vec.size() + 1, 0);
	std::vector<int> temp = vec;
	vec[0] = elem;
	for (size_t i = 0; i < temp.size() - 1; i++)
		vec[i + 1] = temp[i];
}

void addPend(std::vector<int> &main, std::vector<int> &pend, int depth)
{
	if (depth == 1)
	{
		if (main.size() % 2 == 0)
			return;
		push_front(pend, main[main.size() - 1]);
		main.pop_back();
	}
	else
	{
		size_t n_pend = main.size() % static_cast<int>(pow(2, depth));
		size_t i = main.size() - 1;
		while (n_pend)
		{
			push_front(pend, main[i]);
			main.pop_back();
			n_pend--;
			i--;
		}
	}
}

void swap(std::vector<int> &main, int pos, int pack_size)
{
	// pack_size = combien d'elements doivent etre swape
	// pos = position du dernier elem du paquet a swapper
	int tmp;
	size_t stop = pack_size;

	while (stop)
	{
		tmp = main[pos];
		main[pos] = main[pos + pack_size];
		main[pos + pack_size] = tmp;
		stop--;
		pos--;
	}
}

void permutations(std::vector<int> &main, int depth)
{
	//Check si permutation, swap le fait

	// la depth permet de connaitre :
	// 	-1) la taille du paquet (pack_size)
	// 	-2) l'indice d'elements a comparer


	// depth == 1 : pack_size == 1, elem0 vs elem1 --> 1er elem vs 2eme elem
	// depth == 2 : pack_size == 2, elem1 vs elem3 --> 2eme elem vs 4eme elem
	// depth == 3 : pack_size == 4, elem3 vs elem7 --> 4eme elem vs 8eme elem
	// depth == 4 : pack_size == 8, elem7 vs elem15 --> 8eme elem vs 16eme elem
	// 2^depth  == pack_size

	int pack_size = pow(2, depth - 1);

	for (size_t i = pack_size - 1; i < main.size(); i += (pack_size * 2))
	{
		if (main[i] > main[i + pack_size])
		{
			swap(main, i, pack_size);
		}
	}
}

void recursive(std::vector<int> &main, std::vector<int> &pend, int depth, int max_depth)
{
	if (depth != max_depth + 1)
	{
		addPend(main, pend, depth);
		permutations(main, depth);
		recursive(main, pend, depth + 1, max_depth);
	}
	push_everything_to_main(main, pend);
	insertion(main, depth);
	return ;
}

void push_everything_to_main(std::vector<int> &main, std::vector<int> &pend)
{
	for (size_t i = 0; i < pend.size(); i++)
		main.push_back(pend[i]);
	while (!pend.empty())
		pend.pop_back();
}

void clear_main(std::vector<int> &main)
{
	while(!main.empty())
		main.pop_back();
}

std::vector<elem> insert_main(std::vector<int> &main, int pack_size, int n_elems)
{
	std::vector<elem> result;

	size_t idx = 0;
	for (int elems = 0; elems < (n_elems / 2) + 1; elems++)
	{
		std::vector<int> temp;
		for (int i = 0; i < pack_size; i++)
		{
			temp.push_back(main[idx]);
			idx++;
		}

		if (elems == 0)
		{
			elem	e('b', 1, temp);
			result.push_back(e);
		}
		else if (elems == 1)
		{
			elem	e('a', 1, temp);
			result.push_back(e);
			idx += pack_size;
		}
		else
		{
			elem	e('a', elems, temp);
			result.push_back(e);
			idx += pack_size;
		}
	}
	return (result);
}

std::vector<elem> insert_pend(std::vector<int> &main, int pack_size, int n_elems)
{
	std::vector<elem> result;

	size_t idx = 0;
	idx += pack_size * 2;

	// std::cout << "N_ELEMS: " << n_elems << std::endl;

	if (n_elems % 2 != 0)
	{
		for (int elems = 0; elems < n_elems / 2; elems++)
		{
			std::vector<int> temp;
			for (int i = 0; i < pack_size; i++)
			{
				temp.push_back(main[idx]);
				idx++;
			}

			elem	e('b', elems + 2, temp);
			result.push_back(e);

			idx += pack_size;
		}
	}
	else
	{
		for (int elems = 0; elems < (n_elems / 2) - 1; elems++)
		{
			std::vector<int> temp;
			for (int i = 0; i < pack_size; i++)
			{
				temp.push_back(main[idx]);
				idx++;
			}

			elem	e('b', elems + 2, temp);
			result.push_back(e);

			idx += pack_size;
		}
	}

	return (result);
}

std::vector<int> get_rest(std::vector<int> &main, int pack_size, int n_elems)
{
	std::vector<int> rest;
	std::vector<int>::iterator it = main.begin();

	for (int i = 0; i < n_elems; i++)
		it += pack_size;

	while (it != main.end())
	{
		rest.push_back(*it);
		it++;
	}

	return (rest);
}

std::vector<int> calculate_insertion_order(std::vector<int> jacob)
{
	std::vector<int> result;

	for (size_t i = 3; i < jacob.size(); i++)
		result.push_back(jacob[i] - jacob[i - 1] + 1);

	return (result);
}

void begin_insertion(std::vector<elem> &main, std::vector<elem> &pend, std::vector<int> jacob, int pack_size)
{
	size_t elems = pend.size();
	// std::cout << "At init: " << elems << " elements in pend" << std::endl;
	std::vector<int> real_jacob(jacob);
	std::vector<int>::iterator jacob_index = jacob.begin();
	std::vector<int>::iterator jacob_prev = real_jacob.begin();
	jacob_index++;

	while (elems != 0)
	{
		// std::cout << "Still " << elems << " elements to push" << std::endl;
		// std::cout << "Jacobstahl index is: " << *jacob_index << std::endl;

		//Getting the element to push (corresponding to the Jacobstahl suite) --> Needs more work
		std::vector<elem>::iterator to_push = pend.begin();
		while (to_push != pend.end() && (*to_push).getLabel() != *jacob_index)
			to_push++;
		if (to_push == pend.end())
			to_push--;
		// std::cout << "The elem to push is: " << *to_push << std::endl;

		//Getting the search area
		std::vector<elem>::iterator area_start = main.begin();
		std::vector<elem>::iterator area_end = main.begin();
		while (true)
		{
			if ((*area_end).getLabel() == (*to_push).getLabel())
				break;
			else if (area_end + 1 == main.end())
				break;
			area_end++;
		}
		// std::cout << "The search area is: " << *area_start << " ==> " << *area_end << std::endl;

		//Actually makes the comparisons
		while (area_start != main.end())
		{
			// std::cout << "Comparing: " << *to_push << " With: " << *area_start << std::endl;
			if ((*to_push).getValue()[pack_size - 1] < (*area_start).getValue()[pack_size - 1])
			{
				// std::cout << "Inserting" << std::endl;
				main.insert(area_start, *to_push);
				pend.erase(to_push);
				break;
			}
			area_start++;
		}

		(*jacob_index)--;
		if (*jacob_index == *jacob_prev)
		{
			jacob_index++;
			jacob_prev++;
		}
		elems--;

		// std::cout << std::endl << "MAIN after insertion:" << std::endl;
		// for (size_t i = 0; i < main.size(); i++)
		// 	std::cout << main[i] << std::endl;
	}
}

void insertion(std::vector<int> &main, int depth)
{
	int pack_size = pow(2, depth - 1);
	int n_elem = main.size() / pack_size;

	if (n_elem < 3)
		return ; //Only 2 elements, a1 and b1 (which should already be sorted)

	std::vector<elem> main2 = insert_main(main, pack_size, n_elem);
	std::vector<elem> pend2 = insert_pend(main, pack_size, n_elem);
	std::vector<int> rest = get_rest(main, pack_size, n_elem);

	clear_main(main);

	// std::cout << std::endl << "MAIN/Depth: " << depth << std::endl;
	// for (size_t i = 0; i < main2.size(); i++)
	// 	std::cout << main2[i] << std::endl;

	// std::cout << std::endl << "PEND/Depth: " << depth << std::endl;
	// for (size_t i = 0; i < pend2.size(); i++)
	// 	std::cout << pend2[i] << std::endl;

	// std::cout << std::endl << "REST/Depth: " << depth << std::endl;
	// for (size_t i = 0; i < rest.size(); i++)
	// std::cout << rest[i] << std::endl;
	// std::cout << std::endl;

	std::vector<int> jacob = jacobSeq(10000);
	// std::vector<int> jacob = calculate_insertion_order(jacob);
	// std::cout << std::endl << "Jacob: " << std::endl;
	// for (size_t i = 0; i < jacob.size(); i++)
	// 	std::cout << jacob[i] << std::endl;

	//Begin Insertion
	begin_insertion(main2, pend2, jacob, pack_size);

	//Now put back everything into main <int> vector to allow recursion to continue
	reinit_main(main, main2, rest, pack_size);

}

void reinit_main(std::vector<int> &main, std::vector<elem> main2, std::vector<int> rest, int pack_size)
{
	for (size_t i = 0; i < main2.size(); i++)
	{
		for (int j = 0; j < pack_size; j++)
			main.push_back(main2[i].getValue()[j]);
	}

	for (size_t i = 0; i < rest.size(); i++)
		main.push_back(rest[i]);

	// std::cout << std::endl << "MAIN" << std::endl;
	// for (size_t i = 0; i < main.size(); i++)
		// std::cout << main[i] << " ";
	// std::cout << std::endl;
}
