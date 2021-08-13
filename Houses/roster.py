from cs50 import SQL
import csv
from sys import argv, exit


def main():
    # Checking for the command-line argument
    if len(argv) != 2:
        print("Missing command-lin argument")
        exit(1)

    # Starting the SQL
    db = SQL("sqlite:///students.db")

    # The house that the user wants
    house = argv[1]

    # All data from the data base
    allData = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", house)

    # Printing the names with their births that are in the specific house
    for row in allData:
        if row["middle"] == None:
            print(f'{row["first"]} {row["last"]}, born {row["birth"]}')
        else:
            print(f'{row["first"]} {row["middle"]} {row["last"]}, born {row["birth"]}')

main()