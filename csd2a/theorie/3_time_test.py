import time


# Using time.sleep in a forloop does not guarantee exactly 1 sec.
t = time.time()

for i in range(100):
    print("delta t:", time.time()-t)
    t = time.time()
    time.sleep(1)


"""
# This results in a cumulative error
zero_time = time.time()

for i in range(100):
    time.sleep(1)
    print("delta t:", time.time()-zero_time)
"""
