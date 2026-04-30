import csv
import random as rm

with open("", "w", newline="") as f:
    writer = csv.writer(f)
    
    # Example: label = 0 (rest), 1 (move)
    for i in range(0,1000):
      random_number = rm.randint