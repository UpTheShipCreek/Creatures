#include "clist.h"
#include <string>

template <typename T> 
cyList<T>::cyList(){
    Last = new Node<T>;    
    Last->Next = Last;
    Size = 0;
};

template <typename T> 
cyList<T>::~cyList(){
    Node<T>* dnode;
    int i = 1;
    while(i < Size){
        dnode = Last->Next;
        Last->Next= dnode->Next;
        delete dnode;
        i++;
    }
    delete Last;
}
template <typename T> 
void cyList<T>::add_to_empty(T* data){
    Last->Data = data; 
    Size++;
}

template <typename T> 
void cyList<T>::add(T* data){
    if (Size == 0){
        add_to_empty(data);
    }
    else{
    
        Node<T>* New = new Node<T>;
        Node<T>* temp = Last;

        New->Data = data;

        New->Next = Last->Next; //The new node points to the first object on the list, which is the next of the last, because it will become the new last
        temp->Next = New;  //the previous last sets the new object as its next
        Last = New; //the new object becomes the new last
        Size++;
    }
}
template <typename T> 
Node<T>* cyList<T>::traverse(int position){ 
    Node<T>* temp = Last->Next  ;
    int i = 1;
    while(i < position){   
        temp = temp->Next;     
        i++;
    }
    return temp;      
}
template <typename T> 
T* cyList<T>::get_data(Node<T>* Node){  
    return Node->Data; 
}

template <typename T> 
void cyList<T>::add_in_position(T* data, int position){
    Node<T>* node = traverse(position);
    T* Data = get_data(node);
    delete Data;
    node->Data = data;
}

template <typename T> 
int cyList<T>::get_size(){
    return Size;
}

class Creature{
    std::string Name;
    int L;
    bool is_Good;

    public:
    Creature() = default;
    Creature(std::string name);
    Creature(int life, std::string name);
};

template class cyList<Creature>;