#include "ros/ros.h"  //ros.h 包含ros程序常用的头文件。
#include "beginner_tutorials/AddTwoInts.h"  //引用服务类型头文件

//回调函数定义，参数类型需要与所服务类型保持一致
bool add(beginner_tutorials::AddTwoInts::Request  &req,
         beginner_tutorials::AddTwoInts::Response &res)
{
  res.sum = req.a + req.b;      //更新响应值。
  ROS_INFO("request: x=%d, y=%d", req.a, req.b);
  ROS_INFO("sending back response: [%d]", res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener_srv");  //初始化ros，并命令节点名。
  ros::NodeHandle n;        //初始化节点，调用ros api接口句柄。

  //定义一个服务者，服务名字：add_two_ints，服务回调函数：add
  ros::ServiceServer service = n.advertiseService("add_two_ints", add);
  ros::spin();  //不返回函数，监听服务节点中的回调队列，并执行回调函数。
  return 0;     //正常运行时，不会执行到。
}
