/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 2
The myVector
cpp file
*/
#include "myVector.hpp"

// Function to calculate medians using a vector
void vectorMedian(const std::vector<int>* instructions) {
    std::vector<int> vec; // Vector to store elements
    std::vector<int> medianvec; // Vector to store medians
    // Start timing
    //auto start = std::chrono::high_resolution_clock::now();
    // Iterate through the instructions vector
    for (int i = 0; i < instructions->size(); i++) {
        // If the instruction is -1, it indicates a request to calculate and remove the median
        if ((*instructions)[i] == -1) {
            // Check if the vector is not empty
            if (!vec.empty()) {
                int medianIndex = vec.size() / 2; // Calculate the median index

                // Check if the vector size is odd or even to determine median position
                if (vec.size() % 2 == 1) {
                    // For odd size, find the median and erase it from the vector
                    medianvec.push_back(vec[medianIndex]);
                    vec.erase(vec.begin() + medianIndex);
                } else {
                    // For even size, find the median and erase it from the vector
                    medianvec.push_back(vec[medianIndex - 1]);
                    vec.erase(vec.begin() + medianIndex - 1);
                }
            }
        } else {
            auto lower = std::lower_bound(vec.begin(), vec.end(), (*instructions)[i]); // Find lower bound for insertion
            vec.insert(lower, (*instructions)[i]); // Insert element into the sorted position
        }
    }
    // Stop timing
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double, std::micro> elapsed = end - start;
    // std::cout << "Execution time for vectorMedian: " << elapsed.count() << " microseconds\n";
   // Output the calculated medians
    for (int i = 0; i < medianvec.size(); i++) {
        std::cout << medianvec[i] << " ";
    }
}
