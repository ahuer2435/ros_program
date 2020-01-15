#include <pluginlib/class_list_macros.h>
#include <nodelet/nodelet.h>
#include <nodelet_tutorials/nodelet_plugins.h>

//PLUGINLIB_EXPORT_CLASS()将C++类制作为为ros plugin。
PLUGINLIB_EXPORT_CLASS(nodelet_tutorials::nodeletTalker, nodelet::Nodelet)
