//
//  main.cpp
//  Project3
//
//  Created by hu on 2018/11/23.
//  Copyright © 2018 hu. All rights reserved.
//
#include <iostream>
#include "Message.h"
//constructor declarion
Node::Node(unsigned int id, std::string frag)
{
    //put id in identifier
    identifier = id;
    //store the string
    fragment = frag;
    //initialized
    delete [] p_next;
    p_next = nullptr;
}
//return the pointer to point the next node
Node *Node::get_next()
{
    //return the address of next node
    return this->p_next;
}
//return the string saving in this node
std::string Node::get_fragment()
{
    //return string
    return this->fragment;
}
//constructor to set the head as a null pointer
Message::Message()
{
    delete[] head;
    head = nullptr;
}
//destructor to set the node as a nullptr
Message::~Message()
{
    while (head!=nullptr)
    {
        //point the new node to the head
        Node *new_node = head;
        //point the head to the next
        head = head -> get_next();
        delete[] new_node;
        new_node = nullptr;
    }
    delete[] head;
}
void Message::insert( unsigned int id, std::string fragment)
{
    Node *temp_node = nullptr;
    Node *now_node = head;
    Node *new_node{new Node(id,fragment)};
    
    while(now_node != nullptr &&  now_node->identifier < new_node->identifier )
    {
        temp_node = now_node;
        now_node = now_node->p_next;
    }
    new_node->p_next = now_node;
    if(temp_node == nullptr)
    {
        head = new_node;
    }
    else
    {
        temp_node->p_next = new_node;
    }
}
void Message::print_message() {
    Node *temp_node = nullptr;
    Node *print = head;
    std::string fragment;
    std::size_t capacity = 0;
    if (head == nullptr) {
        std::cout << "???" << std::endl;
    }
    //else put the identifier of the last node as the capacity for sorting
    while (print != nullptr) {
        for (std::size_t k = 0; k < print->identifier; k++) {
            std::cout << "..." << std::endl;
        }
        if (print->p_next == nullptr) {
            if (print->fragment != "EOT") {
                std::cout << print->fragment << " " << "???" << std::endl;
            } else {
                std::cout << std::endl;
            }
        }
        std::cout << print->fragment << " ";
        temp_node = print;
        capacity = temp_node->identifier + 1;
        print = print->p_next;
    }
    std::cout<<std::endl;
}
#ifndef MARMOSET_TESTING
int main();
#endif
#ifndef MARMOSET_TESTING
int main() {
    //initialized
    int id;
    std::string fragment;
    std::cin >> id;
    
    Message *message_cout=new Message();
    
    while(id != -2)
    {
        if(id == -1)
        {
            message_cout->print_message();
        }
        else if(id >= 0)
        {
            std::cin >> fragment;
            message_cout->insert(id,fragment);
        }
        std::cin >> id;
    }
    return 0;
}
#endif


