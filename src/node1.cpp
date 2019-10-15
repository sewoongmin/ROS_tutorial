#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char **argv){
    ros::init(argc, argv, "node1");
    ros::NodeHandle nh;
    ros::Publisher hello_pub = nh.advertise<std_msgs::String>("hello", 10);
    ros::Rate rate(10);
    std_msgs::String msg;
    int n=0;
    while (ros::ok())
    {
        msg.data = "hello world!" + std::to_string(n);
        ROS_INFO_STREAM("send msg = " << msg.data);
        hello_pub.publish(msg);
        n++;
        rate.sleep();
    }
    return 0;
}