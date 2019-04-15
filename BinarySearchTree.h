//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_BINARYTREE_H
#define LINKEDLISTVSBINARYTREE_BINARYTREE_H
#include "Location.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

namespace UTEC {

    struct Node2 {
        Location data;
        Node2* right;
        Node2* left;
        Node2(Location data1):data(data1),right(nullptr),left(nullptr){};
    };

    class BinarySearchTree {
        Node2* root;
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(Location data);
        void clear();
        bool is_empty();
        Node2* get_root();
        Node2* search(int position_id);
        void print(Node2* b);
        void deletear_nodos(Node2* a);
    };

    void load_locations(BinarySearchTree* linked_list, std::string file_name);
    void print_node(Node2* node);
}

#endif //LINKEDLISTVSBINARYTREE_BINARYTREE_H
