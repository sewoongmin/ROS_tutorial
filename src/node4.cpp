#include <ros/ros.h>
#include <roscpp_tutorials/TwoInts.h>        //string을 전달하기 위한 토픽 메세지 타입 헤더

int main(int argc, char **argv){    //노드 메인함수
    ros::init(argc, argv, "node4");  //노드명 초기화
    
    if(argc != 3){
        ROS_WARN("cmd:rosrun hello_world node3 arg0 arg1");
        ROS_WARN("arg0 : intager number, arg1 : intager number");
        return 1;
    }

    ros::NodeHandle nh;              //ros 시스템과의 통신을 위한 노드 핸들 선언
    ros::ServiceClient client = nh.serviceClient<roscpp_tutorials::TwoInts>("calculation"); //퍼블리셔 객체 생성 및 토픽 이름 설정

    roscpp_tutorials::TwoInts srv;
    srv.request.a = std::stoi(argv[1]);
    srv.request.b = std::stoi(argv[2]);

    if(client.call(srv)){
        ROS_INFO_STREAM("send srv, srv.Request.a and b : " << srv.request.a << ", " << srv.request.b);
        ROS_INFO_STREAM("receive srv, srv.Response.result : " << srv.response.sum);
    }
    else
    {
        ROS_ERROR("Failed to call service calculation");
        return 1;
    }
    
    return 0;
}