from nytimesarticle import articleAPI
import json
from pprint import pprint
from collections import defaultdict
import string
import os
import sys

'''from lxml import html
import requests
import urllib
import re'''

api = articleAPI('e4ec2febf01140cf80540ae9b73f7fe8')
stockName = raw_input("Enter the stock name:")
stockFile = open(stockName +".txt", "w")
page_num = 0
articles = {}
while page_num < 10:
    articles = api.search( q = stockName, fq = {'headline':stockName, 'source':['Reuters','AP', 'The New York Times']}, begin_date = 20160525,fl = 'headline,pub_date,web_url',page=page_num)
    page_num += 1
    stockFile.write(str(articles))
d = defaultdict(int)
for word in str(articles).split():
    d[word] += 1

stockFile = open(stockName +".txt")
stockList = stockFile.readlines()


dateFile = open("date.txt")
dateList = dateFile.readlines()

docs =  articles["response"]["docs"]
headline_dates = []
headlines = {}
for i in docs:
    headline_dates = i["pub_date"]
    newHeadlineDates = i["pub_date"][:10]
    dateFiles = open("dateFile.txt","w")
    for sDate in dateList:
        finalDate = str(sDate)[:10]
        dateFiles.write(finalDate)
        if str(newHeadlineDates) == finalDate:
            #print i["headline"]["main"]
            #print i["pub_date"]
            headlines[i["headline"]["main"]] = finalDate

wordFile = open("wordFile.txt","w")
words = []
merged_list = ""
temp = ""
finalsplit = ""
split_words = ""
for my_word, my_date in headlines.iteritems():
    split_words = my_word.split(' ')
    for each_word in split_words:
        each_word = each_word + " " +  str(my_date) + "\n"
        newString = (each_word).replace(',', '')
        finalString = (newString).replace(';', '')
        wordFile.write(each_word)

run_command = raw_input("should we push to git: ")
print run_command
if run_command == "yes":
   # print "almost there"
    os.system("git status")


