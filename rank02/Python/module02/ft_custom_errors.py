class GardenError(Exception):
    def __init__(self, message: str = "Unknown Garden Error"):
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown Plant Error"):
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message: str = "Unknown Water Error"):
        super().__init__(message)


def check_plant_temperature(temp: int) -> None:
    if temp < 0:
        raise PlantError(f"Temperature {temp} is too cold for plants!")
    elif temp > 40:
        raise PlantError(f"Temperature {temp} is too hot for plants!")
    else:
        print(f"Temperature {temp} is safe for plants.")


def water_error_checker(water_amount: int) -> None:
    if (water_amount) < 0:
        raise WaterError(f"Water can not be negative: {water_amount}")

    elif (water_amount == 0):
        raise WaterError(f"No water was provided, we got {water_amount}")

    else:
        print(f"Water was provided, in total f{water_amount}")


def check_soil_pH(pH_value: float) -> None:
    if pH_value < 0 or pH_value > 14:
        raise GardenError(f"Invalid pH value: {pH_value}")
    elif pH_value < 6.0:
        raise GardenError(f"Soil too acidic! pH {pH_value} (needs 6.0-7.5)")
    elif pH_value > 7.5:
        raise GardenError(f"Soil too alkaline! pH {pH_value} (needs 6.0-7.5)")
    else:
        print(f"Soil pH {pH_value} is perfect for most plants.")


def demonstrate_inheritance() -> None:
    try:
        check_plant_temperature(-5)
    except GardenError as e:
        print(f"   Caught PlantError as GardenError: {e}")

    print("\n2. WaterError caught by GardenError:")
    try:
        water_error_checker(0)
    except GardenError as e:
        print(f"   Caught WaterError as GardenError: {e}")

    # Test 3: GardenError caught by GardenError
    print("\n3. GardenError caught by GardenError:")
    try:
        check_soil_pH(-1)
    except GardenError as e:
        print(f"   Caught GardenError as GardenError: {e}")


def test_custom_errors() -> None:
    """Main function that demonstrates all requirements."""

    print("=== Custom Garden Errors Demo ===")

    print("\n1. RAISING CUSTOM ERRORS:")
    print("   (These intentionally raise errors to demonstrate)")
    try:
        check_plant_temperature(50)
    except PlantError:
        pass

    try:
        water_error_checker(-10)
    except WaterError:
        pass

    try:
        check_soil_pH(9.0)
    except GardenError:
        pass

    print("  Custom errors raised successfully")

    demonstrate_inheritance()

    print("\n=== All custom error types work correctly! ===")


if __name__ == "__main__":
    test_custom_errors()
