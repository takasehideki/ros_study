# ROS 2 dashing diademataのインストール手順

ROS 2 dashing diademataのインストール手順を説明します．
[公式ページの情報](https://index.ros.org//doc/ros2/Installation/Dashing/Linux-Install-Debians/)もご参照ください．

本手順は，ROS 1 (Melodic)の環境設定されたターミナルで実行すると不具合が起きる可能性があります．ROS 1が設定されているかを確認するには，

```bash
$ echo $ROS_DISTRO
```

を実行して，何も表示されないことを確認してください．
`melodic`等が表示される場合は，いったんターミナルを閉じて再び開いてください．

## インストール前の準備

まずはLocaleを設定します．

```bash
$ sudo locale-gen en_US en_US.UTF-8
$ sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
$ export LANG=en_US.UTF-8
```

ROS 2用のDebian Packagesをインストールするための設定，gpg鍵の取得を行います．

```bash
$ sudo apt update && sudo apt install curl gnupg2 lsb-release
$ curl http://repo.ros2.org/repos.key | sudo apt-key add -
```

ROS 2パッケージをインストールできるように`sources.list`を設定します．

```bash
$ sudo sh -c 'echo "deb [arch=amd64,arm64] http://packages.ros.org/ros2/ubuntu `lsb_release -cs` main" > /etc/apt/sources.list.d/ros2-latest.list'
```

ROS 2に依存する各種ツールをインストールします．

```bash
$ sudo apt update && sudo apt install -y \
  build-essential \
  cmake \
  git \
  python3-colcon-common-extensions \
  python3-pip \
  python-rosdep \
  python3-vcstool \
  wget

# install some pip packages needed for testing
$ python3 -m pip install -U \
  argcomplete \
  flake8 \
  flake8-blind-except \
  flake8-builtins \
  flake8-class-newline \
  flake8-comprehensions \
  flake8-deprecated \
  flake8-docstrings \
  flake8-import-order \
  flake8-quotes \
  pytest-repeat \
  pytest-rerunfailures \
  pytest \
  pytest-cov \
  pytest-runner \
  setuptools

# install Fast-RTPS dependencies
$ sudo apt install --no-install-recommends -y \
  libasio-dev \
  libtinyxml2-dev
```

最後に，Debianパッケージを最新のものにアップデートします．

```bash
$ sudo apt update
$ sudo apt upgrade
```

## ROS 2 Dashing環境のインストール

Desktopのfull versionをインストールします．

```bash
$ sudo apt install ros-dashing-desktop
```

ターミナル上でros2コマンドをオートコンプリートで補完できるようにします．

```bash
$ sudo apt install python3-argcomplete
```

## 環境設定（非推奨）

公式ページでの解説では，ここでROSの環境変数を.bashrcに追加することが推奨されています．しかし，複数のROS Distribution，特にROS 2とROS 1を同一PCで使い分けする際には，本項目を設定させることは避けたほうがよいです．
ひとまず環境設定の方法は記載しておきます．

```bash
$ echo "source /opt/ros/dashing/setup.bash" >> ~/.bashrc
$ source ~/.bashrc
```

## 動作確認

下記のコマンドを実行してエラー無く動作できれば，ROS 2の導入は問題なく完了しています．

```bash
$ source /opt/ros/dashing/setup.bash
$ ros2 run demo_nodes_cpp talker
```

ROS 2 Dashingの導入手順は以上です．

[目次に戻る](./README.md)
