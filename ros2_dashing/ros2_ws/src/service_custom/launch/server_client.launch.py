import launch
import launch_ros.actions


def generate_launch_description():
  bmi_server = launch_ros.actions.Node(
      package='service_custom',
      node_executable='bmi_server',
      output='screen'
      )
  bmi_client1 = launch_ros.actions.Node(
      package='service_custom',
      node_executable='bmi_client',
      output='screen',
      arguments=['Bob', '183', '63.3']
      )

  return launch.LaunchDescription([
      bmi_server,
      bmi_client1,
      launch.actions.RegisterEventHandler(
        event_handler=launch.event_handlers.OnProcessExit(
          target_action=bmi_server,
          on_exit=[launch.actions.EmitEvent(event=launch.events.Shutdown())],
          )),
  ])
