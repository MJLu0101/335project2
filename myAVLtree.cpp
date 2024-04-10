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
            if(!smallTree.isEmpty()){
                //if(smallcount>=largecount){
                    median=smallTree.findMax();
                    smallTree.remove(median);
                    std::cout<<median<<" ";
                    smallcount--;
                //}
            //     else {
            //         median=largeTree.findMin();
            //         largeTree.remove(median);
            //         std::cout<<median<<" ";
            //         largecount--;
            //     }
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
        // Rebalance the trees if necessary
        if(smallcount <largecount){
            int x=largeTree.findMin();
            largeTree.remove(x);
            smallTree.insert(x);
            smallcount++;
            largecount--;
        }
        else if(smallcount >=largecount+1){
            int x=smallTree.findMax();
            largeTree.insert(x);
            smallTree.remove(x);
            smallcount--;
            largecount++;
        }
    }
}