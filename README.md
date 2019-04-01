# 席替えプログラム

csvファイル読み込みに対応した席替えプログラムです。

## 準備
- `change-seats.cpp`12~14行目のマクロ定義を環境に合わせて変更します．
```cpp
#define MAX_NUM 56	//最大出席番号
#define INPUT_FILE "input.csv"	//入力ファイル名
#define OUPUT_FILE "output.txt"	//出力ファイル名
```
- 欠番，固定席情報が入った`input.csv`作成します．
- １行目にカンマ区切り(,)で欠番を入力します．
- ２行目以降に席の情報を入力します．
- 抽選対象の席には`0`，固定席には該当出席番号，空席には`-1`を入力します．（左詰めで処理するので，最右側の`-1`は不要です．）
```
4,10,18,19,23,25,26,30,33,36,37,38,43,45,46,50,52,53
0,0,0,0,0,0
0,0,0,0,0,0
0,0,0,0,0,0
0,0,0,0,0,0
0,0,0,0,0,0
0,0,0,0,0,0
-1,-1,0,0
```

## 使用方法
- `change-seats.cpp`をコンパイル・実行してください．
```
c++ change-seats.cpp -o change-seats
./change-seats
```
- 最初に乱数のseed値を入力します．`0`を入力すると現在時刻をseed値にします．
```
seed値を入力（0~4,294,967,295）（ 0:現在のUNIX時間をseed値にします）
>>
```

- 入力後，抽選結果が表示されます．欠番，固定席が正しいかを確認してください．
``` 
欠番:4 10 18 19 23 25 26 30 33 36 37 38 43 45 46 50 52 53
     [教卓]
20 06 11 24 32 13 
02 29 40 15 44 54 
39 48 56 28 55 27 
14 07 03 01 35 12 
08 51 47 31 21 22 
17 16 49 34 41 09 
      42 05                  
抽選結果をoutput.txtに保存しました．
```
- 抽選結果は`output.txt`に出力されます．