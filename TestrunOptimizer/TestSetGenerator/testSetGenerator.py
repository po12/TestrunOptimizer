import sys
from test import CsvGenerator
from scipy.stats import gamma, beta, norm, uniform, truncnorm
from scipy import mean
import datetime
import numpy

assert len(sys.argv) == 5, "You need to pass 4 parameters: \n1)filename \n2)number of tests \n3)max duration \n4)number of runs"
filename  = sys.argv[1]
num_of_tests, max_duration, num_of_runs = map(int, sys.argv[2:])

print ("filename %s\n num_of_tests %d\n max_duration %d\n num_of_runs %d\n" % (filename, num_of_tests, max_duration, num_of_runs))

class TestSetGenerator:
    def __init__(self, filename, num_of_tests, max_duration, num_of_runs):
        self.filename = filename
        self.num_of_tests = num_of_tests
        self.max_duration = max_duration
        self.num_of_runs = num_of_runs
        self.generator = CsvGenerator(filename, num_of_tests, max_duration, num_of_runs)

    def convToTime(self, entry):
        return str(datetime.timedelta(hours=entry)).rsplit(':',1)[0]

    def createDistribution(self, distributionCalc):
        output = dict()
        for test_id in range(1, self.num_of_tests):
            distribution_specific_time = list(map(self.convToTime, distributionCalc()))
            output[test_id] = distribution_specific_time

        self.generator.generateFromData(output)

    def normalDistribution(self):
        data = norm.rvs(size = self.num_of_runs , loc = 0, scale = self.max_duration)
        mu = mean(data)
        sigma = numpy.std(data)
        lower, upper = 0, self.max_duration
        return truncnorm.rvs((lower-mu)/sigma,(upper-mu)/sigma,loc=mu,scale=sigma,size=self.num_of_runs)

    def gammaDistribution(self):
        return gamma.rvs(1, size = self.num_of_runs)

    def betaDistribution(self):
        return beta.rvs(self.max_duration, 1, size = self.num_of_runs)

    def uniformDistribution(self):
        return uniform.rvs(size = self.num_of_runs , loc = 0, scale = self.max_duration)

setGenerator = TestSetGenerator(filename, num_of_tests, max_duration, num_of_runs)
setGenerator.createDistribution(setGenerator.betaDistribution)
