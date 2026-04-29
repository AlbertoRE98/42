def input_temperature(temp_str: str) -> int:
    temp = int(temp_str)
    return temp


def test_temperature() -> None:
    print("=== Garden Temperature Checker ===")
    test = "25"
    print(f"The value without converting is {test}")

    try:
        test = input_temperature(test)
        print(f"Temperature 1: {test}°C")
    except Exception as e:
        print(f"An error occurred while converting the temperature: {e}")

    try:
        temp2 = input_temperature("abc")
        print(f"Temperature 2: {temp2}°C")
    except Exception as e:
        print(f"An error occurred while converting the temperature: {e}")


if __name__ == "__main__":
    test_temperature()
