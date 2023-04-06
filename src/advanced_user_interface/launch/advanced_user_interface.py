from launch import LaunchDescription
from launch_ros.actions import Node

width = 480
height = 360

def generate_launch_description():
    return LaunchDescription([
       Node(
            package='advanced_user_interface',
            executable='light_position_detection',
            name='light_position_detection',
            parameters=[
                {'brightness_threshold': 250},
                {'roi_origin': [0, 0]},
                {'roi_size': [int(width/2), height]}
            ]
        ),

        Node(
            package='image_tools',
            executable='cam2image',
            parameters=[{"depth": 1}, {"history": "keep_last"}, {"height": height},{"width":width}],
            remappings=[("image", "webcam_input")]
        )
    ])
