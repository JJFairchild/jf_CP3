import csv

def read(): # Function to read the contents of questions.csv and transfer it into a dictionary.

    questions = {}

    with open("Quiz Game/questions.csv", "r", newline='') as file: # Gets the csv file into 'questions'
        questioncsv = csv.reader(file)
        next(questioncsv)
        for question in questioncsv:
            if len(question)==1:
                type=question[0]
                questions[type] = []
            else:
                questions[type].append(question)
    
    return questions

def write(questions):
    pass