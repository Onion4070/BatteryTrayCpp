# Battery Tray Cpp
## はじめに
以前のBattery Trayが言語がJavaのため若干処理が重たかったのでC++にて再作成しました．
C++は1ﾐﾘも理解してないのであしからず...

## 機能
機能面はあくまでも基本的なものしか実装されていません．実装予定は未定です．理解してないのでプルリクでも飛ばしてください．

## 使い方
適当なディレクトリに保存してショートカットを`shell:startup`に配置してください．  
残念ながら終了するボタン等ないのでタスクマネージャからキルしてあげてください．

## 現状の課題
- 終了ボタンがない  
    タスクキルしかないです...  

- ~~バッテリ残量の背景色が黒~~  
    ~~アルファチャンネル云々頑張ってみたけどだめでした. 現状多分黒背景を描画した上に文字を描画してってるはずなので背景描画から変えないとだめです．背景透明できたものの文字まで透明になって萎えました．~~

- ~~うまく実行できない環境でエラーが出ない~~  
    ~~対処法わからんです~~

- 残量による色変更が不可  
    急ぎならソース書き換えてコンパイルしてください

- 電源接続時に表示が変化しない
    いずれ作るかもしれない

## Change Log
- 2024-07-19  
    バッテリー残量が10%未満の場合の表示を修正

- 2024-07-15  
    バッテリ残量の背景を透過  
    バッテリ残量が不正な値をとった際にプログラムを終了

- 2024-07-12  
    必要最低限の作成