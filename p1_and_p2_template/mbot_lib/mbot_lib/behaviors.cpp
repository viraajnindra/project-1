/**
 * File: behaviors.cpp
 * 
 * Sources for high level functions that determine how the robot should move.
 */

#include <mbot_lib/behaviors.h>


std::vector<float> computeWallFollowerCommand(const std::vector<float>& ranges, const std::vector<float>& thetas)
{
    // *** Task: Implement this function according to the header file *** //

    float setpoint = 0.5;  // The goal distance from the wall in meters
    float scaling = 3;

    

    float min_idx = findMinNonzeroDist(ranges);
    float dist_to_wall = ranges[min_idx];
    float angle_to_wall = thetas[min_idx];
    
    float error = pControl(dist_to_wall, setpoint, scaling);

    std::vector<float> vw = rayConversionVector(angle_to_wall);
    std::vector<float> vu = {0,0,1};

    std::vector<float> vx = {-error * cos(angle_to_wall), -error * sin(angle_to_wall), 0};

    std::vector<float> vp = crossProduct(vw, vu);
    float vpmag = sqrt(pow(vp[0], 2) + pow(vp[1], 2));

    vp[0] = vp[0]/vpmag;
    vp[1] = vp[1]/vpmag;

    return vectorAdd(vx, vp);

    // *** End student code *** //
}

std::vector<float> computeDriveToPoseCommand(const std::vector<float>& goal, const std::vector<float>& pose)
{   
    // *** Task: Implement this function according to the header file *** //

    return std::vector<float>();

    // *** End student code *** //
}

bool isGoalAngleObstructed(const std::vector<float>& goal, const std::vector<float>& pose,
                           const std::vector<float>& ranges, const std::vector<float>& thetas)
{
    // *** Task: Implement this function according to the header file *** //

    return false;

    // *** End student code *** //
}