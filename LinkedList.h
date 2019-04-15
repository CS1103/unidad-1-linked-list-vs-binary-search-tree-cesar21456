//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#define LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#include "Location.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
namespace UTEC {

    struct Node {
        Location data;
        Node* next;
        Node(Location data1):data(data1),next(nullptr){};
    };

    class LinkedList {
        Node* head;
        Node* tail;
    public:
        LinkedList();
        ~LinkedList();
        int size();
        bool is_empty();
        Node* get_head();
        Node* get_tail();
        void add_head(const Location data);
        void add_tail(const Location data);
        void print();
        void insert(int position, const Location data);
        Node* search(int position_id);
        void deletear_nodos(Node* a);
    };
    void load_locations2(LinkedList* linked_list, string file_name);

}

#endif //LINKEDLISTVSBINARYTREE_LINKEDLIST_H
