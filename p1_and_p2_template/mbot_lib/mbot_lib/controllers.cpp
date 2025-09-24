/**
 * File: controllers.cpp
 *
 * Sources for feedback controllers.
 */

#include <mbot_lib/controllers.h>


float bangBangControl(float current, float setpoint, float scaling, float tolerance)
{
    // *** Task: Implement this function according to the header file *** //
    float error = setpoint - current;
    
    if (error > tolerance)
        return scaling;
    else if (error < (-1 * tolerance))
        return -1*scaling;
    else
    {
        return 0;
    }

    // *** End student code *** //
}

float pControl(float current, float setpoint, float kp)
{
    // *** Task: Implement this function according to the header file *** //

    return (kp * (setpoint - current));

    // *** End student code *** //
}