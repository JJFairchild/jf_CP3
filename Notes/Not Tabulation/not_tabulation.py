# Jonas Fairchild, Tabulation

from tabulate import tabulate

data = [
    ["Will", 15],
    ["Hope", 19],
    ["Jill", 20],
]


print(tabulate(data, headers=["Character", "Age"], tablefmt="fsql"))