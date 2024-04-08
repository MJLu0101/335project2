#include "myList.hpp"
void listMedian (const std::vector<int> * instructions){
    std::list<int>lst;
    std::list<int>medianlst;
    int medianIndex;
    for(auto i=(*instructions).begin();i!=(*instructions).end();++i){
        if(*i==-1){
            if(!lst.empty()){
                medianIndex=lst.size()/2;
                if(lst.size()%2==1){
                    auto it=lst.begin();
                    std::advance(it,medianIndex);
                    medianlst.push_back(*it);
                    lst.erase(it);
                }
                else{
                    auto it=lst.begin();
                    std::advance(it,medianIndex-1);
                    medianlst.push_back(*it);
                    lst.erase(it);
                }
            }
        }
        else{
            lst.sort();
            auto lower=std::lower_bound(lst.begin(),lst.end(),*i);
            lst.insert(lower,*i);
        }
    }
     for(auto i=medianlst.begin();i!=medianlst.end();++i){
       std::cout<<*i<<" ";
    }
 }
