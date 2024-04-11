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
void heapMedian(const std::vector<int>* instructions) {
    // Initialize two priority queues: one for the maximum elements (max heap) and one for the minimum elements (min heap)
    std::priority_queue<int> max;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min;

    // Vector to store the calculated medians
    std::vector<int> medians;
    //time 
    auto start = std::chrono::high_resolution_clock::now();
    // Iterate through the instructions vector
    for (auto i = (*instructions).begin(); i != (*instructions).end(); ++i) {
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
            // For non-median instructions, insert the element into the appropriate heap
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
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Execution time for heapMedian: " << elapsed.count() << " microseconds\n";
    // Output the calculated medians
    for (auto i = medians.begin(); i != medians.end(); ++i) {
        std::cout << *i << " ";
    }
}
