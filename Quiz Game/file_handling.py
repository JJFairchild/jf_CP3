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

def write(questions): # Writes 'questions' to the csv, for adding custom categories.
    with open("Quiz Game/questions.csv", "w", newline="") as file:
        writer = csv.writer(file)
        
        writer.writerow(["Question", "Answer 1", "Answer 2", "Answer 3", "Answer 4", "Correct answer #"]) # Header
        
        for category, q_list in questions.items():
            # Write category name as a row
            writer.writerow([category])
            
            for question in q_list:
                # Each q is [Question, A1, A2, A3, A4, Correct #]
                writer.writerow(question)

