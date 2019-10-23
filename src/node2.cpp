#include <ros/ros.h>
#include <std_msgs/String.h>

void msgCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO_STREAM(msg->data);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "node2");  //노드명 초기화
    ros::NodeHandle nh;              //노드 관리를 위한 핸들
    ros::Subscriber hello_sub = nh.subscribe("hello", 10, msgCallback); //서브스크라이버 객체 생성 및 설정
    ros::spin();      //콜백함수 호출 및 메세지 수신확인을 위한 것, while문을 포함함.
    return 0;
}