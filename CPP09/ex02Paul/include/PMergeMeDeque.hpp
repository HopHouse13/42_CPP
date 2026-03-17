#ifndef PMERGEMEDEQUE_HPP
# define PMERGEMEDEQUE_HPP

# include "PMergeMeVector.hpp"

class elem2
{
	private:
		char _letter;
		int _label;
		std::deque<int> _value;

	public:
		elem2(char letter, int label, std::deque<int> value);
		~elem2();

		char getLetter() { return _letter; }
		int getLabel() { return _label; }
		std::deque<int> getValue() { return _value; }
};

void push_front(std::deque<int> &vec, int elem);
void addPend(std::deque<int> &list, std::deque<int> &pend, int depth);
void print_vec(std::deque<int> vec);
void recursive(std::deque<int> &main, std::deque<int> &pend, int depth, int max_depth);
void swap(std::deque<int> &main, int pos, int pack_size);
void push_everything_to_main(std::deque<int> &main, std::deque<int> &pend);
void insertion(std::deque<int> &main, int depth);
void clear_main(std::deque<int> &main);
std::deque<elem2> insert_main(std::deque<int> &main, int pack_size, int n_elems);
std::deque<elem2> insert_pend(std::deque<int> &main, int pack_size, int n_elems);
std::deque<int> jacobSeqD(int N);
void begin_insertion(std::deque<elem2> &main, std::deque<elem2> &pend, std::deque<int> jacob, int pack_size);
void reinit_main(std::deque<int> &main, std::deque<elem2> main2, std::deque<int> rest, int pack_size);
std::deque<int> get_rest(std::deque<int> &main, int pack_size, int n_elems);

std::ostream    &operator<<(std::ostream &os, elem2 &rhs);

#endif
