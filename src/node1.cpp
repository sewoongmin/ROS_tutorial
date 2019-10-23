#include <ros/ros.h>                //ros 기본 헤더파일
#include <std_msgs/String.h>        //string을 전달하기 위한 토픽 메세지 타입 헤더

int main(int argc, char **argv){    //노드 메인함수
    ros::init(argc, argv, "node1");  //노드명 초기화
    ros::NodeHandle nh;              //ros 시스템과의 통신을 위한 노드 핸들 선언
    ros::Publisher hello_pub = nh.advertise<std_msgs::String>("hello", 10); //퍼블리셔 객체 생성 및 토픽 이름 설정
    ros::Rate rate(10);     //반복주기 설정 10hz
    std_msgs::String msg;
    int n=0;
    while (ros::ok())               //ros가 살아 있는 동안 반복
    {
        msg.data = "hello world!" + std::to_string(n);
        ROS_INFO_STREAM("send msg = " << msg.data);
        hello_pub.publish(msg);
        n++;
        rate.sleep();
    }
    return 0;
}