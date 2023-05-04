/*
   Copyright 2023 Stefano Carpin

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <rclcpp/rclcpp.hpp> 
#include <final/navigation.hpp>
#include <iostream>
#include <math.h>   

#include <sensor_msgs/msg/laser_scan.hpp>
#include <vector>
#include <string>

rclcpp::Node::SharedPtr nodeh;
std::vector<float> tempDistance = std::vector<float>();

float pillar[9][2] = {
	{-1.1, -1.1}, {-1.1, 0}, {-1.1, 1.1}, 
	{0, 0}, {0, -1.1}, {0, 1.1}, 
	{1.1, 0}, {1.1, -1.1}, {1.1, 1.1}
};
float radius_pillar = 0.3;


void receiveDistance(const sensor_msgs::msg::LaserScan::SharedPtr msg){
	std::vector<float> temp = msg->ranges;
	for(int i = 0; i < 360; i++){
	}
}



std::string distance(float x, float y){
	bool match = false;
	float rad = radius_pillar * radius_pillar;
		for(int i = 0; i < 9; i++){
			float euclidian_dist = (pillar[i][0] - x) * (pillar[i][0] - x) + (pillar[i][1] - y) * (pillar[i][1] - y);
				if(euclidian_dist <  rad || y > 1.7 || y < -1.7 || x > 1.9 || x < -2.4 || x > 2.4 || (x < -1.9 && (y > 1 || y < -1)) || (x > 1.9 && (y > 1 || y < -1))){
					match = true;
				}
		}
	if(!match){
		return "x, y";
	}
	return "false";
}

int main(int argc,char **argv) {

	nodeh = rclcpp::Node::make_shared("receieve");
	rclcpp::init(argc,argv); // initialize ROS 
	Navigator navigator(true,false); // create node with debug info but not verbose

	auto sub1 = nodeh->create_subscription<sensor_msgs::msg::LaserScan>
		("scan",1000,&receiveDistance);
	rclcpp::spin(nodeh);

	// first: it is mandatory to initialize the pose of the robot
	geometry_msgs::msg::Pose::SharedPtr init = std::make_shared<geometry_msgs::msg::Pose>();
	init->position.x = -2;
	init->position.y = -0.5;
	init->orientation.w = 1;
	navigator.SetInitialPose(init);
	// wait for navigation stack to become operationale
	navigator.WaitUntilNav2Active();
	// spin in place of 90 degrees (default parameter)
	navigator.Spin();
	while ( ! navigator.IsTaskComplete() ) {
		// busy waiting for task to be completed
	}
	geometry_msgs::msg::Pose::SharedPtr goal_pos = std::make_shared<geometry_msgs::msg::Pose>();
	goal_pos->position.x = 2;
	goal_pos->position.y = 1;
	goal_pos->orientation.w = 1;
	// move to new pose
	navigator.GoToPose(goal_pos);
	while ( ! navigator.IsTaskComplete() ) {

	}
	goal_pos->position.x = 2;
	goal_pos->position.y = -1;
	goal_pos->orientation.w = 1;
	navigator.GoToPose(goal_pos);
	// move to new pose
	while ( ! navigator.IsTaskComplete() ) {

	}
	// backup of 0.15 m (deafult distance)
	navigator.Backup();
	while ( ! navigator.IsTaskComplete() ) {

	}

	// complete here....

	rclcpp::shutdown(); // shutdown ROS
	return 0;
}
