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
                    std::cout<<median<<" ";
                    smallTree.remove(median);
                    smallcount--;
                    if(smallcount <largecount){
                        int x=largeTree.findMin();
                        largeTree.remove(x);
                        smallTree.insert(x);
                        smallcount++;
                        largecount--;
                    }
                }
                //  else {
                //      median=largeTree.findMin();
                //      largeTree.remove(median);
                //      std::cout<<median<<" ";
                //     largecount--;
                // }
            //}
        }
        else{
            if(smallTree.isEmpty()||*i<=smallTree.findMax()){
                smallTree.insert(*i);
                smallcount++;
                if(smallcount >largecount+1){
                    int x=smallTree.findMax();
                    largeTree.insert(x);
                    smallTree.remove(x);
                    smallcount--;
                    largecount++;
                }

            }
            else{
                largeTree.insert(*i);
                largecount+=1;
                 if(smallcount <largecount){
                    int x=largeTree.findMin();
                    largeTree.remove(x);
                    smallTree.insert(x);
                    smallcount++;
                    largecount--;
                }
            }
        }
        // Rebalance the trees if necessary
        // if(smallcount <largecount){
        //     int x=largeTree.findMin();
        //     largeTree.remove(x);
        //     smallTree.insert(x);
        //     smallcount+=1;
        //     largecount-=1;
        // }
        // else if(smallcount >largecount+1){
        //     int x=smallTree.findMax();
        //     largeTree.insert(x);
        //     smallTree.remove(x);
        //     smallcount-=1;
        //     largecount+1;
        // }
    }
//         if (!smallTree.isEmpty() && *i == -1) {
//             median = smallTree.findMax();
//             std::cout << median << " ";
//             smallTree.remove(median);
//             smallcount -= 1;
//             if (largecount > smallcount) {
//                 auto x = largeTree.findMin();
//                 smallTree.insert(x);
//                 largeTree.remove(x);
//                 largecount -= 1;
//                 smallcount += 1;
//             }
//         } else if (smallTree.isEmpty() && *i != -1) {
//             smallTree.insert(*i);
//             smallcount += 1;
//         } else {
//             if (*i > smallTree.findMax()) {
//                 largeTree.insert(*i);
//                 if (largecount > smallcount) {
//                     auto x = largeTree.findMin();
//                     smallTree.insert(x);
//                     largeTree.remove(x);
//                     largecount -= 1;
//                     smallcount += 1;
//                 }
//             } else if (*i <= smallTree.findMax()) {
//                 smallTree.insert(*i);
//                 smallcount++;
//                 if (smallcount > largecount + 1) {
//                     auto x = smallTree.findMax();
//                     smallTree.remove(x);
//                     largeTree.insert(x);
//                     smallcount -= 1;
//                     largecount += 1;
//                 }
//             }
//         }
//     }
}