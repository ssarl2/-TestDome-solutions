#include <stdexcept>
#include <iostream>

class Node
{
public:
    Node(Node* leftChild, Node* rightChild)
    {
        this->leftChild = leftChild;
        this->rightChild = rightChild;
    }

    Node* getLeftChild() const
    {
        return this->leftChild;
    }

    Node* getRightChild() const
    {
        return this->rightChild;
    }

    int height()
    {
        throw std::logic_error("Waiting to be implemented");
    }
private:
    Node* leftChild;
    Node* rightChild;
};

#ifndef RunTests
int main()
{
    Node* leaf1 = new Node(NULL, NULL);
    Node* leaf2 = new Node(NULL, NULL);
    Node* node = new Node(leaf1, NULL);
    Node* root = new Node(node, leaf2);

    std::cout << root->height();
}
#endif