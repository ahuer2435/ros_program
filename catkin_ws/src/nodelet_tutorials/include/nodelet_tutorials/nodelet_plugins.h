#ifndef NODELET_PLUGINS_H_
#define NODELET_PLUGINS_H_

#include <ros/ros.h>
#include <nodelet/nodelet.h>      // 基类Nodelet所在的头文件。
#include <std_msgs/Float64.h>

namespace nodelet_tutorials
{
class nodeletTalker : public nodelet::Nodelet   //任何nodelet plugin都要继承Nodelet类。
{
public:
  nodeletTalker()
  {}

private:
  virtual void onInit()     //此函数声明部分为固定格式，在nodelet加载此plugin会自动执行此函数。
  {
    ros::NodeHandle& private_nh = getPrivateNodeHandle();   //getPrivateNodeHandle()获取plugin节点名，用于命名其话题以及参数命名空间。
    pub_ = private_nh.advertise<std_msgs::Float64>("out", 1,true);
    std_msgs::Float64Ptr output(new std_msgs::Float64());
    output->data = 10;
    NODELET_INFO("publish data %f", output->data);
    pub_.publish(output);    
  }

  ros::Publisher pub_;
};

}

#endif