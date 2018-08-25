import sys
from random import randint
import csv

assert len(sys.argv) == 5, "You need to pass 4 parameters: \n1)filename \n2)number of tests \n3)max duration \n4)number of runs"

filename  = sys.argv[1]
num_of_tests, max_duration, num_of_runs = map(int, sys.argv[2:])

print ("filename %s\n num_of_tests %d\n max_duration %d\n num_of_runs %d\n" % (filename, num_of_tests, max_duration, num_of_runs))

def genTestId():
	return randint(0, num_of_tests)

def genDuration():
	hours = randint(0, max_duration)
	minutes = randint((1 if hours is 0 else 0), 60)
	return "%d:%02d" % (hours, minutes)

labels = ["Test ID", "Duration"]
writer = csv.DictWriter(open(filename, "wb+"), delimiter =',', quoting=csv.QUOTE_MINIMAL, fieldnames = labels)

for i in range(num_of_runs):
	writer.writerow(dict([
		(labels[0], genTestId()),
		(labels[1], genDuration())
	]))
