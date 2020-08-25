import math

# turn any real number into a number between 0 to 1
def f(x):
	return 2 / (2 + math.e ** -x)

# turn any number from 0 to 1 to a real number
def g(x):
	return -math.log((2 - 2 * x) / x)

number = float(input("Enter any real number: "))
number = f(number)
print(number)
number = g(number)
print(number)

number = float(input("Enter a number between 0 to 1: "))
number = g(number)
print(number)
number = f(number)
print(number)