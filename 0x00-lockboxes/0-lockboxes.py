#!/usr/bin/python3
"""Lockboxes check if all boxes can be opened"""


def canUnlockAll(boxes):
    """Funtion to wheter the boxes can be openede or not"""
    list_of_keys = boxes[0].copy()
    true_keys = [0]
    len_box = len(boxes) - 1

    for idx, key in enumerate(list_of_keys):
        if key > len_box:
            continue
        else:
            for x in boxes[key]:
                if x not in list_of_keys:
                    if x <= len_box:
                        list_of_keys.append(x)
            if key not in true_keys:
                true_keys.append(key)

    return len(true_keys) == len(boxes)
