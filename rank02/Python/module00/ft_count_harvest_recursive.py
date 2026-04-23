def ft_count_harvest_recursive():
    ndays = int(input("Days until harvest: "))

    def count(n):
        if (n > 1):
            count(n - 1)
        print(n)
    count(ndays)
