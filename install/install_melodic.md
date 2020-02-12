# ROS 1 Melodic Moreniaのインストール手順

ROS 1 Melodic Moreniaのインストール手順を説明します．
[公式ページの情報](http://wiki.ros.org/melodic/Installation/Ubuntu)もご参照ください．

## インストール前の準備

まずはROSパッケージ用の配布サイトからソフトウェアをインストールできるように`sources.list`を設定します．

```bash
$ sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
```

ROSパッケージをダウンロードする際に使用するgpg鍵を取得します．

```bash
$ sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
```

Debianパッケージを最新のものにアップデートします．

```bash
$ sudo apt update
$ sudo apt upgrade
```

Ubuntuをインストールしたばかりの環境では，upgrade前に`sudo dpkg --configure -a`の実行が必要となることがあります．

## ROS Melodic環境のインストール

(Gazeboシミュレーションツールを含む)Desktop版のfull versionをインストールします．

```bash
$ sudo apt install ros-melodic-desktop-full
```

ROSを使用可能にするために，rosdepを初期化します．
rosdepはコンパイル対象となるソースのシステム依存のインストールを簡易化し，ROSのコアコンポーネントを実行するために必須となります．

```bash
$ sudo rosdep init
$ rosdep update
```

## 環境設定（非推奨）

公式ページでの解説では，ここでROSの環境変数を.bashrcに追加することが推奨されています．しかし，複数のROS Distribution，特にROS 2とROS 1を同一PCで使い分けする際には，本項目を設定させることは避けたほうがよいです．  
本実習では `ros1setup` というalias関数を [.bashrc](./dotfiles/.bashrc) に設けてあります．ひとま公式ページで紹介されている環境設定の方法は記載しておきます．

```bash
$ echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
$ source ~/.bashrc
```

## ROSパッケージのビルドのための設定

ROSパッケージをインストール／ビルドするためのツールである`rosinstall`等のツールをインストールします．

```bash
$ sudo apt install python-rosinstall python-rosinstall-generator python-wstool build-essential
```

## 動作確認

下記のコマンドを実行してエラー無く動作できれば，ROS 1の導入は問題なく完了しています．

```bash
$ ros1setup
$ roscore & sleep 1 ; rosrun roscpp_tutorials talker 
```

ROS 1 Melodicの導入手順は以上です．

[目次に戻る](./README.md)
