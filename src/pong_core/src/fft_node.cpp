#include <vector>
#include <stdexcept>
#include <chrono>
#include <memory>
#include <iostream>
#include <random>
#include "ffft/FFTRealFixLen.h"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"

#define LN_FFT_SIZE 8   // set the FFT size to 2^8 = 256
#define FFT_SIZE 1<<LN_FFT_SIZE  // calculate the FFT size
#define ALIGNMENT 128   // set the memory alignment for FFT computation

class FFTNode : public rclcpp::Node
{
public:
    FFTNode() : Node("fft_node")
    {
        pub_fft_ = this->create_publisher<std_msgs::msg::Float32MultiArray>("fft_results", 10);
        
        // Create a timer that triggers the 'timer_callback' function every 500 milliseconds
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&FFTNode::timer_callback, this));
    }

private:
    void timer_callback()
    {
        std_msgs::msg::Float32MultiArray msg;  // Create multi-array message
        msg.layout.dim.push_back(std_msgs::msg::MultiArrayDimension());  // Add array dimension
        msg.layout.dim[0].label = "freq";  // Set label for first dimension
        msg.layout.dim[0].size = (FFT_SIZE / 2) + 1;  // Set size for first dimension
        msg.layout.dim[0].stride = 1;  // Set stride for first dimension (default value)
        msg.data.resize(msg.layout.dim[0].size);  // Resize data array to match the size of the first dimension


        // Generate random values
        std::vector<float> input(FFT_SIZE);
        // Create a default random engine and seed it with the current time since epoch. 
        // Otherwise it will always return the same value since the generator is always initialized the same way
        // If you want the same values use this instead: std::default_random_engine generator;
        std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_real_distribution<float> distribution(-1.0, 1.0);
        for (int i = 0; i < FFT_SIZE; i++) {
            input[i] = distribution(generator);
        }


        // Perform FFT
        fft_object.do_fft(msg.data.data(), input.data());
        
        // Publish FFT values
        pub_fft_->publish(msg);

        // Print FFT values in console for debugging
        std::cout << "FFT values: ";
        for (auto val : msg.data) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    ffft::FFTRealFixLen<LN_FFT_SIZE> fft_object;
    rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr pub_fft_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<FFTNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
