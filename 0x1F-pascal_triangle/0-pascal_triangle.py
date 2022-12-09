#!/usr/bin/python3
''' Function that Returns Pascal triangle '''


def pascal_triangle(n):
    ''' Return pascal's trinagle list if n is nonZero  '''

    if (n <= 0):
        return []

    if n == 1:
        return [[1]]
    else:
        pascal_rec = pascal_triangle(n-1)  # Use recursion
        cur_row = [1]  # Each row start with 1
        pre_row = pascal_rec[-1]

    for i in range(len(pre_row)-1):
        # Sum the 2 elelments and add this to current row
        cur_row.append(pre_row[i] + pre_row[i + 1])

    cur_row += [1]  # Each row ends with 1
    pascal_rec.append(cur_row)
    return pascal_rec
