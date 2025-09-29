/**
 * File: utils.cpp
 * 
 * Sources for functions for handling common tasks like working with geometry and interpreting lidar data.
 */

#include <mbot_lib/utils.h>


std::vector<float> rayConversionCartisean(float dist, float angle) 
{
    // *** Task: Implement this function according to the header file *** //

    float x = dist * cos(angle);
    float y = dist * sin(angle);
    std::vector<float> cartesian = {x, y};
    return cartesian;

    // *** End student code *** //
}

std::vector<float> rayConversionVector(float angle) 
{
    // *** Task: Implement this function according to the header file *** //

    float x = cos(angle);
    float y = sin(angle);
    std::vector<float> move = {x, y, 0};
    return move;

    // *** End student code *** //
}

int findMinDist(const std::vector<float>& ranges)
{
    // *** Task: Implement this function according to the header file *** //

    float min = HIGH;
    int index;
    for (int i = 0; i < ranges.size(); i++)
    {
        if (ranges[i] < min)
        {
            min = ranges[i];
            index = i;
        }
    }

    return index;

    // *** End student code *** //
}

int findMinNonzeroDist(const std::vector<float>& ranges)
{
    // *** Task: Implement this function according to the header file *** //
    float min = HIGH;
    int index;
    for (int i = 0; i < ranges.size(); i++)
    {
        if (ranges[i]==0)
            continue;
        else if (ranges[i] < min)
        {
            min = ranges[i];
            index = i;
        }
    }

    return index;
    
    // *** End student code *** //
}

std::vector<float> vectorAdd(const std::vector<float>& v1, const std::vector<float>& v2) 
{
    // *** Task: Implement this function according to the header file *** //

    return std::vector<float>();

    // *** End student code *** //
}

std::vector<float> crossProduct(const std::vector<float>& v1, const std::vector<float>& v2) 
{
    // *** Task: Implement this function according to the header file *** //

    return std::vector<float>();

    // *** End student code *** //
}

void transformVector2D(std::vector<float>& xy, float theta) 
{
    // *** Task: Implement this function according to the header file *** //

    // *** End student code *** //
}
