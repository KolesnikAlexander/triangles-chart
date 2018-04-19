import matplotlib.pyplot as plt
FILE = "out.csv"
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
