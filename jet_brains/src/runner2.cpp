//
// Created by rodriguezjacob245 on 1/6/21.
//

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Pose.h"

#include <sstream>
#include <math.h>

// This program will send a message to an observer node over the ROS system.
// The message being transmitted will be a position in 3D space of type pose.

/*
 * The function that defines the trajectory of the runner will be defined by parametric equations to solve
 * for each respective variable. These will be defined as followed: x(t), y(t), z(t).
 * The trajectory will start at t = 0 and end at t = 40.
*/

float getX(float t)
{
    // x(t) = 3*cos(t)
    return 3 * cos(t);
}

float getY(float t)
{
    // y(t) = 3*sin(t)
    return 3 * sin(t);
}

float getZ(float t)
{
    // z(t) = t/3.14
    return t / 3.14;
}

struct Point
{
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
};

Point getPoint(float t)
{
    Point p;

    p.x = getX(t);
    p.y = getY(t);
    p.z = getZ(t);

    return p;
}


int main (int argc, char **argv)
{
    geometry_msgs::Pose pos;

    ros::init(argc, argv, "runner2");

    ros::NodeHandle n;

    //Runner 1
    ros::Publisher position_pub = n.advertise<geometry_msgs::Pose>("position", 1000);

    ros::Rate loop_rate(1);

    float count = 0;

    while (ros::ok() && count < 1000) {

        // Create Point object to be published
        Point point = getPoint(count);

        // Assign Pose Message with Appropriate Values
        pos.position.x = point.x;
        pos.position.y = point.y;
        pos.position.z = point.z;

        position_pub.publish(pos);


        ros::spinOnce();

        loop_rate.sleep();
        count += .5;
    }

    return 0;

}


