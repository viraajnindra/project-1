#include <cmath>
#include <iostream>
#include <signal.h>

#include <mbot_bridge/robot.h>

#include <mbot_lib/behaviors.h>
#include <mbot_lib/controllers.h>
#include <mbot_lib/utils.h>
using namespace::std;

bool ctrl_c_pressed;
void ctrlc(int) {
    ctrl_c_pressed = true;
}


int main() {
    signal(SIGINT, ctrlc);
    signal(SIGTERM, ctrlc);

    // Initialize the robot.
    mbot_bridge::MBot robot;
    // Reset the robot odometry to zero.
    robot.resetOdometry();

    // *** Task: Get the goal pose (x, y, theta) from the user *** //
    float x;
    float y;
    float theta;
    cout<<"Enter a x position: ";
    cin>>x;
    cout<<"Enter a y position: ";
    cin>>y;
    cout<<"Enter an angle to rotate: ";
    cin>>theta;
    vector<float> goal_pose = {x, y, theta};
    // *** End student code *** //

    // *** Task: Implement bug navigation finite state machine *** //
    


    // NOTE: You may want to change the condition in this loop.
    vector<float> ranges;
    vector<float> thetas;
    while (true) {
        robot.readLidarScan(ranges, thetas);
        vector<float> odometry_pose = robot.readOdometry();

        

        if (isGoalAngleObstructed(goal_pose, odometry_pose, ranges, thetas))
        {
           
            vector<float> vectorParallel = computeWallFollowerCommand(ranges, thetas);
            
            float dx = goal_pose[0]-odometry_pose[0];
            float dy = goal_pose[1]-odometry_pose[1];
            if (sqrt(pow(dx, 2)+pow(dy, 2)) < 0.2)
            {
                vectorParallel[0]=0;
                vectorParallel[1]=0;
                if (abs(odometry_pose[2]-goal_pose[2]) < 0.2)
                {
                    robot.stop();
                    break;
                }
            }
            else
            {
                vectorParallel[2]=0;
            }

            robot.drive(vectorParallel[0], vectorParallel[1], vectorParallel[2]*9);
        }
        else
        {
            
            vector<float> driveVec = computeDriveToPoseCommand(goal_pose, odometry_pose);
            float dx = goal_pose[0]-odometry_pose[0];
            float dy = goal_pose[1]-odometry_pose[1];
            if (sqrt(pow(dx, 2)+pow(dy, 2)) < 0.2)
            {
                driveVec[0]=0;
                driveVec[1]=0;
                if (abs(odometry_pose[2]-goal_pose[2]) < 0.2)
                {
                    robot.stop();
                    break;
                }
            }
            else
            {
                driveVec[2]=0;
            }

            robot.drive(driveVec[0], driveVec[1], driveVec[2]*9);
        }

        if(ctrl_c_pressed) break;
    }

    // *** End student code *** //

    // Stop the robot.
    robot.stop();

    // *** Task: Print out the robot's final odometry pose *** //
    vector<float> odometry_pose = robot.readOdometry();
    cout<<"The robots final pose is: ("<< odometry_pose[0]<< ", "<<odometry_pose[1]<< ")\n";
    // *** End student code *** //
}
