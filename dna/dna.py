import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print(f'Enter database and text file names')
        sys.exit()

    # TODO: Read database file into a nested dictionary; this will make searching for identical STRs easier later
    nested_dict = {}
    with open(sys.argv[1], 'r') as csv_file:
        reader = csv.DictReader(csv_file)
        for row in reader:
            name = row['name']
            strs = {field : int(row[field]) for field in reader.fieldnames if field != 'name'}
            nested_dict[name] = strs

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as txt_file:
        sequence = txt_file.read().strip()

    # TODO: Find longest match of each STR in DNA sequence
    # determine the names of the STRs I have to check. These correspond to the nested keys
    # Get the key (name) at the first index
    nested_keys_strs = [field for field in reader.fieldnames if field != 'name']

    # create temporary dictionary with the results of the for loop
    temp_dict = {}

    # loop over STRs retrieved from the database and pass these into the function to find the longest match of that STR in the sequence from the txt file
    for str_name in nested_keys_strs:
        lm = longest_match(sequence, str_name)
        temp_dict[str_name] = lm

    # TODO: Check database for matching profiles
    for name, values in nested_dict.items():
        if values == temp_dict:
            print(name)
        else:
            print(f'No match')


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
