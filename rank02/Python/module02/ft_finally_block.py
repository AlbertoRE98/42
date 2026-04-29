class GardenError(Exception):
    def __init__(self, message: str = "Unknown Garden Error"):
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown Plant Error"):
        super().__init__(message)


def water_plant(plant_name: str) -> None:
    if plant_name == plant_name.capitalize():
        print("Success on watering")
    else:
        raise PlantError(f"invalid plant name {plant_name}")


def test_watering_system():
    try:
        water_plant("Tomato")
        water_plant("Lettuce")
        water_plant("Almond")
    except PlantError as e:
        print(f"Caught PlantError as {e}")
    finally:
        print("closing system and doing cleanup")

    try:
        water_plant("tomato")
        water_plant("lettuce")
        water_plant("almond")
    except PlantError as e:
        print(f"Caused Plant Error as {e}")
        print("ending test and returning")
        return
    finally:
        print("Closing system and doing cleanup")
    print("No errores happened")


def main() -> None:
    test_watering_system()
    print("Back in main")


if __name__ == "__main__":
    main()
