# For loops examples

# create a simple list with numbers
a_few_numbers = [1, 5, 10, 40, 59, 2, 5, 2]

# iterate through list
print("loop through list")
for item in a_few_numbers:
    print(item)


print("loop through list, also print the index")
# iterate through list, also retrieve the current index
for index, item in enumerate(a_few_numbers):
    print(index, item)


# # https://docs.python.org/3.7/library/stdtypes.html#sequence-types-list-tuple-range
# e.g. we want to 10 times print "hi"
for i in range(10):
    print(i)

print(range(10))``
print(range(5, 10))


# range(start_inclusive, end_exclusive)
for i in range(5, 10):
    print(i)

# with a certain stepsize
print("with a 'step'")
for i in range(5, 10, 2):
    print(i)
