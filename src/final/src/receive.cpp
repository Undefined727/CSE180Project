#include <rclcpp/rclcpp.hpp> 
#include <sensor_msgs/msg/laser_scan.hpp>
#include <vector>
#include <iostream>

rclcpp::Node::SharedPtr nodeh;
std::vector<std::vector<float>> regularMap;
std::vector<float> tempDistance = std::vector<float>();
std::vector<float> tempPose = std::vector<float>();


void receiveDistance(const sensor_msgs::msg::LaserScan::SharedPtr msg){
	std::vector<float> temp = msg->ranges;
}



int main(int argc,char **argv) {
	rclcpp::init(argc,argv);

	nodeh = rclcpp::Node::make_shared("receieve");
	auto sub1 = nodeh->create_subscription<sensor_msgs::msg::LaserScan>
		("scan",1000,&receiveDistance);

	rclcpp::spin(nodeh);
	rclcpp::shutdown();

	rclcpp::shutdown();
	return 0;

}
