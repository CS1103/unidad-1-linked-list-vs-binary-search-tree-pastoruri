//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_BINARYTREE_H
#define LINKEDLISTVSBINARYTREE_BINARYTREE_H

#include "Location.h"


    struct BinarySearchTreeNode {
        Location data;
        BinarySearchTreeNode* right;
        BinarySearchTreeNode* left;
        explicit BinarySearchTreeNode(Location data): data{data}, right{nullptr}, left{nullptr} {}

    };

    class BinarySearchTree {
        BinarySearchTreeNode* root;
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(Location data);
        void clear(BinarySearchTreeNode* root);
        bool is_empty();
        BinarySearchTreeNode* get_root();
        BinarySearchTreeNode* search(std::string position_id);
        void print(BinarySearchTreeNode* ptr);
    };

void load_bst_locations(BinarySearchTree* bst, std::string file_name);



#endif //LINKEDLISTVSBINARYTREE_BINARYTREE_H
