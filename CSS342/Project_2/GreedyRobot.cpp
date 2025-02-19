#include "GreedyRobot.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

GreedyRobot::GreedyRobot()
{
    max_distance_ = 0;
    robot_x_ = 0;
    robot_y_ = 0;
    treasure_x_ = 0;
    treasure_y_ = 0;  
}

GreedyRobot::GreedyRobot(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y)
{
    max_distance_ = max_distance;
    robot_x_ = robot_x;
    robot_y_ = robot_y;
    treasure_x_ = treasure_x;
    treasure_y_ = treasure_y;
}

void GreedyRobot::FindPaths()
{
    FindPathsHelper(robot_x_, robot_y_, 0, '\0', 0, 0, 0, 0, ""); // call FindPathsHelper to start finding paths
}

void GreedyRobot::FindPathsHelper(int robot_x, int robot_y, int move_count, char last_move, int consecutive_n, int consecutive_s, int consecutive_e, int consecutive_w, string path) 
{
    //base case
    if (robot_x == treasure_x_ && robot_y == treasure_y_) 
    {
        if (!path.empty()) // if path is empty, then return. if path is not empty, then add path to paths_
        {
            paths_.push_back(path);
        }
        return;
    }

    // move North
    if (robot_y < treasure_y_) 
    {
        if (consecutive_n < max_distance_)
        {
            FindPathsHelper(robot_x, robot_y + 1, move_count + 1, 'N', consecutive_n + 1, 0, 0, 0, path + "N");
        }
    }

    // move South
    if (robot_y > treasure_y_) 
    {
        if (consecutive_s < max_distance_)
        {
            FindPathsHelper(robot_x, robot_y - 1, move_count + 1, 'S', 0, consecutive_s + 1, 0, 0, path + "S");
        }
    }

    // move East
    if (robot_x < treasure_x_) 
    {
        if (consecutive_e < max_distance_)
        {
            FindPathsHelper(robot_x + 1, robot_y, move_count + 1, 'E', 0, 0, consecutive_e + 1, 0, path + "E");
        }
    }

    // move West
    if (robot_x > treasure_x_) 
    {
        if (consecutive_w < max_distance_)
        {
            FindPathsHelper(robot_x - 1, robot_y, move_count + 1, 'W', 0, 0, 0, consecutive_w + 1, path + "W");
        }
    }
}

// each loop print out paths_[i]
void GreedyRobot::PrintPaths() const
{
    for (int i = 0; i < paths_.size(); i++)
    {
        cout << paths_[i] << endl;
    }

    cout << "Number of paths: " << paths_.size() << endl;
}



