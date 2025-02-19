#include "GreedyRobot.h"
#include <iostream>
#include <vector>
using namespace std;



int main(int argument_count, char* argument_vector[]) {

    // input scripts to variables
    int max_distance = atoi(argument_vector[1]);
    int robot_x = atoi(argument_vector[2]);
    int robot_y = atoi(argument_vector[3]);
    int treasure_x = atoi(argument_vector[4]);
    int treasure_y = atoi(argument_vector[5]);

    //construct robot
    GreedyRobot robot(max_distance, robot_x, robot_y, treasure_x, treasure_y);
    robot.FindPaths(); // call FindPathsHelper
    robot.PrintPaths(); // print out paths

    return 0;
}
