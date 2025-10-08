#include <iostream>
#include <cmath>

#include <mbot_bridge/robot.h>

#include <mbot_lib/behaviors.h>
#include <mbot_lib/controllers.h>
#include <mbot_lib/utils.h>
using namespace::std;

bool ctrl_c_pressed;
void ctrlc(int)
{
    ctrl_c_pressed = true;
}


int main(){
    // Initialize the robot.
    mbot_bridge::MBot robot;
    // Reset the robot odometry to zero at the beginning of the run.
    robot.resetOdometry();

    // *** Task: Get the goal pose (x, y, theta) from the user *** //
    float x;
    float y;
    float theta;
    cout<<"Enter a x position: ";
    cin>>x;
    cout<<"\nEnter a y position: ";
    cin>>y;
    cout<<"\nEnter an angle to rotate: ";
    cin>>theta;
    vector<float> goal_pose = {x, y, theta};
    // *** End student code *** //
    
    while (true) {
        
        // *** Task: Implement hit the spot *** //
        std::vector<float> odometry_pose = robot.readOdometry();
        vector<float> driveVec = computeDriveToPoseCommand(goal_pose, odometry_pose);

        robot.drive(driveVec[0], driveVec[1],driveVec[2]);

        // *** End student code *** //

        if (ctrl_c_pressed) break;
    }

    // Stop the robot before exiting.
    robot.stop();

    // *** Task: Print out the robot's final odometry pose *** //

    std::vector<float> odometry_pose = robot.readOdometry();
    std::cout<< "The pose of the robot is " << odometry_pose[0]<<","<<odometry_pose[1];

    // *** End student code *** //

    return 0;
}
