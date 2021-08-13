from cs50 import SQL
import csv
from sys import argv, exit




def main():

    # Checking for the command-line argument
    if len(argv) != 2:
        print("Missing command-line argument...")
        exit(1)
    # Opening a database named students
    open(f"students.db", "w").close()

    # Running SQL
    db = SQL("sqlite:///students.db")

    # Creating a table
    db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")

    # Opening the csv file
    csv_file = argv[1]
    with open(csv_file) as f:
        reader = csv.DictReader(f)

        for row in reader:
            house = row["house"]
            birth = row["birth"]

            # Separating the names
            names_separated = row["name"].split()
            if len(names_separated) != 3:
                first_name = names_separated[0]
                middle_name = None
                last_name = names_separated[1]
            else:
                first_name = names_separated[0]
                middle_name = names_separated[1]
                last_name = names_separated[2]

            # Putting values in the db
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first_name, middle_name, last_name, house, birth)




main()


