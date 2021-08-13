from sys import argv, exit
import csv
import re
from cs50 import get_string


def main():
    # Open the data base csv
    csv_file = argv[1]
    with open(csv_file) as f:
        reader = csv.reader(f)
        
        # Getting the opitions of STR's from the header of the csv file
        str_options = next(reader)[1:]

        # Open the text file with the dna 
        person_DNA = argv[2]
        with open(person_DNA) as d:
            DNA = d.read()

            # Getting the number of times the especific STR is repeated consecutive
            person = []
            for i in str_options:
                value = maximum_len(DNA, i)
                person.append(value)

            # Comparing with the data base file
            return(compare(reader, person))









# This is the comparing function
def compare(data_base, list_of_str):
    for line in data_base:
        name = line[0]
        person_str = [int(value) for value in line[1:]]
        # If the person is found in the data base
        if person_str == list_of_str:
            print(name)
            return
    # If the person is not in the data base
    print("No match")




# This function gets the index of the ocurrances and check if they are consecutives
def maximum_len(string, substring):
    len_of_substring = len(substring)
    matches = re.finditer(substring, string)
    # This gets the index of the ocurrance of the especific STR in the DNA text
    ocurrances_list = [match.start() for match in matches]
    was_consecutive = False
    consecutives = 0
    max_consecutives = []
    # If there is only one ocurrance
    if len(ocurrances_list) == 1:
        return 1
    # If there is two ocurrances
    elif len(ocurrances_list) == 2:
        if (ocurrances_list[1] - ocurrances_list[0]) == len_of_substring:
            return 2
        else:
            return 0
    # If there is more ocurrances
    for i in range(len(ocurrances_list) - 1):

        if ((ocurrances_list[i + 1] - ocurrances_list[i]) == len_of_substring and was_consecutive == False):
            consecutives += 2
            was_consecutive = True


        elif ((ocurrances_list[i + 1] - ocurrances_list[i]) == len_of_substring and was_consecutive == True):
            consecutives += 1
            was_consecutive = True
            max_consecutives.append(consecutives)

        elif ((ocurrances_list[i + 1] - ocurrances_list[i]) != 4 and was_consecutive == True):
            max_consecutives.append(consecutives)
            consecutives = 0
            was_consecutive = False


    # If there is no consecutives
    if len(max_consecutives) == 0:
        return 0
    return max(max_consecutives)


main()




