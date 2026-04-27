class Plant:

    class _Stats:
        def __init__(self):
            self.age_count = 0
            self.growth_count = 0
            self.show_count = 0

        def display(self):
            print(f"Grow calls: {self.growth_count}")
            print(f"Age calls:  {self.age_count}")
            print(f"Show calls: {self.show_count}")

    def __init__(self, name, height, age, growth_rate):
        self.name = name
        self._height = 0
        self._age = 0
        self.growth_rate = growth_rate

        self.set_height(height)
        self.set_age(age)

        self._stats = self._Stats()

    def set_height(self, value):
        if value < 0:
            print(f"[Error] Invalid height ({value}cm) for {self.name}")
        else:
            self._height = value

    def set_age(self, value):
        if value < 0:
            print(f"[Error] Invalid age ({value} days) for {self.name}.")
        else:
            self._age = value

    def get_height(self):
        return self._height

    def get_age(self):
        return self._age

    def grow(self):
        self.set_height(self.get_height() + self.growth_rate)
        self._stats.growth_count += 1

    def age_one_day(self):
        self.set_age(self.get_age() + 1)
        self.grow()
        self._stats.age_count += 1

    def show(self):
        print(f"{self.name}: {self._height}cm, {self._age} days old")
        self._stats.show_count += 1

    @staticmethod
    def age_checker(age_given):
        print("=== Check year-old ===")
        if (age_given > 365):
            print(f"Is {age_given} days more than a year? -> True")
        elif (age_given < 365 and age_given >= 0):
            print(f"Is {age_given} days more than a year? -> False")
        else:
            print("Error on the age number")

    @classmethod
    def create_anonymous(cls):
        return cls("Anonymous Plant", 0.0, 0, 0.5)


class Flower(Plant):
    def __init__(self, name, height, age, growth_rate, color):
        super().__init__(name, height, age, growth_rate)
        self.color = color
        self.bloomed = False

    def bloom(self):
        print(f" Asking the {self.name} to bloom")
        self.bloomed = True

    def show(self):
        super().show()
        print(f"Color: {self.color}")
        if (self.bloomed):
            print(f" {self.name} is blooming beautifully!")
        else:
            print(f" {self.name} has not bloomed yet")


class Seed(Flower):
    def __init__(self, name, height, age, growth_rate, color, seeds):
        super().__init__(name, height, age, growth_rate, color)
        self.seeds = 0
        self.blooming_seeds = seeds

    def show(self):
        super().show()
        print(f"Seeds: {self.seeds}")

    def bloom(self):
        super().bloom()
        self.seeds += self.blooming_seeds


class Tree(Plant):

    class _Tree_Stats(Plant._Stats):
        def __init__(self):
            super().__init__()
            self.shade_count = 0

        def display(self):
            super().display()
            print(f"Shade calls: {self.shade_count}")

    def __init__(self, name, height, age, growth_rate, trunk_diameter):
        super().__init__(name, height, age, growth_rate)
        self.trunk_diameter = trunk_diameter
        self._stats = self._Tree_Stats()

    def produce_shade(self):
        print(f"[asking the {self.name} to produce shade]")
        print(
            f"{self.name} now produces a shade of {self.get_height()}"
            f"cm long and {self.trunk_diameter}cm wide"
        )
        self._stats.shade_count += 1

    def show(self):
        super().show()
        print(f" Trunk Diameter: {self.trunk_diameter}")


class Vegetable(Plant):
    def __init__(self, name, height, age, growth_rate, harvest_season):
        super().__init__(name, height, age, growth_rate)
        self.harvest_season = harvest_season
        self.nutritional_value = 0

    def show(self):
        super().show()
        print(f" Harvest Season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")

    def grow(self):
        super().grow()
        self.nutritional_value += 1

    def age_one_day(self):
        super().age_one_day()


def report_garden_stats(plant_instance):

    print(f"\n>>> EXTERNAL AUDIT: {plant_instance.name} <<<")

    plant_instance._stats.display()


if __name__ == "__main__":
    rose = Plant("Rose", 25.0, 30, 0.8)
    tulip = Flower("Tulip", 15.0, 20, 0.5, "Red")
    apple_seed = Seed("Apple Seed", 5.0, 10, 0.3, "Brown", 8)
    oak = Tree("Oak", 200.0, 365, 1.5, 25.0)
    carrot = Vegetable("Carrot", 12.0, 45, 0.4, "Summer")

    print("=== Simulating Growth ===")
    for plant in [rose, tulip, apple_seed, oak, carrot]:
        for _ in range(3):
            plant.age_one_day()
            plant.show()
        print("-" * 40)

    tulip.bloom()
    apple_seed.bloom()
    rose.age_one_day()

    print("\n\n=== GARDEN STATISTICS REPORTS ===")
    plants = [rose, tulip, apple_seed, oak, carrot]
    for plant in plants:
        report_garden_stats(plant)
