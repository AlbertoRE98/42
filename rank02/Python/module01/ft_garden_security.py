class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self._height = 0
        self._age = 0

        self.set_height(height)
        self.set_age(age)

    def show(self):
        print(f"{self.name}: {self._height}cm, {self._age} days old")

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


if __name__ == "__main__":
    print("=== Testing Data Integrity ===")

    rose = Plant("Rose", 25, 30)
    rose.show()

    print("\nAttempting to set age to -5...")
    rose.set_age(-5)

    print("Attempting to set height to -10...")
    rose.set_height(-10)

    print("\nVerifying data integrity (should remain 25cm, 30 days):")
    rose.show()

    print("\nCreating 'Mystery Sprout' with -50 height:")
    sprout = Plant("Mystery Sprout", -50, 1)
    sprout.show()
