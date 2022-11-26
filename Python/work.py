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
            checker = (lambda f, i: lambda x: )(checker, i)
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
            def outer():
                def inner():
                    return 
                return 
            checker = 
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
    Fall 2018 Midterm 1, Question 4. Implement rect, which takes two positive
    integer arguments, perimeter and area. It returns the integer length of the longest
    side of a rectangle with integer side lengths ` and h which has the given perimeter
    and area. If no such rectangle exists, it returns False.
    The perimeter of a rectangle with sides ` and h is 2` + 2h. The area is ` ¡¤ h.
    Hint: The built-in function round takes a number as its argument and returns the
    nearest integer. For example, round(2.0) evaluates to 2, and round(2.5) evaluates
    to 3.
    Return the longest side of a rectangle with area and perimeter that has integer sides.
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
    while side * side     area:
    other = round(   )
    if    :
     
    side = side + 1
    return False
