#include <ros/ros.h>
#include <pluginlib/class_loader.h>
#include <pluginlib_tutorials/polygon_base.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "plugin_test");  //初始化ros，并命令节点名。
    ros::NodeHandle n;        //初始化节点，调用ros api接口句柄。

    //使用pluginlib中的ClassLoader模板类，创建ros plugin加载句柄poly_loader。此模板类的数据类型为基类类型，
    //需要传入两个参数，一个是基类所在的包，一个是基类全名。
    pluginlib::ClassLoader<polygon_base::RegularPolygon> poly_loader("pluginlib_tutorials", "polygon_base::RegularPolygon");

    try{
        //通过句柄poly_loader，实例化插件类对象triangle。
        boost::shared_ptr<polygon_base::RegularPolygon> triangle = poly_loader.createInstance("polygon_plugins::Triangle");
        triangle->initialize(10.0);

        boost::shared_ptr<polygon_base::RegularPolygon> square = poly_loader.createInstance("polygon_plugins::Square");
        square->initialize(10.0);

        ROS_INFO("Triangle area: %.2f", triangle->area());
        ROS_INFO("Square area: %.2f", square->area());
    }
    catch(pluginlib::PluginlibException& ex) {
        ROS_ERROR("The plugin failed to load for some reason. Error: %s", ex.what());
    }

    ros::spin();
  return 0;
}