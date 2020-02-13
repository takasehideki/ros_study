cmake_minimum_required(VERSION 3.5)
project(pubsub_component)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(class_loader REQUIRED)

include_directories(include)

add_library(talker_component SHARED src/talker_component.cpp)
add_library(listener_component SHARED src/listener_component.cpp)

target_compile_definitions(talker_component PRIVATE "TALKER_BUILDING_DLL")
target_compile_definitions(listener_component PRIVATE "LISTENER_BUILDING_DLL")

ament_target_dependencies(talker_component
  rclcpp
  std_msgs
  class_loader
)

ament_target_dependencies(listener_component
  rclcpp
  std_msgs
  class_loader
)

add_executable(talker src/talker.cpp)
target_link_libraries(talker talker_component)
ament_target_dependencies(talker rclcpp std_msgs)

add_executable(listener src/listener.cpp)
target_link_libraries(listener listener_component)
ament_target_dependencies(listener rclcpp std_msgs)

ament_export_include_directories(include)
ament_export_libraries(talker_component)
ament_export_libraries(listener_component)

install(DIRECTORY
  include/pubsub_component
  DESTINATION include
)

install(TARGETS
  talker_component
  listener_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
