#pragma once
#include <vector>
#include <iostream>
#include <deque>

class PmergeMe
{
private:
    std::vector<int> _numbers;
    std::deque<int> _numbers_deque;

public:
    PmergeMe();
    PmergeMe (const PmergeMe &PmergeMe);
    ~PmergeMe ();
    PmergeMe& operator = (const PmergeMe &PmergeMe);

    // vec functions
    void add_number_vec(int number);
    void sort_vec();
    void merge_sort_vec(std::vector<int> &elements, int start, int end, int min_len);
    void merge_vec(std::vector<int> &elements, std::vector<int>::size_type vec_len, 
        std::vector<int>::size_type start, std::vector<int>::size_type end);
    void print_vec(std::vector<int> vec, std::string message);
    void insertion_sort_vec(std::vector<int> &elements, std::vector<int>::size_type start, std::vector<int>::size_type end);
    std::vector<int>::size_type get_size_vec();

    // list functions
    void add_number_deque(int number);
    void print_deque(std::deque<int> list, std::string message);
    void sort_deque();
    void insertion_sort_deque(std::deque<int> &elements, std::deque<int>::size_type start, std::deque<int>::size_type end);
    void merge_deque(std::deque<int> &elements, std::deque<int>::size_type vec_len, std::deque<int>::size_type start, 
        std::deque<int>::size_type end);
    void merge_sort_deque(std::deque<int> &elements, int start, int end, int min_len);
    std::deque<int>::size_type get_size_deque();

};