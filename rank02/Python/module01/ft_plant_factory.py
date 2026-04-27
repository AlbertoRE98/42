class Plant:
    def __init__(self, name, starting_height, starting_age, growth_rate):
        self.name = name
        self.height = starting_height
        self.starting_height = starting_height
        self.age = starting_age
        self.growth_rate = growth_rate

    def show(self):
        print(
            f"Created: {self.name}: "
            f"{self.starting_height:0.1f}cm, {self.age} days old"
        )

    def grow(self):
        self.height += self.growth_rate

    def age_one_day(self):
        self.age += 1
        self.grow()


if __name__ == "__main__":
    garden_inventory = [
        Plant("Rose", 25, 30, 0.5),
        Plant("Sunflower", 80, 45, 0.1),
        Plant("Cactus", 15, 120, 0.2),
        Plant("Fern", 40, 60, 0.3),
        Plant("Lavender", 35, 20, 0.4)
    ]
    for Plant in garden_inventory:
        Plant.show()
