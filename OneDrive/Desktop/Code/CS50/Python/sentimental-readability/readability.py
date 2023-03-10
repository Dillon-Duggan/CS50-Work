from cs50 import get_string


text = get_string("Text: ")

letters = 0
words = 1
sentences = 0

for i in text:
    if i.isalpha():
        letters += 1

    if i == " ":
        words += 1

    if i == '.' or i == '?' or i == '!':
        sentences += 1

Coleman_Index = 0.0588 * (letters/words*100) - 0.296 * (sentences/words*100) - 15.8

if Coleman_Index < 1:
    print("Before Grade 1")
elif Coleman_Index >= 16:
    print("Grade 16+")
else:
    print("Grade", round(Coleman_Index))