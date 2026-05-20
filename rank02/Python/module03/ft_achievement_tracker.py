import random


ACHIEVEMENTS = [
    "Crafting Genius", "Strategist", "World Savior", "Speed Runner",
    "Survivor", "Master Explorer", "Treasure Hunter", "Unstoppable",
    "First Steps", "Collector Supreme", "Untouchable", "Sharp Mind",
    "Boss Slayer", "Hidden Path Finder"
]


def gen_player_achievements() -> set[str]:
    num = random.randint(3, 8)
    return set(random.sample(ACHIEVEMENTS, num))


def main() -> None:
    print("=== Achievement Tracker System ===")

    players = {
        "Alberto": gen_player_achievements(),
        "Marcos": gen_player_achievements(),
        "Dani": gen_player_achievements(),
        "Marta": gen_player_achievements()
    }

    for name, ach in players.items():
        print(f"Player {name}: {ach}")

    all_achievements = set().union(*players.values())
    print(f"\nAll distinct achievements: {all_achievements}")

    common = set.intersection(*players.values())
    print(f"Common achievements: {common}")

    for name, ach in players.items():
        others = set().union(*(a for n, a in players.items() if n != name))
        unique = ach - others
        print(f"Only {name} has: {unique}")

    for name, ach in players.items():
        missing = all_achievements - ach
        print(f"{name} is missing: {missing}")


if __name__ == "__main__":
    main()
