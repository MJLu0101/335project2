/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 2
The myList
cpp file
*/
#include "myList.hpp"

// Function to calculate medians using a sorted list
void listMedian(const std::vector<int>* instructions) {
    // Initialize a list to store elements and another list for medians
    std::list<int> lst;
    std::list<int> medianlst;
    int medianIndex; // Index of the median element
    // Start timing
    //auto start = std::chrono::high_resolution_clock::now();
    // Iterate through the instructions vector
    for (auto i = instructions->begin(); i != instructions->end(); ++i) {
        // If the instruction is -1, it indicates a request to calculate and remove the median
        if (*i == -1) {
            if (!lst.empty()) {
                medianIndex = lst.size() / 2; // Calculate the median index

                // Find the median element and erase it from the list
                auto it = lst.begin();
                std::advance(it, medianIndex);
                medianlst.push_back(*it);
                lst.erase(it);
            }
        } else {
            // Insert element into the list in sorted order
            auto lower = std::lower_bound(lst.begin(), lst.end(), *i);
            lst.insert(lower, *i);
        }
    }

    // Stop timing
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double, std::micro> elapsed = end - start;
    // std::cout << "Execution time for listMedian: " << elapsed.count() << " microseconds\n";

    // Output the calculated medians
    for (auto i = medianlst.begin(); i != medianlst.end(); ++i) {
        std::cout << *i << " ";
    }
}