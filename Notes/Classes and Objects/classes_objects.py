# Jonas Fairchild

class Person:
    """
    Person class with first and last names as well as age.
    Methods to get full name and increase age by 1.
    """
    first_name: str
    last_name: str
    age: int

    def __init__(self, first_name="John", _last_name="Doe", age=0):
        """Sets all values"""
        self.first_name = first_name
        self._last_name = _last_name
        self.age = age

    def setAge(self): # Setter
        """Increase age by 1."""
        self.age += 1

    def fullName(self): # Getter
        """Create full name"""
        return self.first_name + " " + self._last_name
    
    def __str__(self):
        return f"Name: {self.fullName()}\nAge: {self.age}"

    
tia = Person("Tia", "LaRose", 28)
alex = Person("Alex", "LaRose", 37)

print(f"{tia.fullName()}'s age: {tia.age}")
print(f"{alex.fullName()}'s age: {alex.age}")

print(tia)