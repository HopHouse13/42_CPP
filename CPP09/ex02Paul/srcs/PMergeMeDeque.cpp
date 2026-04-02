#include "../include/PMergeMeDeque.hpp"

// Genere les elem2ents de la suite de jacobsthal inferieurs a N
//  N = pend.size() + 1
std::deque<int> jacobSeqD(int N)
{
	std::deque<int> sequence;
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

elem2::elem2(char letter, int label, std::deque<int> value) : _letter(letter), _label(label), _value(value)
{
}

elem2::~elem2()
{
}

std::ostream    &operator<<(std::ostream &os, elem2 &rhs)
{
	for (size_t i = 0; i < rhs.getValue().size(); i++)
		os << rhs.getValue()[i] << " ";
	os << "/" << rhs.getLetter() << rhs.getLabel();
	return (os);
}

void print_vec(std::deque<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "[" << i << "] " << vec[i] << std::endl;
	std::cout << std::endl << std::endl;
}

void push_front(std::deque<int> &vec, int elem2)
{
	vec.resize(vec.size() + 1, 0);
	std::deque<int> temp = vec;
	vec[0] = elem2;
	for (size_t i = 0; i < temp.size() - 1; i++)
		vec[i + 1] = temp[i];
}

void addPend(std::deque<int> &main, std::deque<int> &pend, int depth)
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

void swap(std::deque<int> &main, int pos, int pack_size)
{
	// pack_size = combien d'elem2ents doivent etre swape
	// pos = position du dernier elem2 du paquet a swapper
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

void permutations(std::deque<int> &main, int depth)
{
	//Check si permutation, swap le fait

	// la depth permet de connaitre :
	// 	-1) la taille du paquet (pack_size)
	// 	-2) l'indice d'elem2ents a comparer


	// depth == 1 : pack_size == 1, elem20 vs elem21 --> 1er elem2 vs 2eme elem2
	// depth == 2 : pack_size == 2, elem21 vs elem23 --> 2eme elem2 vs 4eme elem2
	// depth == 3 : pack_size == 4, elem23 vs elem27 --> 4eme elem2 vs 8eme elem2
	// depth == 4 : pack_size == 8, elem27 vs elem215 --> 8eme elem2 vs 16eme elem2
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

void recursive(std::deque<int> &main, std::deque<int> &pend, int depth, int max_depth)
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

void push_everything_to_main(std::deque<int> &main, std::deque<int> &pend)
{
	for (size_t i = 0; i < pend.size(); i++)
		main.push_back(pend[i]);
	while (!pend.empty())
		pend.pop_back();
}

void clear_main(std::deque<int> &main)
{
	while(!main.empty())
		main.pop_back();
}

std::deque<elem2> insert_main(std::deque<int> &main, int pack_size, int n_elem2s)
{
	std::deque<elem2> result;

	size_t idx = 0;
	for (int elem2s = 0; elem2s < (n_elem2s / 2) + 1; elem2s++)
	{
		std::deque<int> temp;
		for (int i = 0; i < pack_size; i++)
		{
			temp.push_back(main[idx]);
			idx++;
		}

		if (elem2s == 0)
		{
			elem2	e('b', 1, temp);
			result.push_back(e);
		}
		else if (elem2s == 1)
		{
			elem2	e('a', 1, temp);
			result.push_back(e);
			idx += pack_size;
		}
		else
		{
			elem2	e('a', elem2s, temp);
			result.push_back(e);
			idx += pack_size;
		}
	}
	return (result);
}

std::deque<elem2> insert_pend(std::deque<int> &main, int pack_size, int n_elem2s)
{
	std::deque<elem2> result;

	size_t idx = 0;
	idx += pack_size * 2;

	 std::cout << "N_ELEM2S: " << n_elem2s << std::endl;

	if (n_elem2s % 2 != 0)
	{
		for (int elem2s = 0; elem2s < n_elem2s / 2; elem2s++)
		{
			std::deque<int> temp;
			for (int i = 0; i < pack_size; i++)
			{
				temp.push_back(main[idx]);
				idx++;
			}

			elem2	e('b', elem2s + 2, temp);
			result.push_back(e);

			idx += pack_size;
		}
	}
	else
	{
		for (int elem2s = 0; elem2s < (n_elem2s / 2) - 1; elem2s++)
		{
			std::deque<int> temp;
			for (int i = 0; i < pack_size; i++)
			{
				temp.push_back(main[idx]);
				idx++;
			}

			elem2	e('b', elem2s + 2, temp);
			result.push_back(e);

			idx += pack_size;
		}
	}

	return (result);
}

std::deque<int> get_rest(std::deque<int> &main, int pack_size, int n_elem2s)
{
	std::deque<int> rest;
	std::deque<int>::iterator it = main.begin();

	for (int i = 0; i < n_elem2s; i++)
		it += pack_size;

	while (it != main.end())
	{
		rest.push_back(*it);
		it++;
	}

	return (rest);
}

std::deque<int> calculate_insertion_order(std::deque<int> jacob)
{
	std::deque<int> result;

	for (size_t i = 3; i < jacob.size(); i++)
		result.push_back(jacob[i] - jacob[i - 1] + 1);

	return (result);
}

void begin_insertion(std::deque<elem2> &main, std::deque<elem2> &pend, std::deque<int> jacob, int pack_size)
{
	size_t elem2s = pend.size();
	// std::cout << "At init: " << elem2s << " elem2ents in pend" << std::endl;
	std::deque<int> real_jacob(jacob);
	std::deque<int>::iterator jacob_index = jacob.begin();
	std::deque<int>::iterator jacob_prev = real_jacob.begin();
	jacob_index++;

	while (elem2s != 0)
	{
		 std::cout << "Still " << elem2s << " elem2ents to push" << std::endl;
		 std::cout << "Jacobstahl index is: " << *jacob_index << std::endl;

		//Getting the elem2ent to push (corresponding to the Jacobstahl suite) --> Needs more work
		std::deque<elem2>::iterator to_push = pend.begin();
		while (to_push != pend.end() && (*to_push).getLabel() != *jacob_index)
			to_push++;
		if (to_push == pend.end())
			to_push--;
		 std::cout << "The elem2 to push is: " << *to_push << std::endl;

		//Getting the search area
		std::deque<elem2>::iterator area_start = main.begin();
		std::deque<elem2>::iterator area_end = main.begin();
		while (true)
		{
			if ((*area_end).getLabel() == (*to_push).getLabel())
				break;
			else if (area_end + 1 == main.end())
				break;
			area_end++;
		}
		 std::cout << "The search area is: " << *area_start << " ==> " << *area_end << std::endl;

		//Actually makes the comparisons
		while (area_start != main.end())
		{
			 std::cout << "Comparing: " << *to_push << " With: " << *area_start << std::endl;
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
		elem2s--;

		 std::cout << std::endl << "MAIN after insertion:" << std::endl;
		 for (size_t i = 0; i < main.size(); i++)
		 	std::cout << main[i] << std::endl;
	}
}

void insertion(std::deque<int> &main, int depth)
{
	int pack_size = pow(2, depth - 1);
	int n_elem2 = main.size() / pack_size;

	if (n_elem2 < 3)
		return ; //Only 2 elem2ents, a1 and b1 (which should already be sorted)

	std::deque<elem2> main2 = insert_main(main, pack_size, n_elem2);
	std::deque<elem2> pend2 = insert_pend(main, pack_size, n_elem2);
	std::deque<int> rest = get_rest(main, pack_size, n_elem2);

	clear_main(main);

	 std::cout << std::endl << "MAIN/Depth: " << depth << std::endl;
	 for (size_t i = 0; i < main2.size(); i++)
	 	std::cout << main2[i] << std::endl;

	 std::cout << std::endl << "PEND/Depth: " << depth << std::endl;
	 for (size_t i = 0; i < pend2.size(); i++)
	 	std::cout << pend2[i] << std::endl;

	 std::cout << std::endl << "REST/Depth: " << depth << std::endl;
	 for (size_t i = 0; i < rest.size(); i++)
	 	std::cout << rest[i] << std::endl;
	 std::cout << std::endl;

	std::deque<int> jacob = jacobSeqD(10000);
	// std::deque<int> jacob = calculate_insertion_order(jacob);
	// std::cout << std::endl << "Jacob: " << std::endl;
	// for (size_t i = 0; i < jacob.size(); i++)
	// 	std::cout << jacob[i] << std::endl;

	//Begin Insertion
	begin_insertion(main2, pend2, jacob, pack_size);

	//Now put back everything into main <int> vector to allow recursion to continue
	reinit_main(main, main2, rest, pack_size);

}

void reinit_main(std::deque<int> &main, std::deque<elem2> main2, std::deque<int> rest, int pack_size)
{
	for (size_t i = 0; i < main2.size(); i++)
	{
		for (int j = 0; j < pack_size; j++)
			main.push_back(main2[i].getValue()[j]);
	}

	for (size_t i = 0; i < rest.size(); i++)
		main.push_back(rest[i]);

	 std::cout << std::endl << "MAIN" << std::endl;
	 for (size_t i = 0; i < main.size(); i++)
	 	std::cout << main[i] << " ";
	 std::cout << std::endl;
}
