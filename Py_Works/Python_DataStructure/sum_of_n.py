import time
def sum_of_n(n):
    start = time.time()
    sum_all = 0
    for i in range(1,n+1):
        sum_all = sum_all + i;
        end = time.time()
    return sum_all, end - start 
print("Sum is %d requqired %10.7f seconds" % sum_of_n(10000))
