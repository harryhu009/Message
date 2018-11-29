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
    //let the p_next is nullptr so that the last one is to nullptr
    Node *p_next = nullptr;
}
//return the pointer to point the next node
Node *Node::get_next()
{
    //return the address of next node
    return p_next;
}
//return the string saving in this node
std::string Node::get_fragment()
{
    //return string
    return fragment;
}
//constructor to set the head as a null pointer
Message::Message()
{
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
        delete new_node;
    }
    delete head;
}
void Message::insert( unsigned int id, std::string fragment)
{
    //create three pointer so that we can create the list as the order by sorting
    //temp node for save the previous node and connect the next node
    Node *temp_node{nullptr};
    //head node for store and immediate
    Node *now_node{head};
    //new node for saving new number
    Node *new_node{new Node(id,fragment)};
    //when the now_node is not empty, which means that some data in "head", we start to sorting these data
    //if the new one is bigger than the now one:
    while(now_node!=nullptr && new_node->identifier > now_node->identifier)
    {
        temp_node = now_node;
        //equal to nullptr
        now_node = now_node->p_next;
    }
    //equal to (now_node = )nullptr to stop
    new_node->p_next = now_node;
    if(temp_node == nullptr)
    {
        //when temp_node is nullptr, means that this is the first fragment that users cin
        //let the head connect the new_node
        head = new_node;
    }
    else
    {
        //when temp_node is not nullptr, means that there exits some fragment so that we can put the new one the compare
        temp_node->p_next = new_node;
    }
}
void Message::print_message()
{
    //draw the head so that we can read the all list
    Node *print_node = head;
    Node *temp = nullptr;
    int num = 0;
    if(head == nullptr)
    {
        std::cout << "???";
    }
    while(print_node!= nullptr){
        //when print_node != nullptr, means we have something in list
        for(std::size_t k = num; k< print_node->identifier;k++)
        {
            std::cout << "..."<<" ";
        }
        while(print_node->p_next == nullptr)
        {
            //print_node->p_next == nullptr means the next one is null
            //if user has type the "EOT"
            if(print_node->fragment == "EOT")
            {
                std::cout<<std::endl;
            }
            else
            {
                //print_node -> fragment != "EOT"
                std::cout << print_node->fragment<<" "<<"???"<<std::endl;
            }
        }
        std::cout<<print_node->fragment<<" ";
        //list traversal
        //let temp to store the print_node
        temp = print_node;
        //if print_node != nullptr, means the former pointer has something, we shoud narrow the "..." print
        num = temp->identifier + 1;
        print_node = print_node->p_next;
        
    }
    std::cout<<std::endl;
}
#ifndef MARMOSET_TESTING
int main();
#endif
#ifndef MARMOSET_TESTING
int main() {
    //initialized
    int id = -3;
    std::string fragment;
    std::cin >> id;
    
    Message *message_cout = new Message();
    //when id is not equal to negative two
    while(id != -2)
    {
        //when -1, print out all the former string
        if(id == -1)
        {
            message_cout->print_message();
        }
        //cin all ids and fragments from user
        else if(id >= 0)
        {
            std::cin >> fragment;
            message_cout->insert(id,fragment);
        }
        std::cin >> id;
    }
    //delete the used ptr(heap clear)
    delete message_cout;
    return 0;
}
#endif



