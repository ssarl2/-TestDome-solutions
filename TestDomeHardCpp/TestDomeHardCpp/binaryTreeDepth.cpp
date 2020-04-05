#include <stdexcept>
#include <iostream>
#include <algorithm>

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
        int leftHeight = -1;
        int rightHeight = -1;

        if (this->getLeftChild())
        {
            leftHeight = getLeftChild()->height();
        }
        if (this->getRightChild())
        {
            rightHeight = getRightChild()->height();
        }

        return std::max(leftHeight, rightHeight) + 1;
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

/*

Some node's child node is also some node's parent.
Some nodes can both have parents as well as children.
It means I don't need to think about this question in a difficult way.
I define first leftHeight, rightHeight.
Check left and right. Not if, else if.
And then return the biggest number between leftHeight and rightHeight with adding + 1 counting.

*/