"""
Generate a random DNA sequence of user-defined size.
"""

import random
import sys

def gen_sequence(size):
    return ''.join(random.choice('CGTA') for _ in range(size))
    
length = int(sys.argv[1])

sequence = gen_sequence(length)

fh = open("SEQUENCE", "w")
fh.write(sequence)
fh.close()

