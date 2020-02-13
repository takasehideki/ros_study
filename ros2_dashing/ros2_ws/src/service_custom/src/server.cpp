/*
 * Copyright (C) 2008, Morgan Quigley and Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
// %Tag(FULLTEXT)%
// %Tag(ROS_HEADER)%
#include "rclcpp/rclcpp.hpp"
// %EndTag(ROS_HEADER)%
// %Tag(MSG_HEADER)%
#include "ros_study_types/srv/human.hpp"
// %EndTag(MSG_HEADER)%

rclcpp::Node::SharedPtr n = nullptr;

void calc_bmi(
  const std::shared_ptr<rmw_request_id_t> req_header,
  const std::shared_ptr<ros_study_types::srv::Human::Request>  req,
  const std::shared_ptr<ros_study_types::srv::Human::Response> res)
{
  (void)req_header;
  res->bmi = req->weight / (req->height/100.0) / (req->height/100.0);
  RCLCPP_INFO(n->get_logger(), "request: name: %s height: %d weight: %.2f",
    req->name.c_str(), req->height, req->weight);
  RCLCPP_INFO(n->get_logger(), "sending back response: bmi = %.2f", res->bmi);
}

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
// %Tag(INIT)%
  rclcpp::init(argc, argv);
// %EndTag(INIT)%

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
// %Tag(NODEHANDLE)%
  n = rclcpp::Node::make_shared("bmi_server");
// %EndTag(NODEHANDLE)%

  /**
   * The advertiseService() function
   */
// %Tag(SERVICESERVER)%
  auto service = n->create_service<ros_study_types::srv::Human>("human_info", calc_bmi);
// %EndTag(SERVICESERVER)%

  RCLCPP_INFO(n->get_logger(), "Ready to calc human's BMI.");

// %Tag(SPIN)%
  rclcpp::spin(n);
// %EndTag(SPIN)%

  rclcpp::shutdown();
  n = nullptr;

  return 0;
}
// %EndTag(FULLTEXT)%
