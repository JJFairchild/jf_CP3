from dessert import *

def Candy_set():
    c = Candy()
    assert c.name == ""
    assert c.weight == 0.0
    assert c.priceppound == 0.0
    assert c.calculate_cost() == 0.0
    assert c.calculate_tax() == 0.0

    c2 = Candy("Chocolate", 1.5, 2.99)
    assert c2.name == "Chocolate"
    assert c2.weight == 1.5
    assert c2.priceppound == 2.99

    c2.name = "Gummy Bears"
    c2.weight = 2.0
    c2.priceppound = 3.49
    assert c2.name == "Gummy Bears"
    assert c2.weight == 2.0
    assert c2.priceppound == 3.49

Candy_set()

print("No errors")