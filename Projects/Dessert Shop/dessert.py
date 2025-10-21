class DessertItem:
    def __init__(self, name=""):
        self.name = name

class Candy(DessertItem):
    def __init__(self, name="", weight=0.0, priceppound=0.0):
        super().__init__(name)
        self.weight = weight
        self.priceppound = priceppound
        
class Cookie(DessertItem):
    def __init__(self, name="", ccount=0, pricepdozen=0.0):
        super().__init__(name)
        self.ccount = ccount
        self.pricepdozen = pricepdozen
        
class IceCream(DessertItem):
    def __init__(self, name="", scount=0, pricepscoop=0.0):
        super().__init__(name)
        self.scount = scount
        self.pricepscoop = pricepscoop
    
class Sundae(IceCream):
    def __init__(self, name="", scount=0, pricepscoop=0.0, tname="", tprice=0.0):
        super().__init__(name, scount, pricepscoop)
        self.tname=tname
        self.tprice=tprice

class Order:
    def __init__(self, orders=[]):
        self.orders = orders

    def add(self, order):
        self.orders.append(order)

    def __len__(self):
        return len(self.orders)