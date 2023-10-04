/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:27:34 by marvin            #+#    #+#             */
/*   Updated: 2023/10/03 14:27:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <assert.h>

/*ATOI unit test*/
void unit_atoi()
{
    const char *test_cases[] = {
        "12345",
        "-54321",
        "0",
        "42 with additional text",
        "abc",
        "   123  ",
        "   -456  ",
        "   +789  ",
        "2147483647",  // Maximum positive integer
        "-2147483648", // Minimum negative integer
        "99999999999999999999999999999999999999999999", // Too large for int
        "   123.45  ", // Not a valid integer
        "   -12.34  ", // Not a valid integer
    };

    int expected_results[] = {
        12345,
        -54321,
        0,
        42,
        0,
        123,
        -456,
        789,
        2147483647,
        -2147483648,
        0, // Overflow, expected result is undefined
        123, // Parsing stops at the decimal point
        -12, // Parsing stops at the decimal point
    };

    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    for (size_t i = 0; i < num_tests; i++) {
        int result = ft_atoi(test_cases[i]);
        printf("Test Case %zu: %s -> Expected: %d, Actual: %d\n", i + 1, test_cases[i], expected_results[i], result);
        assert(result == expected_results[i]);
    }

    printf("All tests passed!\n");
}

void unit_bzero() {
    const char *test_cases[] = {
        "Hello, World!",
        "",
        "12345",
        "\0\0\0\0\0\0",
    };

    size_t test_lengths[] = { 13, 0, 5, 6 }; 

    for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        char buffer[20];
        strcpy(buffer, test_cases[i]);

        ft_bzero(buffer, test_lengths[i]);

        for (size_t j = 0; j < test_lengths[i]; j++) {
            assert(buffer[j] == '\0');
        }

        printf("Test Case %zu passed!\n", i + 1);
    }

    printf("All tests passed!\n");
}

void unit_isalnum() {
    char test_cases[] = {
        'A', 'a', 'B', 'b', 'C', 'c', 'Z', 'z', '0', '9',
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
        '\n', '\t', ' ', '\0'
    };

    int expected_results[] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0
    };

    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_tests; i++) {
        int result = ft_isalnum(test_cases[i]);
        printf("Test Case %zu: '%c' -> Expected: %d, Actual: %d\n", i + 1, test_cases[i], expected_results[i], result);
        assert(result == expected_results[i]);
    }

    printf("All tests passed!\n");
}

void unit_isalpha() {
    char test_cases[] = {
        'A', 'a', 'B', 'b', 'C', 'c', 'Z', 'z', '0', '9',
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
        '\n', '\t', ' ', '\0'
    };

    int expected_results[] = {
        1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0
    };

    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_tests; i++) {
        int result = ft_isalpha(test_cases[i]);
        printf("Test Case %zu: '%c' -> Expected: %d, Actual: %d\n", i + 1, test_cases[i], expected_results[i], result);
        assert(result == expected_results[i]);
    }

    printf("All tests passed!\n");
}

void unit_isascii() {
    int test_cases[] = {
        'A', 'a', 'B', 'b', 'C', 'c', 'Z', 'z', '0', '9',
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
        '\n', '\t', ' ', '\0', 128, 255
    };

    int expected_results[] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 0, 0
    };

    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_tests; i++) {
        int result = ft_isascii(test_cases[i]);
        printf("Test Case %zu: '%c' (%d) -> Expected: %d, Actual: %d\n", i + 1, test_cases[i], test_cases[i], expected_results[i], result);
        assert(result == expected_results[i]);
    }

    printf("All tests passed!\n");
}

void unit_isdigit() {
    char test_cases[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'a', 'B', 'b', 'C', 'c', 'Z', 'z', '!',
        '@', '#', '$', '%', '^', '&', '*', '(', ')',
        '\n', '\t', ' ', '\0'
    };

    int expected_results[] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0
    };

    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_tests; i++) {
        int result = ft_isdigit(test_cases[i]);
        printf("Test Case %zu: '%c' (%d) -> Expected: %d, Actual: %d\n", i + 1, test_cases[i], test_cases[i], expected_results[i], result);
        assert(result == expected_results[i]);
    }

    printf("All tests passed!\n");
}

void unit_isprint() {
    // Test cases
    char test_cases[] = {
        ' ', '!', '\'', '(', ')',
        'z', '{', '|', '}', '~', 
        '\n', '\t', '\0', -1
    };

    int expected_results[] = {
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        0, 0, 0, 0
    };

    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_tests; i++) {
        int result = ft_isprint(test_cases[i]);
        printf("Test Case %zu: '%c' (%d) -> Expected: %d, Actual: %d\n", i + 1, test_cases[i], test_cases[i], expected_results[i], result);
        assert(result == expected_results[i]);
    }

    printf("All tests passed!\n");
}

void unit_memchr() {

    char *test_cases[] = {
        "Hello World", 
        "42 school",
        "Hello, World!"
    };

    int search_results[] = {
        'o', 's', '2'
    };

    int expected_results[] = {
        'o', 's', 0
    };

    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_tests; i++)
    {
        char buffer[20];
        strcpy(buffer, test_cases[i]);

        void *result = ft_memchr(buffer, search_results[i], sizeof(buffer) - 1);  // - 1 to ignore the null terminator
        if(expected_results[i] != NULL)
            assert(((char*)result)[0] == expected_results[i]);
        else   
            assert(result == expected_results[i]);
        printf("Test Case %zu passed!\n", i + 1);
    }

    printf("All tests passed!\n");
}

void unit_memcmp() {

    char *test_cases[] = {
        "Hello World", 
        "42 school",
        "Hello, World!",
        "Hello, Coder!"
    };

    char *test_cases2[] = {
        "Hello World", 
        "42 school",
        "Hello, Coder!",
        "Hello, orld!"
    };

    int expected_results[] = { // this can also be like (0, 0, 1, -1) just depends on how you coded memcmp. but i aint gonna be adding support for the ones that coded like that 
        0, 0, 20, -44
    };

    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_tests; i++)
    {
        char buffer[20];
        strcpy(buffer, test_cases[i]);
        char buffer2[20];
        strcpy(buffer2, test_cases2[i]);
        int result = ft_memcmp(buffer, buffer2, strlen(test_cases[i]) - 1); // - 1 to ignore the null terminator
        assert(result == expected_results[i]);
        printf("Test Case %zu passed!\n", i + 1);
    }
    
    printf("All tests passed!\n");
}

void unit_memcpy() {
    char test_cases[][20] = {
        "Hello, World!", 
        "42 school",
        "Programming",
        "memcpy test"
    };

    char expected_results[][20] = {
        "Hello, World!", 
        "42 school",
        "Programming",
        "memcpy test"
    };

    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_tests; i++) {
        char dest[20];
        ft_memcpy(dest, test_cases[i], strlen(test_cases[i]) + 1); // + 1 to include the null terminator
        assert(strcmp(dest, expected_results[i]) == 0);
        printf("Test Case %zu passed!\n", i + 1);
    }
    
    printf("All tests passed!\n");
}

void unit_memmove() {
    char test_cases[][20] = {
        "Hello, World!", 
        "42 school",
        "Programming",
        "memmove test"
    };

    char expected_results[][20] = {
        "Hello, World!", 
        "42 school",
        "Programming",
        "memmove test"
    };

    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_tests; i++) {
        char dest[20];
        ft_memmove(dest, test_cases[i], strlen(test_cases[i]) + 1); // +1 to include the null terminator
        assert(strcmp(dest, expected_results[i]) == 0);
        printf("Test Case %zu passed!\n", i + 1);
    }

    for (size_t i = 0; i < num_tests; i++) {
        char dest[20];
        char* new_dest = ft_memmove(dest, test_cases[i], strlen(test_cases[i]) + 1); // +1 to include the null terminator
        assert(strcmp(new_dest, expected_results[i]) == 0);
        printf("Test2 Case %zu passed!\n", i + 1);
    }
    char fuck[] = "Hello, ";
    const char *fuck2 = "Hello, World!";
    ft_memmove(fuck, fuck2, strlen(fuck2) + 1);
    assert(strcmp(fuck, "Hello, World!") == 0);

    printf("All tests passed!\n");
}

void unit_memset() {
    char buffer[20];

    ft_memset(buffer, 'A', 10);
    for (size_t i = 0; i < 10; i++) {
        assert(buffer[i] == 'A');
    }
    printf("Test Case 1 passed!\n");
    ft_memset(buffer + 5, 'B', 5);
    for (size_t i = 0; i < 5; i++) {
        assert(buffer[i] == 'A');
        assert(buffer[i + 5] == 'B');
    }
    printf("Test Case 2 passed!\n");
    ft_memset(buffer + 5, 'C', 1);
    assert(buffer[5] == 'C');
    printf("Test Case 3 passed!\n");
    //sorry got lazy
    printf("All tests passed!\n");
}

void unit_strchr()
{
       // Test data
    const char *test_strings[] = {
        "Hello, World!",
        "This is a test",
        "Search for 's'",
        "No match here"
    };

    char expected_results[] = {
        NULL,
        's',
        's',
        '\0'
    };

    size_t num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (size_t i = 0; i < num_tests; i++) {
        char *result = ft_strchr(test_strings[i], 's');
        if(expected_results[i] == NULL)
            assert(result == expected_results[i]);
        else
            assert(result[0] == expected_results[i]);
        printf("Test Case %zu passed!\n", i + 1);
    }

    printf("All tests passed!\n");
}

void unit_strjoin()
{
    const char *s1[] = {
        "Hello, ",
        "This is a ",
        "Concatenation ",
        "Empty String ",
    };

    const char *s2[] = {
        "World!",
        "test",
        "of Two Strings",
        ""
    };

    const char *expected_results[] = {
        "Hello, World!",
        "This is a test",
        "Concatenation of Two Strings",
        "Empty String "
    };

    size_t num_tests = sizeof(s1) / sizeof(s1[0]);

    for (size_t i = 0; i < num_tests; i++) {
        char *result = ft_strjoin(s1[i], s2[i]);
        assert(strcmp(result, expected_results[i]) == 0);
        free(result); // Free the memory allocated by ft_strjoin
    }

    printf("All tests passed!\n");
}


void unit_strlcpy() {
    // Test data
    char dst[20];
    const char *src[] = {
        "Hello, ",
        "This is a ",
        "String",
        "Testing",
        "World!",
        "test",
        "of Two Strings",
        ""
    };

    const size_t sizes[] = {
        20,
        10,
        15,
        10,
        7,
        3,
        20,
        5
    };

    const char *expected_results[] = {
        "Hello, ",
        "This is a",
        "String",
        "Testing",
        "World!",
        "te",
        "of Two Strings",
        ""
    };

    size_t num_tests = sizeof(src) / sizeof(src[0]);

    for (size_t i = 0; i < num_tests; i++) {
        strcpy(dst, src[i]);
        size_t result = ft_strlcpy(dst, src[i], sizes[i]);
        printf("Test Case %zu: %s -> Expected: %s, Actual: %s\n", i + 1, src[i], expected_results[i], dst);
        assert(strcmp(dst, expected_results[i]) == 0);
        printf("Checking return value for test case %zu\n", i + 1);
        assert(result == strlen(src[i]));
        printf("Test Case %zu passed!\n", i + 1);
    }

    printf("All tests passed!\n");
}

void unit_strlen()
{
       const char *test_strings[] = {
        "Hello, World!",
        "This is a test.",
        "",
        "12345",
        "A",
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
        "abcdefghijklmnopqrstuvwxyz",
        "1234567890",
        "Testing strlen function",
        "The quick brown fox jumps over the lazy dog."
    };

    size_t expected_lengths[] = {
        13,
        15,
        0,
        5,
        1,
        56,
        26,
        10,
        23,
        44
    };

    size_t num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (size_t i = 0; i < num_tests; i++) {
        size_t result = ft_strlen(test_strings[i]);
        printf("Test Case %zu: \"%s\" -> Expected: %zu, Actual: %zu\n", i + 1, test_strings[i], expected_lengths[i], result);
        assert(result == expected_lengths[i]);
        printf("Test Case %zu passed!\n", i + 1);
    }

    printf("All tests passed!\n");
}

void unit_strncmp()
{
     const char *str1[] = {
        "Hello, World!",
        "This is a test.",
        "12345",
        "abcde",
        "abcdef",
        "abcdefgh",
        "123",
        "xyz",
        "Test",
        "The quick brown fox\xFF",
        "The quick brown fox\xFF"
    };

    const char *str2[] = {
        "Hello, World!",
        "This is a test.",
        "12345",
        "abcde",
        "abcdee",
        "abcdegh",
        "123",
        "xyzz",
        "test",
        "The quick brown fox",
        "The quick brown fox"
    };

    int n_values[] = {
        13,
        5,
        10,
        3,
        6,
        7,
        1,
        4,
        4,
        21,
        10
    };

    //Once again, this can be -1, 1, but just depends how you coded it. i do s1 - s2 to get the value between it so it will be higher than -1 or 1.
    int expected_results[] = {
        0,
        0,
        0,
        0,
        1,
        -1,
        0,
        -122,
        -32,
        255,
        0
    };

    size_t num_tests = sizeof(str1) / sizeof(str1[0]);

    for (size_t i = 0; i < num_tests; i++) {
        int result = ft_strncmp(str1[i], str2[i], n_values[i]);
        printf("Test Case %zu: \"%s\" vs \"%s\" (n = %d) -> Expected: %d, Actual: %d\n", i + 1, str1[i], str2[i], n_values[i], expected_results[i], result);
        assert(result == expected_results[i]);
        printf("Test Case %zu passed!\n", i + 1);
    }

    printf("All tests passed!\n");
}

void unit_strnstr()
{
     const char *big[] = {
        "Hello, World!",
        "This is a test.",
        "12345",
        "abcde",
        "abcdef",
        "abcdefgh",
        "123",
        "xyz",
        "Test",
        "The quick brown fox",
        "Test2",
    };

    const char *little[] = {
        "World",
        "test",
        "45",
        "cd",
        "def",
        "efgh",
        "23",
        "z",
        "Te",
        "jump",
        "\0",
    };

    size_t len_values[] = {
        13,
        16,
        5,
        5,
        7,
        8,
        3,
        3,
        2,
        20,
        4,
    };

    const char *expected_results[] = {
        "World!",
        "test.",
        "45",
        "cde",
        "def",
        "efgh",
        "23",
        "z",
        "Test",
        NULL,
        "Test2",
    };

    size_t num_tests = sizeof(big) / sizeof(big[0]);

    for (size_t i = 0; i < num_tests; i++) {
        char *result = ft_strnstr(big[i], little[i], len_values[i]);
        printf("Test Case %zu: \"%s\" in \"%s\" (len = %zu) -> Expected: \"%s\", Actual: \"%s\"\n", i + 1, little[i], big[i], len_values[i], expected_results[i], result);
        if (expected_results[i] == NULL) {
            assert(result == NULL);
        } else {
            assert(strcmp(result, expected_results[i]) == 0);
        }
        printf("Test Case %zu passed!\n", i + 1);
    }

    printf("All tests passed!\n");
}

void unit_strrchr()
{
     const char *test_strings[] = {
        "Hello, World!",
        "This is a test.",
        "12345",
        "abcdefg",
        "abcdabcd",
        "abcdefgh",
        "123",
        "xyz",
        "Test",
        "The quick brown fox"
    };

    int characters_to_find[] = {
        'o',
        't',
        '4',
        'c',
        'd',
        'h',
        '3',
        'z',
        'T',
        'k'
    };

    const char *expected_results[] = {
        "orld!",
        "t.",
        "45",
        "cdefg",
        "d",
        "h",
        "3",
        "z",
        "Test",
        "k brown fox"
    };

    size_t num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (size_t i = 0; i < num_tests; i++) {
        char *result = ft_strrchr(test_strings[i], characters_to_find[i]);
        printf("Test Case %zu: Searching for '%c' in \"%s\" -> Expected: \"%s\", Actual: \"%s\"\n", i + 1, characters_to_find[i], test_strings[i], expected_results[i], result);
        assert((result == NULL && expected_results[i] == NULL) || (result != NULL && strcmp(result, expected_results[i]) == 0));
        printf("Test Case %zu passed!\n", i + 1);
    }

    printf("All tests passed!\n");
}

void unit_strtrim()
{
        const char *test_strings[] = {
        "   Hello, World!   ",
        "   This is a test.   ",
        "12345",
        "   abcdefg   ",
        "   abcdabcd   ",
        "   abcdefgh   ",
        "   123   ",
        "xyz",
        "   Test",
        "The quick brown fox   "
    };

    const char *set[] = {
        " ",
        " .",
        "135",
        "acg",
        "bd",
        "efh",
        "23 ",
        "z",
        "T e",
        "o"
    };

    const char *expected_results[] = {
        "Hello, World!",
        "This is a test",
        "234",
        "   abcdefg   ",
        "   abcdabcd   ",
        "   abcdefgh   ",
        "1",
        "xy",
        "st",
        "The quick brown fox   "
    };

    size_t num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (size_t i = 0; i < num_tests; i++) {
        char *result = ft_strtrim(test_strings[i], set[i]);
        printf("Test Case %zu: Trim \"%s\" with \"%s\" -> Expected: \"%s\", Actual: \"%s\"\n", i + 1, test_strings[i], set[i], expected_results[i], result);
        assert(strcmp(result, expected_results[i]) == 0);
        free(result); // Free the memory allocated by ft_strtrim
        printf("Test Case %zu passed!\n", i + 1);
    }

    printf("All tests passed!\n");
}

void unit_substr(void) {
    const char *test_strings[] = {
        "Hello, World!",
        "This is a test.",
        "12345",
        "abcdefg",
    };

    unsigned int start_values[] = {
        0,
        5,
        2,
        1,
    };

    size_t len_values[] = {
        5,
        5,
        3,
        6,
    };

    const char *expected_results[] = {
        "Hello",
        "is a ",
        "345",
        "bcdefg",
    };

    size_t num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (size_t i = 0; i < num_tests; i++) {
        char *result = ft_substr(test_strings[i], start_values[i], len_values[i]);
        printf("Test Case %zu: Substring of \"%s\" starting at %u with length %zu -> Expected: \"%s\", Actual: \"%s\"\n", i + 1, test_strings[i], start_values[i], len_values[i], expected_results[i], result);
        assert(strcmp(result, expected_results[i]) == 0);
        free(result); // Free the memory allocated by ft_substr
        printf("Test Case %zu passed!\n", i + 1);
    }

    printf("All tests passed!\n");
}

void unit_tolower() {
    int test_characters[] = {
        'A',
        'B',
        'Z',
        'a',
        'b',
        'z',
        '1',
        '9',
        '@',
        ' '
    };

    int expected_results[] = {
        'a',
        'b',
        'z',
        'a',
        'b',
        'z',
        '1',
        '9',
        '@',
        ' '
    };

    size_t num_tests = sizeof(test_characters) / sizeof(test_characters[0]);

    for (size_t i = 0; i < num_tests; i++) {
        int result = ft_tolower(test_characters[i]);
        printf("Test Case %zu: Convert '%c' to lowercase -> Expected: '%c', Actual: '%c'\n", i + 1, test_characters[i], expected_results[i], result);
        assert(result == expected_results[i]);
        printf("Test Case %zu passed!\n", i + 1);
    }

    printf("All tests passed!\n");
}

void unit_toupper() {
    int test_characters[] = {
        'A',
        'B',
        'Z',
        'a',
        'b',
        'z',
        '1',
        '9',
        '@',
        ' '
    };

    int expected_results[] = {
        'A',
        'B',
        'Z',
        'A',
        'B',
        'Z',
        '1',
        '9',
        '@',
        ' '
    };

    size_t num_tests = sizeof(test_characters) / sizeof(test_characters[0]);

    for (size_t i = 0; i < num_tests; i++) {
        int result = ft_toupper(test_characters[i]);
        printf("Test Case %zu: Convert '%c' to uppercase -> Expected: '%c', Actual: '%c'\n", i + 1, test_characters[i], expected_results[i], result);
        assert(result == expected_results[i]);
        printf("Test Case %zu passed!\n", i + 1);
    }

    printf("All tests passed!\n");
}

void unit_split() {
    const char* test_strings[] = {
        "Hello,World!This is,a,test",
        "    Hello  ,World!,This is,a,,,test  ",
        ",",
        ", hello, hi"
    };

    char delimiter = ',';

    const char* expected_results[][6] = {
        {"Hello", "World!This is", "a", "test", NULL},
        {"    Hello  ", "World!", "This is", "a", "test  "},
        {""},
        {" hello", " hi"}
    };

    size_t num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (size_t i = 0; i < num_tests; i++) {
        char** result = ft_split(test_strings[i], delimiter);
        int ii = 0;
        while(result[ii] != NULL)
        {
            printf("Test case %zu: Expected: %s, Actual: %s\n", i + 1, expected_results[i][ii], result[ii]);
            assert(strcmp(result[ii], expected_results[i][ii]) == 0);
            ii++;
        }
        printf("Test Case %zu passed!\n", i + 1);
    }
    printf("All tests passed!\n");
}

void unit_itoa() {
    int test_numbers[] = {
        12345,
        -9876,
        0,
        999999,
        -999999,
        2147483647,
        -2147483648
    };

    const char* expected_results[] = {
        "12345",
        "-9876",
        "0",
        "999999",
        "-999999",
        "2147483647",
        "-2147483648"
    };

    size_t num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);

    for (size_t i = 0; i < num_tests; i++) {
        char* result = ft_itoa(test_numbers[i]);
        const char* expected = expected_results[i];

        printf("Test Case %zu: Convert %d to string -> Expected: \"%s\", Actual: \"%s\"\n", i + 1, test_numbers[i], expected, result);
        assert(strcmp(result, expected) == 0);
        free(result);
        printf("Test Case %zu passed!\n", i + 1);
    }

    printf("All tests passed!\n");
}

void unit_calloc()
{
    printf("Testing calloc\n");
    void* ptr = ft_calloc(200, sizeof(char));
    for(int i = 0; i< 200; i++)
    {
        assert(((char*)ptr)[i] == 0);
    }
    printf("All tests passed !\n");
}

void unit_strdup()
{
    const char* test_numbers[] = {
        "12345",
        "testing a longer string if that works",
        "",
        "42 ",
    };

    const char* expected_results[] = {
        "12345",
        "testing a longer string if that works",
        "",
        "42 ",
    };

    int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);
    for(int i = 0; i < num_tests; i++)
    {
        char* result = ft_strdup(test_numbers[i]);
        printf("Test Case %zu: Convert %d to string -> Expected: \"%s\", Actual: \"%s\"\n", i + 1, test_numbers[i], expected_results[i], result);
        if(expected_results[i] == NULL)
            assert(result == expected_results[i]);
        else
            assert(strcmp(result, expected_results[i]) == 0);
        if(expected_results[i] != NULL)
            free(result);
        printf("Test Case %zu passed!\n", i + 1);
    }
    printf("All tests passed !\n");
}


//Can't think of a nice way to unit test strlcat. :(
//TODO: ADD FT_STRLCAT

typedef void (*unit_test_cb)(void);

typedef struct s_unit_test {
    unit_test_cb callback;
    char *name;
} t_unit_test;

static const t_unit_test unit_tests[] = {
    { .name = "ft_atoi",    .callback = unit_atoi },
    { .name = "ft_bzero",   .callback = unit_bzero },
    { .name = "ft_isalnum", .callback = unit_isalnum },
    { .name = "ft_isalpha", .callback = unit_isalpha },
    { .name = "ft_isascii", .callback = unit_isascii },
    { .name = "ft_isdigit", .callback = unit_isdigit },
    { .name = "ft_isprint", .callback = unit_isprint },
    { .name = "ft_memchr",  .callback = unit_memchr },
    { .name = "ft_memcmp",  .callback = unit_memcmp },
    { .name = "ft_memcpy",  .callback = unit_memcpy },
    { .name = "ft_memmove", .callback = unit_memmove },
    { .name = "ft_memset",  .callback = unit_memset },
    { .name = "ft_strchr",  .callback = unit_strchr },
    { .name = "ft_strjoin", .callback = unit_strjoin },
    { .name = "ft_strlcpy", .callback = unit_strlcpy },
    { .name = "ft_strlen",  .callback = unit_strlen },
    { .name = "ft_strncmp", .callback = unit_strncmp },
    { .name = "ft_strnstr", .callback = unit_strnstr },
    { .name = "ft_strrchr", .callback = unit_strrchr },
    { .name = "ft_strtrim", .callback = unit_strtrim },
    { .name = "ft_substr",  .callback = unit_substr },
    { .name = "ft_tolower", .callback = unit_tolower },
    { .name = "ft_toupper", .callback = unit_toupper },
    { .name = "ft_split",   .callback = unit_split },
    { .name = "ft_itoa",    .callback = unit_itoa },
};

int main(void)
{
    int test_index = 0;
    int tests_count = sizeof(unit_tests) / sizeof(t_unit_test);
    
    while (test_index < tests_count) {
        printf("Starting test: %s\n", unit_tests[test_index].name);
        unit_tests[test_index].callback();
        ++test_index;
    }
    printf("\n\nAll Unit tests passed!\n");
}
