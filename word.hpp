//
//  word.hpp
//  originalstructure
//
//  Created by Amir Jabbari on 9/12/16.
//  Copyright © 2016 Amir Jabbari. All rights reserved.
//

#ifndef word_hpp
#define word_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class word {
    
public:
    word(string wordItself = "", string headlineDate = "", int wordCount = 0, double wordWeight = 0, double percentStockChange = 0);
    word& operator=(word);
    string wordItself;
    string headlineDate;
    int wordCount;
    double wordWeight;
    double percentStockChange; //percent change based on headline data
    
    friend istream& operator>>(istream&,word&);
    friend ostream& operator<<(ostream&,word&);
    
    
};
class BTreeNode
{
public:
    int *keys; // An array of keys
    int t;	 // Minimum degree (defines the range for number of keys)
    BTreeNode **C; // An array of child pointers
    int n;	 // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false

    BTreeNode(int _t, bool _leaf); // Constructor
    
    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    void insertNonFull(int k);
    
    // A utility function to split the child y of this node. i is index of y in
    // child array C[]. The Child y must be full when this function is called
    void splitChild(int i, BTreeNode *y);
    
    // A function to traverse all nodes in a subtree rooted with this node
    void traverse();
    
    // A function to search a key in subtree rooted with this node.
    BTreeNode *search(int k); // returns NULL if k is not present.
    
    // Make BTree friend of this so that we can access private members of this
    // class in BTree functions
    friend class BTree;
};

// A BTree
class BTree
{
public:
    BTreeNode *root; // Pointer to root node
    int t; // Minimum degree

    // Constructor (Initializes tree as empty)
    BTree(int _t)
    { root = NULL; t = _t; }
    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    void insertNonFull(int k);
    
    // A utility function to split the child y of this node. i is index of y in
    // child array C[]. The Child y must be full when this function is called
    void splitChild(int i, BTreeNode *y);
    
    // function to traverse the tree
    void traverse()
    { if (root != NULL) root->traverse(); }
    
    // function to search a key in this tree
    BTreeNode* search(int k)
    { return (root == NULL)? NULL : root->search(k); }
    
    // The main function that inserts a new key in this B-Tree
    void insert(int k);
};



#endif /* word_hpp */
