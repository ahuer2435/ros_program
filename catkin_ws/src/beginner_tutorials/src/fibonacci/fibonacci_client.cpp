#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <beginner_tutorials/FibonacciAction.h>

int main (int argc, char **argv)
{
  ros::init(argc, argv, "fibonacci_client");
  //创建actionlib 客户端：ac.
  //模板数据类型需要与服务端一致。参数fibonacci也需要与服务端一致，第二个参数为true表示自动启动一个线程监视订阅队列，有消息自动处理；
  //如果为false，需要调用ros::spin()以达到同样效果。
  actionlib::SimpleActionClient<beginner_tutorials::FibonacciAction> ac("fibonacci", true);

  ROS_INFO("Waiting for action server to start.");
  // 在服务端节点没有启动前，客户端在这里一直等待，可以使用参数设置超时处理。
  ac.waitForServer();

  ROS_INFO("Action server started, sending goal.");
  // send a goal to the action
  beginner_tutorials::FibonacciGoal goal;
  goal.order = 20;        
  ac.sendGoal(goal);      //发送目标

  //等待action是否结果，设置超时时间为30，也可以不加参数，一直等待，不过建议加入超时处理的。
  bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));

  if (finished_before_timeout)
  {
    actionlib::SimpleClientGoalState state = ac.getState();     //action 正常返回。
    ROS_INFO("Action finished: %s",state.toString().c_str());
  }
  else{
    ROS_INFO("Action did not finish before the time out.");     //超时处理。
  }
  return 0;
}