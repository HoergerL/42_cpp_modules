# include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <cerrno>
#include <sstream>
#include <sys/time.h>


void check_arguments_count(int argc)
{
    if (argc < 2)
    {
        std::cout << "too less arguments" << std::endl;
        exit(1);
    }
}

PmergeMe parse_input(int argc, char * argv[], bool is_vec)
{
    PmergeMe pmergeMe;

    check_arguments_count(argc);
        // Loop through each command line argument
    for (int i = 1; i < argc; i++) {
        // Use strtol to parse the argument as an integer
        char *endptr;
        long int n = strtol(argv[i], &endptr, 10);

        // Check for errors in the conversion
        if (*endptr != '\0') {
            std::cerr << "Invalid argument: " << argv[i] << std::endl;
            exit(1);
        } 
        // int is out of range
        else if (errno == ERANGE) {
            std::cerr << "Value too big/small for an int: " << argv[i] << std::endl;
            exit(1);
        }
        if (n < 0 || n > std::numeric_limits<int>::max())
        {
            std::cerr << "Value too big/small for a positive int: " << argv[i] << std::endl;
            exit(1);
        }
        else
        {
            if (is_vec)
                pmergeMe.add_number_vec(n);
            else
                pmergeMe.add_number_deque(n);
        }
    }
    return pmergeMe;
}


void test_vector(int argc, char * argv[])
{
    timeval startTime;
    gettimeofday(&startTime, NULL);

    PmergeMe pmergeMe = parse_input(argc, argv, 1);
    pmergeMe.sort_vec();

    timeval endTime;
    gettimeofday(&endTime, NULL);

     long int runtime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + (endTime.tv_usec - startTime.tv_usec);

    // Print the runtime
    std::cout << "Time to process a range of: " << pmergeMe.get_size_vec()  << " elements with std::vector: "<< runtime << " microseconds" << std::endl;
}


void test_deque(int argc, char * argv[])
{
    timeval startTime;
    gettimeofday(&startTime, NULL);

    PmergeMe pmergeMe = parse_input(argc, argv, 0);
    pmergeMe.sort_deque();

    timeval endTime;
    gettimeofday(&endTime, NULL);

     long int runtime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + (endTime.tv_usec - startTime.tv_usec);

    // Print the runtime
    std::cout << "Time to process a range of: " << pmergeMe.get_size_deque()  << " elements with std::deque: "<< runtime << " microseconds" << std::endl;
}


int main (int argc, char * argv[])
{
    test_vector(argc, argv);
    test_deque(argc, argv);
    return 0;
}