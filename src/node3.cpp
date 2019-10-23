#include <ros/ros.h>                //ros 기본 헤더파일
#include <roscpp_tutorials/TwoInts.h>        //string을 전달하기 위한 토픽 메세지 타입 헤더

bool calculation(roscpp_tutorials::TwoInts::Request &req,
    roscpp_tutorials::TwoInts::Response &res)
{  
    res.sum = req.a + req.b;
    ROS_INFO_STREAM("request : x = " << req.a << ", y = " << req.b);
    ROS_INFO_STREAM("sending back response : " << res.sum );
    
    return true;    
}

int main(int argc, char **argv){    //노드 메인함수
    ros::init(argc, argv, "node3");  //노드명 초기화
    ros::NodeHandle nh;              //ros 시스템과의 통신을 위한 노드 핸들 선언
    ros::ServiceServer calculation_server = nh.advertiseService("calculation", calculation); //퍼블리셔 객체 생성 및 토픽 이름 설정
        
    ROS_INFO_STREAM("ready to calculate");

    ros::spin();

    return 0;
}