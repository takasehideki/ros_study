#include <ros/ros.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "getter");
  ros::NodeHandle n;

  ros::Rate loop_rate(0.2);

  while (ros::ok()) {
    if (n.hasParam("/foo")) {
      int param;
      if (n.getParam("/foo", param)) {
        ROS_INFO("Value of /foo is %d", param);
      } else {
        ROS_ERROR("Type of /foo is not integer");
      }
    } else {
      ROS_WARN("Key /foo is not set now");
    }

    loop_rate.sleep();
  }

  return 0;
}
