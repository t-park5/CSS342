README.txt

Assignment 2: BinarySearchTree Program Course: CSS343 Data Structures, Algorithms, and Discrete Mathematics II

Overview:
This assignment implements a templated BinarySearchTree (BST) class capable of storing various data types (e.g., string, int). The BST class uses the provided BinaryNode class without modification. All required functionalities are implemented, including:
• Constructors: Default, with a root item, and copy constructor 
• Destructor and clear() for proper memory management 
• Basic operations: isEmpty(), getHeight(), getNumberOfNodes(), and contains() • Insertion (add) with duplicate prevention 
• Inorder traversal (inorderTraverse) 
• Tree rebalancing (rebalance) and tree reconstruction from a sorted array (readTree) 
• Equality operators: operator== and operator!= for comparing tree structures and values

Implementation Details:
1. The BinarySearchTree class is templated. Its declaration is in binarysearchtree.h, and the template implementations are included at the end of that header file (via an #include "binarysearchtree.cpp" directive) to ensure proper instantiation.
2. Memory management is handled via recursive helper functions:
copyTree() performs a deep copy of the tree (used in the copy constructor).
removeTree() deletes all nodes (used in the destructor and clear()).
3. The rebalance() method works by storing the BST’s inorder traversal in an array, then reconstructing a balanced BST recursively.
4. Extensive testing is provided in assignment2.cpp, which includes both interactive menus and automatic test cases for string and integer trees.
5. The implementation was compiled using g++ with C++14 and warnings enabled (-Wall -Wextra) and was verified using valgrind for memory leak detection.

Assumptions:
• Duplicate elements are not inserted into the BST. • The comparison operators (<, >, ==) are correctly defined for the data types used. • Input via the interactive menus is assumed to be valid (minimal error handling is implemented for unexpected inputs).

Compilation and Execution:
To compile the project on a Linux machine, use the following command: g++ assignment2.cpp -o assignment2 -std=c++14 -Wall -Wextra

Note: Since the BST template implementation is included via the header, compile only assignment2.cpp.

To run the program, execute: ./assignment2

This will first run the automatic tests and then launch the interactive menus for further testing.

Files Included:
• binarysearchtree.h – BST class declaration and inline template implementations. 
• binarysearchtree.cpp – Template function definitions (included by binarysearchtree.h). 
• assignment2.cpp – Main function with interactive menus and additional test cases. 
• binarynode.h and binarynode.cpp – Provided BinaryNode class files (not modified). 
• output.txt – A sample run output (to be generated during execution). 
• performance.txt – (Optional) Contains details and benchmarks of any performance enhancements implemented.