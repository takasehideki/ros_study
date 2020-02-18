# ROS 2用TurtleBot3パッケージのインストール

ROS公式の研究・教育用ロボット組立キットであるTurtleBot3について，ROS 2用のパッケージをインストールします．本内容は実習項目としては扱いませんが，手元の環境で再現されたい場合にはご利用ください．
[公式ページの情報](http://emanual.robotis.com/docs/en/platform/turtlebot3/ros2/)もご参照ください．

本手順は，ROS 1 (Melodic)の環境設定されたターミナルで実行すると不具合が起きる可能性があります．ROS 1が設定されているかを確認するには，

```bash
$ echo $ROS_DISTRO
```

を実行して，何も表示されないことを確認してください．
`melodic`等が表示される場合は，いったんターミナルを閉じて再び開いてください．

## 依存ライブラリのインストール 

ROS 2用のTurtleBot3パッケージで採用されているSLAMライブラリである`Cartographer`に依存するライブラリをインストールします．

```bash
$ sudo apt install -y \
    google-mock \
    libceres-dev \
    liblua5.3-dev \
    libboost-dev \
    libboost-iostreams-dev \
    libprotobuf-dev \
    protobuf-compiler \
    libcairo2-dev \
    libpcl-dev \
    python3-sphinx
```

ROS 2の自己位置推定や経路探索を含むパッケージである`navigation2`に依存するライブラリをインストールします．

```bash
$ sudo apt install -y \
    libsdl-image1.2 \
    libsdl-image1.2-dev \
    libsdl1.2debian \
    libsdl1.2-dev
```

ROS 2用TurtleBot3パッケージに依存するパッケージを個別インストールします．

```bash
$ sudo apt install ros-dashing-test-msgs
$ sudo apt install ros-dashing-tf2-sensor-msgs
```

TurtleBot3実機との時刻同期のためのNTPをインストールして設定します．

```bash
$ sudo apt-get install ntpdate
$ sudo ntpdate ntp.ubuntu.com
```

## パッケージのインストール

ROS 2用のTurtleBot3パッケージをインストールします．

```bash
$ source /opt/ros/dashing/setup.bash
$ mkdir -p ~/turtlebot3_ws/src
$ cd ~/turtlebot3_ws
$ wget https://raw.githubusercontent.com/ROBOTIS-GIT/turtlebot3/ros2/turtlebot3.repos
$ vcs import src < turtlebot3.repos
$ colcon build --symlink-install
```

ROS 2用のTurtleBot3パッケージの導入手順は以上です．

### 追記

Gazebo用パッケージ，Cartographer (SLAM)とNavigation2のパッケージをインストールします．


```bash
$ sudo apt install ros-dashing-gazebo-*
# Install Cartographer
$ sudo apt install ros-dashing-cartographer
$ sudo apt install ros-dashing-cartographer-ros
# Install Navigation2
$ sudo apt install ros-dashing-navigation2
$ sudo apt install ros-dashing-nav2-bringup
# Install vcstool
$ sudo apt install python3-vcstool
```

[目次に戻る](./README.md)
