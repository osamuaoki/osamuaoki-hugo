# BCCWJデーターの解析と利用

## 概要

このスクリプト群はBCCWJデーターを解析し、NLPや日本語に関する知見の薄い
私が状況認識をするとともに、その利用方法を考えるネタを作成する事を目的
としています。

元データーは含まれず、以下からダウンロードされます：

  * https://pj.ninjal.ac.jp/corpus_center/bccwj/freq-list.html
  * https://pj.ninjal.ac.jp/corpus_center/bccwj/data-files/frequency-list/BCCWJ_frequencylist_suw_ver1_0.zip
  * https://pj.ninjal.ac.jp/corpus_center/bccwj/data-files/frequency-list/BCCWJ_frequencylist_luw_ver1_0.zip

## 使用法（事前準備）

リモートアクセス可能な環境で、必要ファイルを`./data/`にダウンロードし、
閲覧可能な形式まで展開されます。

```
 $ make get
```

### 入力ファイル形式(BCCWJ)



0. rank BCCWJ 全体の順位（同順、飛び順あり）
1. lForm 語彙素読み
2. lemma 語彙素
3. pos 品詞
4. subLemma 語彙素細分類
5. wType 語種
7. pmw BCCWJ 全体での 100 万語当たりの頻度
89. core_pmw コアデータにおける 100 万語当たりの頻度


## 使用法（本格解析）

`./data/`にある閲覧可能な形式まで展開されたファイルを解析して、有用な
データーを作成されます。
```
 $ make analyze
```


### 出力ファイル


順位と語彙頻度の関係＊（分野無視）

rank 順位（同順あり）
lForm　辞書形（カタカナ）ZZ
lemma   pos     subLemma        wType   frequency       pmw



