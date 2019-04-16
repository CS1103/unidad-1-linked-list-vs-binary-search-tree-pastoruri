//
// Created by ruben on 4/5/19.
//

#include <iostream>
#include <fstream>
#include "LinkedList.h"





LinkedList::~LinkedList() {
    if (!is_empty()) {
        for (int i = 0; i < size(); i++) {
            remove_tail();
        }
    }
}


int LinkedList::size() {
    int count = 0;
    Node* actual = this->head;
    while(actual != nullptr) {
        count++;
        actual = actual->next;
    }
    return count;
}


bool LinkedList::is_empty() {
    return this->head == nullptr;
}


Node* LinkedList::get_head() {
    return this->head;
}


Node* LinkedList::get_tail() {
    return this->tail;
}


void LinkedList::add_head(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        this->tail = temp;
        this->head = temp;
    } else {
        temp->next = head;
        this->head = temp;
    }
}


void LinkedList::add_tail(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        this->tail = temp;
        this->head = temp;
    } else {
        this->tail->next = temp;
        this->tail = temp;
    }
}


void LinkedList::print() {
    if (size() == 0) {
        std::cout << "No existen datos para imprimir" << std::endl;
    }
    Node* temp = this->head;
    for (int i = 0; i < size(); ++i) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }

}


void LinkedList::insert(int pos, const Location& data) {
    if (size() == 0) {
        this->add_tail(data);
        return;
    } else if (size() == 1) {
        if (pos == 0) {
            this->add_tail(data);
            return;
        } else if (pos == 1) {
            this->add_tail(data);
            return;
        }
    } else {
        if (pos == 0) {
            Node* newItem = nullptr;
            newItem = this->head;
            this->head = this->head->next;
            newItem->next = this->head;
            newItem->data = data;
            return;
        }
    }

    Node* temp = this->head;
    Node* newItem = new Node(data);
    Node* aux = this->head;

    for (int i = 0; i < pos; i++) {
        aux = aux->next;
    }

    for (int i = 0; i < pos-1; i++) {
        temp = temp->next;
    }

    temp->next = newItem;
    newItem->next = aux;
}


Node* LinkedList::search(std::string position_id) {
    Node* search_node = nullptr;
    return search_node;
}


void LinkedList::remove_tail() {
    if (is_empty()) {
        std::cout << "No se pueden remover elementos de una lista vacia" << std::endl;
    } else {
        delete this->tail;
        Node* temp = this->head;
        while (temp->next != this->tail) {
            temp = temp->next;
        }
        this->tail = temp;
        this->tail->next = nullptr;
    }
}


void load_ll_locations(LinkedList* ll, std::string filename) {
    std::ifstream locations;
    locations.open(filename);
    std::string locationString;

    if (locations.is_open()) {
        std::string posid, statecode, county, latitude, longitude, line, construction;
        while(locations.good()){
            getline(locations,posid,',');
            getline(locations,statecode,',');
            getline(locations,county,',');
            getline(locations,latitude,',');
            getline(locations,longitude,',');
            getline(locations,line,',');
            getline(locations,construction,'\n');
            ll->add_tail(Location(posid,statecode,county,stod(latitude),stod(longitude),line,construction));
        }
        locations.close();
    } else {
        std::cout << "No se pudo abrir el archivo: " << filename << std::endl;
    }
}
































































