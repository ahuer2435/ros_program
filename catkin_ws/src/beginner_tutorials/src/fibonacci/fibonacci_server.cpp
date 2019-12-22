#include <ros/ros.h>
#include <beginner_tutorials/FibonacciAction.h>  //包含action 消息头文件。
#include <actionlib/server/simple_action_server.h>  //包含SimpleActionServer头文件

//重定义SimpleActionServer类型为Server.
typedef actionlib::SimpleActionServer<beginner_tutorials::FibonacciAction> Server;

//ActionServer的回调函数，类似服务的回调函数。
void executeCB(const beginner_tutorials::FibonacciGoalConstPtr &goal, Server *as)
{
  beginner_tutorials::FibonacciFeedback feedback; //定义反馈队列
  beginner_tutorials::FibonacciResult result;     //定义结果队列
  feedback.sequence.clear();                      //初始化反馈队列
  feedback.sequence.push_back(0);
  feedback.sequence.push_back(1);

  ROS_INFO("Creating fibonacci sequence of order %i with seeds %i, %i", goal->order, feedback.sequence[0], feedback.sequence[1]);
  ros::Rate r(1);
  bool success = true;  
  for(int i=1; i<=goal->order; i++) {
    //被强占或者程序结束，退出程序
    if (as->isPreemptRequested() || !ros::ok()) {
      ROS_INFO("action Preempted.");
      as->setPreempted();   //更新状态为被强占状态
      success = false;
      break;
    }
    //更新反馈队列
    feedback.sequence.push_back(feedback.sequence[i] + feedback.sequence[i-1]);
    as->publishFeedback(feedback);
    r.sleep();  //控制更新频率
  }

  if(success){
    result.sequence = feedback.sequence;  //更新结果队列
    ROS_INFO("Action Succeeded.");
    as->setSucceeded(result);             //更新状态为成功
  }
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "fibonacci_server");
  ros::NodeHandle n;
  //创建一个ActionServer:server.
  Server server(n, "fibonacci", boost::bind(&executeCB, _1, &server), false);
  //启动server.
  server.start();
  ros::spin();
  return 0;
}