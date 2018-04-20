import matplotlib.pyplot as plt
import os.path
import sys

FILE = "out.csv"

if not os.path.isfile(FILE):
    print("Put ", FILE, " in a current directory")
    sys.exit(0)

x = ()
y = ()
with open(FILE, "r") as filestream:
        for line in filestream:
            currentline = line.split(",")
            x = x + (int(currentline[0]),)
            y = y + (float(currentline[1]),)

plt.bar(x,y,align='center')
plt.xlabel('Angle')
plt.ylabel('Area')
plt.show()
