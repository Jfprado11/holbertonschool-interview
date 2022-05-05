#!/usr/bin/python3
"""moduel to resolve problem of the api
"""
import requests


def count_words(subreddit, word_list, idx=0, data_send={}, after="", keys=""):
    """Funtion recursively resolve the problem of fetching data in reddit"""
    params = {"limit": 1, "after": after}
    headers = {"User-agent": "holbie"}
    data = requests.get("https://www.reddit.com/r/{}/hot.json".format(
        subreddit), allow_redirects=False,
        params=params, headers=headers)
    if data.status_code == 200:
        data = data.json()
        posts = data["data"]["children"]
        if after is not None:
            title = posts[0]["data"]["title"].lower().split()
            if idx < len(word_list):
                looking_word = word_list[idx].lower()
                if looking_word in title:
                    if looking_word in data_send:
                        data_send[looking_word] += 1
                    else:
                        data_send[looking_word] = 1
                    print(data_send)
                return count_words(subreddit, word_list,
                                   idx + 1, data_send, after)
            else:
                after = data["data"]["after"]
                return count_words(subreddit, word_list, 0, data_send, after)
        else:
            keys = list(data_send.keys())
            values = list(data_send.values())
            if len(keys) != 0:
                print("{}: {}".format(keys[0], values[0]))
                del data_send[keys[0]]
            else:
                keys = None
            if keys is not None:
                return count_words(subreddit, word_list, 0,
                                   data_send, None, keys)
            return
