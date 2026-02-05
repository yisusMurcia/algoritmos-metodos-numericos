# [Lagrange interpolation](Lagrange.h)

This method build the polynomial function that matches the given points, for use it this function needs a x arr and y arr of the same length ant the number n of that array size, and return a stirng with the formula, this does'nt resolve the multiplications avoiden aproximation mistakes. 

# [Split differences (Newton)](splitDiferences.h)

This method as the langrange method return a polynomial function that matches the givens points and return a mathematical expresion. Also this method is optimized for uniformed spaced cases

# [Newton](Newton.h)

This file has two functions, one for polynomials, where the guven input has the initial value of aproximation, the number of terms of the polynomial and an array of the terms starting from the coefficient of the higher term. The other function requieres the initial value and the function.

# [Muller](muller.h)
This method use a quadratic aproximation finding that makes the function equal 0, this version only works on real numbers but in future. Also, this fila also has a function for use it in complex functions and return a very precise aproximation.