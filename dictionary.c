// Implements a dictionary's functionality
//BLOOM Filter

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

// Create macros
#define N 10000 //size of an array
#define SetBit(A, k)    ( A[k/32] |= (1 << (k%32)) ) // Set k bit to 1
#define CheckBit(A, k)  ( A[k/32] &= (1 << (k%32)) ) // Check if k bit is 1 (if it is 1 returns true, if 0 -> false)

// Create array for Bloom filter
unsigned int bloomArr[N] = {0};

//How many bits are in the array
unsigned int sizeBits = N*32;

// Count of words in dictionary
unsigned int size_dict = 0;


// Declare hash functions to return number between 0 and k-1 bit
//TODO
unsigned int djb2(const void *_str) {
	const char *str = _str;
	unsigned int hash = 5381;
	char c;
	while ((c = *str++)) {
		hash = (((hash << 5) + hash) + c) % sizeBits;
	}
	return hash;
}

unsigned int jenkins(const void *_str) {
	const char *key = _str;
	unsigned int hash = 0;
	while (*key) {
		hash += *key;
		hash += (hash << 10);
		hash ^= (hash >> 6);
		key++;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	hash %= sizeBits;
	return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // TODO
        unsigned int num = jenkins(word); // Take hash func index of bit
        SetBit(bloomArr, num); // Set this (num's) bit to 1

        num = djb2(word);
        SetBit(bloomArr, num);

        size_dict++;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (size_dict)
    {
        return size_dict;
    }
    else
    {
        return 0;
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    unsigned int num = jenkins(word); // Take hash func index of bit
    if (!(CheckBit(bloomArr, num)))
        return false;

    num = djb2(word);
    if (!(CheckBit(bloomArr, num)))
        return false;

    return true;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return true; // No need to unload
}
