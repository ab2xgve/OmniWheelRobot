日付：2021/2/24
Font Utf-8

全方向移動ロボット(オムニホイール)をUDP通信で駆動させるためのプログラム

実行手順
  1. ターミナル上でフォルダ「OmniWheelRobot」へ移動
  2.“sudo pigpiod” をターミナルに入力
  3. フォルダ「config」内の「UDPconfig.txt」を次のように上書き
      ・1行目:送信元のIPアドレス(もしくは 0.0.0.0←推奨)
      ・2行目:送信元で指定したポート番号
  4. フォルダ「OmniWheelRobot」内でターミナルに”./OmniRobotGoGo”を入力
  5. ターミナルの表示が高速で更新されるようになるまで待機(20~30秒位)

コンパイル手順
  1.ターミナル上でフォルダ「OmniWheelRobot」へ移動
  2.ターミナルに“make” を入力

make cleanコマンドについて
 現存する.oファイルと実行ファイルを消すためのコマンド
 依存関係や実行結果がおかしくなったら試しに実行してみること.
 実行後は再度'make'で実行ファイルが再生成される. 

 手順
  1.ターミナル上でフォルダ「OmniWheelRobot」へ移動
  2.ターミナルに“make clean” を入力

ファイル構成
	├── Makefile       :ビルドするため
	├── OmniRobotGoGo  : 実行ファイル(makeで生成)
	├── archive　　　　: 外製ライブラリ
	│   ├── Makefile
	│   ├── bin
	│   │   ├── ADS1256.o
	│   │   └── DEV_Config.o
	│   ├── libads1256.a
	│   ├── obj
	│   │   ├── ADS1256.cpp
	│   │   ├── ADS1256.hpp
	│   │   ├── DEV_Config.cpp
	│   │   ├── DEV_Config.hpp
	│   │   └── Debug.hpp
	├── bin ##オブジェクトファイル##
	│   ├── MotorDrive.o
	│   ├── OmniRobot.o
	│   ├── TeamSpirit.o
	│   ├── TextReader.o
	│   └── UDP.o
	├── config
	│   ├── PID_GAIN_POSITION.txt :位置型PID用ゲイン
	│   ├── PID_GAIN_VELOCITY.txt :速度型PID用ゲイン
	│   ├── UDP_CONFIG.txt        :UDP通信の設定
	│   └── readme.txt
	├── obj ##ソース、ヘッダー##
	│   ├── CSVWrite.hpp               :csvファイルへの書き込み
	│   ├── MotorDrive.cpp             :モータのPWM駆動について
	│   ├── MotorDrive.hpp
	│   ├── OmniRobot.cpp              :オムニロボットの制御、駆動について(本プログラムの本体)
	│   ├── OmniRobot.hpp
	│   ├── MultiProcess.cpp           :マルチプロセスの制御とプロセス間(UDP-OmniRobot)通信について
	│   ├── MultiProcess.hpp
	│   ├── TextReader.cpp　　　　　　 : ./config 内のテキスト群の読み込みについて
	│   ├── TextReader.hpp
	│   ├── UDP.cpp　　　　  　  　　　：UDP無線通信について
	│   └── UDP.hpp
	├── plotter ##CSVファイルの読み込みとプロット##
	│   ├── Plotter  :実行ファイ:CSVファイルの入出力先
	│   ├── data :走行データ保存箇所    
	│   │   └── drive_data.csv  :CSVファイルの入出力先
	│   ├── Makefile
	│   ├── bin
	│   │   ├── CSVRead.o
	│   │   └── main.o
	│   ├── image
	│   └── obj
	│       ├── CSVRead.cpp
	│       ├── CSVRead.hpp
	│       ├── main.cpp
	│       └── matplotlibcpp.h
	└── readme_コピー.txt 

