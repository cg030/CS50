import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print(f'Enter database and text file names')
        sys.exit

    csv_file = sys.argv[1]
    # TODO: Read database file into a variable
    with open(sys.argv[1], 'r') as csv_file:
        db = csv.DictReader(csv_file)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as txt_file:
        sq = csv.reader(txt_file)

    # TODO: Find longest match of each STR in DNA sequence
    headers = db.fieldnames

    temp_dict = {}

    # for loop that passes a subsequence into the longest_match function
    for strs in headers:
        lm = longest_match(sq, strs)
        temp_dict[strs] = [lm]


    # TODO: Check database for matching profiles
    for x in temp_dict:
        for y in db:
            if x == y

    return


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
