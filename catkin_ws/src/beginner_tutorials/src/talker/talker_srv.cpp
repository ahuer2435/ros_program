#include "ros/ros.h"    //ros.h 包含ros程序常用的头文件。
#include "beginner_tutorials/AddTwoInts.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker_srv");  //初始化ros，并命令节点名。
  ros::NodeHandle n;    //初始化节点，调用ros api接口句柄。
  //定义一个客户端
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
  beginner_tutorials::AddTwoInts srv;
  srv.request.a = 100;
  srv.request.b = 10;
  if (client.call(srv)) {
    ROS_INFO("Sum: %d", srv.response.sum);
  }
  else {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }
  return 0;
}
