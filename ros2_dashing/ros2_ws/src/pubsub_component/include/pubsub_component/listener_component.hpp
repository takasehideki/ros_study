#if !defined LISTENER_NODE_HPP_
#define LISTENER_NODE_HPP_

#if __cplusplus
extern "C" {
#endif

// The below macros are taken from https://gcc.gnu.org/wiki/Visibility and from
// demos/composition/include/composition/visibility_control.h at https://github.com/ros2/demos
#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define LISTENER_EXPORT __attribute__ ((dllexport))
#define LISTENER_IMPORT __attribute__ ((dllimport))
#else
#define LISTENER_EXPORT __declspec(dllexport)
#define LISTENER_IMPORT __declspec(dllimport)
#endif
#ifdef LISTENER_BUILDING_DLL
#define LISTENER_PUBLIC LISTENER_EXPORT
#else
#define LISTENER_PUBLIC LISTENER_IMPORT
#endif
#define LISTENER_PUBLIC_TYPE LISTENER_PUBLIC
#define LISTENER_LOCAL
#else
#define LISTENER_EXPORT __attribute__ ((visibility("default")))
#define LISTENER_IMPORT
#if __GNUC__ >= 4
#define LISTENER_PUBLIC __attribute__ ((visibility("default")))
#define LISTENER_LOCAL  __attribute__ ((visibility("hidden")))
#else
#define LISTENER_PUBLIC
#define LISTENER_LOCAL
#endif
#define LISTENER_PUBLIC_TYPE
#endif

#if __cplusplus
} // extern "C"
#endif

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

namespace pubsub_component
{

  class Listener : public rclcpp::Node
  {
    public:
      LISTENER_PUBLIC Listener();

    private:
      rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub;
      void chatterCallback(const std_msgs::msg::String::SharedPtr msg);

  };

}

#endif // LISTENER_NODE_HPP_
