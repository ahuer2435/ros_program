#include "ros/ros.h"    //ros.h 包含ros程序常用的头文件。
#include "beginner_tutorials/AddTwoInts.h"  //引用服务类型头文件

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker_srv");  //初始化ros，并命令节点名。
  ros::NodeHandle n;    //初始化节点，调用ros api接口句柄。
  //定义一个客户端
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
  ros::Rate loop_rate(1);  //设置发布频率
  int count = 0;    //发布请求计数
  beginner_tutorials::AddTwoInts srv;   //定义服务变量
  while (ros::ok()){    //检测节点是否正常运行
    srv.request.a = count;      //更新服务变量值。
    srv.request.b = count+1;
    if (client.call(srv)) {     //发送请求
      ROS_INFO("Sum: %d", srv.response.sum);  //收到请求响应。
    }
    else {
      ROS_ERROR("Failed to call service add_two_ints"); //请求响应失败
      return 1;
    }
    ros::spinOnce();    //处理回调函数，会返回，这里也可以不加，因为此节点没有回调函数。
    loop_rate.sleep();  //与Line 10配套使用，用于控制发布频率。
    ++count;            //消息计数。
  }
  return 0;
}
