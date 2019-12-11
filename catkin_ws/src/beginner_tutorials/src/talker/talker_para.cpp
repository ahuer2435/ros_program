#include "ros/ros.h"    //ros.h 包含ros程序常用的头文件。
#include "beginner_tutorials/Num.h"  //自定义消息类型。

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker_para");  //初始化ros，并命令节点名。
  ros::NodeHandle n("~");    //初始化节点，调用ros api接口句柄。
  //定义一个发布者
  ros::Publisher chatter_pub = n.advertise<beginner_tutorials::Num>("chatter_para", 1);
  ros::Rate loop_rate(1);  //设置发布频率
  int count = 0;    //发布消息计数
  beginner_tutorials::Num num;   //定义一个消息变量。
  int32_t a,b;            //定义变量a和b，用于获取参数。
  while (ros::ok()){    //检测节点是否正常运行
    if(n.getParam("avalue",a)){     //从参数服务器中获取参数avalue
      num.a = a;  
    }else{
      ROS_WARN("fail get avalue.");
    }
    if(n.getParam("bvalue",b)){     //从参数服务器中获取参数bvalue
      num.b = b;  
    }else{
      ROS_WARN("fail get bvalue.");
    }
    ROS_INFO("%d %d", num.a,num.b);   //打印消息
    chatter_pub.publish(num);   //发布消息
    ros::spinOnce();    //处理回调函数，会返回，这里也可以不加，因为此节点没有回调函数。
    loop_rate.sleep();  //与Line 11配套使用，用于控制发布频率。
    ++count;            //消息计数。
  }
  return 0;
}
