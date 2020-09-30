# ROS install

[설치페이지 안내](http://wiki.ros.org/melodic/Installation/Ubuntu)



`sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'`



`sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654`



`sudo apt update`



`sudo apt install ros-melodic-desktop-full`



`sudo apt-get install python-pip`



`sudo pip install -U rosdep`



`sudo rosdep init`



`rosdep update`



`echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc`



`source ~/.bashrc`



`source /opt/ros/melodic/setup.bash`



`sudo apt install python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential`



### 실행 확인

`roscore`

`rosrun turtlesim turtlesim_node`

`ros turtlesim turtle_teleop_key`



