#include <pluginlib/class_list_macros.h>   //PLUGINLIB_EXPORT_CLASS()所在的头文件。
#include <pluginlib_tutorials/polygon_base.h>
#include <pluginlib_tutorials/polygon_plugins.h>

//PLUGINLIB_EXPORT_CLASS()将C++类制作为为ros plugin。 
PLUGINLIB_EXPORT_CLASS(polygon_plugins::Triangle, polygon_base::RegularPolygon)
PLUGINLIB_EXPORT_CLASS(polygon_plugins::Square, polygon_base::RegularPolygon)