// card_list.h
// Binary search tree used to store a player's hand of cards

#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h" 

using namespace std;

class CardBST {
    private:
        struct Node { // node struct
            Card card;
            Node* left;
            Node* right;
            Node* parent;

            Node(const Card& c, Node* p = nullptr){
                card = c;
                left = nullptr;
                right = nullptr;
                parent = p;
        }

        Node* root = nullptr;

    };
    public:
        CardBST();
        ~CardBST();
        bool insert(const Card& card);
        bool remove(const Card& card);
        bool contains(const Card& card) const;
        void printInOrder() const;

        class Iterator {
            private:
                Node * current;
                Node* successor(Node* node) const;
                Node* predecessor(Node* node) const;

            public:
                Iterator(Node* node){
                    current = node;
                }
                
                const Card& operator*() const; // overload dereferncing function
                Iterator& operator++();
                Iterator& operator--();
                bool operator==(const Iterator& rhs) const;
                bool operator!=(const Iterator& rhs) const;
        };

        Iterator begin() const;
        Iterator end() const;
        Iterator rbegin() const;
        Iterator rend() const;
        
};
#endif
