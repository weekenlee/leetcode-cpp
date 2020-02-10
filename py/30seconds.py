#all_equal
def all_equal(lst):
    return lst[1:] == lst[:-1]

#all_unique
def all_unique(lst):
    return len(lst) == len(set(lst))

#bifurcate , splits values into two groups, if an element in filter is true
def bifurcate(lst, filterm):
    return [
            [x for i, x in enumerate(lst) if filterm[i] == True],
            [x for i, x in enumerate(lst) if filterm[i] == False]
            ]

#bifurcate_by, splites values into two groups according to a function
def bifurcate_by(lst, fn):
    return [
            [x for x in lst if fn(x)],
            [x for x in lst if not fn(x)]
            ]

#chunk, chunks a list into smaller lists of a specified size
from math import ceil
def chunk(lst, size):
    return list(
            map(lambda x : lst[x * size:x*size + size],
                list(range(0, ceil(len(lst)/size))))
            )

#compact , filter out falsey values
def compact(lst):
    return list(filter(bool, lst))

#count_by, groups the elements of a list based on given function
def count_by(arr, fn = lambda x : x):
    key = {}
    for el in map(fn, arr):
        key[el] = 0 if el not in key else key[el]
        key[el] += 1
    return key

#count_occurentces, counts the occurrences of a value in a list
def count_occurences(lst, val):
    return len([x for x in lst if x == val and type(x) == type(val)])

#deep_flatten
def spread(arg):
    ret = []
    for i in arg:
        if isinstance(i, list):
            ret.extend(i)
        else:
            ret.append(i)
    return ret

def deep_flatten(lst):
    result = []
    result.extend(
            spread(list(map(lambda x : deep_flatten(x) if type(x) == list else x, lst)))
            )
    return result

#difference , diff between two iterables
def difference(a, b):
    _b = set(b)
    return [item for item in a if item not in _b]

#diffence_by, diff between two lists
def difference_by(a, b, fn):
    _b = set(map(fn, b))
    return [item for item in a if fn(item) not in _b]

#every, return true if the provied function returns true for every element
def every(lst, fn = lambda x : not not x):
    for el in lst:
        if not fn(el):
            return False
    return True

#every_nth, return every nth element in a list
def every_nth(lst, nth):
    return lst[1::nth]

#filter_non_unique, filters out the non-unique values in a list
def filter_non_unique(lst):
    return [item for item in lst if lst.count(item) == 1]

#group the elements of a list based on the given function
def group_by(lst, fn):
    groups = {}
    for key in list(map(fn, lst)):
        groups[key] = [item for item in lst if fn(item) == key]
    return groups

#has duplicates, return true if there are duplicate values in a flast list
def has_duplicates(lst):
    return len(lst) != len(set(lst))

#head , return the head of a list
def head(lst):
    return lst[0]

#initial, return all the elements of a list except the last one
def initial(lst):
    return lst[0:-1]

#initialize_2d_list, initialize a 2d list of given width and height and value
def initialize_2d_list(w, h, val = None):
    return [[val for x in range(w)] for y in range(h)]

#initializes a list containing the numbers in the specified range
def initialize_list_with_range(end, start = 0, step = 1):
    return list(range(start, end + 1, step))

#initialize_list_with_values
def initialize_list_with_values(n, val = 0):
    return [val for x in range(n)]

#intersection, return a list of elements that exist in both lists
def intersection(a, b):
    _b = set(b)
    return [item for item in a if item in _b]

#intersection_by, return a list of elements that exist in both lists, after apply the fun to each element of both
def intersection_by(a, b, fn):
    _b = set(map(fn, b))
    return [item for item in a if fn(item) in _b]

#last, return the last element in a list
def last(lst):
    return lst[-1]

#longest_item
def longest_item(*args):
    return max(args, key = len)

#max_n
def max_n(lst, n=1):
    return sorted(lst, reverse=True)[:n]

#min_n
def min_n(lst, n=1):
    return sorted(lst, reverse=False)[:n]

#none, return false if the provided function returns ture for at least one element in the list
def none(lst, fn = lambda x: not not x):
    for el in lst:
        if fn(el):
            return False
    return True

#offset, move the specified amount of elements to the end of the list
def offset(lst, offset):
    return lst[offset:] + lst[:offset]

#sample, return a random element from an array
from random import randint
def sample(lst):
    return lst[randint(0, len(lst) - 1)]

#shuffle , randonmizes the order of the values of an list, return a new list
from copy import deepcopy
from random import randint
def shuffle(lst):
    temp_lst = deepcopy(lst)
    m = len(temp_lst)
    while(m):
        m -= 1
        i = randint(0, m)
        temp_lst[m], temp_lst[i] = temp_lst[i], temp_lst[m]
    return temp_lst

#similarity , return a list of elments that exist in both lists
def similarity(a, b):
    return [item for item in a if item in b]


if __name__ == '__main__':
    print(chunk([1,2,3,4,5], 2))
    print(deep_flatten([1, [2], [[3], 4], 5]))
