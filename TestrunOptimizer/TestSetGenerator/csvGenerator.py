from random import randint
import csv

class CsvGenerator:
    def __init__(self, filename, num_of_tests, max_duration, num_of_runs):
        self.filename = filename
        self.num_of_tests = num_of_tests
        self.max_duration = max_duration
        self.num_of_runs = num_of_runs
        self.labels = ["Test ID", "Duration"]
        self.writer = csv.DictWriter(open(filename, "w+"), delimiter =',', quoting=csv.QUOTE_MINIMAL, fieldnames = self.labels, lineterminator='\n')

    def genTestId(self):
        return randint(1, self.num_of_tests)

    def genDuration(self):
        hours=randint(0, self.max_duration)
        minutes = 0
        if hours is not self.max_duration:
            minutes = randint((1 if hours is 0 else 0), 60)
        return "%d:%02d" % (hours, minutes)

    def writeRow(self, test_id, test_duration):
        self.writer.writerow(dict([
                                (self.labels[0], test_id),
                                (self.labels[1], test_duration)]))
    def generateFile(self):
        for i in range(self.num_of_runs):
            self.writeRow(self.genTestId(), self.genDuration())

    def generateFromData(self, data):
        for key in data:
            [self.writeRow(key, test_duration) for test_duration in data[key]]
