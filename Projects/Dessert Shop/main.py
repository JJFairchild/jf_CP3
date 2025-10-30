# Jonas Fairchild, Dessert Shop

"""
INSTRUCTIONS:
- Part One of a multistep project to create a Dessert shop (Yes this is pulled from UVU. . . I am not sorry)


STEP 1:
- Create a file named "dessert" on this file create the 5 classes listed below:

DessertItem (Parent class)
    - Attributes: 
        name: str
            Default Value: ""
    - Methods:
        Constructor (__init__)
Candy
    - Attributes:
        name: str
            Default Value: ""
        candy_weight: float
            Default Value: 0.0
        price_per_pound: float
            Default Value: 0.0
    - Methods:
        Constructor (__init__)
Cookie
    - Attributes:
        name: str
            Default Value: ""
        cookie_quantity: int
            Default Value: 0
        price_per_dozen: float
            Default Value: 0.0
    - Methods:
        Constructor (__init__)
IceCream
    - Attributes:
        name: str
            Default Value: ""
        scoop_count: int
            Default Value: 0
        price_per_scoop: float
            Default Value: 0.0
    - Methods:
        Constructor (__init__)
Sundae (subclass of IceCream)
    - Attributes: 
        name: str
            Default Value: ""
        scoop_count: int
            Default Value: 0
        price_per_scoop: float
            Default Value: 0.0
        topping_name: str
            Default Value: ""
        topping_price: float
            Default Value: 0.0
    - Methods:
        Constructor (__init__)


STEP 2:
Add an order class that will keep track of all the items a customer buys
Add a new file that test the classes by making examples of each and adding them to an order

Order
    - Attributes: 
        order: list
            Value = []
    - Methods:
        Constructor (__init__)
        add(item) 
            Takes a single DessertItem argument and adds it to the order list
        __len__()
            Magic method returns the number of items in the order

dessert_shop.py
Import your classes

Create a main() function that
- Creates a new instance of the order class
- Adds the following items to the order
    Candy("Candy Corn", 1.5, .25)
    Candy("Gummy Bears", .25, .35)
    Cookie("Chocolate Chip", 6, 3.99)
    IceCream("Pistachio", 2, .79)
    Sundae("Vanilla", 3, .69, "Hot Fudge", 1.29)
    Cookie("Oatmeal Raisin", 2, 3.45)
- Prints out the name of each DessertItem in the order
- Print out the total number of items in the order


STEP 3:
Create pytests cases for constructors, attributes, and methods
Create a different "test" page for each of the classes you need to test (DessertItem, Candy, Cookie, IceCream, Sundae)
Note: You don't need to write tests for the Order class

Write three test cases for each of the five classes listed above:
1. Default values: Verify attributes are initialized with default values.
2. Provided values: Verify attributes are initialized correctly with given values.
3. Updated values: Confirm that attributes can be updated and that the changes are reflected correctly.

Note: All test cases must be implemented using pytest.

EXAMPLE TERMINAL OUTPUT:
    Candy Corn
    Gummy Bears
    Chocolate Chip
    Pistachio
    Vanilla
    Oatmeal Raisin
    Total number of items in order: 6

KEY REMINDERS:
- Create a separate folder (or repository) called Dessert Shop
- Create a file named "dessert.py" containing the following classes: DessertItem, Candy, Cookie, IceCream, and Sundae.
- Implement the DessertItem class as the parent class with a 'name' attribute and constructor.
- Create Candy, Cookie, and IceCream classes as subclasses of DessertItem, each with their specific attributes and constructors.
- Implement the Sundae class as a subclass of IceCream with additional attributes for toppings.
- Ensure all classes have appropriate default values for their attributes.
- Create an Order class in the same file with methods to add items and get the order length.
- Create a separate file named "dessert_shop.py" to test the classes.
- In dessert_shop.py, import the classes from dessert.py and create a main() function.
- In the main() function, create an Order instance and add various dessert items to it.
- Print the name of each DessertItem in the order and the total number of items.
- Create separate test files for each class (DessertItem, Candy, Cookie, IceCream, Sundae) using pytest.
- Write three test cases for each class: default values, provided values, and updated values.
- Ensure proper Python syntax, including correct indentation and method definitions.
- Use meaningful variable and method names for code clarity.
- Add comments to explain code logic where necessary.
- Test all classes thoroughly to ensure required functionality works as expected.

HOW TO SUBMIT:
- Submit the link to your project on Github
"""

from dessert import *
from tabulate import tabulate

def getString(message):
    while True:
        string = input(message)
        if len(string) != 0:
            return string
        else:
            print("You have to type something. Try again.")

def getFloat(message):
    while True:
        num = input(message)
        try:
            fl = float(num)
            if fl >= 0.0:
                return fl
            else:
                print("You have to input a positive float. Try again.")
        except:
            print("Invalid input. Try again.")

class DessertShop:
    def user_prompt_candy(self):
        return Candy(
            getString("What is the name of the candy?: "),
            getFloat("How many pounds of candy are you buying?: "),
            getFloat("How much does that candy cost per pound?: ")
        )

    def user_prompt_cookie(self):
        return Cookie(
            getString("What is the name of the cookie?: "),
            getFloat("How many cookies are you buying?: "),
            getFloat("How much do those cookies cost per dozen?: ")
        )

    def user_prompt_icecream(self):
        return IceCream(
            getString("What is the name of the ice cream?: "),
            getFloat("How many scoops of ice cream are you buying?: "),
            getFloat("How much does that ice cream cost per scoop?: ")
        )

    def user_prompt_sundae(self):
        return Sundae(
            getString("What is the name of the ice cream?: "),
            getFloat("How many scoops of ice cream are you buying?: "),
            getFloat("How much does that ice cream cost per scoop?: "),
            getString("What is the name of the topping?: "),
            getFloat("How much does that topping cost?: "),
        )

def main():
    shop = DessertShop()
    order = Order()
    '''
    order.add(Candy('Candy Corn', 1.5, 0.25))
    order.add(Candy('Gummy Bears', 0.25, 0.35))
    order.add(Cookie('Chocolate Chip', 6, 3.99))
    order.add(IceCream('Pistachio', 2, 0.79))
    order.add(Sundae('Vanilla', 3, 0.69, 'Hot Fudge', 1.29))
    order.add(Cookie('Oatmeal Raisin', 2, 3.45))
    '''
    done: bool = False
    # build the prompt string once
    prompt = '\n'.join([ '\n',
        '1: Candy',
        '2: Cookie',
        '3: Ice Cream',
        '4: Sundae',
        '\nWhat would you like to add to the order? (1-4, Enter for done): '
    ])
    while not done:
        choice = input(prompt)
        match choice:
            case '':
                done = True
            case '1':
                item = shop.user_prompt_candy()
                order.add(item)
                print(f'{item.name} has been added to your order.')
            case '2':
                item = shop.user_prompt_cookie()
                order.add(item)
                print(f'{item.name} has been added to your order.')
            case '3':
                item = shop.user_prompt_icecream()
                order.add(item)
                print(f'{item.name} has been added to your order.')
            case '4':
                item = shop.user_prompt_sundae()
                order.add(item)
                print(f'{item.name} has been added to your order.')
            case _:
                print('Invalid response: Please enter a choice from the menu (1-4) or Enter')
    print()

    data = []
    for item in order.orders:
        data.append([item.name, item.calculate_cost(), item.calculate_tax()])

    print(tabulate(data, headers=["Name", "Price", "Tax"]))
    print(tabulate([
        ["Order Subtotals", order.order_cost(), order.order_tax()],
        ["Order Total:", "", order.order_cost() + order.order_tax()],
        ["Total Items in the order:", "", len(order.orders)]
        ]))

main()