#include "uint.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main()
{
	Data data;
	data.i = 5;
	data.j = 6;
	uintptr_t ptr = serialize(&data);
	Data *data2 = deserialize(ptr);
	std::cout << "i: " << data2->i << ", j: " << data2->j << std::endl;
	std::cout << "pointer data: " << &data << ", pointer data2: " << data2 << std::endl;
}