template <typename T> class Node
{   
    public:
    T* Data;
    Node<T>* Next;
    Node() = default;
};

template <typename T> class cyList{
    Node<T>* Last;
    int Size;

    public:
    cyList();
    ~cyList();
    void add_to_empty(T* data);
    void add(T* data);
    Node<T>* traverse(int position);
    void add_in_position(T* data, int position);
    T* get_data(Node<T>* Node);
    int get_size();
    int get_position(T* data);
};