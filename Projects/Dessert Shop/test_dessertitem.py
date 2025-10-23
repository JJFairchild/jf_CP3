from dessert import *

def Dessert_set():
    d = DessertItem()
    assert d.name == ""
    
    d2 = DessertItem("Licorice")
    assert d2.name == "Licorice"

    d2.name = "Candy Cane"
    assert d2.name == "Candy Cane"

Dessert_set()

print("No errors")