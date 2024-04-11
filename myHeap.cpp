/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 2
The myHeap
cpp file
*/
#include "myHeap.hpp"
void heapMedian (const std::vector<int> * instructions){
    // Initialize two priority queues: one for the maximum elements (max heap) and one for the minimum elements (min heap)
    std::priority_queue<int>max;
    std::priority_queue<int, std::vector<int>, std::greater<int>>min;
    // Vector to store the calculated medians
    std::vector<int>medians;
     // Iterate through the instructions vector
    for(auto i=(*instructions).begin();i!=(*instructions).end();++i){
        if(*i==-1){
             // Check if both max heap and min heap are not empty
            if(!max.empty()&&!min.empty()){
                // Median is the top element of max heap (larger half)
                if(max.size()==min.size()){
                    int median=max.top();
                    medians.push_back(median);
                    max.pop();// Remove median from max heap
                }
                else{
                    // If sizes are not equal, median is still from max heap, but don't remove it
                    medians.push_back(max.top());
                    max.pop();
                }

            }
        }
        else{
             // For non-median instructions, insert the element into the appropriate heap
            if(max.empty()||*i<=max.top()){
                max.push(*i);
            }
            else{
                min.push(*i);
            }
        }
        // Rebalance the heaps if necessary to maintain the invariant that max heap has more elements than min heap
        if(max.size()>min.size()+1){
            min.push(max.top());
            max.pop();
        }
        else if(max.size()<min.size()){
            max.push(min.top());
            min.pop();
        }
    }
    for(auto i=medians.begin();i!=medians.end();++i){
       std::cout<<*i<<" ";
    }
}