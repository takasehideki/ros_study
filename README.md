# ros_study
ROS講習会用のソースファイル

まずはgitをインストールし，本リポジトリを`clone`しておいてください．

```bash
$ sudo apt install git
$ git clone https://github.com/takasehideki/ros_study.git
```

下記の項目はブランチ名に対応しています．
適宜で`git checkout`してご確認ください．

## インストール・環境構築

- `install`: 
  - 講習会用の環境構築の手引きです
  - 詳細は[install/README.md](./install/README.md)をご覧ください

## 目次と実習内容

- `2`: 「2. ROSの基本的な仕組み」実習の[ソースコード等](./ros1_melodic)
  - `2-1`: ワークスペースの設定
  - `2-2`: pubsub_topicパッケージの作成
  - `2-3`: pubsub_topicパッケージの実装
  - `2-4`: 独自型ファイルの定義
  - `2-5`: pubsub_customパッケージの実装
  - `2-6`: human型にidを追加（演習P.36）
  - `2-7`: service_customパッケージの作成
  - `2-8`: service_customパッケージの実装
  - `2-9`: param_commパッケージの実装
  - `2-p`: pubsub_topic_pyパッケージ（Python実装）
  - `2-l`: service_customのroslaunch実行

- `4`: 「4. ROS 2によるプログラミング」実習の[ソースコード等](./ros2_dashing)
  - `4-1`: ワークスペースの設定
  - `4-2`: pubsub_topicパッケージの作成
  - `4-3`: pubsub_topicパッケージの実装
  - `4-4`: 独自定義型ライブラリros_study_typesの実装
  - `4-5`: pubsub_customパッケージの実装
  - `4-6`: 独自定義型のメッセージの変更
  - `4-7`: 独自定義型のサービスの作成
  - `4-8`: service_customパッケージの実装
  - `4-l`: service_customのroslaunch実行
  - `4-a`: action_customパッケージの実装
  - `4-c1`: pubsub_componentパッケージの実装
  - `4-c2`: pubsub_compositionパッケージの実装
  - `4-ca`: pubsub_compositionパッケージのlistener実装

## 参考にしたリポジトリ／利用しているソース

- https://github.com/ros/ros_tutorials
- https://github.com/ros2/examples

