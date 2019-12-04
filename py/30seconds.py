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
def bifurcate(lst, fn):
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

if __name__ == '__main__':
    print(chunk([1,2,3,4,5], 2))
