#include <stdio.h>
#include "trie.h"

int main() {
    TrieNode* root = create_node();

    insert(root, "hello");
    insert(root, "hell");
    insert(root, "heaven");
    insert(root, "heavy");

    printf("Search results:\n");
    printf("heaven: %d\n", search(root, "heaven"));
    printf("hell: %d\n", search(root, "hell"));
    printf("hello: %d\n", search(root, "hello"));
    printf("heav: %d\n", search(root, "heav"));

    printf("\nAutocomplete results for 'he':\n");
    autocomplete(root, "he");

    free_trie(root);
    return 0;
}
