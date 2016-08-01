#include <iostream>

#define ZERO 0

template<class KeyType, class DataType>
class BinaryTreeNode;

template<class KeyType, class DataType>
class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();
    DataType find(KeyType key);
    void insert(KeyType key, DataType data);
    void erase(KeyType key);
    void clear();

protected:
    unsigned int nodeCount;
    BinaryTreeNode<KeyType, DataType> *treeRoot;
};

template<class KeyType, class DataType>
BinaryTree<KeyType, DataType>::BinaryTree()
    :nodeCount(ZERO), treeRoot(NULL)
{
    //TODO Тут нечего добавлять
}

template<class KeyType, class DataType>
BinaryTree<KeyType, DataType>::~BinaryTree()
{
    //TODO Удаление всех элементов через обход всего деорева.
}

template<class KeyType, class DataType>
DataType BinaryTree<KeyType, DataType>::find(KeyType key)
{
    if (this->treeRoot == NULL){
        return NULL;
    } else {
        BinaryTreeNode<KeyType, DataType> *workingNode = this->treeRoot;
        do
        {
            if (workingNode->key == key){
                return workingNode->data;
            } else {
                if (workingNode->key < key) {
                    if (workingNode->rightChildReference == NULL)
                    {
                        return NULL;
                    } else {
                        workingNode = workingNode->rightChildReference;
                    }
                } else {
                    if (workingNode->leftChildReference == NULL)
                    {
                        return NULL;
                    } else {
                        workingNode = workingNode->leftChildReference;
                    }

                }
            }
        } while(true);
    }
}

template<class KeyType, class DataType>
void BinaryTree<KeyType, DataType>::insert(const KeyType key, const DataType data)
{
    BinaryTreeNode<KeyType, DataType> *const newNode = new BinaryTreeNode<KeyType, DataType>;
    newNode->key = key;
    newNode->data = data;

    if (this->treeRoot == NULL){
        this->treeRoot = newNode;
    } else {
        BinaryTreeNode<KeyType, DataType> *workingNode = this->treeRoot;
        bool canExit = false;
        do
        {
            if (workingNode->key == newNode->key){
                newNode->rightChildReference = workingNode->rightChildReference;
                newNode->leftChildReference = workingNode->leftChildReference;
                delete workingNode;
                canExit = true;
            } else {
                    if (workingNode->key < newNode->key) {
                        if (workingNode->rightChildReference == NULL)
                        {
                            workingNode->rightChildReference = newNode;
                            canExit = true;
                        } else {
                            workingNode = workingNode->rightChildReference;
                        }
                    } else {
                        if (workingNode->leftChildReference == NULL)
                        {
                            workingNode->leftChildReference = newNode;
                            canExit = true;
                        } else {
                            workingNode = workingNode->leftChildReference;
                        }

                    }
            }
        } while(!canExit);
    }
    this->nodeCount++;
};

template<class KeyType, class DataType>
void BinaryTree<KeyType, DataType>::erase(KeyType key)
{
    //TODO Удаление элемента по индексу
};

template<class KeyType, class DataType>
void BinaryTree<KeyType, DataType>::clear()
{
    //TODO Очищение бинарного дерева
};




template<class KeyType, class DataType>
struct BinaryTreeNode
{
private:
    KeyType key;
    DataType data;
    BinaryTreeNode *leftChildReference = NULL;
    BinaryTreeNode *rightChildReference = NULL;

public:
    friend class BinaryTree<KeyType, DataType>;
};


int main()
{
    BinaryTree<int, float> floatTree;
    floatTree.insert(5, 25.0);
    floatTree.insert(7, 49.0);
    floatTree.insert(3, 9.0);
    floatTree.insert(6, 36.0);
    floatTree.insert(8, 64.0);
    floatTree.insert(2, 4.0);
    floatTree.insert(4, 16.0);
    std::cout << "2 - " << floatTree.find(2) << std::endl;
    std::cout << "10 - " << floatTree.find(10) << std::endl;
    std::cout << "4 - " << floatTree.find(4) << std::endl;
    std::cout << "7 - " << floatTree.find(7) << std::endl;
    std::cout << "5 - " << floatTree.find(5) << std::endl;
    std::cout << "1 - " << floatTree.find(1) << std::endl;
    std::cout << "0 - " << floatTree.find(0) << std::endl;
    std::cout << "8 - " << floatTree.find(8) << std::endl;
    std::cout << "22 - " << floatTree.find(22) << std::endl;
    std::cout << "6 - " << floatTree.find(6) << std::endl;
    std::cout << "-1 - " << floatTree.find(-1) << std::endl;
    std::cout << "3 - " << floatTree.find(3) << std::endl;
    int k;
    std::cin >> k;
    return 0;
}