// stub file
// provided so that the BinarySearchTree can be compiled
// none of the functions are implemented

using namespace std;


template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() 
{
    //constructor
    //in BinarySearchTree, rootPtr is initialized to nullptr, so no need to allocate nullptr again.
    
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() 
{
    //destructor
    removeTree(rootPtr);
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) 
{
    //constructor with root item
    rootPtr = new BinaryNode<ItemType>(rootItem);
}


template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& bst) 
{
    //copy constructor
    rootPtr = copyTree(bst.rootPtr);
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::copyTree(BinaryNode<ItemType>* bst) const
{
    //helper function for copy constructor

    //if the tree is empty, then there is nothing to copy
    if (bst == nullptr)
    {
        return nullptr;
    }
    
    //copy tree nodes during a preorder traversal

    //copy the root node
    BinaryNode<ItemType>* newTreePtr = new BinaryNode<ItemType>(bst->getItem());
        
    //copy the left subtree
    newTreePtr->setLeftChildPtr(copyTree(bst->getLeftChildPtr()));
        
    //copy the right subtree
    newTreePtr->setRightChildPtr(copyTree(bst->getRightChildPtr()));
    
    
    return newTreePtr;
}

template<class ItemType>
void BinarySearchTree<ItemType>::removeTree(BinaryNode<ItemType>* nodePtr)
{
    //helper function for destructor

    //if the tree is empty, then there is nothing to delete
    if (nodePtr == nullptr)
    {
        return;
    }
    
    //delete tree nodes during a postorder traversal

    //delete the left subtree
    removeTree(nodePtr->getLeftChildPtr());
        
    //delete the right subtree
    removeTree(nodePtr->getRightChildPtr());
    
    //delete the root node
    delete nodePtr;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const 
{
    //true if no nodes
    if (rootPtr == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const 
{
    if (rootPtr == nullptr)
    {
        return 0;
    }
    else
    {
        return getHeightHelper(rootPtr);
    }

}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
    //if the tree is empty, then there is nothing to delete
    if (subTreePtr == nullptr)
    {
        return 0;
    }
    
    //calculate the height of the tree during a postorder traversal

    //calculate the height of the left subtree
    int leftHeight = getHeightHelper(subTreePtr->getLeftChildPtr());
        
    //calculate the height of the right subtree
    int rightHeight = getHeightHelper(subTreePtr->getRightChildPtr());
    
    //return the height of the tree
    return 1 + max(leftHeight, rightHeight);

}


template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const 
{
    return getNumberOfNodesHelper(rootPtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
{
    //if the tree is empty
    if (subTreePtr == nullptr)
    {
        return 0;
    }
    
    //calculate the number of nodes in the tree during a postorder traversal

    //calculate the number of nodes in the left subtree
    int leftNodes = getNumberOfNodesHelper(subTreePtr->getLeftChildPtr());
        
    //calculate the number of nodes in the right subtree
    int rightNodes = getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
    
    //return the number of nodes in the tree
    return 1 + leftNodes + rightNodes;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& item) 
{

    if (rootPtr == nullptr) 
    { 
        rootPtr = new BinaryNode<ItemType>(item);
        return true; 
    }

    BinaryNode<ItemType>* parent = nullptr;
    BinaryNode<ItemType>* current = rootPtr;

    // Traverse the tree once for both duplicate checking and insertion point search
    while (current != nullptr)
    {
        parent = current;
        if (item < current->getItem())
        {
            current = current->getLeftChildPtr();
        }
        else if (item > current->getItem())
        {
            current = current->getRightChildPtr();
        }
        else
        {
            // If the item already exists, insertion fails
            return false;
        }
    }

    // Link the new node to the appropriate child pointer of parent
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(item);
    if (item < parent->getItem())
    {
        parent->setLeftChildPtr(newNodePtr);
    }
    else
    {
        parent->setRightChildPtr(newNodePtr);
    }

    return true;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear() 
{
    //delete all nodes in tree and set root to nullptr
    removeTree(rootPtr);
    rootPtr = nullptr;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& item) const 
{
    //true if item is in tree
    if (findNode(rootPtr, item) != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }

}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr) 
{
    //add a new node, helper function for add

    if (newNodePtr->getItem() < subTreePtr->getItem())
    {
        if (subTreePtr->getLeftChildPtr() == nullptr)
        {
            subTreePtr->setLeftChildPtr(newNodePtr);
            return subTreePtr;
        }
        else
        {
            subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr(), newNodePtr));    
        }
    }
    else if (newNodePtr->getItem() > subTreePtr->getItem())
    {
        if (subTreePtr->getRightChildPtr() == nullptr)
        {
            subTreePtr->setRightChildPtr(newNodePtr);
            return subTreePtr;
        }
        else
        {
            subTreePtr->setRightChildPtr(placeNode(subTreePtr->getRightChildPtr(), newNodePtr));
        }
    }

    return subTreePtr;
}  // end placeNode

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* subTreePtr, const ItemType& target) const 
{
    // helper function for contains
    // return a pointer to the node containing the target

    if (subTreePtr == nullptr)
    {
        return nullptr;
    }

    else if (subTreePtr->getItem() == target)
    {
        return subTreePtr;
    }

    else if (target < subTreePtr->getItem())
    {
        return findNode(subTreePtr->getLeftChildPtr(), target);
    }

    else
    {
        return findNode(subTreePtr->getRightChildPtr(), target);
    }
}  // end findNode

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const 
{
    // inorder traversal: left-root-right
    inorder(rootPtr, visit);
}  // end inorder

template<class ItemType>
void BinarySearchTree<ItemType>::inorder(BinaryNode<ItemType>* nodePtr, void visit(ItemType&)) const 
{
    if (nodePtr != nullptr)
    {
        inorder(nodePtr->getLeftChildPtr(), visit);
        ItemType item = nodePtr->getItem();
        visit(item);
        inorder(nodePtr->getRightChildPtr(), visit);
    }
}  // end inorder

template<class ItemType>
void BinarySearchTree<ItemType>::rebalance() 
{
    // create dynamic array, copy all the items to the array
    int nodeCount = getNumberOfNodes();
    if (nodeCount == 0) return;
    
    ItemType* arr = new ItemType[nodeCount];
    int index = 0;
    
    
    storeInorder(rootPtr, arr, index);
    
 
    clear();
    
 
    rootPtr = arrayToBalancedBST(arr, 0, nodeCount - 1);
    
    delete[] arr;
}

template<class ItemType>
void BinarySearchTree<ItemType>::storeInorder(BinaryNode<ItemType>* node, ItemType arr[], int& index) 
{
    // store the inorder traversal of the tree in the array
    if (node == nullptr) return;
    
    storeInorder(node->getLeftChildPtr(), arr, index);
    arr[index++] = node->getItem();
    storeInorder(node->getRightChildPtr(), arr, index);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::readTree(ItemType arr[], int n) 
{
    // given an array of length n

    clear();
    
    if (n <= 0) return false;
    
    rootPtr = arrayToBalancedBST(arr, 0, n - 1);
    return true;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::arrayToBalancedBST(ItemType arr[], int start, int end) 
{
    // create this tree to have all items in that array
    if (start > end) return nullptr;
    
 
    int mid = start + (end - start + 1) / 2;
    BinaryNode<ItemType>* node = new BinaryNode<ItemType>(arr[mid]);
    
    node->setLeftChildPtr(arrayToBalancedBST(arr, start, mid - 1));
    node->setRightChildPtr(arrayToBalancedBST(arr, mid + 1, end));
    
    return node;
}


template<class ItemType>
void BinarySearchTree<ItemType>::displaySideways() const {
    sideways(rootPtr, 0);
}

template<class ItemType>
void BinarySearchTree<ItemType>::sideways(BinaryNode<ItemType>* current, int level) const {
    if (current != NULL) {
        level++;
        sideways(current->getRightChildPtr(), level);

        // indent for readability, 4 spaces per depth level
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }

        cout << current->getItem() << endl;        // display information of object
        sideways(current->getLeftChildPtr(), level);
    }
}

template<class ItemType>
bool BinarySearchTree<ItemType>::operator==(const BinarySearchTree<ItemType>& other) const 
{
    // trees are equal if they have the same structure
    return isEqual(rootPtr, other.rootPtr);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEqual(BinaryNode<ItemType>* node1, BinaryNode<ItemType>* node2) const
{
    if (node1 == nullptr && node2 == nullptr)
    {
        return true;
    }
    else if (node1 != nullptr && node2 != nullptr)
    {
        return (node1->getItem() == node2->getItem() && isEqual(node1->getLeftChildPtr(), node2->getLeftChildPtr()) && isEqual(node1->getRightChildPtr(), node2->getRightChildPtr()));
    }
    else
    {
        return false;
    } 
}

template<class ItemType>
bool BinarySearchTree<ItemType>::operator!=(const BinarySearchTree<ItemType>& other) const 
{
    // not == to each other
    return !(*this == other);
}
