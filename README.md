# プロジェクト名

software-c

## 概要

電話交換機

## ファイル構成

```bash
software-c/
├── devcontainer/
│     └── devcontainer.json   remote-container設定ファイル
├── main/
│     ├── header.h            開発ヘッダファイル
│     └── *.o                 開発オブジェクトファイル（初期）
├── src/
│     ├── header.h            開発ヘッダファイル
│     └── *.c                 開発プロジェクトファイル
├── .gitignore
└── README.md
```

## コンパイル方法

```bash
//オブジェクトファイルの作成方法
$ gcc -c <ファイル名>.c

//実行ファイルの作成方法
$ gcc *.o
```

## テストコード

環境作成中
