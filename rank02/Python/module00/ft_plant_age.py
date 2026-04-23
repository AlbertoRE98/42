def ft_plant_age():
    p_age = float(input("Enter plant age in days: "))
    if (p_age > 60):
        print("Plant is ready to harvest!")
    else:
        print("Plant needs more time to grow.")
