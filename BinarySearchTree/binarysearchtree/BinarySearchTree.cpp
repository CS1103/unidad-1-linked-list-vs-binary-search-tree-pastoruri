//
// Created by ruben on 4/5/19.
//

#include "BinarySearchTree.h"
#include <fstream>
#include <string>
#include <iostream>


BinarySearchTree::BinarySearchTree(){this->root= nullptr;}


BinarySearchTree::~BinarySearchTree(){
    clear(this->root);
}


void BinarySearchTree::insert(Location data) {
    BinarySearchTreeNode* nodo = new BinarySearchTreeNode(data);

    if (this->root == nullptr) {
        this->root = nodo;
    }
    else if (this->root != nullptr) {
        for (BinarySearchTreeNode* temp = this->root; temp != nullptr;) {
            if (temp->data.get_position_id() > nodo->data.get_position_id()) {
                if (temp->left == nullptr) {
                    temp->left = nodo;
                    break;
                } else {
                    temp = temp->left;
                }
            } else if (temp->data.get_position_id() < nodo->data.get_position_id()) {
                if (temp->right == nullptr) {
                    temp->right = nodo;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
    }

}


void BinarySearchTree::clear(BinarySearchTreeNode* root) {
    if (root != nullptr) {
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
}


BinarySearchTreeNode* BinarySearchTree::get_root() {
    return this->root;
}


BinarySearchTreeNode* BinarySearchTree::search(std::string position_id) {
    for (BinarySearchTreeNode* temp = root; temp != nullptr;) {
        if (temp->data.get_position_id() == position_id)
            return temp;
        else if (temp->data.get_position_id() > position_id)
            temp = temp->left;
        else if (temp->data.get_position_id() < position_id)
            temp = temp->right;
    }
}


bool BinarySearchTree::is_empty() {
    return (this->root == nullptr);
}



void BinarySearchTree::print(BinarySearchTreeNode* raiz) {
    if (raiz) {
        print(raiz->left);
        std::cout << raiz->data <<std::endl;
        print(raiz->right);
    }
//NOTA AL LECTOR este codigo fue el que originalmente trate de implementar
// pero no alcance a terminar, al final mis companeros me recomendaron usar la funcion recursiva que se puede ver arriba
//    BinarySearchTree* BTSP = this;
// cout<<BTSP->root->data;
//        BinarySearchTreeNode* aux=(BTSP->root);
//        BinarySearchTreeNode* prevaux;
//        while(!(BTSP->is_empty())){
//        while((aux->left)!= nullptr){
//            prevaux->right=aux;
//            aux=aux->left;
//        }
//        if((aux->left)== nullptr && (aux->right)!= nullptr){
//            prevaux->right=aux;
//            aux=(aux->right);
//        }
//        else if (aux->left== nullptr && aux->right== nullptr){
//            cout<<(prevaux->right->data);
//           delete prevaux->right;
//           BinarySearchTreeNode* aux=(BTSP->root);
//
//        }
//    }


}


void load_bst_locations(BinarySearchTree* bst, std::string filename) {
    std::ifstream locations;
    locations.open(filename);

    std::string pos, state, county, latitude, longitude, line ,construction;
    if (locations.is_open()) {

        while (locations.good()) {

            getline(locations, pos, ',');
            getline(locations, state, ',');
            getline(locations, county, ',');
            getline(locations, latitude, ',');
            getline(locations, longitude, ',');
            getline(locations, line, ',');
            getline(locations, construction, '\n');



            bst->insert(Location(pos, state, county, stod(latitude), stod(longitude), line, construction));
        }
        locations.close();
    } else {
        std::cout << "El archivo no se ha podido abrir: " << filename << std::endl;
    }
}