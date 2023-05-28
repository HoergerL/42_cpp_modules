#include "iter.hpp"

void	print_str(std::string str)
{
	std::cout << str << std::endl;
}

void	print_int(int i)
{
	std::cout << i << std::endl;
}

int main()
{
	std::string arr[4] = {"a", "b", "c", "d"};
	int arr2[7] = {1, 2, 3, 4, 5, 6, 7};

	iter(arr, 4, &print_str);
	iter(arr2, 7, &print_int);
}

/* class Awesome
{
public:
Awesome( void ) : _n( 42 ) { return; }
int get( void ) const { return this->_n; }
private:
int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

void	print(Awesome aw)
{
	std::cout << aw << std::endl;
}

int main() {
int tab[] = { 0, 1, 2, 3, 4 };
Awesome tab2[5];
iter( tab, 5, print_int);
iter( tab2, 5, print);
return 0;
} */