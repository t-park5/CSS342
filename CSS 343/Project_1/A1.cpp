#include "turtleprogram.h"
#include <iostream>
using namespace std;

int main() {
   
   TurtleProgram tp1;
   cout << "tp1: " << tp1 << endl;
   TurtleProgram tp2("F", "10");
   cout << "tp2: " << tp2 << endl;
   TurtleProgram tp3("R", "90");
   tp1 = tp2 + tp3;
   cout << "tp1 now as tp2+tp3: " << tp1 << endl;
   tp1 = tp2 * 3;
   cout << "tp1 now as tp2 * 3: " << tp1 << endl;
   TurtleProgram tp4(tp1);
   cout << "tp4 is a copy of tp1: " << tp4 << endl;
   TurtleProgram tp5("F", "10");
   cout << "tp5: " << tp5 << endl;
   cout << boolalpha;
   cout << "tp2 and tp5 are == to each other: " << (tp2 == tp5) << endl;
   cout << "tp2 and tp3 are != to each other: " << (tp2 != tp3) << endl;
   cout << "index 0 of tp2 is " << tp2.getIndex(0) << endl;
   tp2.setIndex(0, "R");
   tp2.setIndex(1, "90");
   cout << "tp2 after 2 calls to setIndex: " << tp2 << endl;
   cout << "tp2 and tp3 are == to each other: " << (tp2 == tp3) << endl;

   cout << "\n=== Additional Test Cases ===" << endl;

// Additional test for copy constructor
   TurtleProgram tp6 = tp2;
   cout << "tp6 (copy of tp2): " << tp6 << endl;
   tp2.setIndex(0, "F");
   cout << "tp6 after changing tp2: " << tp6 << endl;  


   TurtleProgram tp7;
   tp7 = tp2 = tp3;
   cout << "tp7 after chaining assignment: " << tp7 << endl;

   
   TurtleProgram tp8("F", "30");
   cout << "tp8 before += chain: " << tp8 << endl;
   (tp8 += tp2) += tp3;
   cout << "tp8 after += chain: " << tp8 << endl;

  
   TurtleProgram tp9 = (tp2 + tp3) * 2;
   cout << "tp9 = (tp2 + tp3) * 2: " << tp9 << endl;

  
   cout << "tp2 * 0: " << (tp2 * 0) << endl;
   cout << "tp2 * -1: " << (tp2 * -1) << endl;
   cout << "tp2 * 1: " << (tp2 * 1) << endl;

  
   TurtleProgram empty1, empty2;
   cout << "empty1 + empty2: " << (empty1 + empty2) << endl;
   cout << "empty1 == empty2: " << (empty1 == empty2) << endl;

  
   cout << "tp2.getIndex(-1): '" << tp2.getIndex(-1) << "'" << endl;
   cout << "tp2.getIndex(999): '" << tp2.getIndex(999) << "'" << endl;

   
   TurtleProgram tp10("F", "5");
   cout << "Initial tp10: " << tp10 << endl;
   tp10 *= 2;
   cout << "After *=2: " << tp10 << endl;
   tp10 += tp2;
   cout << "After +=tp2: " << tp10 << endl;
   tp10 *= 3;
   cout << "After *=3: " << tp10 << endl;

   cout << "Done." << endl;
   return 0;
}