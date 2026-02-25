#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"


void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
    
    if (index < 0) {
        fprintf(stderr, "Error: invalid index %d\n", index);
        return;
    }

    
    item_list[index].price = price;

    
    item_list[index].sku = (char *)malloc(strlen(sku) + 1);
    if (item_list[index].sku == NULL) {
        perror("malloc failed for sku");
        exit(EXIT_FAILURE);
    }
    strcpy(item_list[index].sku, sku);

    
    item_list[index].name = (char *)malloc(strlen(name) + 1);
    if (item_list[index].name == NULL) {
        perror("malloc failed for name");
        exit(EXIT_FAILURE);
    }
    strcpy(item_list[index].name, name);

    
    item_list[index].category = (char *)malloc(strlen(category) + 1);
    if (item_list[index].category == NULL) {
        perror("malloc failed for category");
        exit(EXIT_FAILURE);
    }
    strcpy(item_list[index].category, category);
}


void free_items(Item *item_list, int size)
{
    if (item_list == NULL) return;

    
    for (int i = 0; i < size; i++) {
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
        
        item_list[i].sku = NULL;
        item_list[i].name = NULL;
        item_list[i].category = NULL;
    }
    
    free(item_list);
}


double average_price(Item *item_list, int size)
{
    if (size <= 0 || item_list == NULL) return 0.0;

    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += item_list[i].price;
    }
    return total / size;
}


void print_items(Item *item_list, int size)
{
    for (int i = 0; i < size; i++) {
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %f\n", item_list[i].price);
    }
    printf("###############\n");
}


int find_item_by_sku(Item *item_list, int size, char *target_sku, Item *found_item)
{
    int ct = 0;
    
    while (ct < size && strcmp(item_list[ct].sku, target_sku) != 0) {
        ct++;
    }

    
    if (ct < size) {
        *found_item = item_list[ct]; 
        return 0;
    } else {
        return -1;
    }
}

int main(int argc, char *argv[])
{
    
    int item_count = 5;
    Item *item_list = (Item *)malloc(item_count * sizeof(Item));
    if (item_list == NULL) {
        perror("malloc failed for item list");
        exit(EXIT_FAILURE);
    }

    
    add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
    add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
    add_item(item_list, 8.50, "45678", "snacks", "chips", 2);
    add_item(item_list, 6.75, "98765", "beverages", "soda", 3);
    add_item(item_list, 7.20, "14512", "bakery", "bread", 4);

    
    print_items(item_list, item_count);

    
    double avg = average_price(item_list, item_count);
    printf("average price of items = %f\n", avg);

    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <SKU to search>\n", argv[0]);
        free_items(item_list, item_count);
        exit(EXIT_FAILURE);
    }

    
    Item found_item;
    int result = find_item_by_sku(item_list, item_count, argv[1], &found_item);
    if (result == 0) {
        printf("\n=== Found Item ===\n");
        printf("item name = %s\n", found_item.name);
        printf("item sku = %s\n", found_item.sku);
        printf("item category = %s\n", found_item.category);
        printf("item price = %f\n", found_item.price);
    } else {
        printf("\nitem not found\n");
    }

    
    free_items(item_list, item_count);
    item_list = NULL;

    return 0;
}