def f():
    def g():
        print(3)
    return g


h = f()


def g():
    print(5)


h()

