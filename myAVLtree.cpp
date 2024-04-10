#include "myAVLtree.hpp"
#include <iostream>
#include <vector>
void treeMedian (const std::vector<int> * instructions){
    AvlTree smallTree;
    AvlTree largeTree;
    int smallcount=0;
    int largecount=0;
    int median;
    for(auto i=(*instructions).begin();i!=(*instructions).end();++i){
        if(*i==-1){
            if(!smallTree.isEmpty()&&!largeTree.isEmpty()){
                if(smallcount>=largecount){
                    median=smallTree.findMax();
                    smallTree.remove(median);
                    cout<<median<<" ";
                }
                else if(smallcount<largecount){
                    median=largeTree.findMin();
                    largeTree.remove(median);
                    cout<<median<<" ";
                }
            }

        }
        else{
            if(smallTree.isEmpty()||*i<=smallTree.findMax()){
                smallTree.insert(*i);
                smallcount++;
            }
            else{
                largeTree.insert(*i);
                largecount++;
            }
        }
    }
}