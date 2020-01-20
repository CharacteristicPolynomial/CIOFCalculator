# CIOFCalculator

## Intro
The goal of this project is to create a framework in which the parameters of a given CIFF can be calculated. Also, we want some tools to compare and visualize the results of different strategies. 

The focus of this project is on calculating HyperLogLog. We choose to use *GNU Multiple Precision Arithmetic Library* to do calculations. The calculation is using rationals with infinite precision to gurantee the correctness of the results.

## Design
### List of Values
Since this project involves some extensive computations, it is essential to use files to stage the computations. Each list file starts with some english and after an "=" symbol the list starts. The list files have a suffix ".list".

We can use two list files to represent a discrete function. For example, put the input values in a list file and put the output values in another list file (in the same order). 

The type of the list elements is *double*.

There is no native support for functions with 2 or more arguments, but as long as the number of inputs is finite, one could find a way to use a single input that enumerates all input. For example, if the first argument has m possibilities and the second argument has n possibilities, then we can map input (i,j) to i+j*m. All these mappings should be specified clearly somewhere.

We need the following two basic functions.

| function | usage |
| --- | --- |
| list_read(vector& vec, const char* filename) | read a list file into a vector |
| list_write(const vector& vec, char* file) | write a vector into a list file |

### Function a(x;s,t) and b(x;s,t)
There are two functions- a(x;s,t) and b(x;s,t) that require lengthy computations. 

| function | usage |
| --- | --- |
| compute_ax() | compute the list of a(x) values, the parameters are set in config.h |
| compute_bx() | compute the list of b(x) values, the parameters are set in config.h |

Note that both compute_ax() and compute_bx() work in an additive way. That is it will first see whether some previous sessions have computed some the results in the file and then compute the rest in order.

### Function LogLog_g(i)
This gives the optimal guess on state i (corresponding to the ith lambda). The value is calculated given this is a LogLog scheme with PARAMETER_M independent copies and each copy has PARAMETER_N states. The result should be stored in a list file.

## Mio
![momo](mio.png)