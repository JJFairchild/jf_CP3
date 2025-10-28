# Jonas Fairchild, Tabulation

import tabulate

data = [
    ["Bruce Wayne", "Batman", 6535907546], 
    ["Oliver Queen", "Green Arrow", 5873222983], 
    ["Clark Kent", "Reporter", 8743298754],
    ["Barry Allen", "CSI", 1283272345],
    ["John Smith", "Unemployment", 4582054231]
]

print(tabulate(data, headers=["Name", "Job", "Number"]))