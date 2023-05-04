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

float min = -1;

float mins[17]= {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
float points[17][2] = {{1.6, -1.6}, {0.6, -1.8}, {0, -2.4}, {-0.6, -1.8}, {-1.6, -1.6}, {-1.8, -0.8}, {-0.5, -0.5}, {0.5, -0.5}, {1.8, -0.8}, {1.8, 0.8}, {0.5, 0.5}, {-0.5, 0.5}, {-1.8, 0.8}, {-1.5, 1.5}, {-0.5, 1.75}, {0.5, 1.75}, {1.5, 1.5}};


void receiveDistance(const sensor_msgs::msg::LaserScan::SharedPtr msg){
	min = 99999;
	std::vector<float> temp = msg->ranges;
	for(int i = 0; i < 360; i++){
	if (temp[i] < min) min = temp[i];
	}
}


int main(int argc,char **argv) {
	rclcpp::init(argc,argv); // initialize ROS 
	
	std::cout << "test";

	
	nodeh = rclcpp::Node::make_shared("receieve");
	geometry_msgs::msg::Pose::SharedPtr init = std::make_shared<geometry_msgs::msg::Pose>();
	geometry_msgs::msg::Pose::SharedPtr goal_pos = std::make_shared<geometry_msgs::msg::Pose>();
	std::cout << "test";
	rclcpp::spin(nodeh);
	Navigator navigator(true,false); // create node with debug info but not verbose

	auto sub1 = nodeh->create_subscription<sensor_msgs::msg::LaserScan>
		("scan",1000,&receiveDistance);
	rclcpp::spin(nodeh);

	// first: it is mandatory to initialize the pose of the robot
	std::cout << "test";
	init->position.x = -2;
	init->position.y = -0.5;
	init->orientation.w = 1;
	
	navigator.SetInitialPose(init);
	// wait for navigation stack to become operationale
	navigator.WaitUntilNav2Active();
	// spin in place of 90 degrees (default parameter)
	navigator.Spin();
	
	
	
	
	
	
	std::cout << "test";
	
	for(int i = 0; i < 17; i++) {
		while ( ! navigator.IsTaskComplete() ) {
		// busy waiting for task to be completed	
		
		}
		
		goal_pos->position.x = points[i][0];
		goal_pos->position.y = points[i][1];
		goal_pos->orientation.w = 1;
		
		rclcpp::spin(nodeh);
		std::string returnedString = "Found new min at point " + std::to_string(i) + ", value " + std::to_string(min) + ".";
		
		if(min < mins[i]) {
			std::cout << returnedString;
		}
		// move to new pose
		navigator.GoToPose(goal_pos);
	}


	// complete here....

	rclcpp::shutdown(); // shutdown ROS
	return 0;
}
