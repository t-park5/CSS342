#include "turtleprogram.h"
#include <iostream>
#include <string>

using namespace std;

//default constructor
TurtleProgram::TurtleProgram()
{
    size_ = 0;
    data_ = nullptr;
}

//constructor
TurtleProgram::TurtleProgram(const string& cmd, const string& value)
{
    size_ = 2;
    data_ = new string[size_];
    data_[0] = cmd;
    data_[1] = value;
}

//copy constructor
TurtleProgram::TurtleProgram(const TurtleProgram& other)
{
    copy(other);
}

//destructor
TurtleProgram::~TurtleProgram()
{
    delete[] data_;
}

//getters
//returns number of strings in program
int TurtleProgram::getLength() const
{
    return size_;
}

//returns string at specified index
string TurtleProgram::getIndex(int index) const
{
    if (index < 0 || index >= size_)
    {
        return "";
    }
    return data_[index];
}

//sets string at specified index, ignores if invalid index
void TurtleProgram::setIndex(int index, const string& value)
{
    if (index < 0 || index >= size_)
    {
        return;
    }
    data_[index] = value;
}

//operator overloads
//performs deep copy
TurtleProgram& TurtleProgram::operator=(const TurtleProgram& other)
{
    if (this != &other)
    {
        delete[] data_;
        copy(other);
    }
    return *this;
}


//creates new program by concatenating two programs
TurtleProgram TurtleProgram::operator+(const TurtleProgram& other) const
{
    TurtleProgram temp;
    delete[] temp.data_;
    temp.size_ = size_ + other.size_;
    temp.data_ = new string[temp.size_];
    for (int i = 0; i < size_; i++)
    {
        temp.data_[i] = data_[i];
    }
    for (int i = 0; i < other.size_; i++)
    {
        temp.data_[size_ + i] = other.data_[i];
    }
    return temp;
}

//adds another program to current program
TurtleProgram& TurtleProgram::operator+=(const TurtleProgram& other)
{
    *this = *this + other;
    return *this;
}


//creates new program by repeating current program specified times
TurtleProgram TurtleProgram::operator*(int times) const
{

    if (times <= 0)
    {
        return TurtleProgram();
    }

    TurtleProgram temp;
    delete[] temp.data_;
    temp.size_ = size_ * times;
    temp.data_ = new string[temp.size_];
    for (int i = 0; i < times; i++)
    {
        for (int j = 0; j < size_; j++)
        {
            temp.data_[i * size_ + j] = data_[j];
        }
    }
    return temp;
}

//multiplies current program by specified times
TurtleProgram& TurtleProgram::operator*=(int times)
{
    if (times <= 0)
    {
        *this = TurtleProgram();
        return *this;
    }

    *this = *this * times;
    return *this;
}

//checks if two programs are identical
bool TurtleProgram::operator==(const TurtleProgram& other) const
{
    if (size_ != other.size_)
    {
        return false;
    }
    for (int i = 0; i < size_; i++)
    {
        if (data_[i] != other.data_[i])
        {
            return false;
        }
    }
    return true;
}

//checks if two programs are different
bool TurtleProgram::operator!=(const TurtleProgram& other) const
{
    return !(*this == other);
}

//formats program output
ostream& operator<<(ostream& out, const TurtleProgram& other)
{
    out << "[";

    for (int i = 0; i < other.size_; i++)
    {
        out << other.data_[i];

        if (i < other.size_ - 1)
        {
            out << " ";
        }
    }

    out << "]";

    return out;
}

//private helper function
//resizes array to new size
void TurtleProgram::resize(int newSize)
{
    if (newSize < 0)
    {
        return;
    }

    string* temp = new string[newSize];
    int minSize = min(size_, newSize);

    for (int i = 0; i < minSize; i++)
    {
        temp[i] = data_[i];
    }
    delete[] data_;
    data_ = temp;
    size_ = newSize;
}

//copies data from another program
void TurtleProgram::copy(const TurtleProgram& other)
{
    size_ = other.size_;
    data_ = new string[size_];
    for (int i = 0; i < size_; i++)
    {
        data_[i] = other.data_[i];
    }
}



