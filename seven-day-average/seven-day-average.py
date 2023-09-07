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
    new_cases = {}

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
        if state not in new_cases:
            new_cases[state] = []
        else:
            new_cases[state].append(daily_new_cases)

        # Ensure we stre only the most recent 14 days
        while len(new_cases[state]) > 14:
            new_cases[state].pop(0)


    return new_cases

# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    current_week_avg = new_cases[state][7:13].sum() / 7
    previous_week_avg = new_cases[state][:6].sum() / 7

    try:
        percentage_change = ((current_week_avg - previous_week_avg) / previous_week_avg) * 100
        if percentage_change > 0:
            print(f'{new_cases[state]} had a 7-day average of {previous_week_avg} and an increase of 'percentage_change')
        else:
            print(f'{new_cases[state]} had a 7-day average of {previous_week_avg} and an decrease of 'percentage_change')
    except ZeroDivisionError:
        print(f'Can not divide by zero')
        return 1

main()
