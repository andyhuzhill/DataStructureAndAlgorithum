#pragma once
#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>

/**
 *  return the index of key in sorted vector data, return -1 if not found
 */
template<typename T>
int binary_search(T key, const std::vector<T> data) 
{
    int left = 0; 
    int right = data.size() - 1;
    int mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (data[mid] < key) {
            left = mid + 1;
        } else if (data[mid] > key) {
            right = mid - 1;
        } else {
            return mid;
        }
    }

    // not found return -1
    return -1;
}


template<typename T>
int binary_search_subrecursion(T key, int left, int right, const std::vector<T> data) 
{
    if (left > right) {
        // not found return -1
        return -1;
    }
    
    int mid = (left + right) / 2;

    if (data[mid] == key) {
        return mid;
    } else if (data[mid] < key) {
        return binary_search_subrecursion(key, left + 1, right, data);
    } else if (data[mid] > key) {
        return binary_search_subrecursion(key, left, right - 1, data);
    }
}


/**
 *  return the index of key in sorted vector data, return -1 if not found
 */
 template<typename T>
 int binary_search_recursion(T key, const std::vector<T> data) 
 {
    return binary_search_subrecursion(key, 0, data.size() - 1, data);
 }

#endif
