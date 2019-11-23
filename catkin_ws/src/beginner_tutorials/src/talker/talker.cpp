#include "ros/ros.h"    //ros.h 包含ros程序常用的头文件。
#include "std_msgs/String.h"    //ros 内置字符串数据类型。
#include <sstream>      //c++ 流处理函数

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");  //初始化ros，并命令节点名。
  ros::NodeHandle n;    //初始化节点，调用ros api接口句柄。
  //定义一个发布者
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1);
  ros::Rate loop_rate(10);  //设置发布频率
  int count = 0;    //发布消息计数
  while (ros::ok()){    //检测节点是否正常运行
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();    //填充要发布的消息
    ROS_INFO("%s", msg.data.c_str());   //打印消息
    chatter_pub.publish(msg);   //发布消息
    ros::spinOnce();    //处理回调函数，会返回，这里也可以不加，因为此节点没有回调函数。
    loop_rate.sleep();  //与Line 11配套使用，用于控制发布频率。
    ++count;            //消息计数。
  }
  return 0;
}
