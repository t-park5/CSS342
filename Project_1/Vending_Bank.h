#ifndef VENDING_BANK_H_ 
#define VENDING_BANK_H_ 
#include <iostream>
#include <string> 

class VendingBank 
{
public: 
    VendingBank(); 
    VendingBank(int id, int pennies, int nickles, int dimes, int quarters); 
    VendingBank(int id);

//getters-setters 
    int id() const;

// Action Verbs
    int pennies() const;
    int nickles() const;
    int dimes() const;
    int quarters() const;

    bool SetQuarters(int n);
    bool SetDimes(int n);
    bool SetNickles(int n);
    bool SetPennies(int n);

   
    void SetId(int ID);

// functions
    int Balance();
    bool AddCoins(int pennies, int nickles, int dimes, int quarters);
    bool MakeCahnge(int amount);
    bool RemoveAmount(int amount);
    int total() const;
    bool isEmpty() const;


//Overload Operators

    bool operator==(const VendingBank& other) const;

    
 

private: 

    int id_ ;
    int Amount_;
    int pennies_;
    int nickles_;
    int dimes_;
    int quarters;

};
#endif