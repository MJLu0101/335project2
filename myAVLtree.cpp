#include "myAVLtree.hpp"
#include <iostream>
#include <vector>
int height(AvlNode *t){
    return t==nullptr?-1:t->height; //getheight
}
void insert( const int & x, AvlNode *&t){
    if(t==nullptr ){
    t=new AvlNode{x,nullptr, nullptr}; 
    }
 else if( x <= t->element ){//modified to handle dupilcates
 insert( x, t->left );  //insert left for smaller element 
 }
 else if( t->element < x ){
 insert( x, t->right );//insert right forbiger element 
 balance( t );
 }
}
static const int ALLOWED_IMBALANCE = 1;
void balance(AvlNode *&t) {
    if (t == nullptr) {
        return;
    }
    if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE) {
        if (height(t->left->left) >= height(t->left->right)) { //rebalance
            rotateWithLeftChild(t);
        } else {
            doubleWithLeftChild(t);
        }
    } else {
        if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE) {
            if (height(t->right->right) >= height(t->right->left)) {
                rotateWithRightChild(t);
            } else {                        //rebalance
                doubleWithRightChild(t);
            }
        }
    }
    t->height = std::max(height(t->left), height(t->right)) + 1;
}
void rotateWithLeftChild(AvlNode * & k2) {
    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;                 //rotation
    k2->height = std::max(height(k2->left), height(k2->right)) + 1;
    k1->height = std::max(height(k1->left), k2->height) + 1;
    k2 = k1;
}
void rotateWithRightChild(AvlNode * & k2){
    AvlNode *k1 = k2->right;    //rotation
    k2->right = k1->left;
    k1->left = k2;
    k2->height = std::max(height(k2->left), height(k2->right)) + 1;
    k1->height = std::max(height(k1->right), k2->height) + 1;
    k2 = k1;
}
void remove(const int & x, AvlNode *& t) {
    if (t == nullptr){
        return; // Item not found; do nothing
    }
    if (x < t->element){ //remove from left when smaller
        remove(x, t->left);
    }
    else if (t->element < x){
        remove(x, t->right);    //remove from right when smaller
    }
    else if (t->left != nullptr && t->right != nullptr) // Two children
    {
        t->element = findMin(t->right)->element; //find the smallest element in right and remove it 
        remove(t->element, t->right);
    }
    else 
    {
        AvlNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
        oldNode=nullptr; //modified to avoid dangling pointer
    }
}
void doubleWithLeftChild(AvlNode * & k3) 
{ 
    rotateWithRightChild(k3->left); //for balancing
    rotateWithLeftChild(k3); 
}
void doubleWithRightChild(AvlNode * & k1) 
{ 
    rotateWithLeftChild(k1->right); //for balancing
    rotateWithRightChild(k1); 
}
AvlNode *findMax(AvlNode *t) {
    if (t != nullptr) {
        while (t->right != nullptr) { 
            t = t->right;//find the max element
        }
    }
    return t;
}
AvlNode *findMin(AvlNode *t){
if( t == nullptr ){ 
    return nullptr;
}
 if( t->left == nullptr ){
    return t;           
 }
return findMin( t->left );//find the mix element
}
void treeMedian (const std::vector<int> * instructions){
    AvlNode *smallTree =nullptr;//max is median
    AvlNode *largeTree=nullptr;
    int smallcount=0;
    int largecount=0;
     std::vector<int>medians;
    for(auto i=(*instructions).begin();i!=(*instructions).end();++i){
        //cout<<*i<<std::endl;
        if (*i == -1) {
            if(smallTree!=nullptr){
                int median = findMax(smallTree)->element;
                medians.push_back(median);
                remove(median,smallTree);
                smallcount --;
                if (largecount > smallcount) {
                    auto x = findMin(largeTree)->element;
                    insert(x,smallTree);
                    remove(x,largeTree);
                    largecount --;
                    smallcount ++;
                }
            }
        } 
        else{
            if (smallTree==nullptr||*i<=findMax(smallTree)->element) {
                insert(*i,smallTree);
                smallcount ++;
                if (smallcount > largecount + 1) {
                    auto x = findMax(smallTree)->element;
                    remove(x,smallTree);
                    insert(x,largeTree);
                    smallcount --;
                    largecount ++;
                }
            } 
            else {//if (*i > findMax(smallTree)->element) 
                insert(*i,largeTree);
                largecount++;
                 if (largecount > smallcount) {
                    auto x = findMin(largeTree)->element;
                    insert(x,smallTree);
                    remove(x,largeTree);
                    largecount --;
                    smallcount ++;
                }
            }
        }
    }
    for(auto i=medians.begin();i!=medians.end();++i){
       std::cout<<*i<<" ";
    }
}