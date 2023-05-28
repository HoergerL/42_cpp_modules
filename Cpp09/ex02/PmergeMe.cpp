#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}
PmergeMe::PmergeMe (const PmergeMe &pmergeMe)
{
    *this = pmergeMe;
}
PmergeMe::~PmergeMe ()
{

}
PmergeMe& PmergeMe::operator = (const PmergeMe &pmergeMe)
{
    this->_numbers = pmergeMe._numbers;
    return (*this);
}

 void PmergeMe::add_number_vec(int number)
 {
    this->_numbers.push_back(number);
 }

void PmergeMe::insertion_sort_vec(std::vector<int> &elements, std::vector<int>::size_type start, std::vector<int>::size_type end)
 {
    for (std::vector<int>::size_type i = start; i < end; i++) {
        int key = elements[i];
        // std::cout << "key: " << key << ", i: " << i << std::endl;
        long int j = i - 1;
        // std::cout << j << std::endl;
        // Move elements greater than key to one position ahead of their current position
        while (j >= (long int) start && elements[j] > key) {
            elements[j + 1] = elements[j];
            j--;
        }

        elements[j + 1] = key;
    }
}

void PmergeMe::print_vec(std::vector<int> vec, std::string message)
{
    std::cout << message;
    for (std::vector<int>::size_type i = 0; i <  vec.size(); i++)
    {
        std::cout  << vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::merge_vec(std::vector<int> &elements, std::vector<int>::size_type vec_len, std::vector<int>::size_type start, 
        std::vector<int>::size_type end)
{
    std::vector<int> copy1;
    std::vector<int> copy2;
    std::vector<int>::size_type j = 0; //copy1
    std::vector<int>::size_type k = 0; // copy2

    copy1.reserve(vec_len);
    copy2.reserve(vec_len);

    // print_vec(elements, "elements merge: ");
    // std::cout << "vec_len: " << vec_len << std::endl;

    for (std::vector<int>::size_type i = start; i < end; i++)
    {
        if (i < start + vec_len)
            copy1.push_back(elements[i]);
        else
            copy2.push_back(elements[i]);
    }

    // print_vec(copy1, "copy1: ");
    // print_vec(copy2, "copy2: ");
    for(std::vector<int>::size_type i = start; i < end; i++)
    {
        if (j < copy1.size() && k < copy2.size())
        {
            if (copy1[j] > copy2[k])
            {
                elements[i] = copy2[k];
                k++;
            }
            else
            {
                elements[i] = copy1[j];
                j++;
            }
        }
        else if (j < copy1.size())
        {
            // std::cout << "copy rest elements from copy 1" << std::endl;
            elements[i] = copy1[j];
                j++;
        }
        else if (k < copy2.size())
        {
            // std::cout << "copy rest elements from copy 2" << std::endl;
            elements[i] = copy2[k];
                k++;
        }
        else
            std::cout << "Error: inside Merge" << std::endl;

    }
}

void PmergeMe::merge_sort_vec(std::vector<int> &elements, int start, int end, int min_len)
{
    int vec_len = end - start;
    if (vec_len > min_len)
    {  
        merge_sort_vec(elements, start, start + vec_len / 2, min_len );
        merge_sort_vec(elements, start + vec_len / 2, end, min_len);
        merge_vec(elements, vec_len / 2, start, end);
    }
    else
        insertion_sort_vec(elements, start, end);
}


 void PmergeMe::sort_vec()
 {
    std::cout << "VECTOR: " << std::endl;
    int size_groups = 5;
    print_vec(this->_numbers, "Before: ");
    merge_sort_vec(this->_numbers, 0, this->_numbers.size(), size_groups);
    print_vec(this->_numbers, "After: ");

 }

std::vector<int>::size_type PmergeMe::get_size_vec()
{
return this->_numbers.size();
}


// deque functions


 void PmergeMe::add_number_deque(int number)
 {
    this->_numbers_deque.push_back(number);
 }

 void PmergeMe::print_deque(std::deque<int> deque, std::string message)
{
    std::cout << message;
    for (std::deque<int>::iterator it=deque.begin(); it!=deque.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}


void PmergeMe::insertion_sort_deque(std::deque<int> &elements, std::deque<int>::size_type start, std::deque<int>::size_type end)
 {
    for (std::deque<int>::size_type i = start; i < end; i++) {
        int key = elements[i];
        long int j = i - 1;
        // Move elements greater than key to one position ahead of their current position
        while (j >= (long int) start && elements[j] > key) {
            elements[j + 1] = elements[j];
            j--;
        }

        elements[j + 1] = key;
    }
}

void PmergeMe::merge_deque(std::deque<int> &elements, std::deque<int>::size_type deque_len, std::deque<int>::size_type start, 
        std::deque<int>::size_type end)
{
    std::deque<int> copy1;
    std::deque<int> copy2;
    std::deque<int>::size_type j = 0; //copy1
    std::deque<int>::size_type k = 0; // copy2

    // print_vec(elements, "elements merge: ");
    // std::cout << "deque_len: " << deque_len << std::endl;

    for (std::deque<int>::size_type i = start; i < end; i++)
    {
        if (i < start + deque_len)
            copy1.push_back(elements[i]);
        else
            copy2.push_back(elements[i]);
    }

    // print_deque(copy1, "copy1: ");
    // print_deque(copy2, "copy2: ");
    for(std::deque<int>::size_type i = start; i < end; i++)
    {
        if (j < copy1.size() && k < copy2.size())
        {
            if (copy1[j] > copy2[k])
            {
                elements[i] = copy2[k];
                k++;
            }
            else
            {
                elements[i] = copy1[j];
                j++;
            }
        }
        else if (j < copy1.size())
        {
            // std::cout << "copy rest elements from copy 1" << std::endl;
            elements[i] = copy1[j];
                j++;
        }
        else if (k < copy2.size())
        {
            // std::cout << "copy rest elements from copy 2" << std::endl;
            elements[i] = copy2[k];
                k++;
        }
        else
            std::cout << "Error: inside Merge" << std::endl;
    }
}


void PmergeMe::merge_sort_deque(std::deque<int> &elements, int start, int end, int min_len)
{
    int deque_len = end - start;
    if (deque_len > min_len)
    {  
        merge_sort_deque(elements, start, start + deque_len / 2, min_len );
        merge_sort_deque(elements, start + deque_len / 2, end, min_len);
        merge_deque(elements, deque_len / 2, start, end);
    }
    else
        insertion_sort_deque(elements, start, end);
}


 void PmergeMe::sort_deque()
 {
    std::cout << std::endl << "DEQUE: " << std::endl;
    int size_groups = 5;
    print_deque(this->_numbers_deque, "Before: ");
    merge_sort_deque(this->_numbers_deque, 0, this->_numbers_deque.size(), size_groups);
    print_deque(this->_numbers_deque, "After: ");
 }

  std::deque<int>::size_type PmergeMe::get_size_deque()
 {
    return this->_numbers_deque.size();
 }