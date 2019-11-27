#include "ros/ros.h"  //ros.h 包含ros程序常用的头文件。
#include "beginner_tutorials/Num.h"  //自定义消息类型。

//回调函数定义，参数类型需要与所订阅的消息类型保持一致
void chatterCallback(const beginner_tutorials::Num::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d %d %d]", msg->a,msg->b,msg->a+msg->b);
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener_msg");  //初始化ros，并命令节点名。
  ros::NodeHandle n;        //初始化节点，调用ros api接口句柄。

  ros::Subscriber sub = n.subscribe("chatter_msg", 1, chatterCallback);  //定义一个订阅者。
  ros::spin();  //不返回函数，监听订阅者中的回调队列，并执行回调函数。
  return 0;     //正常运行时，不会执行到。
}
