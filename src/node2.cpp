#include <ros/ros.h>
#include <std_msgs/String.h>

void msgCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO_STREAM(msg->data);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "node2");
    ros::NodeHandle nh;
    ros::Subscriber hello_sub = nh.subscribe("hello", 10, msgCallback);
    ros::spin();
    return 0;
}