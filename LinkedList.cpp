//
// Created by ruben on 4/5/19.
//

#include "LinkedList.h"

void UTEC::LinkedList::deletear_nodos(Node* a){
    Node* b=a;
    a=b->next;
    delete b;


}

UTEC::LinkedList::LinkedList() {
    head=nullptr;
    tail=nullptr;
}

UTEC::LinkedList::~LinkedList() {
    deletear_nodos(get_head());
    delete tail;
}

int UTEC::LinkedList::size() {
    int count = 0;
    Node* actual = head;
    while(actual != nullptr) {
        count++;
        actual = actual->next;
    }
    return count;
}

bool UTEC::LinkedList::is_empty() {
    return head == nullptr;
}

UTEC::Node *UTEC::LinkedList::get_head() {
    return head;
}

UTEC::Node *UTEC::LinkedList::get_tail() {
    return tail;
}

void UTEC::LinkedList::add_head(const Location data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void UTEC::LinkedList::add_tail(const Location data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }

}

void UTEC::LinkedList::print(){
    Node *a=get_head();
    while (a!=tail){
        cout<<a->data.get_id()<<endl;
        a=a->next;
    }
    cout<<a->data.get_id()<<endl;
}

void UTEC::LinkedList::insert(int position, const Location data){
    Node* a=new Node(data);
    Node* b=head;
    for (int i=0;i<position;i++){
        b=b->next;
    }
    a->next=b->next;
    b->next=a;
}

UTEC::Node* UTEC::LinkedList::search(int position_id){
    Node* a=head;
    while (a->data.get_id()!=position_id){
        if (a->next==nullptr){
            return nullptr;
        }
        a=a->next;
    }
    return a;
}

void UTEC::load_locations2(LinkedList* linked_list,string file_name){
    ifstream abrir(file_name);
    string frase,palabra;
    getline(abrir,frase);
    int position_id;
    string state_code;
    string county;
    double latitude;
    double longitude;
    string line;
    string construction;
    for (int i=0;i<36635;i++){
        getline(abrir,palabra,',');
        istringstream(palabra) >> position_id;
        getline(abrir,palabra,',');
        state_code=palabra;
        getline(abrir,palabra,',');
        county=palabra;
        getline(abrir,palabra,',');
        istringstream(palabra) >> latitude;
        getline(abrir,palabra,',');
        istringstream(palabra) >> longitude;
        getline(abrir,palabra,',');
        line=palabra;
        getline(abrir,palabra,'\n');
        construction=palabra;
        Location a(position_id,state_code,county,latitude,longitude,line,construction);
        linked_list->add_tail(a);
    }
}
