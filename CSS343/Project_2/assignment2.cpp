#include <iostream>
#include <sstream>
#include <vector>
#include <climits>
#include "binarysearchtree.h"
#include "binarynode.h"

using namespace std;

void itemDisplay(string &anItem) {
    cout << anItem << " ";
}

string getString() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    return str;
}

vector<string> getStrings() {
    string longString;
    cout << "Enter multiple strings: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, longString);
    stringstream ss(longString);
    vector<string> v;
    string word;
    while (getline(ss, word, ' ')) {
        v.push_back(word);
    }
    return v;
}

void treeMenuString() {
    BinarySearchTree<string> bst;
    const string menu = "treeMenuString\n"
                        "1. Add\n"
                        "2. Search\n"
                        "3. Inorder traverse\n"
                        "4. Height & Number of nodes\n"
                        "5. Rebalance\n"
                        "6. Add Multiple\n"
                        "7. Clear tree\n"
                        "8. Create tree from sorted array\n"
                        "10. Exit\n>> ";
    int choice;
    string str;
    cout << menu;
    while (true) {
        cin >> choice;
        switch (choice) {
            case 1:
                str = getString();
                cout << (bst.add(str) ? "" : "Not ") << "Added " << str << endl;
                break;
            case 2:
                str = getString();
                cout << (bst.contains(str) ? "" : "Not ") << "Found " << str << endl;
                break;
            case 3:
                bst.inorderTraverse(itemDisplay);
                cout << endl;
                break;
            case 4:
                cout << "Height: " << bst.getHeight() << endl;
                cout << "Number of nodes: " << bst.getNumberOfNodes() << endl;
                break;
            case 5:
                bst.rebalance();
                break;
            case 6:
                for (string word : getStrings())
                    cout << (bst.add(word) ? "" : "Not ") << "Added " << word << endl;
                break;
            case 7:
                bst.clear();
                break;
            case 8: {
                bst.clear();
                vector<string> v = getStrings();
                bst.readTree(&v[0], v.size());
                break;
            }
            case 10:
                bst.clear();
                return;
            default:
                cout << "Invalid input" << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
        }
        bst.displaySideways();
        cout << menu;
    }
}

void treeMenuInt() {
    BinarySearchTree<int> bst;
    const string menu = "treeMenuInt\n"
                        "1. Add\n"
                        "10. Exit\n>> ";
    int choice;
    int number;
    cout << menu;
    while (true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter a number: ";
                cin >> number;
                cout << (bst.add(number) ? "" : "Not ") << "Added " << number << endl;
                break;
            case 10:
                bst.clear();
                return;
            default:
                cout << "Invalid input" << endl;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
        }
        bst.displaySideways();
        cout << menu;
    }
}

// Automatic testing function for various features
void runAutomaticTests() {
    cout << "\n===== Automatic Tests: String Tree =====" << endl;
    
    // Test string tree operations
    BinarySearchTree<string> bstStr;
    vector<string> words = {"delta", "alpha", "epsilon", "beta", "gamma"};
    for (auto &w : words) {
        cout << "Adding \"" << w << "\": " << (bstStr.add(w) ? "Success" : "Fail") << endl;
    }
    cout << "Attempt to add duplicate (\"alpha\"): " 
         << (bstStr.add("alpha") ? "Success (error)" : "Fail (expected)") << endl;
    cout << "Inorder Traversal: ";
    bstStr.inorderTraverse(itemDisplay);
    cout << "\nHeight: " << bstStr.getHeight() 
         << ", Number of nodes: " << bstStr.getNumberOfNodes() << endl;
    cout << "Search for \"gamma\": " << (bstStr.contains("gamma") ? "Found" : "Not found") << endl;
    cout << "Search for \"zeta\": " << (bstStr.contains("zeta") ? "Found" : "Not found") << endl;
    
    // Test rebalance on a skewed tree
    BinarySearchTree<string> bstSkew;
    vector<string> skewed = {"a", "b", "c", "d", "e", "f", "g"};
    for (auto &s : skewed) {
        bstSkew.add(s);
    }
    cout << "\nSkewed tree height before rebalance: " << bstSkew.getHeight() << endl;
    bstSkew.rebalance();
    cout << "Skewed tree height after rebalance: " << bstSkew.getHeight() << endl;
    cout << "Skewed tree (sideways):" << endl;
    bstSkew.displaySideways();
    
    cout << "\n===== Automatic Tests: Integer Tree =====" << endl;
    
    // Test integer tree operations
    BinarySearchTree<int> bstInt;
    int intValues[] = {10, 5, 15, 3, 7, 12, 18};
    for (int val : intValues) {
        cout << "Adding " << val << ": " << (bstInt.add(val) ? "Success" : "Fail") << endl;
    }
    cout << "Attempt to add duplicate (10): " 
         << (bstInt.add(10) ? "Success (error)" : "Fail (expected)") << endl;
    cout << "Inorder Traversal: ";
    bstInt.inorderTraverse([](int &n) { cout << n << " "; });
    cout << "\nHeight: " << bstInt.getHeight() 
         << ", Number of nodes: " << bstInt.getNumberOfNodes() << endl;
    cout << "Search for 7: " << (bstInt.contains(7) ? "Found" : "Not found") << endl;
    cout << "Search for 20: " << (bstInt.contains(20) ? "Found" : "Not found") << endl;
    
    // Test copy constructor and operator==
    BinarySearchTree<int> bstIntCopy(bstInt);
    cout << "\nAfter copy constructor, are bstInt and its copy equal? " 
         << (bstInt == bstIntCopy ? "Yes" : "No") << endl;
    
    // Test clear
    bstInt.clear();
    cout << "After clear, is bstInt empty? " 
         << (bstInt.isEmpty() ? "Yes" : "No") << endl;
    
    // Test readTree using a sorted array
    int sortedArr[] = {1, 2, 3, 4, 5, 6, 7};
    int arrSize = sizeof(sortedArr) / sizeof(sortedArr[0]);
    BinarySearchTree<int> bstFromArr;
    bstFromArr.readTree(sortedArr, arrSize);
    cout << "After readTree, inorder traversal: ";
    bstFromArr.inorderTraverse([](int &n) { cout << n << " "; });
    cout << "\n========================================\n" << endl;
}

int main() {
    // Original sample tests
    BinarySearchTree<string> bst1;
    BinarySearchTree<string> bst2;
    bst1.add("g");
    bst1.add("d");
    bst1.add("k");
    cout << ((bst1 != bst2) ? "OK" : "ERR") << ": bst1 != bst2" << endl;
    bst2.add("g");
    bst2.add("d");
    bst2.add("k");
    cout << ((bst1 == bst2) ? "OK" : "ERR") << ": bst1 == bst2" << endl;
    cout << (bst1.contains("d") ? "OK" : "ERR") << ": bst1 contains d" << endl;
    cout << (bst1.contains("x") ? "ERR" : "OK") << ": bst1 does not contain x" << endl;
    cout << (bst1.add("g") ? "ERR" : "OK") << ": adding g second time returns false" << endl;
    BinarySearchTree<string> bst3("g");
    cout << (bst3.contains("x") ? "ERR" : "OK") << ": bst3 does not contain x" << endl;
    cout << (bst3.contains("g") ? "OK" : "ERR") << ": bst3 contains g" << endl;
    BinarySearchTree<string> bst4(bst2);
    cout << ((bst4 == bst2) ? "OK" : "ERR") << ": bst4 == bst2" << endl;
    
    // Run automatic tests
    runAutomaticTests();
    
    // Interactive menu for string tree
    treeMenuString();
    // Uncomment the following line to run the interactive menu for the integer tree:
    // treeMenuInt();
    
    return 0;
}
