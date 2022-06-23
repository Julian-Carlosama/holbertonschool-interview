#!/usr/bin/python3
""" Valid UTF-8 """


def validUTF8(data):
    """
        Method that determines if a given data set
        represents a valid UTF-8 encoding
    """
    counter = 0

    for numb in data:
        byte = numb & 0xFF
        """byte = format(numb, "#10b")[-8:]"""
        if counter:
            if byte >> 6 != 2:
                return False
            counter -= 1
            continue
        while (1 << abs(7 - counter)) & byte:
            counter += 1
        if counter == 1 or counter > 4:
            return False
        counter = max(counter - 1, 0)
    return counter == 0
