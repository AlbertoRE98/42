class Plant:
    def __init__(self, name, height, age, growth_rate):
        self.name = name
        self._height = 0
        self._age = 0
        self.growth_rate = growth_rate

        self.set_height(height)
        self.set_age(age)

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

    def show(self):
        print(f"{self.name}: {self._height}cm, {self._age} days old")

    def grow(self):
        self.set_height(self.get_height() + self.growth_rate)

    def age_one_day(self):
        self.set_age(self.get_age() + 1)
        self.grow()


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


class Tree(Plant):
    def __init__(self, name, height, age, growth_rate, trunk_diameter):
        super().__init__(name, height, age, growth_rate)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self):
        print(f"[asking the {self.name} to produce shade]")
        print(
            f"{self.name} now produces a shade of {self.get_height()}"
            f"cm long and {self.trunk_diameter}cm wide"
        )

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
        self.nutritional_value += 1

    def age_one_day(self):
        self.set_age(self.get_age() + 1)
        self.grow()


if __name__ == "__main__":
    print("=== Garden Plant Types ===")

    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, 2.0, "red")
    rose.show()
    rose.bloom()
    rose.show()

    print("=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0, 10.0)
    oak.show()
    oak.produce_shade()

    print("=== Vegetable")
    tomato = Vegetable("Tomato", 5.0, 10, 1.0, "April")
    tomato.show()

    print(f"[make {tomato.name.lower()} grow and age for 20 days]")
    for _ in range(20):
        tomato.age_one_day()
    tomato.show()
