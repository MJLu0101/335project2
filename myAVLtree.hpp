/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 2
The myAVLtree
hpp file
*/
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
    int height(AvlNode *t);// Function to calculate the height of a node
    void insert( const int & x, AvlNode *&t);// Function to insert a new element into the AVL tree
    void balance(AvlNode *&t);// Function to balance the AVL tree after insertion or removal
    void rotateWithLeftChild(AvlNode * & k2);// Rotation functions for balancing
    void rotateWithRightChild(AvlNode * & k2);
    void remove(const int & x, AvlNode *& t);// Function to remove an element from the AVL tree
    void doubleWithLeftChild(AvlNode * & k3);// Double rotation functions for balancing
    void doubleWithRightChild(AvlNode * & k1);
    AvlNode *findMax(AvlNode *t);// Function to find the maximum element in the AVL tree
    AvlNode *findMin(AvlNode *t);// Function to find the minimum element in the AVL tree
    
    void treeMedian(const std::vector<int>* instructions);// Function to calculate the median of elements in the AVL tree

#endif