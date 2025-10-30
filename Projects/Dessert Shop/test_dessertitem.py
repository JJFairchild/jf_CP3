from dessert import *

def Dessert_set():
    d = Candy()
    assert d.name == ""
    assert d.tax_percent == 7.25
    
    d2 = Candy("Licorice")
    assert d2.name == "Licorice"

    d2.name = "Candy Cane"
    assert d2.name == "Candy Cane"

Dessert_set()

print("No errors")