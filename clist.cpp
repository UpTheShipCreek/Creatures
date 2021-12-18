#include "clist.h"

template <typename T> 
cyList<T>::cyList(){
    Head = new Node<T>;
    Last = new Node<T>; 

    Head->Next = Last;
    Last->Next = Head;
};

template <typename T> 
cyList<T>::~cyList(){
    int i = 1;
    Node<T>* dnode = Head;
    Node<T>* temp = Head->Next;

    while(i <= size){
        delete dnode;
        dnode = temp;
        temp->Next;
        i++;
    }
}
template <typename T> 
void cyList<T>::addToEmpty(T data){
    Last->Data = data;
}

template <typename T> 
void cyList<T>::add(T data){
    if (Head == NULL){
        addToEmpty(data);
    }
    
    Node<T>* New = new Node<T>;
    Node<T>* temp = Last;
    New->Data = data;

    New->Next = Head;
    temp->Next = New;
    Last = New;
    size++;
}
template <typename T> 
Node<T>* cyList<T>::traverse(int position){
    Node<T>* temp = Head;
    
    for(int i = 1; i <= position; i++){
        temp = temp->Next;
    }
    return temp;       
}
template <typename T> 
T cyList<T>::get_data(Node<T>* Node){
    return Node->Data;
}

template <typename T> 
void cyList<T>::add_in_position(T data, int position){
    Node<T>* node = traverse(position);
    node->Data = data;
}
