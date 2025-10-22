# Jonas Fairchild, Abstraction

from abc import ABC, abstractmethod

class Animal(ABC):
    def __init__(self, name):
        self.name = name
    
    @abstractmethod
    def move(self):
        pass

class Quadroped(Animal):
    def __init__(self, name):
        super().__init__(name)

    def move(self):
        print(f"{self.name} can walk or run.")

class Aquatic(Animal):
    def __init__(self, name):
        super().__init__(name)

    def move(self):
        print(f"{self.name} can swim.")

class SeaLion(Aquatic, Quadroped):
    def __init__(self, name):
        super().__init__(name)

    def eat(self):
        print(f"{self.name} eats penguins and krill")

    def __str__(self):
        return self.name

greg = SeaLion("Greg")

print(greg)
greg.move()
greg.eat()

print(SeaLion.mro())