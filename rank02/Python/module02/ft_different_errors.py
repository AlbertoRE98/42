def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        int("abc")

    elif operation_number == 1:
        10 / 0

    elif operation_number == 2:
        open("/not/existent/file", "r")

    elif operation_number == 3:
        "holaquetal" + 25

    else:
        return


def test_error_types() -> None:
    garden_err = (ValueError, ZeroDivisionError, FileNotFoundError, TypeError)
    print("=== Catching Multiple Error Types Demo ===")

    operations = [0, 1, 2, 3, 4]

    for op_num in operations:
        print(f"Testing operation {op_num}...")

        try:
            garden_operations(op_num)
            if op_num >= 4:
                print("Operation completed successfully")

        except (garden_err) as e:
            print(f"Caught an error: {type(e).__name__} - {e}")

    print("All tests completed!")


if __name__ == "__main__":
    test_error_types()
