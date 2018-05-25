"""
Program: CS 115 Lab 10
Author: Your name
Description: This program will open a file and then search its contents
             using linear and binary search.
"""


def readfile(filename):
    """
    Reads the entire contents of a file into a single string using
    the read() method.

    Parameter: the name of the file to read (as a string)
    Returns: the text in the file as a large, possibly multi-line, string
    """

    infile = open(filename, "r")  # open file for reading

    # Use Python's file read function to read the file contents
    filetext = infile.read().splitlines()

    infile.close()  # close the file

    return filetext  # the text of the file, as a single string


def print_list(list_to_print):
    """
    Print the contents of a list.

    Parameter: the list to print
    Returns: nothing
    """

    for i, item in enumerate(list_to_print):
        print(i, ': ', item, sep="")


def linear_search(search_list, value_to_find):
    """
    Uses a hand-coded linear search to find the position of an item in a list

    Parameters: the list; the item to search for
    Returns: the position of the item in the list
        (or None if it is not in the list)
    """

    for i in range(len(search_list)):
        if search_list[i] == value_to_find:
            return i


import sys


def main():
    """ Read and print a file's contents. """

    filename = str(input('Name of input file: '))

    num_lines = int(input('Number of lines in file: '))

    string = readfile(filename)

    print(string)

    sum=0
    for i in range (len(string)):
        sum+=1

    print(sum)

main()