import sys


def calculate_stats(scores: list):
    if not scores:
        return None
    total = sum(scores)
    average = total / len(scores)
    max_score = max(scores)
    min_score = min(scores)
    return {
        "total": total,
        "average": average,
        "High Score": max_score,
        "Low Score": min_score,
        "Score Range": max_score - min_score
    }


def main() -> None:
    scores_list = []
    if (len(sys.argv) <= 1):
        print("no scores provided")
    else:
        for arg in sys.argv[1:]:
            try:
                score = int(arg)
                scores_list.append(score)
            except ValueError:
                print(f"Invalid score '{arg}'")
    if not scores_list:
        print("no valid scores provided")
        return
    stats = calculate_stats(scores_list)
    if stats:
        print(f"Scores processed: {scores_list}")
        print(f"Total players: {len(scores_list)}")
        print(f"Total score: {int(stats['total'])}")
        print(f"Average score: {stats['average']:.1f}")
        print(f"High score: {int(stats['High Score'])}")
        print(f"Low score: {int(stats['Low Score'])}")
        print(f"Score range: {int(stats['Score Range'])}")


if __name__ == "__main__":
    main()
