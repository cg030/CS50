test_dict = {
    'Luffy' : 16,
    'Zoro' : 20,
    'Nami' : 18,
    'Usopp' : 17,
    'Sanji' : 19,
    'Chopper' : 15,
    'Robin' : 28,
    'Franky' : 30,
    'Brooke' : 80,
    'Jimbei' : 40
}

print(test_dict)

updated_dict = {key + '-san' : value for key, value in test_dict.items()}
for key in test_dict:
    key + '-san'

print(updated_dict)