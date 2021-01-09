#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Pose

def callback(data):

    # Output position to the console
    rospy.loginfo("The position is \n%s", data.position)

def listener():

    # Intitalize Observer Node with Unique Name
    rospy.init_node('observer', anonymous=True)

    # Has Observer Node Subscribe to the "position" topics each runner is publishing
    rospy.Subscriber("position", Pose, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()


