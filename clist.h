template <typename T> class Node
{   
    public:
    T Data;
    Node<T>* Next;
    Node() = default;
};

template <typename T> class cyList{
    Node<T>* Head;
    Node<T>* Last;
    int size;

    public:
    cyList();
    void addToEmpty(T data);
    void add(T data);
    Node<T>* traverse(int position);
    void add_in_position(T data, int position);
};