//
// Created by rodriguezjacob245 on 1/6/21.
//

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Pose.h"

void positionCallback(const geometry_msgs::Pose::ConstPtr& msg)
{
    std::cout << "Robot Trajectory at: " << "\n" << msg->position << "\n";
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "observer");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("position", 1000, positionCallback);

    ros::spin();

    return 0;
}


