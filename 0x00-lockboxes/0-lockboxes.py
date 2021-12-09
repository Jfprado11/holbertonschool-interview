#!/usr/bin/python3
"""Lockboxes check if all boxes can be opened"""


def canUnlockAll(boxes):
    """Funtion to wheter the boxes can be openede or not"""
    list_of_keys = [0]
    len_box = len(boxes) - 1
    for key in boxes:
        for item in key:
            if item <= len_box and item not in list_of_keys:
                list_of_keys.append(item)

    print(list_of_keys)
    return len(list_of_keys) == len(boxes)
