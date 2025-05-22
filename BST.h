#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <iostream>
/**
 * @class BST
 * @brief  A Temu-Version of BST
 *
 *
 *
 * @author Ken Giron
 * @version 01
 * @date 5/14/2025 Ken Giron, Started
 *
 * @todo [NA]
 *
 * @bug My program has no bugs.
 */

template<class T>
class BST
{
public:
    typedef void(*f1Typ)(T &);

    BST();
    /**
    	 * @brief  Destructor
    	 *
    	 * Destructs the Object Class
    	 */
    ~BST();
    /**
    	 * @brief  Copy Constructor
    	 *
    	 * Copies another object to the current object, while voiding shallow copies
    	 *
    	 * @param other = Another BST object, origin of copy.
    	 * @return a copied object
    	 */
    BST(const BST& other);
    /**
    	 * @brief  Copy Assignment Operator
    	 *
    	 * Copies another object and assigns its value to another object
    	 * @param other = Another BST object, origin of copy.
    	 * @return a deep copy of the class
    	 */
    BST<T>& operator=(const BST<T>& other);
    /**
    	 * @brief  Inserts value in the tree
    	 * @param value = The value being inserted in the tree
    	 * @return void
    	 */
    void Insert(const T &value);
    /**
    	 * @brief  Searches if the value is in the tree
    	 * @param value = The value we are searching for
    	 *
    	 * returns true if the value is located
    	 *
    	 * @return status of the search, True if value is in the tree
    	 */
    bool Search(const T &value);
    /**
    	 * @brief  Traverses the tree and prints in a "sorted" order
    	 *
    	 *
    	 * @return void
    	 */
    void InOrderTraversal(f1Typ f1) const;
    /**
    	 * @brief  Traverses the tree in the order of the actual Tree.
    	 * @param a Function Pointer that takes a function that has a void return type and a Reference Parameter.
    	 *
    	 * Node, Left, Right Movement
    	 *
    	 * @return void
    	 */
    void PreOrderTraversal(f1Typ f1) const;
    /**
    	 * @brief  Traverses the tree, in the order of the children first then the parent.
         * @param a Function Pointer that takes a function that has a void return type and a Reference Parameter.
    	 *
    	 *
    	 *
    	 * @return void
    	 */
    void PostOrderTraversal(f1Typ f1) const;
    /**
    	 * @brief  Checks if the Tree is Valid, and there are no errors in the tree's structure
    	 * @param a Function Pointer that takes a function that has a void return type and a Reference Parameter.
    	 *
    	 * @return Status of the tree, if its true then there are no faults
    	 */
    bool isValidTree();
private:
    template<typename P>
    struct Node
    {
        P data;
        Node<P>* left = nullptr;
        Node<P>* right = nullptr;

        Node(const P& val);
    };
    ///The root of the Tree.
    Node<T>* root;
    /**
    	 * @brief  Deletes the tree, avoiding memory leaks
    	 * @param node = The node currently traversing in
    	 * @return void
    	 */
    void DeleteTree(Node<T>* node);
    /**
    	 * @brief  Recursive Helper function for insert
    	 * @param node = The node currently traversing in
    	 * @return void
    	 */
    void insertHelper(Node<T>* node, const T &value);
    /**
    	 * @brief  Recursive Helper function for Search
    	 * @param node = The node currently traversing in
    	 * @param value = The value we are locating
    	 *
    	 * @return bool if the value has been located.
    	 */
    bool searchHelper(Node<T>* node, const T &value);
    /**
    	 * @brief  Recursive Helper function for Copy Assignment and Copy Constructor
    	 * @param node = The node currently traversing in
    	 * This makes sure the copy goes smoothly without any memory leakage of the previous tree and the tree being co
    	 *
    	 * @return void
    	 */
    void copyHelper(Node<T>* node);
    /**
    	 * @brief  Recursive Helper function for InOrderTraversal
    	 * @param node = The node currently traversing in
    	 *
    	 * @return void
    	 */
    void InOrderHelper(f1Typ f1, Node<T>* node) const;
    /**
    	 * @brief  Recursive Helper function for PreOrderTraversal
    	 * @param node = The node currently traversing in
    	 *
    	 * @return void
    	 */
    void PreOrderHelper(f1Typ f1, Node<T>* node) const;
    /**
    	 * @brief  Recursive Helper function for PostOrderTraversal
    	 * @param node = The node currently traversing in
    	 *
    	 * @return void
    	 */
    void PostOrderHelper(f1Typ f1, Node<T>* node) const;
    /**
    	 * @brief  Recursive Helper function for isValid
    	 * @param node = The node currently traversing in
    	 *
    	 * @return void
    	 */
    bool isValidTreeHelper(Node<T>* node, T* minVal, T* maxVal);

};
template<class T>
template<typename P>
BST<T>::Node<P>::Node(const P& val)
{
    data = val;
    left = nullptr;
    right = nullptr;
}

template<class T>
BST<T>::BST()
{
    root = nullptr;
}
template<class T>
BST<T>::~BST()
{
    DeleteTree(root);
    root = nullptr; //This Completes the Destructor

}
template<class T>
BST<T>::BST(const BST& other)
{
    root = nullptr;
    if(other.root != nullptr)
    {
        copyHelper(other.root);
        //Since this and the parameter are the same object
        //They have access to each other privates
    }
}
template<class T>
BST<T>& BST<T>::operator=(const BST<T>& other)
{
    if(this == &other)
    {
        return *this;
    }
    DeleteTree(root);
    copyHelper(other.root);
    return *this;
}
template<class T>
void BST<T>::Insert(const T &value)
{
    if(root == nullptr)
    {
        root = new Node<T>(value);
    }
    else
    {
        insertHelper(root, value);
    }
}
template<class T>
bool BST<T>::Search(const T &value)
{
    return searchHelper(root, value);
}
template<class T>
void BST<T>::InOrderTraversal(f1Typ f1) const
{
    InOrderHelper(f1, root);
    std::cout << '\n';
}
template<class T>
void BST<T>::PreOrderTraversal(f1Typ f1) const
{
    PreOrderHelper(f1, root);
    std::cout << '\n';
}
template<class T>
void BST<T>::PostOrderTraversal(f1Typ f1) const
{
    PostOrderHelper(f1, root);
    std::cout << '\n';
}
template<class T>
void BST<T>::DeleteTree(Node<T>* node)
{
    if(node == nullptr)
    {
        return;
    }
    DeleteTree(node->left);
    DeleteTree(node->right);

    delete node;
}

template <class T>
bool BST<T>::isValidTree()
{
    return isValidTreeHelper(root, nullptr, nullptr);
}

template<class T>
void BST<T>::insertHelper(Node<T>* node, const T &value)
{
    if(value == node->data)
    {
        return;
    }
    if(value < node->data)//Left Side
    {
        if(node->left == nullptr)
        {
            //If it is empty, make a new node, with the value
            Node<T>* leftNode = new Node<T>(value);
            node->left = leftNode;
        }
        else
        {
            //A node is there, traverse through it, Do not replace data.
            insertHelper(node->left, value);
        }
    }
    if(value > node->data) //Right Side
    {
        if(node->right == nullptr)
        {
            Node<T>* rightNode = new Node<T>(value);
            node->right = rightNode;
            //Set the current Node's Right node to the new node with the value
        }
        else
        {
            insertHelper(node->right, value);
        }
    }
}
template<class T>
bool BST<T>::searchHelper(Node<T>* node, const T &value)
{
    if(node == nullptr)
    {
        //Check if its Empty, Not here Mate
        return false;
    }
    if(node->data == value)
    {
        //Found the Value!
        return true;
    }
    if(value > node->data)
    {
        //If the Value is more than the data, go Right
        return searchHelper(node->right, value);
    }
    else
    {
        return searchHelper(node->left, value);
    }
}
template<class T>
void BST<T>::copyHelper(Node<T>* node)
{
    if(node == nullptr)
    {
        //Check if its Empty
        return;
    }
    Insert(node->data); //Insert the Node's data into our data.
    copyHelper(node->left); //Time to go Left!
    copyHelper(node->right); //Time to go Right!
}
template<class T>
void BST<T>::InOrderHelper(f1Typ f1,  Node<T>* node) const
{
    if(node == nullptr) //Check if its empty
    {
        return;
    }
    InOrderHelper(f1, node->left); //Check the Lowest First!
    f1(node->data);
    InOrderHelper(f1, node->right);
}
template<class T>
void BST<T>::PreOrderHelper(f1Typ f1, Node<T>* node) const
{
    if(node == nullptr) //Check if its empty
    {
        return;
    }
    f1(node->data);
    PreOrderHelper(f1, node->left);
    PreOrderHelper(f1, node->right);
}
template<class T>
void BST<T>::PostOrderHelper(f1Typ f1, Node<T>* node) const
{
    if(node == nullptr) //Check if its empty
    {
        return;
    }
    PostOrderHelper(f1, node->left);
    PostOrderHelper(f1, node->right);
    f1(node->data);
}
template<class T>
bool BST<T>::isValidTreeHelper(Node<T>* node, T* minVal, T* maxVal)
{
    if(node == nullptr)
    {
        return true;
    }
    T val = node->data; //Current Value take it to be passed as min max
    if(minVal!= nullptr && val < *minVal)
    {
        return false;
    }
    if(maxVal!= nullptr && val > *maxVal)
    {
        return false;
    }
    return(isValidTreeHelper(node->left, minVal, &val) && isValidTreeHelper(node->right, &val, maxVal));
}
#endif // BST_H_INCLUDED
