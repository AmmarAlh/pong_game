#include "visualization/game_render.hpp"


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto game_render = std::make_shared<GameRender>();
  game_render->run();
  rclcpp::shutdown();
  return 0;
}
