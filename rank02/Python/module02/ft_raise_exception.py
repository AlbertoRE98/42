def input_temperature(temp_str: str) -> int:
    temp = int(temp_str)
    if (temp > 40):
        raise ValueError("Temperature cannot be greater than 40°C.")
    elif (temp < 0):
        raise ValueError("Temperature cannot be less than 0")
    return temp

def test_temperature() -> None:

    print("=== Garden Temperature Checker ===")
    test = "25"
    print(f"The value without converting is {test}")

    try:
        test = input_temperature(test)
        print(f"Temperature 1: {test}°C")
    except ValueError as e:
        print(f"An error occurred while converting the temperature: {e}")

    try:
        temp2 = input_temperature("abc")
        print(f"Temperature 2: {temp2}°C")
    except ValueError as e:
        print(f"An error occurred while converting the temperature: {e}")

    try:
        result = input_temperature("100")
        print(f"Temperature is now {result}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")

    # Test 4: Extreme value - too cold (-50°C)
    print(f"\nInput data is '-50'")
    try:
        result = input_temperature("-50")
        print(f"Temperature is now {result}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")

if __name__ == "__main__":
    test_temperature()
