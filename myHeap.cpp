/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 2
The myHeap
cpp file
*/
#include "myHeap.hpp"

// Function to calculate medians using two priority queues (max heap and min heap)
#include "myHeap.hpp"
void heapMedian(const std::vector<int>* instructions) {
    std::priority_queue<int> max; // Max heap to store larger elements
    std::priority_queue<int, std::vector<int>, std::greater<int>> min; // Min heap to store smaller elements
    std::vector<int> medians; // Vector to store calculated medians

    // Iterate through the instructions vector
    for (auto i = instructions->begin(); i != instructions->end(); ++i) {
        // If the instruction is -1, it indicates a request to calculate and remove the median
        if (*i == -1) {
            // Check if both max heap and min heap are not empty
            if (!max.empty() && !min.empty()) {
                // Check if the sizes of max heap and min heap are equal
                if (max.size() == min.size()) {
                    // Median is the top element of max heap (larger half)
                    int median = max.top();
                    medians.push_back(median);
                    max.pop(); // Remove median from max heap
                } else {
                    // If sizes are not equal, median is still from max heap, but don't remove it
                    medians.push_back(max.top());
                    // Do not pop to maintain the invariant that max heap has more elements than min heap
                }
            }
        } else {
            // Insert element into the appropriate heap based on its value
            if (max.empty() || *i <= max.top()) {
                max.push(*i); // Insert into max heap if empty or element is smaller than current max
            } else {
                min.push(*i); // Insert into min heap if element is larger than current max
            }

            // Rebalance the heaps if necessary to maintain the invariant that max heap has more elements than min heap
            if (max.size() > min.size() + 1) {
                min.push(max.top()); // Move top element of max heap to min heap
                max.pop(); // Remove element from max heap
            } else if (max.size() < min.size()) {
                max.push(min.top()); // Move top element of min heap to max heap
                min.pop(); // Remove element from min heap
            }
            
        }
    }

    // Output the calculated medians
    for (auto i = medians.begin(); i != medians.end(); ++i) {
        std::cout << *i << " ";
    }
}
