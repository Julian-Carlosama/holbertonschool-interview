#!/usr/bin/python3
""" Game prime """


def isWinner(x, nums):
    """Determine who wins the game"""
    players = {"Maria": 0, "Ben": 0}

    for round in range(x):
        """Create a set of numbers from 1 to n"""
        numbers = set(i for i in range(1, nums[round] + 1))
        """Mark all multiples of primes as non-prime"""
        i = 2
        
        while i <= nums[round]:
            """Remove all multiples of i from the set"""
            numbers.difference_update(set(range(i, nums[round] + 1, i)))

            """Find the next prime number"""
            i = min(numbers, default=nums[round] + 1)
        
        """Count the number of prime numbers"""
        prime_count = len(numbers)
        
        """Determine the winner"""
        if prime_count % 2 == 0:
            winner = "Ben"
        else:
            winner = "Maria"

        """Increment the winner's score"""
        players[winner] += 1

    if players["Maria"] > players["Ben"]:
        return "Maria"
    elif players["Maria"] < players["Ben"]:
        return "Ben"
    else:
        return None
