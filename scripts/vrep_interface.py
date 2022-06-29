#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from std_msgs.msg import Bool
 
def user_interface():
    pub_start = rospy.Publisher('startSimulation', Bool, queue_size=10)
    pub_stop = rospy.Publisher('stopSimulation', Bool, queue_size=10)
    rospy.init_node('vrep_interface', anonymous=True)
    rate = rospy.Rate(10) # 10hz
        
    x = int(input("\nPress 1 to start the simulation "))
    while not rospy.is_shutdown():
        if (x == 1):
            rospy.loginfo("Simulation Started at %s", rospy.get_time())
            pub_start.publish(True)
            x = int(input("\nPress 0 to stop the simulation "))
            
        else:
            rospy.loginfo("Simulation Stopped at %s", rospy.get_time())
            pub_stop.publish(False)
            x = int(input("\nPress 1 to start the simulation "))

if __name__ == '__main__':
    try:
        user_interface()
    except rospy.ROSInterruptException:
           pass