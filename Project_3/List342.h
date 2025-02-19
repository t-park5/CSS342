#ifndef LIST342_H_
#define LIST342_H_
#include <iostream>
#include <fstream>
using namespace std;


template <class T>

class List342
{
private:
    struct Node
    {
        T* data;
        Node* next;
    };
    
    Node* head_;
    int size_;

public:
    //constructor
    List342()
    {
        head_ = nullptr;
        size_ = 0;
    }

    ~List342() //destructor
    {
        DeleteList();
    }

    List342(const List342& other)
    {
        head_ = nullptr;
        size_ = 0;
        Node* current = other.head_;
        
        while (current != nullptr)
        {
            Insert(current->data);
            current = current->next;
        }
    }

    bool BuildList(string file_name)
    {
        ifstream infile(file_name);

        if (!infile)
        {
            cerr << "Unable to open file: " << file_name << endl;  // Add this for debugging
            return false;
        }

        T item;

        while (infile >> item)
        {
            T* new_item = new T(item);
            bool insert_result = Insert(new_item);
        
        
            delete new_item;
        

        }

        infile.close();
        return true;
    }

    bool Insert(T* obj)
    {
        if (obj == nullptr) // if passed value is null
        {
            return false;
        }

        Node* previous = nullptr;
        Node* current = head_;

        // find point to insert
        while (current != nullptr && *current->data < *obj)
        {
            previous = current;
            current = current->next;
        }

        if (current != nullptr && *current->data == *obj)
        {
            return false;
        }

        // New node with passed data
        Node* new_node = new Node;
        new_node->data = new T(*obj);
        new_node->next = nullptr;
        
        if (previous == nullptr)
        {
            new_node->next = head_;
            head_ = new_node;
        }

        else
        {
            new_node->next = current;
            previous->next = new_node;
        }

        size_++;
        return true;

    }

    bool Remove(T target, T& result)
    {
        Node* previous = nullptr;
        Node* current = head_;

        while (current != nullptr && *current->data != target)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            return false;
        }

        result = *current->data;

        if (previous == nullptr)
        {
            head_ = current->next;
        }

        else
        {
            previous->next = current->next;
        }


        //delete node
        delete current->data; 
        delete current;
        size_--;
        return true;
    }

    bool Peek(T target, T& result) const
    {
        Node* current = head_;
        
        while (current != nullptr && *current->data != target)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            return false;
        }

        result = *current->data;
        return true;
    }

    //size of list
    int Size() const
    {
        return size_;
    }

    //delete entire list
    void DeleteList()
    {
        while (head_ != nullptr)
        {
            Node* temp = head_;
            head_ = head_->next;
            delete temp->data;
            delete temp;
        }

        size_ = 0;
    }

    bool Merge(List342& list1)
    {
        // if the list is same
        if (this == &list1) 
        {
            return false;
        }

    // 병합할 리스트가 비어있는 경우
        if (list1.head_ == nullptr)
        {
            return false;
        }

        bool merged = false;
        Node* current = list1.head_;
    
        while (current != nullptr)
        {
            Node* next = current->next;  // 다음 노드 저장
        
            // 현재 리스트에 삽입할 위치 찾기
            Node* prev = nullptr;
            Node* pos = head_;
        
        while (pos != nullptr && *pos->data < *current->data)
        {
            prev = pos;
            pos = pos->next;
        }
        
        // 중복 체크
        if (pos != nullptr && *pos->data == *current->data)
        {
            // 중복된 경우 현재 노드 삭제
            delete current->data;
            delete current;
        }

        else
        {
            // 노드 연결 재조정
            current->next = pos;
            if (prev == nullptr)
            {
                head_ = current;
            }

            else
            {
                prev->next = current;
            }
            merged = true;
            size_++;
        }
        
        current = next; 
        }
    
        // reset list
        list1.head_ = nullptr;
        list1.size_ = 0;
    
        return merged;
    }

    List342 operator+(const List342& list1) const
    {
        List342 result = *this;
        Node* current = list1.head_;
    
        while (current != nullptr)
        {
            result.Insert(current->data);
            current = current->next;
        }

        return result;

    }

    List342& operator+=(const List342 &list1)
    {
        Node* current = list1.head_;

        while (current != nullptr)
        {
            Insert(current->data);
            current = current->next;
        }

        return *this;
    }

    bool operator==(const List342 &list1) const
    {
        if (size_ != list1.size_)
        {
            return false;
        }

        Node* current1 = head_;
        Node* current2 = list1.head_;

        while (current1 != nullptr)
        {
            if (*current1->data != *current2->data)
            {
                return false;
            }

            current1 = current1->next;
            current2 = current2->next;
        }

        return true;
    }

    //make a deep copy
    List342& operator=(const List342 &list1)
    {
        if (this != &list1)
        {
            DeleteList();
            Node* current = list1.head_;
            
            while (current != nullptr)
            {
                Insert(current->data);
                current = current->next;
            }
        }

        return *this;
    }

    bool operator!=(const List342 &list1) const
    {
        return !(*this == list1);
    }

    friend ostream& operator<<(ostream& os, const List342<T>& list1)
    {
        Node* current = list1.head_;

        while (current != nullptr)
        {
            os << *current->data;
            current = current->next;
        }

        return os;
    }

};
#endif