# dictionary-C-Bloom-filter (In work)

Program that upload .txt dictionary file and check another texts in .txt format for words that isn't in the dictionary.

It uses [bloom filter](https://en.wikipedia.org/wiki/Bloom_filter) to upload dictionary words in the array and then search them very fast.

directory kays/ contains expected result of our output.

derectory dictionaries/ contains 2 dictionaries small and large.

directory texts/ contains texts that we wont to check.

to start the programe type: ./speller texts/text_that_you_want_to_check.txt (in that case programe will upload by default large dictionary)

to start small dictionnary type: ./speller dictionaries/small texts/text_that_you_want_to_check.txt
