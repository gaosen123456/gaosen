#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct {
    char* key;
    int value;
} Entry;

typedef struct {
    Entry* entries[TABLE_SIZE];
} HashTable;

unsigned int hash(const char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key;
        key++;
    }
    return hash % TABLE_SIZE;
}

HashTable* createHashTable() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    memset(table->entries, 0, sizeof(table->entries));
    return table;
}

void insert(HashTable* table, const char* key, int value) {
    unsigned int index = hash(key);
    Entry* entry = (Entry*)malloc(sizeof(Entry));
    entry->key = strdup(key);
    entry->value = value;
    table->entries[index] = entry;
}

int get(HashTable* table, const char* key) {
    unsigned int index = hash(key);
    Entry* entry = table->entries[index];
    if (entry && strcmp(entry->key, key) == 0) {
        return entry->value;
    }
    return -1; // Not found
}

void destroyHashTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->entries[i]) {
            free(table->entries[i]->key);
            free(table->entries[i]);
        }
    }
    free(table);
}

int main() {
    HashTable* hashTable = createHashTable();
    insert(hashTable, "apple", 42);
    insert(hashTable, "banana", 73);

    printf("Value for 'apple': %d\n", get(hashTable, "apple"));
    printf("Value for 'banana': %d\n", get(hashTable, "banana"));
    printf("Value for 'grape': %d\n", get(hashTable, "grape"));

    destroyHashTable(hashTable);

    return 0;
}

