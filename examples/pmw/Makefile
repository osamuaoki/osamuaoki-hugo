SUBDIRS = data result01


SUW = BCCWJ_frequencylist_suw_ver1_1
LUW = BCCWJ_frequencylist_luw_ver1_1

# get data and clean it
data/$(SUW).tsv:
	cd data >/dev/null; wget https://pj.ninjal.ac.jp/corpus_center/bccwj/data-files/frequency-list/$(SUW).zip
	cd data >/dev/null; unzip $(SUW).zip

data/$(LUW).tsv:
	cd data >/dev/null; wget https://pj.ninjal.ac.jp/corpus_center/bccwj/data-files/frequency-list/$(LUW).zip
	cd data >/dev/null; unzip $(LUW).zip

get: data/$(SUW).tsv data/$(LUW).tsv

data/suw.tsv:
	cd data; ../bin/simple $(SUW).tsv > suw.tsv 2>suw-err.tsv

data/luw.tsv:
	cd data; ../bin/simple $(LUW).tsv > luw.tsv 2>luv-err.tsv

simple: data/suw.tsv data/luw.tsv
	cd data >/dev/null; wc -l *.tsv

pos: data/suw.tsv data/luw.tsv
	cd data >/dev/null; ../bin/pos suw.tsv >suw.stat
	#cd data >/dev/null; ../bin/pos luw.tsv >luw.stat

clean:
	rm -f data/suw.tsv data/luw.tsv
	rm -f data/suw-err.tsv data/luw-err.tsv

distclean:
	rm -rf data
