# source code:
# https://docs.python.org/3.7/library/stdtypes.html#sequence-types-list-tuple-range

# This example displays different types of list allocation,
# some list specific functionality, like reverse and sort

# create an empty list
empty_list = []
print("empty_list", empty_list)

# create a filled list
filled_list = [10, 20, 40]
print("filled_list", filled_list)
foo = 0
another_filled_list = ['a', 'b', foo]
print("another_filled_list", another_filled_list)

# using the list constructor
list_constructor = list()
print("list_constructor", list_constructor)


# using a list comprehension
sequential_numbers = [number for number in range(10)]
print("sequential_numbers", sequential_numbers)

sequential_numbers.reverse()
print("reversed sequential_numbers", sequential_numbers)
sequential_numbers.sort()
print("sorted sequential_numbers", sequential_numbers)

# sorted --> new list instance
a_list = [10, 40, 2, 1, 0]
print("new sorted list", sorted(a_list))
print("a_list", a_list)


# some interesting tricks
ten_times = [0] * 10
print("ten_times", ten_times)
print("concatenated lists: filled_list + another_filled_list = ", filled_list + another_filled_list)
