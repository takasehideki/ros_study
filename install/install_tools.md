# 各種ツールのインストール手順

ROS 2 dashing diademataのための各種ツールのインストール手順を説明します．
- colcon
- Gazebo
- ros1_bridge
- Terminator, Gvim等

## colconのインストール

ROS 2のビルドツールである`colcon`をインストールします．

```bash
$ sudo apt install python3-colcon-common-extensions
```

## Gazebo

3D物理シミュレータであるGazeboをインストールします．
ROS 1 Melodicの導入時にもインストールはされますが，ROS 2 Dashing対応のために最新版に更新しておきます．

```bash
$ curl -sSL http://get.gazebosim.org | sh
$ sudo apt upgrade libignition-math2
```

## ros1_bridgeのインストール

ROS 1とROS 2のそれぞれのノードを通信するためのツールである`ros1bridge`をインストールします．

```bash
$ sudo apt install ros-dashing-ros1-bridge
```

## その他のインストール

### Terminator

ROSの開発・実行時には多くのターミナルを同時に開くことがあります．このような時のために`terminator`をインストールしておくと便利です．

```bash
$ sudo apt install terminator
```

Terminatorでは，下記のショートカットが有用です．

- Ctrl+Shift+O: ターミナルの水平分割
- Ctrl+Shift+E: ターミナルの垂直分割
- Ctrl+Tab: 次のターミナルへ
- Ctrl+Shift+Tab: 前のターミナルへ

### エディタ

ご自身で好みのエディタをインストールしましょう．
私はVimが好きです．

```bash
$ sudo apt install vim-gnome
```

各種ツールの導入手順は以上です．

[目次に戻る](./README.md)
