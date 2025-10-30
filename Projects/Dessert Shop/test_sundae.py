from dessert import *

def Sundae_set():
    s = Sundae()
    assert s.name == ""
    assert s.scount == 0
    assert s.pricepscoop == 0.0
    assert s.tname == ""
    assert s.tprice == 0.0
    assert s.calculate_cost() == 0.0
    assert s.calculate_tax() == 0.0

    s2 = Sundae("Chocolate", 2, 1.50, "Hot Fudge", 0.75)
    assert s2.name == "Chocolate"
    assert s2.scount == 2
    assert s2.pricepscoop == 1.50
    assert s2.tname == "Hot Fudge"
    assert s2.tprice == 0.75

    s2.name = "Mint"
    s2.scount = 3
    s2.pricepscoop = 1.25
    s2.tname = "Caramel"
    s2.tprice = 0.50
    assert s2.name == "Mint"
    assert s2.scount == 3
    assert s2.pricepscoop == 1.25
    assert s2.tname == "Caramel"
    assert s2.tprice == 0.50

Sundae_set()

print("No errors")