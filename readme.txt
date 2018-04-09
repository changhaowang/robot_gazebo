. ~/catkin_ws/devel/setup.bash
cd ~/catkin_ws/src/robot_gazebo/universal_robot/ur_gazebo/launch
roslaunch ur10.launch

cd ~/catkin_ws/src/robot_gazebo/universal_robot/ur10_moveit_config/launch
roslaunch ur10_planning_execution.launch

cd ~/catkin_ws
rosrun endpos test_custom_node

