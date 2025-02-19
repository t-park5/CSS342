#ifndef TURTLE_PROGRAM_H
#define TURTLE_PROGRAM_H
#include <iostream>
using namespace std;

class TurtleProgram
{
public:

    //constructor
    TurtleProgram(); // default constructor
    TurtleProgram(const string& cmd, const string& value);
    TurtleProgram(const TurtleProgram& other); //copy constructor
    ~TurtleProgram(); //destructor

    //getters-setters
    int getLength() const;
    string getIndex(int index) const;
    void setIndex(int index, const string& value);

    //operator overlaods
    TurtleProgram& operator=(const TurtleProgram& other);
    TurtleProgram operator+(const TurtleProgram& other) const;
    TurtleProgram& operator+=(const TurtleProgram& other);
    TurtleProgram operator*(int times) const;
    TurtleProgram& operator*=(int times);
    bool operator==(const TurtleProgram& other) const;
    bool operator!=(const TurtleProgram& other) const;

    friend ostream& operator<<(ostream& out, const TurtleProgram& other);

private:
    string* data_;
    int size_;
    void resize(int newSize);
    void copy(const TurtleProgram& other);
    
    
};

#endif