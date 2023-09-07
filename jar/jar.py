class Jar:
    def __init__(self, capacity=12):
        if not isinstance(capacity, int) or capacity < 0:
            raise ValueError("Capacity should be a non-negative integer.")

        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return '🍪' * self._size

    def deposit(self, n):
        self._size += n
        if self._size > capacity:
            raise ValueError("Capacity reached")

    def withdraw(self, n):
        self._size -= n
        if self._size = -1:
            raise ValueError ("No more cookies")

    @property
    def capacity(self):
        return c

    @property
    def size(self):
        s = 0
        return s