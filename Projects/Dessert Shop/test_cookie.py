from dessert import *

def Cookie_set():
    ck = Cookie()
    assert ck.name == ""
    assert ck.ccount == 0
    assert ck.pricepdozen == 0.0

    ck2 = Cookie("Chocolate Chip", 12, 5.99)
    assert ck2.name == "Chocolate Chip"
    assert ck2.ccount == 12
    assert ck2.pricepdozen == 5.99

    ck2.name = "Oatmeal Raisin"
    ck2.ccount = 24
    ck2.pricepdozen = 6.49
    assert ck2.name == "Oatmeal Raisin"
    assert ck2.ccount == 24
    assert ck2.pricepdozen == 6.49

Cookie_set()

print("No errors")