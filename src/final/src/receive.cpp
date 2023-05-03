#include <rclcpp/rclcpp.hpp> 
#include <sensor_msgs/msg/laser_scan.hpp>
#include <vector>
#include <iostream>

rclcpp::Node::SharedPtr nodeh;
std::vector<vector<float>> regularMap;
std::vector<float> tempDistance = NULL;
std::vector<float> tempPose = NULL;
std::vector<float> tempPose = NULL;


void receiveDistance(const sensor_msgs::msg::LaserScan::SharedPtr msg){
	std::vector<float> temp = msg->ranges;
	if(tempPose != NULL){

	}
}



int main(int argc,char **argv) {
	rclcpp::init(argc,argv);

	nodeh = rclcpp::Node::make_shared("posesensor");
	auto sub = nodeh->create_subscription<sensor_msgs::msg::LaserScan>
		("scan",1000,&receiveDistance);
	// TODO: Implement the other callback to get POSE
	// auto sub = nodeh->create_subscription<sensor_msgs::msg::LaserScan>
	// ("scan",1000,&receiveScan);

	rclcpp::spin(nodeh);
	rclcpp::shutdown();

	rclcpp::shutdown();
	return 0;

}
