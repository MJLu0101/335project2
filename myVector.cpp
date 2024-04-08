#include "myVector.hpp"
void vectorMedian (const std::vector<int> * instructions){
    std::vector<int> vec;
    std::vector<int> medianvec;
    for(int i=0;i<instructions->size();i++){
        if(((*instructions)[i])==-1){
            if(!vec.empty()){
                int medianIndex=vec.size()/2;
                if(vec.size()%2==1){
                    medianvec.push_back(vec[medianIndex]);
                    vec.erase(vec.begin()+medianIndex);
                }
                else{//if median is odd
                    medianvec.push_back(vec[medianIndex-1]);
                    vec.erase(vec.begin()+medianIndex-1);
                }
            }
        }
        else{
            auto lower=std::lower_bound(vec.begin(),vec.end(),(*instructions)[i]);
            //auto uper=std::upper_bound(vec.begin(),vec.end(),(*instructions)[i]);
            vec.insert(lower,(*instructions)[i]);
        }
    }
    // for(int i=0;i<vec.size();i++){
    //    std::cout<<vec[i]<<" ";
    // }
    std::cout<<std::endl;
     for(int i=0;i<medianvec.size();i++){
       std::cout<<medianvec[i]<<" ";
    }
}