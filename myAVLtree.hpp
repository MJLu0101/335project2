#ifndef MYAVLTREE_HPP
#define MYAVLTREE_HPP

#include <algorithm>
#include <iostream> 
#include  <vector>
#include <chrono>
using namespace std;
    struct AvlNode
    {
        int element;
        AvlNode   *left;
        AvlNode   *right;
        int       height;

        AvlNode( const int & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
          : element{ ele }, left{ lt }, right{ rt }, height{ h } { }
        
        AvlNode( int && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
          : element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
    };
    int height(AvlNode *t);
    void insert( const int & x, AvlNode *&t);
    void balance(AvlNode *&t);
    void rotateWithLeftChild(AvlNode * & k2);
    void rotateWithRightChild(AvlNode * & k2);
    void remove(const int & x, AvlNode *& t);
    void doubleWithLeftChild(AvlNode * & k3);
    void doubleWithRightChild(AvlNode * & k1);
    AvlNode *findMax(AvlNode *t);
    AvlNode *findMin(AvlNode *t);
    
    void treeMedian(const std::vector<int>* instructions);

#endif