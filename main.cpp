#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <string>
#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include "myAVLtree.hpp"

int main(){
    std::string inputfile, line;
    std::vector<int> *x=new std::vector<int>;
    std::cout<<"input file name: "<<std::endl;
    std::cin>>inputfile;
    std::ifstream File(inputfile);
    if(!File.is_open()){
        std::cerr<<"Failed to input file"<<std::endl;
        return 1;
    }
    std::string op;
    int value;
    while(getline(File,line)){
        std::stringstream ss(line);
        ss>>op;
        //std::cout<<op;
        if(op=="insert"){
            ss>>value;
            x->push_back(value);
            //std::cout<< x.back()<<std::endl;
        }
        else if(op=="pop"){
            x->push_back(-1);
            //std::cout<< x.back()<<std::endl;
        }
        
    }
    // for(int i=0;i<x.size();i++){
    //    std::cout<<x[i]<<" ";
    // }
    //vectorMedian(x);
    //listMedian(x);
    //heapMedian(x);
    treeMedian(x);
    return 0;
}
