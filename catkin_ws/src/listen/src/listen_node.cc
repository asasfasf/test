/**
 * 该例程将订阅/turtle1/pose话题，消息类型turtlesim::Pose
 */

#include <ros/ros.h>
#include <std_msgs/String.h>
#include "turtlesim/Pose.h"

void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
    // 将接收到的消息打印出来
    ROS_INFO("Turtle pose: x:%0.6f, y:%0.6f", msg->x, msg->y);
}

class TurtlesimToplicListen{
public:
    TurtlesimToplicListen(int argc,char **argv){
        // 初始化ROS节点
        ros::init(argc, argv, "pose_subscriber");

        // 创建节点句柄
        ros::NodeHandle n;

        // 创建一个Subscriber，订阅名为/turtle1/pose的topic，注册回调函数poseCallback
        //ros::Subscriber pose_sub = n.subscribe("/turtle1/cmd_vel", 10, poseCallback);
        ros::Subscriber pose_sub = n.subscribe("/turtle1/pose", 10, poseCallback);

        // 循环等待回调函数
        ros::spin();
    }
};


void chattercallback(const std_msgs::String::ConstPtr & msg){
        ROS_INFO("I heard:  [%s]",msg->data.c_str());   //具体什么也不知道
}

class Chatterlisten{
public:
    Chatterlisten(int argc,char **argv){

        //1.初始化节点
        ros::init(argc,argv,"listen");

        //2.创建句柄
        ros::NodeHandle node_;

        //3.创建发布者
        // Topic size 回调函数
        ros::Subscriber chatter_sub = node_.subscribe("chatter", 1000, chattercallback);

        //4.等待回调函数 --- 程序会阻塞在这里不断回调
        ros::spin();

    }

};

void test(int argc,char** argv){
    Chatterlisten(argc,argv);
}

int main(int argc, char **argv)
{
    test(argc,argv);
    return 0;
}
