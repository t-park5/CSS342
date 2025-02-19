#include <iostream>
#include <vector>
using namespace std;

int catalan(int n) {

    // create a vector to store Catalan numbers from 0 to n
    vector<int> catalan_numbers(n + 1, 0); 

    // loop to compute Catalan numbers from 0 to n
    for(int i = 0; i <= n; i++) 
    {

        // base case
        if(i == 0 || i == 1) catalan_numbers[i] = 1;

        else
        {
            int temp = 0;

            for (int j = 0; j < i; j++) 
            {
                temp += catalan_numbers[j] * catalan_numbers[i - j - 1];
            }

            // store the computed Catalan number
            catalan_numbers[i] = temp;
        }
    }
    // return the nth Catalan number
    return catalan_numbers[n];
}

int main(int argc, char* argv[]) {

    int n;
    cout << "Enter your Catalan number: ";
    cin >> n;

    // check for negative input
    if (n < 0) 
    {
        cout << "You can't enter a negative number." << endl;
        return 1;
    }


    cout << catalan(n) << endl;

    return 0;
}
