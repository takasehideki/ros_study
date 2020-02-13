# ROS講習会用の環境構築

```bash
$ git checkout install
```

## 想定するインストール環境

- ホストOS：[Ubuntu 18.04.3 LTS 日本語Remixリリース](https://www.ubuntulinux.jp/download/ja-remix)
- dotfilesの用意
  - 講習会で環境を統一するためのdotfilesを用意しました．
  - 下記を実行してください．
  ```bash
  $ cd ~/ros_study
  $ cp install/dotfiles/.bashrc ~
  $ source ~/.bashrc
  ```

## ROS環境の構築（目次）

- [ROS 1 Melodic Morenia](./install_melodic.md)
- [ROS 2 Dashing Diademata](./install_dashing.md)
- [各種ツールのインストール](./install_tools.md)
  - colcon
  - Gazebo
  - ros1_bridge
  - Terminator, Gvim等
- [ROS 2用TurtleBot3パッケージのインストール](./install_tb3.md)

各インストール方法の詳細は，それぞれのリンクをご覧ください．
