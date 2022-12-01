def get_k_run_starter(n, k):
    """
    >>> get_k_run_starter(123444345, 0) # example from description
    3
    >>> get_k_run_starter(123444345, 1)
    4
    >>> get_k_run_starter(123444345, 2)
    4
    >>> get_k_run_starter(123444345, 3)
    1
    >>> get_k_run_starter(123412341234, 1)
    1
    >>> get_k_run_starter(1234234534564567, 0)
    4
    >>> get_k_run_starter(1234234534564567, 1)
    3
    >>> get_k_run_starter(1234234534564567, 2)
    2
    """
    i = 0
    final = None
    while i < k + 1:
        while n % 10 > (n % 100 - n % 10) // 10 and n > 9:
            n = n // 10
        final = n % 10
        i = i + 1
        n = n // 10
    return final


def best_k_segmenter(k, score):
    """
    >>> largest_digit_getter = best_k_segmenter(1, lambda x: x)
    >>> largest_digit_getter(12345)
    5
    >>> largest_digit_getter(245351)
    5
    >>> largest_pair_getter = best_k_segmenter(2, lambda x: x)
    >>> largest_pair_getter(12345)
    45
    >>> largest_pair_getter(245351)
    53
    >>> best_k_segmenter(1, lambda x: -x)(12345)
    1
    >>> best_k_segmenter(3, lambda x: (x // 10) % 10)(192837465)
    192
    """
    partitioner = lambda x: (x // 10 ** k, x % 10 ** k)
    def best_getter(n):
        assert n > 0
        best_seg = None
        while n > 0:
            n, seg = partitioner(n)
            if score(seg) > score(best_seg):
                best_seg = seg
        return best_seg
    return best_getter


def div_by_primes_under(n):
    """
    Implement div_by_primes_under, which takes in an integer n and 
    returns an n-divisibility checker. An n-divisibility-checker is 
    a function that takes in an integer k and returns whether k is 
    divisible by any integers between 2 and n, inclusive.
    >>> div_by_primes_under(10)(11)
    False
    >>> div_by_primes_under(10)(121)
    False
    >>> div_by_primes_under(10)(12)
    True
    >>> div_by_primes_under(5)(1)
    False
    """
    checker = lambda x: False
    i = 2
    while i <= n:
        if not checker(i):
            checker = (lambda f, i: lambda x: x % i == 0 or f(x))(checker, i)
        i = i + 1 
    return checker


def div_by_primes_under_no_lambda(n):
    """
    >>> div_by_primes_under_no_lambda(10)(11)
    False
    >>> div_by_primes_under_no_lambda(10)(121)
    False
    >>> div_by_primes_under_no_lambda(10)(12)
    True
    >>> div_by_primes_under_no_lambda(5)(1)
    False
    """
    def checker(x):
        return False
    i = 2
    while i <= n:
        if not checker(i):
            def outer(f, i):
                def inner(x):
                    return x % i == 0 or f(x)
                return inner
            checker = outer(checker, i)
        i = i + 1
    return checker


def three_memory(n):
    """
    >>> f = three_memory('first')
    >>> f = f('first')
    Not found
    >>> f = f('second')
    Not found
    >>> f = f('third')
    Not found
    >>> f = f('second') # 'second' was not input three calls ago
    Not found
    >>> f = f('second') # 'second' was input three calls ago
    Found
    >>> f = f('third') # 'third' was input three calls ago
    Found
    >>> f = f('third') # 'third' was not input three calls ago
    Not found
    """
    def f(x, y, z):
        def g(i):
            if i == x:
                print('Found')
            else:
                print('Not Found')
            return f(y, z, i)
        return g
    return f(None, None, n)



def rect(area, perimeter):
    """
    >>> rect(10, 14) # A 2 x 5 rectangle
    5
    >>> rect(5, 12) # A 1 x 5 rectangle
    5
    >>> rect(25, 20) # A 5 x 5 rectangle
    5
    >>> rect(25, 25) # A 2.5 x 10 rectangle doesn't count because sides are not integers
    False
    >>> rect(25, 29) # A 2 x 12.5 rectangle doesn't count because sides are not integers
    False
    >>> rect(100, 50) # A 5 x 20 rectangle
    20
    """
    side = 1
    while side * side <= area:
        other = round(area/side)
        if  2 * (side + other) == perimeter:
            return other
        side = side + 1
    return False


def keep_ints(cond, n):
    """Print out all integers 1..i..n where cond(i) is true
    >>> def is_even(x):
    ...     # Even numbers have remainder 0 when divided by 2.
    ...     return x % 2 == 0
    >>> keep_ints(is_even, 5)
    2
    4
    """
    for i in range(1, n+1):
        if cond(i):
            print(i)


def make_keeper(n):
    """Returns a function which takes one parameter cond and prints out all integers 1..i..n where calling cond(i) returns True.
        >>> def is_even(x):
        ...     # Even numbers have remainder 0 when divided by 2.
        ...     return x % 2 == 0
        >>> make_keeper(5)(is_even)
        2
        4
    """
    def inner(cond):
        for i in range(1, n+1):
            if(cond):
                print(i)
    return inner


def print_delayed(x):
    """Return a new function. This new function, when called, will print out x and return another function with the same behavior.
    >>> f = print_delayed(1)
    >>> f = f(2)
    1
    >>> f = f(3)
    2
    >>> f = f(4)(5)
    3
    4
    >>> f("hi") # a function is returned
    5
    <function delay_print>
    """
    def delay_print(y):
        print(x)
        return print_delayed(y)
    return delay_print


def print_n(n):
    """
    >>> f = print_n(2)
    >>> f = f("hi")
    hi
    >>> f = f("hello")
    hello
    >>> f = f("bye")
    done
    >>> g = print_n(1)
    >>> g("first")("second")("third")
    first
    done
    done
    <function inner_print>
    """
    def inner_print(x):
        if n <= 0:
            print("done")
        else:
            print(x)
        return print_n(n-1)
    return inner_print


def match_k(k):
    """ Return a function that checks if digits k apart match

    >>> match_k(2)(1010)
    True
    >>> match_k(2)(2010)
    False
    >>> match_k(1)(1010)
    False
    >>> match_k(1)(1)
    True
    >>> match_k(1)(2111111111111111)
    False
    >>> match_k(3)(123123)
    True
    >>> match_k(2)(123123)
    False
    """
    def checker(x): 
        while x >= 10 ** k:
            if x % 10 != (x // 10 ** k) % 10:
                return False
            x = x // 10
        return True
    return checker


def chain_function():
    """
    >>> tester = chain_function()
    >>> x = tester(1)(2)(4)(5) # Expected 3 but got 4, so print 3. 1st chain break, so print 1 too.
    3 1
    >>> x = x(2) # 6 should've followed 5 from above, so print 6. 2nd chain break, so print 2
    6 2
    >>> x = x(8) # The chain restarted at 2 from the previous line, but we got 8. 3rd chain break.
    3 3
    >>> x = x(3)(4)(5) # Chain restarted at 8 in the previous line, but we got 3 instead. 4th break
    9 4
    >>> x = x(9) # Similar logic to the above line
    6 5
    >>> x = x(10) # Nothing is printed because 10 follows 9.
    >>> y = tester(4)(5)(8) # New chain, starting at 4, break at 6, first chain break
    6 1
    >>> y = y(2)(3)(10) # Chain expected 9 next, and 4 after 10. Break 2 and 3.
    9 2
    4 3
    """
    cnt = 0
    def g(y):
        def h(n):
            if (y + 1) == n:
                return g(n)
            else:
                nonlocal cnt
                cnt = cnt + 1
                print(y + 1, cnt)
                return g(n)
        return h
    return g


def cs61nay(combiner, n):
    """ Return a function that takes n arguments,
    one at a time, and combines them using combiner.

    >>> f = cs61nay(lambda x, y: x * y, 3)
    >>> f(2)(3)(4) # 2 * 3 * 4
    24
    >>> f(-1)(2)(3) # -1 * 2 * 3
    -6
    >>> f = cs61nay(lambda x, y: x - y, 4)
    >>> f(1)(2)(-2)(-1) # 1 - 2 - -2 - -1
    2
    >>> f = cs61nay(lambda x, y: x + y, 1)
    >>> f(61)
    61
    >>> f(2021)
    2021
    """
    if n == 1:
        return lambda x: x
    else:
        return lambda x: lambda y: cs61nay(combiner, n - 1)(combiner(x, y))

