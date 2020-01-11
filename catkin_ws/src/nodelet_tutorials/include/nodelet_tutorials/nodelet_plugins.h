#ifndef NODELET_PLUGINS_H_
#define NODELET_PLUGINS_H_

#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include <std_msgs/Float64.h>

namespace nodelet_tutorials
{
class nodeletTalker : public nodelet::Nodelet
{
public:
  nodeletTalker()
  {}

private:
  virtual void onInit()
  {
    ros::NodeHandle& private_nh = getPrivateNodeHandle();
    pub_ = private_nh.advertise<std_msgs::Float64>("out", 1,true);
    std_msgs::Float64Ptr output(new std_msgs::Float64());
    output->data = 10;
    NODELET_DEBUG("publish data %f", output->data);
    pub_.publish(output);    
  }

  ros::Publisher pub_;
};

}

#endif