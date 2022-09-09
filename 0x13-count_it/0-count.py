#!/usr/bin/python3
"""
0-main
"""
import requests


def count_words(subreddit, word_list):
    hot_titles = recursive(subreddit, word_list, {})
    if hot_titles:
        for key, values in sorted(hot_titles.items(), key=lambda val: val[1],
                                  reverse=True):
            if values != 0:
                print('{}: {}'.format(key, values))


def recursive(subreddit, word_list, hot_titles, after=""):
    headers = {'User-Agent': 'Carlosam'}
    params = {"limit": 100, 'after': after}
    sub = subreddit
    url = "https://www.reddit.com/r/{}/hot/.json".format(sub)
    respons = requests.get(url, headers=headers, params=params)

    # handles error response; invalid subreddit
    if respons.status_code is not 200:
        return None
    if after is None:
        return hot_titles

    for i in respons.json().get('data').get('children'):
        title_s = i.get('data').get('title').split()
        for word in set(word_list):
            if word.lower() in [x.lower() for x in title_s]:
                if hot_titles.get(word):
                    hot_titles[word] += 1
                else:
                    hot_titles[word] = 1

    after = respons.json().get('data').get('after')
    recursive(subreddit, word_list, hot_titles, after)
    return hot_titles
