from collections import defaultdict
import random
import time
filename = "frank10.txt"

f = open(filename, 'r')

markovMatrix = defaultdict(dict)

starters = []
enders = []

for line in f:
    splitLine = line.replace(",","").split()
    i = 0
    while i < len(splitLine) - 1:

        #get 2 adjacent words
        first = splitLine[i]
        second = splitLine[i+1]
        #check for edge words
        if "." in first:
            starters += [second]
            enders += [first]
            i += 1
            continue
        elif "." in second:
            enders += [second]

        #add to adjacent word matrix
        if first in markovMatrix.keys():
            if second in markovMatrix.get(first):
                markovMatrix[first][second] += 1
            else:
                markovMatrix[first][second] = 1
        else:
            markovMatrix[first][second] = 1
        i += 1

#given a 1D dictionary, pick one key weighted random based on the values
def weightedChoice(dict):
    pool = []
    for key in dict.keys():
        for i in range(0,dict[key]):
            pool += [key]
    return random.choice(pool)

def makeTweet():
    tweet = [random.choice(starters)]
    for i in range(0,280):

        if markovMatrix.get(tweet[i]) == None:
            tweet += [random.choice(enders)]
            break
        nextWord = weightedChoice(markovMatrix.get(tweet[i]))
        tweet += [nextWord]
        if nextWord in enders:
            break
    print " ".join(tweet)


for i in range(0,3):
    makeTweet()
    print "\n"

