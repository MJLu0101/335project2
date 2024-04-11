#include "myList.hpp"

// Function to calculate medians using a sorted list
void listMedian(const std::vector<int>* instructions) {
    // Initialize a list to store elements and another list for medians
    std::list<int> lst;
    std::list<int> medianlst;
    int medianIndex; // Index of the median element

    // Iterate through the instructions vector
    for (auto i = (*instructions).begin(); i != (*instructions).end(); ++i) {
        // If the instruction is -1, it indicates a request to calculate and remove the median
        if (*i == -1) {
            // Check if the list is not empty
            if (!lst.empty()) {
                medianIndex = lst.size() / 2; // Calculate the median index

                // Check if the list size is odd or even to determine median position
                if (lst.size() % 2 == 1) {
                    // For odd size, find the median and erase it from the list
                    auto it = lst.begin();
                    std::advance(it, medianIndex);
                    medianlst.push_back(*it);
                    lst.erase(it);
                } else {
                    // For even size, find the median and erase it from the list
                    auto it = lst.begin();
                    std::advance(it, medianIndex - 1);
                    medianlst.push_back(*it);
                    lst.erase(it);
                }
            }
        } else {
            lst.sort(); // Sort the list in ascending order
            auto lower = std::lower_bound(lst.begin(), lst.end(), *i); // Find lower bound for insertion
            lst.insert(lower, *i); // Insert element into the sorted position
        }
    }

    // Output the calculated medians
    for (auto i = medianlst.begin(); i != medianlst.end(); ++i) {
        std::cout << *i << " ";
    }
}
