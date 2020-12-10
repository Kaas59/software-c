# プロジェクト名

software-c

## 概要

電話交換機

## ファイル構成

```bash
software-c/
├── devcontainer/
│     └── devcontainer.json   remote-container設定ファイル
├── build/*                   GoogleTestビルドファイル
├── googlemock/*              GoogleTest関連ファイル
├── googletest/*              GoogleTest関連ファイル
├── main/
│     ├── header.h            開発ヘッダファイル
│     └── *.o                 開発オブジェクトファイル（初期）
├── src/
│     ├── header.h            開発ヘッダファイル
│     └── *.c                 開発プロジェクトファイル
├── test/
│     └── test.cpp            テストコード
├── .gitignore
├── .tavis.yml
├── appveyor.yml
├── CMakeLists.txt
├── README.md
└── travis.sh
```

## コンパイル方法

```bash
//オブジェクトファイルの作成方法
$ gcc -c <ファイル名>.c

//実行ファイルの作成方法
$ gcc *.o
```

## テストコード

cmakeの環境設定している端末でしか確認出来ません。

```bash
$ cd build
$ cmake ../
$ make
$ make test
````
