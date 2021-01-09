#!/usr/bin/env python
# license removed for brevity
import math
import rospy
from geometry_msgs.msg import Pose

# This program will send a message to an observer node over the ROS system.
# The message being transmitted will be a position in 3D space of type pose.

# The function that defines the trajectory of the runner will be defined by parametric equations to solve
# for each respective variable. These will be defined as followed: x(t), y(t), z(t).

def getX(time):
    # x(t) = 3*cos(t)
    return 3 * math.cos(time)

def getY(time):
    # y(t) = 3*sin(t)
    return 3 * math.sin(time)

def getZ(time):
    # z(t) = time / pi
    return (time) / math.pi()

# Creates a class so Point objects can be created to store x y and z
class Point:

    x = 0.0;
    y = 0.0;
    z = 0.0;

#Assigns the values of the point at a specific time defined by the given trajectory
def getPoint(time):
    p = Point()

    p.x = getX(time)
    p.y = getY(time)
    p.z = getZ(time)



def talker():

    # Publishes a topic "position"of type Pose
    pub = rospy.Publisher('position', Pose, queue_size=10)

    # Creates the Runner Node with Unique Name
    rospy.init_node('runner2', anonymous=True)

    rate = rospy.Rate(10) # 10hz

    # Has Parametric Equation Start at t = 0
    t = 0

    # Creates New Pose Object
    pos = Pose()

    while not rospy.is_shutdown():

        # Attaches the position of the robot at time t to the pose object
        pos.position.x = getX(t)
        pos.position.y = getY(t)
        pos.position.z = getZ(t)

        # Publishes pos object for subscriber
        pub.publish(pos)
        rate.sleep()

        #iterates t
        t += 1

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
