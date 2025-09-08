#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// =============================================================================
// EASY PROBLEMS
// =============================================================================

// 1. Valid Palindrome (LeetCode 125)
// Given a string, determine if it is a palindrome, considering only alphanumeric characters
bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    
    while (left < right) {
        // Skip non-alphanumeric characters from left
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        // Skip non-alphanumeric characters from right
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        
        // Compare characters (case insensitive)
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// 2. Reverse String (LeetCode 344)
// Write a function that reverses a string in-place
void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

// 3. Valid Anagram (LeetCode 242)
// Given two strings s and t, return true if t is an anagram of s
bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }
    
    int count[26] = {0}; // For lowercase letters
    
    // Count characters in s
    for (int i = 0; s[i]; i++) {
        count[s[i] - 'a']++;
    }
    
    // Subtract characters in t
    for (int i = 0; t[i]; i++) {
        count[t[i] - 'a']--;
    }
    
    // Check if all counts are zero
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    
    return true;
}

// 4. First Unique Character (LeetCode 387)
// Given a string s, find the first non-repeating character and return its index
int firstUniqChar(char* s) {
    int count[26] = {0};
    int len = strlen(s);
    
    // Count frequency of each character
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }
    
    // Find first character with count 1
    for (int i = 0; i < len; i++) {
        if (count[s[i] - 'a'] == 1) {
            return i;
        }
    }
    
    return -1;
}

// =============================================================================
// MEDIUM PROBLEMS
// =============================================================================

// 5. Longest Substring Without Repeating Characters (LeetCode 3)
// Given a string, find length of longest substring without repeating characters
int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;
    
    int charIndex[128]; // ASCII characters
    for (int i = 0; i < 128; i++) {
        charIndex[i] = -1;
    }
    
    int maxLength = 0;
    int start = 0;
    
    for (int end = 0; end < n; end++) {
        char currentChar = s[end];
        
        // If character is already seen and is in current window
        if (charIndex[currentChar] >= start) {
            start = charIndex[currentChar] + 1;
        }
        
        charIndex[currentChar] = end;
        maxLength = (end - start + 1 > maxLength) ? end - start + 1 : maxLength;
    }
    
    return maxLength;
}

// 6. Group Anagrams (LeetCode 49)
// Group strings that are anagrams of each other
// Note: This is a simplified version - full implementation would use hash tables
void sortString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

bool areAnagrams(char* s1, char* s2) {
    if (strlen(s1) != strlen(s2)) return false;
    
    char temp1[1000], temp2[1000];
    strcpy(temp1, s1);
    strcpy(temp2, s2);
    
    sortString(temp1);
    sortString(temp2);
    
    return strcmp(temp1, temp2) == 0;
}

// 7. String to Integer (atoi) (LeetCode 8)
// Implement the myAtoi(string s) function
int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    long result = 0;
    int n = strlen(s);
    
    // Skip leading whitespace
    while (i < n && s[i] == ' ') {
        i++;
    }
    
    // Check for sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    
    // Convert digits
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        
        // Check for overflow
        if (result * sign > INT_MAX) {
            return INT_MAX;
        }
        if (result * sign < INT_MIN) {
            return INT_MIN;
        }
        i++;
    }
    
    return (int)(result * sign);
}

// 8. Longest Palindromic Substring (LeetCode 5)
// Given a string s, return the longest palindromic substring in s
char* expandAroundCenters(char* s, int left, int right, int* maxLen, int* start) {
    int n = strlen(s);
    
    // Expand around center
    while (left >= 0 && right < n && s[left] == s[right]) {
        int currentLen = right - left + 1;
        if (currentLen > *maxLen) {
            *maxLen = currentLen;
            *start = left;
        }
        left--;
        right++;
    }
    return s;
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n <= 1) return s;
    
    int maxLen = 1;
    int start = 0;
    
    for (int i = 0; i < n; i++) {
        // Check for odd length palindromes
        expandAroundCenters(s, i, i, &maxLen, &start);
        
        // Check for even length palindromes
        expandAroundCenters(s, i, i + 1, &maxLen, &start);
    }
    
    // Create result string
    char* result = malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    
    return result;
}

// =============================================================================
// HARD PROBLEMS
// =============================================================================

// 9. Minimum Window Substring (LeetCode 76)
// Given strings s and t, return minimum window substring of s that contains all characters of t
char* minWindow(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    
    if (sLen == 0 || tLen == 0 || sLen < tLen) {
        char* empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }
    
    // Count characters in t
    int tCount[128] = {0};
    for (int i = 0; i < tLen; i++) {
        tCount[t[i]]++;
    }
    
    int required = 0; // Number of unique characters in t
    for (int i = 0; i < 128; i++) {
        if (tCount[i] > 0) required++;
    }
    
    int left = 0, right = 0;
    int formed = 0; // Number of unique chars in current window with desired frequency
    int windowCounts[128] = {0};
    
    // Result
    int minLen = INT_MAX;
    int minLeft = 0;
    
    while (right < sLen) {
        char c = s[right];
        windowCounts[c]++;
        
        if (tCount[c] > 0 && windowCounts[c] == tCount[c]) {
            formed++;
        }
        
        // Try to shrink window from left
        while (left <= right && formed == required) {
            c = s[left];
            
            // Update result if this window is smaller
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minLeft = left;
            }
            
            windowCounts[c]--;
            if (tCount[c] > 0 && windowCounts[c] < tCount[c]) {
                formed--;
            }
            left++;
        }
        right++;
    }
    
    char* result = malloc((minLen == INT_MAX ? 1 : minLen + 1) * sizeof(char));
    if (minLen == INT_MAX) {
        result[0] = '\0';
    } else {
        strncpy(result, s + minLeft, minLen);
        result[minLen] = '\0';
    }
    
    return result;
}

// 10. Regular Expression Matching (LeetCode 10)
// Given input string s and pattern p, implement regex matching with '.' and '*'
bool isMatchHelper(char* s, char* p, int sIndex, int pIndex, int sLen, int pLen) {
    // Base case: if pattern is exhausted
    if (pIndex == pLen) {
        return sIndex == sLen;
    }
    
    // Check if current characters match
    bool currentMatch = (sIndex < sLen) && 
                       (p[pIndex] == s[sIndex] || p[pIndex] == '.');
    
    // If next character is '*'
    if (pIndex + 1 < pLen && p[pIndex + 1] == '*') {
        // Two choices: skip pattern or use it if current chars match
        return isMatchHelper(s, p, sIndex, pIndex + 2, sLen, pLen) ||
               (currentMatch && isMatchHelper(s, p, sIndex + 1, pIndex, sLen, pLen));
    } else {
        // Must match current character and continue
        return currentMatch && isMatchHelper(s, p, sIndex + 1, pIndex + 1, sLen, pLen);
    }
}

bool isMatch(char* s, char* p) {
    return isMatchHelper(s, p, 0, 0, strlen(s), strlen(p));
}

// =============================================================================
// TEST FUNCTIONS
// =============================================================================

void testStringProblems() {
    printf("=== LeetCode String Problems Test Cases ===\n\n");
    
    // Test 1: Valid Palindrome
    printf("1. Valid Palindrome:\n");
    printf("\"A man, a plan, a canal: Panama\" -> %s\n", 
           isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false");
    printf("\"race a car\" -> %s\n\n", 
           isPalindrome("race a car") ? "true" : "false");
    
    // Test 2: Reverse String
    printf("2. Reverse String:\n");
    char test2[] = "hello";
    printf("Before: %s\n", test2);
    reverseString(test2, 5);
    printf("After: %s\n\n", test2);
    
    // Test 3: Valid Anagram
    printf("3. Valid Anagram:\n");
    printf("\"anagram\", \"nagaram\" -> %s\n", 
           isAnagram("anagram", "nagaram") ? "true" : "false");
    printf("\"rat\", \"car\" -> %s\n\n", 
           isAnagram("rat", "car") ? "true" : "false");
    
    // Test 4: First Unique Character
    printf("4. First Unique Character:\n");
    printf("\"leetcode\" -> %d\n", firstUniqChar("leetcode"));
    printf("\"loveleetcode\" -> %d\n\n", firstUniqChar("loveleetcode"));
    
    // Test 5: Longest Substring Without Repeating Characters
    printf("5. Longest Substring Without Repeating Characters:\n");
    printf("\"abcabcbb\" -> %d\n", lengthOfLongestSubstring("abcabcbb"));
    printf("\"bbbbb\" -> %d\n\n", lengthOfLongestSubstring("bbbbb"));
    
    // Test 6: String to Integer (atoi)
    printf("6. String to Integer (atoi):\n");
    printf("\"42\" -> %d\n", myAtoi("42"));
    printf("\"   -42\" -> %d\n", myAtoi("   -42"));
    printf("\"4193 with words\" -> %d\n\n", myAtoi("4193 with words"));
    
    // Test 7: Longest Palindromic Substring
    printf("7. Longest Palindromic Substring:\n");
    char* result7 = longestPalindrome("babad");
    printf("\"babad\" -> %s\n", result7);
    free(result7);
    
    result7 = longestPalindrome("cbbd");
    printf("\"cbbd\" -> %s\n\n", result7);
    free(result7);
    
    // Test 8: Minimum Window Substring
    printf("8. Minimum Window Substring:\n");
    char* result8 = minWindow("ADOBECODEBANC", "ABC");
    printf("s=\"ADOBECODEBANC\", t=\"ABC\" -> \"%s\"\n", result8);
    free(result8);
    
    result8 = minWindow("a", "a");
    printf("s=\"a\", t=\"a\" -> \"%s\"\n\n", result8);
    free(result8);
    
    // Test 9: Regular Expression Matching
    printf("9. Regular Expression Matching:\n");
    printf("s=\"aa\", p=\"a\" -> %s\n", 
           isMatch("aa", "a") ? "true" : "false");
    printf("s=\"aa\", p=\"a*\" -> %s\n", 
           isMatch("aa", "a*") ? "true" : "false");
    printf("s=\"ab\", p=\".*\" -> %s\n", 
           isMatch("ab", ".*") ? "true" : "false");
}

int main() {
    testStringProblems();
    return 0;
}
