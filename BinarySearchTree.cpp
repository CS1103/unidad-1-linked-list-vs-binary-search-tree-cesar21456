#include "BinarySearchTree.h"
#include "location.h"
using namespace std;
UTEC::BinarySearchTree::BinarySearchTree():root(nullptr){};
void UTEC::BinarySearchTree::deletear_nodos(Node2* a) {
    if (a != nullptr) {
        if (a->left != nullptr) {
            deletear_nodos(a->left);
        }
        if (a->right != nullptr) {
            deletear_nodos(a->right);
        }
        delete a;
    }
}

UTEC::BinarySearchTree::~BinarySearchTree(){
    deletear_nodos(root);


};
void UTEC::BinarySearchTree::insert(Location data){
    bool i=true;
    if (root==nullptr){
        root=new Node2(data);
        return;
    }
     Node2* b=root;
    while (i==true){
        if (data.get_id()>=b->data.get_id()){
            if (b->right==nullptr){
                Node2* a=new Node2(data);
                b->right=a;
                i=false;
            }else{
                b=b->right;
            }
        }else{
            if (b->left==nullptr){
                Node2* a=new Node2(data);
                b->left=a;
                i=false;
            }else{
                b=b->left;
            }
        }
    }
};
void UTEC::BinarySearchTree::clear(){}
bool UTEC::BinarySearchTree::is_empty(){
    if (root==nullptr){
    return true;
    }else{
        return false;
    }
}
UTEC::Node2* UTEC::BinarySearchTree::get_root(){
    return root;
};
UTEC::Node2* UTEC::BinarySearchTree::search(int position_id){
    bool i=true;
    if (root==nullptr){
        cout<<"no esta en este arbol binario"<<endl;
        return nullptr;
    }
    Node2* b=root;


    while (i==true){

        if (position_id>b->data.get_id()){

            if (b->right==nullptr){
                cout<<"no esta en este arbol binario"<<endl;
                i=false;
            }else{
                b=b->right;
            }
        }else{
            if (position_id<b->data.get_id()){
                if (b->left==nullptr){
                    cout<<"no esta en este arbol binario"<<endl;
                    i=false;
                }else{
                    b=b->left;
                }
            }else{
                return b;

            }
        }
    }
    cout<<"no lo encontro"<<endl;
    return nullptr;
}
void UTEC::BinarySearchTree::print(Node2* b){
    if (b->left!=nullptr){
        Node2* a=b->left;
        cout<<a->data.get_id()<<endl;
        UTEC::BinarySearchTree::print(a);
    }
    if (b->right!=nullptr){
        Node2* c=b->right;
        cout<<c->data.get_id()<<endl;
        UTEC::BinarySearchTree::print(c);
    }else{
        cout<<root->data.get_id()<<endl;
    }


}

void UTEC::load_locations(BinarySearchTree* linked_list, std::string file_name){
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
        linked_list->insert(a);
    }

}

void UTEC::print_node(Node2* node){
    cout<<node->data.get_all()<<endl;
}
