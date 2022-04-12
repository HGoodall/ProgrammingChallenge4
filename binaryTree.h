
#include <iostream>
using namespace std;

template <class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType>* left;
    nodeType<elemType>* right;
};

template <class elemType>
class binaryTree
{
public:
    bool search(elemType searchItem, elemType& value);
      //Function to determine if searchItem is in the binary
      //search tree.
      //Postcondition: Returns true if searchItem is found in
      //               the binary search tree; otherwise,
      //               returns false.

      void insert(const elemType& insertItem);
      //Function to insert insertItem in the binary search tree.
      //Postcondition: If there is no node in the binary search
      //               tree that has the same info as
      //               insertItem, a node with the info
      //               insertItem is created and inserted in the
      //               binary search tree.

      void inorderTraversal() const;
      //Function to do an inorder traversal of the binary tree.
      //Postcondition: Nodes are printed in inorder sequence.
      binaryTree();
      //Default constructor
      ~binaryTree();
      //Destructor
protected:
    nodeType<elemType>* root;
private:
    void inorder(nodeType<elemType>* p) const;

    void destroy(nodeType<elemType>*& p);


};

template<class elemType>
inline bool binaryTree<elemType>::search(elemType searchItem, elemType &name)
{
    nodeType<elemType>* current;
    bool found = false;

    if (this->root == nullptr)
        cout << "Cannot search an empty tree." << endl;
    else
    {
        current = this->root;

        while (current != nullptr && !found)
        {
            if (current->info == searchItem) {
                name = current->info;
                found = true;
            }
            else if (current->info > searchItem)
                current = current->left;
            else
                current = current->right;
        }//end while
    }//end else

    return found;
}

template<class elemType>
inline void binaryTree<elemType>::insert(const elemType& insertItem)
{
    nodeType<elemType>* current; //pointer to traverse the tree
    nodeType<elemType>* trailCurrent = nullptr; //pointer
                                              //behind current
    nodeType<elemType>* newNode;  //pointer to create the node

    newNode = new nodeType<elemType>;
    newNode->info = insertItem;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (this->root == nullptr)
        this->root = newNode;
    else
    {
        current = this->root;

        while (current != nullptr)
        {
            trailCurrent = current;

            if (current->info == insertItem)
            {
                return;
            }
            if (current->info > insertItem)
                current = current->left;
            else
                current = current->right;
        }//end while

        if (trailCurrent->info > insertItem)
            trailCurrent->left = newNode;
        else
            trailCurrent->right = newNode;
    }
}

template<class elemType>
inline void binaryTree<elemType>::inorderTraversal() const
{
    inorder(root);
}

template<class elemType>
inline binaryTree<elemType>::binaryTree()
{
    root = nullptr;
}

template<class elemType>
inline binaryTree<elemType>::~binaryTree()
{
    destroy(root);
}

template<class elemType>
inline void binaryTree<elemType>::inorder(nodeType<elemType>* p) const
{
    if (p != nullptr)
    {
        inorder(p->left);
        cout << p->info << endl;
        inorder(p->right);
    }
}

template<class elemType>
inline void binaryTree<elemType>::destroy(nodeType<elemType>*& p)
{
    if (p != nullptr)
    {
        destroy(p->left);
        destroy(p->right);
        delete p;
        p = nullptr;
    }
}


