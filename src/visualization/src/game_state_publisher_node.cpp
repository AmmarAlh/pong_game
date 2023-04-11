#include "rclcpp/rclcpp.hpp"
#include "game_msgs/msg/game_state.hpp"

#include <random>

class GameStatePublisher : public rclcpp::Node
{
public:
  GameStatePublisher()
  : Node("game_state_publisher")
  {
    publisher_ = this->create_publisher<game_msgs::msg::GameState>("game_state", 10);
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(100),
      std::bind(&GameStatePublisher::publishGameState, this)
    );
  }

private:
  void publishGameState()
  {
    auto msg = std::make_shared<game_msgs::msg::GameState>();

    // Simulate game state updates with random data
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> pos_dist(0, 100);
    std::uniform_int_distribution<> score_dist(0, 10);

    msg->bat_left_pos_y = pos_dist(gen);
    msg->bat_right_pos_y = pos_dist(gen);
    msg->ball_pos_x= pos_dist(gen);
    msg->ball_pos_y = pos_dist(gen);
    msg->score_left = score_dist(gen);
    msg->score_right = score_dist(gen);

    RCLCPP_INFO(this->get_logger(), "Publishing game state");
    publisher_->publish(*msg);
  }

  rclcpp::Publisher<game_msgs::msg::GameState>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GameStatePublisher>());
  rclcpp::shutdown();
  return 0;
}
