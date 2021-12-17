#include "clist.h"

template <typename T> 
cyList<T>::cyList(){
    Head = new Node<T>;
    Last = new Node<T>; 

    Head->Next = Last;
    Last->Next = Head;
};

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
    Node<T>* temp = Head->Next;
    
    for(int i = 1; i <= position; i++){
        temp = temp->Next;
    }
    return temp;       
}

template <typename T> 
void cyList<T>::add_in_position(T data, int position){
    Node<T>* node = traverse(position);
    node->Data = data;
}
