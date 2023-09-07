import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    # create two dictionaries, one cumulative, the other single cases

    dict_cumulative = {}
    dict_single = {}

    for row in reader:
        state = row['state']
        cumulative_cases = int(row['cases'])

        if state in dict_cumulative:
            daily_new_cases = cumulative_cases - dict_cumulative[state]
        else:
            daily_new_cases = cumulative_cases

        # Update the cumulative_cases dictionary
        dict_cumulative[state] = cumulative_cases

        # Update the single_cases dictionary
        if state not in single_cases

        
        dict_single[state] = daily_new_cases
    return new_cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    ...


main()
