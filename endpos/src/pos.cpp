

#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_group_interface_tutorial");
  ros::NodeHandle node_handle;  
  ros::AsyncSpinner spinner(1);
  spinner.start();

  moveit::planning_interface::MoveGroup group("manipulator");
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;  
  ros::Publisher display_publisher = node_handle.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
  moveit_msgs::DisplayTrajectory display_trajectory;
  ROS_INFO("Reference frame: %s", group.getPlanningFrame().c_str());
  ROS_INFO("Reference frame: %s", group.getEndEffectorLink().c_str());
  geometry_msgs::Pose target_pose1;
  target_pose1.orientation.w = 1;
  target_pose1.orientation.x= 0;
  target_pose1.orientation.y = 0;
  target_pose1.orientation.z = 0;

  target_pose1.position.x = 0.8;
  target_pose1.position.y = 0;
  target_pose1.position.z = 0.3;
  //group.setPoseTarget(target_pose1);
  group.setJointValueTarget ("shoulder_pan_joint", 0);
  group.setJointValueTarget ("shoulder_lift_joint", -1.5707);
  group.setJointValueTarget ("elbow_joint", 1.5707);
  group.setJointValueTarget ("wrist_1_joint", -1.5707);
  group.setJointValueTarget ("wrist_2_joint", 0);
  group.setJointValueTarget ("wrist_3_joint", 0);

  // Now, we call the planner to compute the plan
  // and visualize it.
  // Note that we are just planning, not asking move_group 
  // to actually move the robot.
  moveit::planning_interface::MoveGroup::Plan my_plan;
  bool success = (group.plan(my_plan)==moveit::planning_interface::MoveItErrorCode::SUCCESS);

  ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"":"FAILED");    
  /* Sleep to give Rviz time to visualize the plan. */
  sleep(5.0);
    //让机械臂按照规划的轨迹开始运动。
if(success)
     group.execute(my_plan);
// END_TUTORIAL
  sleep(10.0);
  target_pose1.orientation.w = 0.7071067812;
  target_pose1.orientation.x= 0;
  target_pose1.orientation.y = 0.7071067812;
  target_pose1.orientation.z = 0;

  target_pose1.position.x = 0.6;
  target_pose1.position.y = -0.1;
  target_pose1.position.z = 0;
  group.setPoseTarget(target_pose1);
  success = (group.plan(my_plan)==moveit::planning_interface::MoveItErrorCode::SUCCESS);
  ROS_INFO("Visualizing plan 2 (pose goal) %s",success?"":"FAILED");    
  sleep(5.0);
if(success)
     group.execute(my_plan);

  sleep(10.0);
  target_pose1.orientation.w = 0.7071067812;
  target_pose1.orientation.x= 0;
  target_pose1.orientation.y = 0.7071067812;
  target_pose1.orientation.z = 0;

  target_pose1.position.x = 0.6;
  target_pose1.position.y = -0.1;
  target_pose1.position.z = 0.20;
  group.setPoseTarget(target_pose1);
  success = (group.plan(my_plan)==moveit::planning_interface::MoveItErrorCode::SUCCESS);
  ROS_INFO("Visualizing plan 3 (pose goal) %s",success?"":"FAILED");    
  sleep(5.0);
if(success)
     group.execute(my_plan);

  sleep(10.0);
  target_pose1.orientation.w = 0.7071067812;
  target_pose1.orientation.x= 0;
  target_pose1.orientation.y = 0.7071067812;
  target_pose1.orientation.z = 0;

  target_pose1.position.x = 0.8;
  target_pose1.position.y = -0.1;
  target_pose1.position.z = 0.18;
  group.setPoseTarget(target_pose1);
  success = (group.plan(my_plan)==moveit::planning_interface::MoveItErrorCode::SUCCESS);
  ROS_INFO("Visualizing plan 4 (pose goal) %s",success?"":"FAILED");    
  sleep(5.0);
if(success)
     group.execute(my_plan);

  sleep(10.0);
  target_pose1.orientation.w = 0.7071067812;
  target_pose1.orientation.x= 0;
  target_pose1.orientation.y = 0.7071067812;
  target_pose1.orientation.z = 0;

  target_pose1.position.x = 0.95;
  target_pose1.position.y = -0.1;
  target_pose1.position.z = 0.18;
  group.setPoseTarget(target_pose1);
  success = (group.plan(my_plan)==moveit::planning_interface::MoveItErrorCode::SUCCESS);
  ROS_INFO("Visualizing plan 5 (pose goal) %s",success?"":"FAILED");    
  sleep(5.0);
if(success)
     group.execute(my_plan);

  sleep(10.0);
  target_pose1.orientation.w = 0.7071067812;
  target_pose1.orientation.x= 0;
  target_pose1.orientation.y = 0.7071067812;
  target_pose1.orientation.z = 0;

  target_pose1.position.x = 1.1;
  target_pose1.position.y = -0.1;
  target_pose1.position.z = 0.080;
  group.setPoseTarget(target_pose1);
  success = (group.plan(my_plan)==moveit::planning_interface::MoveItErrorCode::SUCCESS);
  ROS_INFO("Visualizing plan 6 (pose goal) %s",success?"":"FAILED");    
  sleep(5.0);
if(success)
     group.execute(my_plan);

  ros::shutdown();  
  return 0;
}
