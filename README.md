# 席替えプログラム

csvファイル読み込みに対応した席替えプログラムです。

## 準備
- 欠番，固定席情報が入った`input.csv`作成します．
- １行目にカンマ区切り(,)で欠番を入力します．
- ２行目以降に席の情報を入力します．
- 抽選対象の席には`0`，固定席には該当出席番号，空席には`-1`を入力します．
```
10,19,23,25,26,33,43,45,50,57,58,59,60
0,0,44,17,42,0
0,0,0,0,0,0
0,0,0,0,0,0
0,0,0,0,0,0
0,0,0,0,0,0
0,0,0,0,0,0
0,0,0,0,0,0
-1,0,0,0,0,0
```

## 使用方法
- `change-seats.cpp`をコンパイルしてください．
```
c++ change-seats.cpp -o change-seats
```
- `change-seats`を実行後，最初に乱数のseed値を入力します．`0`を入力すると現在時刻をseed値にします．
```
seed値を入力（0~4,294,967,295）（ 0:UNIX時間をseed値にします）
>>
```

- 入力後，抽選結果が表示されます．欠番，固定席が正しいかを確認してください．
``` 
欠番:10,19,23,25,26,33,43,45,50,57,58,59,60,
     [教卓]
47 56 44 17 42 54             
13 02 03 08 51 20             
24 01 07 53 12 09             
28 30 14 32 34 22             
38 39 36 31 21 46             
06 18 16 15 04 49             
37 55 11 48 27 05             
41 52 29 35 40                
抽選結果をoutput.csvに保存しました．
```
- 抽選結果は`output.csv`に出力されます．