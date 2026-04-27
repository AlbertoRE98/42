class Plant:
    def __init__(self, name, height, age, growth_rate):
        self.name = name
        self.height = height
        self.age = age
        self.init_height = height
        self.growth_rate = growth_rate

    def grow(self):
        self.height += self.growth_rate

    def age_one_day(self):
        self.age += 1
        self.grow()

    def show_stats(self):
        print(f"{self.name}: {self.height:0.1f}cm, {self.age} days old")


if __name__ == "__main__":
    rose = Plant("Rose", 25.0, 30, 0.8)
    print("=== Garden Plant Growth ===")
    for i in range(1, 8):
        rose.age_one_day()
        print(f"=== Day{i} ===")
        rose.show_stats()
    growth = rose.height - rose.init_height
    print(f"Growth this week: {growth:0.1f}cm")
