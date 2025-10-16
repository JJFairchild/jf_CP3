# Jonas Fairchild, Parent and Child Classes

class Animal():
    def __init__(self, age, color):
        self.age = age
        self.color = color

    def move(self):
        pass

    def __str__(self):
        return f"Age: {self.age}\ncolor: {self.color}"
    
    def __eq__(self, other):
        return (self.age == other.age and self.color == other.color)
    
class Dog(Animal):
    def __init__(self, age, color, owner, breed, name):
        super().__init__(age, color)
        self.owner = owner
        self.breed = breed
        self.name = name

    def move(self):
        print(f"{self.name} runs")
    
    def __str__(self):
        return f"Age: {self.age}\ncolor: {self.color}\nOwner: {self.owner}\nBreed: {self.breed}\nName: {self.name}\n"
    
    def __eq__(self, other):
        return (self.age == other.age and 
                self.color == other.color and
                self.owner == other.owner and
                self.breed == other.breed and
                self.name == other.name)

bobby = Dog(5, "brown", "Jill", "Bulldog", "Bobby")
birdy = Dog(1, "Black", "Nikkie", "Lab", "Birdy")
alex = Animal(16, "White")
nick = Animal(16, "White")

print(bobby.move())
print(alex)

print(alex == nick)
print(bobby == birdy)