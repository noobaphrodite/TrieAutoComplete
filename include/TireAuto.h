#ifndef TRIE_H
#define TRIE_H

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

TrieNode* create_node(void);
void insert(TrieNode* root, const char* key);
int search(TrieNode* root, const char* key);
void autocomplete(TrieNode* root, const char* prefix);
void free_trie(TrieNode* root);

#endif // TRIE_H
