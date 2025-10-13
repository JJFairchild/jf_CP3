# Jonas Fairchild, Student Class

"""
Lesson 1: Classes and Objects
LESSON I CAN: I CAN create objects using a class

By the end of this lesson you will be able to:
- Create a class
- Describe how a class is an abstraction of an object
- Create a constructor method
- Create a magic method
- Create methods to manipulate the class objects

State Standards:
    STRAND 5: Students will design and implement advanced object oriented concepts.

        STANDARD 1: Implement object-oriented programs

            -Create classes with minimal extraneous relationships (high cohesion and low coupling)

            -Demonstrate and use composition and aggregation (HAS-A) relationships

            -Demonstrate the use of class variables (static variables) 

INSTRUCTIONS:
- Write a program that uses a class to abstract a student. Students need to have a student id, name, and grade. The student class should have an __init__ method to initialize the values. Have the id default to 000, name to John Doe and grade to 100. Make a getter function that will display the student's grade. Make a setter function that will change the student's grade. Create at least 5 student objects. Print each object (note that means you will need a __str__ method), change the grades of at least 3 students and then use the getter method to display the new grades. 

KEY REMINDERS:
- Use a class to define the Student object with attributes for id, name, and grade.
- Implement the init method with default values for all attributes.
- Create a getter method (get_grade()) to retrieve the student's grade.
- Create a setter method (set_grade()) to modify the student's grade.
- Include a str method for proper string representation of Student objects.
- Create at least 5 Student objects, some with custom values and some with defaults.
- Print all Student objects to demonstrate the str method's functionality.
- Use the setter method to change grades for at least 3 students.
- Use the getter method to display the updated grades after changes.
- Pay attention to proper Python syntax, including correct indentation and method definitions.
- Test the class thoroughly to ensure all required functionality works as expected.
- Use meaningful variable and method names for code clarity.
- Add comments to explain code logic where necessary.

HOW TO SUBMIT:
- Submit the link to your project on Github
"""

class Student:
    """Creates a class that abstracts a student"""

    def __init__(self, id = 000, name = "John Doe", grade = 100):
        """Initializes a student with optional default values"""
        self.id = id
        self.name = name
        self.grade = grade

    def get_grade(self):
        """Returns the grade of a student"""
        return self.grade
    
    def set_grade(self, grade):
        """Gives a student a new grade"""
        self.grade = grade
    
    def __str__(self):
        """Allows the student object to be printed"""
        return f"ID: {self.id}; Name: {self.name}; Grade: {self.grade}"
    
john = Student(1, "John Clarke", 85)
tina = Student(2, "Tina Granger", 100)
mark = Student(3, "Mark Challenger", 90)
zack = Student(4, "Zack Lopez", 80)
zoey = Student(5, "Zoey Wilson", 95)

print(john)
print(tina)
print(mark)
print(zack)
print(zoey)

john.set_grade(80)
tina.set_grade(105)
zack.set_grade(85)

print(f"\nNew grades for John, Tina, and Zack:\n{john.get_grade()}\n{tina.get_grade()}\n{zack.get_grade()}")