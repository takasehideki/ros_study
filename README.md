# ros_study
ROS講習会用のソースファイル

まずはgitをインストールし，本リポジトリを`clone`しておいてください．

```bash
$ sudo apt install git
$ git clone https://github.com/takasehideki/ros_study
```

下記の項目はブランチ名に対応しています．
適宜で`git checkout`してご確認ください．

## インストール・環境構築

- `install`: 
  - 講習会用の環境構築の手引きです
  - 詳細は[install/README.md](./install/README.md)をご覧ください

- `2`: 「2. ROSの基本的な仕組み」実習の[ソースコード等](./ros1_melodic)
  - `2-1`: ワークスペースの設定
  - `2-2`: pubsub_topicパッケージの作成
  - `2-3`: pubsub_topicパッケージの実装
