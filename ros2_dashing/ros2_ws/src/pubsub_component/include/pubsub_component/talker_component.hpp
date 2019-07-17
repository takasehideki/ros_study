#if !defined TALKER_NODE_HPP_
#define TALKER_NODE_HPP_

#if __cplusplus
extern "C" {
#endif

// The below macros are taken from https://gcc.gnu.org/wiki/Visibility and from
// demos/composition/include/composition/visibility_control.h at https://github.com/ros2/demos
#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define TALKER_EXPORT __attribute__ ((dllexport))
#define TALKER_IMPORT __attribute__ ((dllimport))
#else
#define TALKER_EXPORT __declspec(dllexport)
#define TALKER_IMPORT __declspec(dllimport)
#endif
#ifdef TALKER_BUILDING_DLL
#define TALKER_PUBLIC TALKER_EXPORT
#else
#define TALKER_PUBLIC TALKER_IMPORT
#endif
#define TALKER_PUBLIC_TYPE TALKER_PUBLIC
#define TALKER_LOCAL
#else
#define TALKER_EXPORT __attribute__ ((visibility("default")))
#define TALKER_IMPORT
#if __GNUC__ >= 4
#define TALKER_PUBLIC __attribute__ ((visibility("default")))
#define TALKER_LOCAL  __attribute__ ((visibility("hidden")))
#else
#define TALKER_PUBLIC
#define TALKER_LOCAL
#endif
#define TALKER_PUBLIC_TYPE
#endif

#if __cplusplus
} // extern "C"
#endif

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

namespace pubsub_component
{

  class Talker : public rclcpp::Node
  {
    public:
      TALKER_PUBLIC Talker();

    private:
      rclcpp::Publisher<std_msgs::msg::String>::SharedPtr chatter_pub;

  };

}

#endif // TALKER_NODE_HPP_
