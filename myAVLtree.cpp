/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 2
The myAVLtree
cpp file
*/
#include "myAVLtree.hpp"

// Function to calculate the height of a node
int height(AvlNode *t) {
    return t == nullptr ? -1 : t->height;
}

// Function to insert a new element into the AVL tree
void insert(const int &x, AvlNode *&t) {
    if (t == nullptr) {
        t = new AvlNode{x, nullptr, nullptr}; // Create a new node if the tree is empty
    } else if (x <= t->element) {
        insert(x, t->left); // Insert to the left subtree for smaller elements
    } else if (t->element < x) {
        insert(x, t->right); // Insert to the right subtree for larger elements
        balance(t); // Balance the tree after insertion
    }
}

// Static constant for allowed imbalance in the AVL tree
static const int ALLOWED_IMBALANCE = 1;

// Function to balance the AVL tree after insertion or removal
void balance(AvlNode *&t) {
    if (t == nullptr) {
        return;
    }
    // Left subtree is higher
    if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE) {
        if (height(t->left->left) >= height(t->left->right)) {
            rotateWithLeftChild(t); // Perform rotation with left child
        } else {
            doubleWithLeftChild(t); // Perform double rotation with left child
        }
    } else {
        // Right subtree is higher
        if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE) {
            if (height(t->right->right) >= height(t->right->left)) {
                rotateWithRightChild(t); // Perform rotation with right child
            } else {
                doubleWithRightChild(t); // Perform double rotation with right child
            }
        }
    }
    t->height = std::max(height(t->left), height(t->right)) + 1; // Update node height
}

// Rotation functions for balancing
void rotateWithLeftChild(AvlNode *&k2) {
    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = std::max(height(k2->left), height(k2->right)) + 1;
    k1->height = std::max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

void rotateWithRightChild(AvlNode *&k2) {
    AvlNode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = std::max(height(k2->left), height(k2->right)) + 1;
    k1->height = std::max(height(k1->right), k2->height) + 1;
    k2 = k1;
}

// Function to remove an element from the AVL tree
void remove(const int &x, AvlNode *&t) {
    if (t == nullptr) {
        return; // Item not found; do nothing
    }
    if (x < t->element) {
        remove(x, t->left); // Remove from the left subtree
    } else if (t->element < x) {
        remove(x, t->right); // Remove from the right subtree
    } else if (t->left != nullptr && t->right != nullptr) { // Two children
        t->element = findMin(t->right)->element; // Replace with the smallest element in the right subtree
        remove(t->element, t->right); // Remove the replaced element from the right subtree
    } else {
        AvlNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
        oldNode = nullptr; // Avoid dangling pointer
    }
}

// Double rotation functions for balancing
void doubleWithLeftChild(AvlNode *&k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void doubleWithRightChild(AvlNode *&k1) {
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

// Function to find the maximum element in the AVL tree
AvlNode *findMax(AvlNode *t) {
    if (t != nullptr) {
        while (t->right != nullptr) {
            t = t->right;
        }
    }
    return t;
}

// Function to find the minimum element in the AVL tree
AvlNode *findMin(AvlNode *t) {
    if (t == nullptr) {
        return nullptr;
    }
    if (t->left == nullptr) {
        return t;
    }
    return findMin(t->left);
}

// Function to calculate the median of elements in the AVL tree
void treeMedian(const std::vector<int> *instructions) {
    // Initialize two AVL trees: one for elements less than the current median (smallTree),
    // and one for elements greater than the current median (largeTree).
    AvlNode *smallTree = nullptr;
    AvlNode *largeTree = nullptr;

    // Initialize counters for the number of elements in each tree.
    int smallcount = 0;
    int largecount = 0;

    // Vector to store the medians calculated during the process.
    std::vector<int> medians;

    //time: beging:
   // auto start = std::chrono::high_resolution_clock::now();
    // Iterate through the instructions vector.
    for (auto i = (*instructions).begin(); i != (*instructions).end(); ++i) {
        // If the instruction is -1, it indicates a request to calculate and remove the median.
        if (*i == -1&&smallTree != nullptr) {
            // Check if the smallTree is not empty.
                // Calculate the median as the maximum element in the smallTree.
                int median = findMax(smallTree)->element;

                // Store the median in the medians vector.
                medians.push_back(median);

                // Remove the median from the smallTree.
                remove(median, smallTree);

                // Update the count of elements in the smallTree.
                smallcount--;

                // Rebalance the trees if needed.
                if (largecount > smallcount) {
                    // Move the minimum element from the largeTree to the smallTree.
                    auto x = findMin(largeTree)->element;
                    insert(x, smallTree);
                    remove(x, largeTree);
                    largecount--;
                    smallcount++;
                }
        } 
        else {
            // For non-median instructions, insert the element into the appropriate tree.
            if (smallTree == nullptr || *i <= findMax(smallTree)->element) {
                // Insert into the smallTree if it's empty or the element is less than or equal to its maximum.
                insert(*i, smallTree);
                smallcount++;

                // Rebalance the trees if needed.
                if (smallcount > largecount + 1) {
                    // Move the maximum element from the smallTree to the largeTree.
                    auto x = findMax(smallTree)->element;
                    remove(x, smallTree);
                    insert(x, largeTree);
                    smallcount--;
                    largecount++;
                }
            } else {
                // Insert into the largeTree if the element is greater than the maximum in the smallTree.
                insert(*i, largeTree);
                largecount++;

                // Rebalance the trees if needed.
                if (largecount > smallcount) {
                    // Move the minimum element from the largeTree to the smallTree.
                    auto x = findMin(largeTree)->element;
                    insert(x, smallTree);
                    remove(x, largeTree);
                    largecount--;
                    smallcount++;
                }
            }
        }
    }
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double, std::micro> elapsed = end - start;
    // std::cout << "Execution time for treeMedian: " << elapsed.count() << " microseconds\n";

    // Output the calculated medians.
    for (auto i = medians.begin(); i != medians.end(); ++i) {
        std::cout << *i << " ";
    }
}

