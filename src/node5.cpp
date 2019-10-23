#include <ros/ros.h>                //ros 기본 헤더파일
#include <roscpp_tutorials/TwoInts.h>        //string을 전달하기 위한 토픽 메세지 타입 헤더

#define PLUS    1
#define MINUS   2
#define MULTIPLICATION  3
#define DIVISION    4
#define MOD 5

int operater = PLUS;

bool calculation(roscpp_tutorials::TwoInts::Request &req,
    roscpp_tutorials::TwoInts::Response &res)
{  
    switch (operater)
    {
    case PLUS:
        res.sum = req.a + req.b;
        break;
    case MINUS:
        res.sum = req.a - req.b;
        break;
    case MULTIPLICATION:
        res.sum = req.a * req.b;
        break;
    case DIVISION:
        if(req.b !=0 )
            res.sum = req.a / req.b;
        else{
            res.sum = std::numeric_limits<int>::infinity();
            return false;
        }
        break;
    case MOD:
        res.sum = req.a % req.b;
    default:
        res.sum = 0;
        break;
    }
    ROS_INFO_STREAM("request : x = " << req.a << ", y = " << req.b);
    ROS_INFO_STREAM("sending back response : " << res.sum );
    
    return true;    
}

int main(int argc, char **argv){    //노드 메인함수
    ros::init(argc, argv, "node5");  //노드명 초기화
    ros::NodeHandle nh;              //ros 시스템과의 통신을 위한 노드 핸들 선언
    nh.setParam("calculation_method", PLUS);
    ros::ServiceServer calculation_server = nh.advertiseService("calculation", calculation); //퍼블리셔 객체 생성 및 토픽 이름 설정
        
    ROS_INFO_STREAM("ready to calculate");
    ros::Rate rate(10);
    while (ros::ok())
    {
        nh.getParam("calculation_method", operater);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;;
}