//
//  main.cpp
//  Project3
//
//  Created by hu on 2018/11/23.
//  Copyright © 2018 hu. All rights reserved.
//
#include <iostream>
#include "Message.h"
//constructor declartion
Node::Node(unsigned int id, std::string frag)
{
    //put id in identifier
    identifier = id;
    //store the string
    fragment = frag;
    //initialized
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
    delete head;
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
        head = head -> p_next;
        delete[] new_node;
        new_node = nullptr;
    }
    delete[] head;
}
void Message::insert( unsigned int id, std::string fragment)
{
   if(head == nullptr)
   {
       Node *new_node{new Node(id,fragment)};
       new_node -> p_next = head;
       head = new_node;
   }
    //when head != nullptr
    else
    {
        Node *new1_node{new Node(id,fragment)};
        new1_node -> p_next = head;
        head = new1_node;
    }
}
void Message::print_message()
{
    //capacity initialized
    std::size_t capacity = 0;
    Node *print = head;
    //if head is no input any id or fragment , print out "???"
    if(head == nullptr)
    {
        std::cout << "???" << std::endl;
    }
    //else put the identifier of the last node as the capacity for sorting
    else
    {
        capacity = head->identifier;
    }
    while(print!=nullptr)
    {
        //select the max identifier as the capacity of these node
        if(capacity < print->identifier)
        {
            capacity = print->identifier;
        }
        //list loop
        print = print->p_next;
    }
    //create an pointer array for storing pointers of all nodes in the list
    Node **create_array = new Node *[capacity+1]{nullptr};
    print = head;
    do{
        //put the original address of each node into the new pointer-array so that we can sort it
        create_array[print->identifier] = print;
        print = print->p_next;
    }while(print == nullptr);
    for(std::size_t k = 0; k<capacity+1;k++)
    {
        if(create_array[k]==nullptr)
        {
            std::cout << "..." <<"\t";
        }
        else
        {
            do{
                std::cout <<create_array[k]-> fragment<<"\t";
            }while(create_array[k]-> fragment != "EOT");
        }
        std::cout << std::endl;
    }
    delete[] create_array;
}

int main() {
    //initialized
    int num = -4;
    std::string fragment;
    Message message_cout;
    do{
        std::cout << "Enter the order : ";
        std::cin >> num;
        if(num==-1)
        {
            message_cout.print_message();
            std::cout<<std::endl;
        }
        else if(num>=0)
        {
            std::cout << "Enter the " << num <<"'s fragment : ";
            std::cin >> fragment;
            message_cout.insert(num,fragment);
        }
    }while(num==-2);
    
    return 0;
}
