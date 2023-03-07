from cs50 import get_float

# Establish variable for coins
coins = 0

# Input change owed
change = get_float("Change owed: ")

while change <= 0:
    change = get_float("Change owed: ")


# Multiply change by 100
cents = round(change * 100)


while cents >= 25:
    cents -= 25
    coins += 1


while cents >= 10:
    cents -= 10
    coins += 1


while cents >= 5:
    cents -= 5
    coins += 1


while cents >= 1:
    cents -= 1
    coins += 1

# Print total number of coins
print(f"{coins}")