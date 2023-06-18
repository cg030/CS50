def get_population_growth_years():
    # Prompt for the start population size
    while True:
        start_pop = int(input("Start size: "))
        if start_pop >= 9:
            break
        print("Start size should be at least 9.")

    # Prompt for the end population size
    while True:
        end_pop = int(input("End size: "))
        if end_pop >= start_pop:
            break
        print("End size should be greater than or equal to the start size.")

    # Calculate the number of years
    years = 0
    while start_pop < end_pop:
        births = start_pop // 3
        deaths = start_pop // 4
        start_pop = start_pop + births - deaths
        years += 1

    # Print the number of years
    print("Years:", years)

get_population_growth_years()
