#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

TrieNode* create_node(void) {
    TrieNode* node = (TrieNode*) malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode* root, const char* key) {
    TrieNode* node = root;
    while (*key) {
        int index = *key - 'a';
        if (!node->children[index])
            node->children[index] = create_node();
        node = node->children[index];
        key++;
    }
    node->isEndOfWord = 1;
}

int search(TrieNode* root, const char* key) {
    TrieNode* node = root;
    while (*key) {
        int index = *key - 'a';
        if (!node->children[index])
            return 0;
        node = node->children[index];
        key++;
    }
    return (node != NULL && node->isEndOfWord);
}

static void autocomplete_helper(TrieNode* root, char* prefix, int level) {
    if (root->isEndOfWord) {
        prefix[level] = '\0';
        printf("%s\n", prefix);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            prefix[level] = i + 'a';
            autocomplete_helper(root->children[i], prefix, level + 1);
        }
    }
}

void autocomplete(TrieNode* root, const char* prefix) {
    TrieNode* node = root;
    while (*prefix) {
        int index = *prefix - 'a';
        if (!node->children[index])
            return;
        node = node->children[index];
        prefix++;
    }

    char buffer[100];
    strcpy(buffer, prefix);
    autocomplete_helper(node, buffer, strlen(prefix));
}

void free_trie(TrieNode* root) {
    if (!root)
        return;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        free_trie(root->children[i]);
    free(root);
}
