#ifndef GRREDY_ROBOT_H_
#define GRREDY_ROBOT_H_
#include <iostream>
#include <vector>
using namespace std;

class GreedyRobot
{
    private:
    
    int max_distance_;
    int robot_x_;
    int robot_y_;
    int treasure_x_;
    int treasure_y_;
    vector<string> paths_; // save paths

    void FindPathsHelper(int robot_x, int robot_y, int move_count, char last_move, int consecutive_n, int consecutive_s, int consecutive_e, int consecutive_w, string path);

    public:
    
    //constructor
    GreedyRobot();
    GreedyRobot(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y);

    //Actions
    void FindPaths(); // start finding paths
    void PrintPaths() const; // print found paths
    

};
#endif