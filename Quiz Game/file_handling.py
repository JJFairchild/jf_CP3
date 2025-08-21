import csv

def read(): # Function to read the contents of questions.csv and transfer it into a dictionary.

    questions = {}

    with open("Quiz Game/questions.csv", "r", newline='') as file:
        question_csv = csv.reader(file)
        next(question_csv)
        for question in question_csv:
            if len(question)==1: # Differentiates between category titles and individual questions.
                type=question[0]
                questions[type] = []
            else:
                questions[type].append(question)
    
    return questions

def write(questions):
    pass