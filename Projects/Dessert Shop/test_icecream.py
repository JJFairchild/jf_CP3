from dessert import *

def IceCream_set():
    i = IceCream()
    assert i.name == ""
    assert i.scount == 0
    assert i.pricepscoop == 0.0

    i2 = IceCream("Vanilla", 3, 1.25)
    assert i2.name == "Vanilla"
    assert i2.scount == 3
    assert i2.pricepscoop == 1.25

    i2.name = "Strawberry"
    i2.scount = 2
    i2.pricepscoop = 1.75
    assert i2.name == "Strawberry"
    assert i2.scount == 2
    assert i2.pricepscoop == 1.75

IceCream_set()

print("No errors")