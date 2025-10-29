from abc import ABC, abstractmethod

class DessertItem(ABC):
    def __init__(self, name="", tax_percent=7.25):
        self.name = name
        self.tax_percent = tax_percent
    
    def calculate_tax(self):
        return round(self.tax_percent / 100 * self.calculate_cost(), 2)

    @abstractmethod
    def calculate_cost(self):
        pass

class Candy(DessertItem):
    def __init__(self, name="", weight=0.0, priceppound=0.0):
        super().__init__(name)
        self.weight = weight
        self.priceppound = priceppound
    
    def calculate_cost(self):
        return round(self.priceppound * self.weight, 2)
        
class Cookie(DessertItem):
    def __init__(self, name="", ccount=0, pricepdozen=0.0):
        super().__init__(name)
        self.ccount = ccount
        self.pricepdozen = pricepdozen
        
    def calculate_cost(self):
        return round(self.pricepdozen * (self.ccount / 12), 2)
    
class IceCream(DessertItem):
    def __init__(self, name="", scount=0, pricepscoop=0.0):
        super().__init__(name)
        self.scount = scount
        self.pricepscoop = pricepscoop
    
    def calculate_cost(self):
        return round(self.pricepscoop * self.scount, 2)

class Sundae(IceCream):
    def __init__(self, name="", scount=0, pricepscoop=0.0, tname="", tprice=0.0):
        super().__init__(name, scount, pricepscoop)
        self.tname=tname
        self.tprice=tprice

    def calculate_cost(self):
        return round(self.pricepscoop * self.scount + self.tprice, 2)

class Order:
    def __init__(self, orders=[]):
        self.orders = orders

    def add(self, order):
        self.orders.append(order)

    def __len__(self):
        return len(self.orders)
    
    def order_cost(self):
        cost = 0.0
        for order in self.orders:
            cost += order.calculate_cost()
        return cost
    
    def order_tax(self):
        tax = 0.0
        for order in self.orders:
            tax += order.calculate_tax()
        return tax