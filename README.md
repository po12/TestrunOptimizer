# TestrunOptimizer

# Project structure

├── input (generated input files for optimizer UT)\
├── TestSetGenerator\
│     ├──  csvGenerator.py\
│     ├── testSetGenerator.py\
├── TestrunOptimizer\
│     ├── Code\
│         ├── Headers (all *.h files)\
│         ├── Sources (all *.cpp files with implementation)\
│     ├── Tests (all UT)


# Class Diagram

![alt text](https://raw.githubusercontent.com/po12/TestrunOptimizer/master/TestrunOptimizer/extras/optimizer_uml.JPG)

# Input data

In this solution csv format support is implemented. However it can be easily expanded with new formats by creating another Reader class derived from IFileReader. First column in file stands for test id and second for execution time. Execution time is stored in format "hh:mm". Example file can look like:

1, "0:04"\
1, "1:05"\
3, "2:05"

# Test set generator

For purpose of testing test set generator had been written. It consist of two python scripts:\
* csvGenerator - writes data to csv file,
* testSetGenerator - creates data with concrete distribution


Four distributions are supported: 
* truncated normal
* uniform
* beta
* gamma

# Solution

Solution is based on Strategy Design Pattern.  In base OptimizationStrategy class we are preparing data by creating map wih cutted-off abnormal values. Cutting is made by calculating third standard deviation - for normal distribution it leaves 99.7% of data. After preparation we are calculating new test run execution limit in chosen strategy. On purpose of this project MedianStrategy have been implemented. Further development of this project is easier due to Strategy Design Pattern.
