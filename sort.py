import numpy as np
import time

soday = 10
sophantu = 1000000


with open("data.txt", "r") as f:
    data = np.fromfile(f, sep=" ")


if len(data) != soday * sophantu:
    raise ValueError("Số phần tử trong data.txt không đúng!")

data = data.reshape((soday, sophantu))  

sorted_arrays = []
for i in range(soday):
    start = time.time()
    
    sorted_arr = np.sort(data[i])
    
    end = time.time()
    duration = (end - start) * 1000  
    
    sorted_arrays.append(sorted_arr)
    
    print(f"Lần {i + 1}: {duration:.2f} ms", file=sys.stderr)


np.savetxt("pysorted.txt", sorted_arrays, fmt="%.6f")
