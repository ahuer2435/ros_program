#include "ros/ros.h"   //ros.h 包含ros程序常用的头文件，必须。
int main(int argc, char **argv)
{
  ros::init(argc, argv, "hello_world");  //初始化ros，并命令节点名，必须。
  ros::NodeHandle n;                     //初始化节点，调用ros api接口句柄，这里非必须。
  ROS_INFO("hello world.");              //打印语句
  ros::spin();                           //处理所有回调函数，这里非必须。
  return 0;                              //返回值。
}