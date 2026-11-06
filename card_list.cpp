// card_list.cpp
// Author: Albert Wang
// Implementation of the classes defined in card_list.h
#include "card_list.h"
#include <iostream>
using namespace std;

// gets successor in iterator
CardBST::Node* CardBST::Iterator::successor(Node* node) const {
    if (node == nullptr){
        return nullptr;
    }

    // get right most if it exists
    // to do this we go right and then left
    if (node->right != nullptr){
        node = node->right;

        while (node->left != nullptr){
            node = node->left;
        }
        return node;
    }
    //if there is no right subtree, we go upwards
    // do this by going left (parent) and then going right
    Node* parent = node->parent;
    while (parent != nullptr && node == parent->right){
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

// gets predecessor in iterator
CardBST::Node* CardBST::Iterator::predecessor(Node* node) const {
    if (node == nullptr){
        return nullptr;
    }

    // go down one and then go all the way left
    if (node->left != nullptr){
        node = node->left;

        while (node->right != nullptr){
            node = node->right;
        }
        return node;
    }
    Node* parent = node->parent;
    while (parent != nullptr && node == parent->left){
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

// increment iterator
CardBST::Iterator& CardBST::Iterator::operator++(){
    current = successor(current);
    return *this;
}

// reduce iterator
CardBST::Iterator& CardBST::Iterator::operator--(){
    current = predecessor(current);
    return *this;
}

bool CardBST::Iterator::operator==(const Iterator& rhs) const{
    return current == rhs.current;
}

bool CardBST::Iterator::operator!=(const Iterator& rhs) const{
    return current != rhs.current;
}

CardBST::Iterator CardBST::begin() const{
    Node* node = root;
    while (node != nullptr && node->left != nullptr){
        node = node->left;
    }

    return Iterator(node);
}
CardBST::Iterator CardBST::end() const{
    return nullptr;
}

CardBST::Iterator CardBST::rbegin() const{
    Node* node = root;
    while (node != nullptr && node->right != nullptr){
        node = node->right;
    }

    return Iterator(node);
}
CardBST::Iterator CardBST::rend() const{
    return nullptr; // since the end of it is nullptr
}

// get card something is pointing to
const Card& CardBST::Iterator::operator*() const {
    return current->card;
}

void CardBST::printInOrder() const{
    for (auto it = begin(); it != end(); ++it){
        cout << *it << endl;
    }
}