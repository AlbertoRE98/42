class Plant:
    def __init__(self, name, height, age, growth_rate):
        self.name = name
        self.height = height
        self.age = age
    def grow(self):
        self.height += self.growth_rate
