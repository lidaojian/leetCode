//
//  longestSubstringWithoutRepeatingCharacters.c
//  LeetCode
//
//  Created by lidaojian on 2018/1/12.
//  Copyright © 2018年 lidaojian. All rights reserved.
//

#include "longestSubstringWithoutRepeatingCharacters.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 Longest Substring Without Repeating Characters
 
 Given a string, find the length of the longest substring without repeating characters.
 
 Examples:
 
 Given "abcabcbb", the answer is "abc", which the length is 3.
 
 Given "bbbbb", the answer is "b", with the length of 1.
 
 Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

/*
 983 / 983 test cases passed.
 Status: Accepted
 Runtime: 236 ms
 **/
int lengthOfLongestSubstring(char* s) {
    long len = strlen(s);
    if (!len) {
        return 0;
    }
    int i, j, k;
    bool repeat = false;
    int temp, maxlen = -1;
    for (i = 0; i < len; i ++) {
        temp = 1;
        repeat = false;
        j = i + 1;
        while (j < len && !repeat) {
            k = i;
            while (k < j) {
                if (s[k] != s[j]) {
                    k ++;
                } else {
                    repeat = true;
                    break;
                }
            }
            if (k == j) {
                j ++;
                temp ++;
            }
        }
        maxlen = maxlen < temp ? temp :maxlen;
    }
    return maxlen;
}

/**
 Submission Detail
 983 / 983 test cases passed.
 Status: Accepted
 Runtime: 24 ms
 */
int lengthOfLongestSubstring_method2(char* s) {
    int maxlen = 0, currentlen = 0;
    int numChar[128], i, j, start = 0;
    memset(numChar, 0, sizeof(numChar));
    for (i = 0; s[i] != '\0'; i ++) {
        if (++numChar[s[i]] == 2) {
            if (currentlen > maxlen) {
                maxlen = currentlen;
            }
            for (j = start; j < i; j ++) {
                if (s[i] == s[j]) {
                    numChar[s[j]] = 1;
                    start = j + 1;
                    break;
                } else {
                    currentlen--;
                    numChar[s[j]] = 0;
                }
            }
        } else {
            currentlen++;
        }
        if (currentlen > maxlen) {
            maxlen = currentlen;
        }
    }
    return maxlen;
}

