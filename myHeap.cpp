#include "myHeap.hpp"
void heapMedian (const std::vector<int> * instructions){
    std::priority_queue<int>max;
    std::priority_queue<int, std::vector<int>, std::greater<int>>min;
    std::vector<int>medians;
    for(auto i=(*instructions).begin();i!=(*instructions).end();++i){
        if(*i==-1){
            if(!max.empty()&&!min.empty()){
                if(max.size()==min.size()){
                    int median=(max.top()+min.top())/2;
                    medians.push_back(median);
                    max.pop();
                }
                else{
                    medians.push_back(max.top());
                    max.pop();
                }

            }
        }
        else{
            if(max.empty()||*i<=max.top()){
                max.push(*i);
            }
            else{
                min.push(*i);
            }
        }
        //rebalance
        if(max.size()>min.size()+1){
            min.push(max.top());
            max.pop();
        }
        else if(max.size()<min.size()){
            max.push(min.top());
            min.pop();
        }
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<medians.size();
    std::cout<<std::endl;
    for(auto i=medians.begin();i!=medians.end();++i){
       std::cout<<*i<<" ";
    }
}