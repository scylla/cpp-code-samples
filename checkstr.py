import os
import sys

f1 = open("testout.txt", "rb")
f2 = open("out7.txt" , "rb")

l1 = f1.readlines()
l2 = f2.readlines()

print len(l1[0].strip())
print len(l2[0].strip())

print l1[0].strip() == l2[0].strip()
count = 0

for x in xrange(len(l1[0])):
	if l1[0][x] != l2[0][x]:
		count += 1
		print x, l1[0][x], l2[0][x]

print count
