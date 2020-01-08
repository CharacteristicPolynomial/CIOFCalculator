# CIOFCalculator

## Intro
The goal of this project is to create a framework in which the parameters of a given CIFF can be calculated. Also, we want some tools to compare and visualize the results of different strategies. Of course, all the input sizes are supposed to be very small.

## Mio
![momo](mio.png)

## Design
### Counter
A counter is just a CIMAS (Commutative and Idempotent Memory Access Scheme). Basically it encodes the answers of all M_ie_k and the probabilities p_i in some way and keeps a variable indicating the current memory state. As an object, it has the following three methods.
1. init(); // initialize the memory state
2. update(); // update the memory state
3. get(); // return the current state

