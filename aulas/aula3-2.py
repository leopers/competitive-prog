from math import *
from sys import getsizeof

print(factorial(40))
x = factorial(200)//factorial(100)
print(x)

try:
    x = factorial(300) / factorial(100)
except OverflowError as error:
    print(error)
    print("Don't use '/' to divide between integers (unless you want to convert the result to float)")

print("Float size:")
y = 4.3
print(getsizeof(y))
print("Also, notice that the python float standard is the same as the c++ double standard.")
print("Wait, this has 24 bytes, not the 8 bytes that c++ doubles have !?")
print('"a Python float object takes a full 24 bytes of memory: 8 bytes for the underlying double-precision value, 8 bytes for a pointer to the object type, and 8 bytes for a reference count (used for garbage collection)."')
# https://stackoverflow.com/questions/29826523/python-float-precision-float