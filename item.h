#ifndef ITEM_H
#define ITEM_H

struct _Item
{
    double price;       
    char *sku;          
    char *name;         
    char *category;     
};
typedef struct _Item Item;


void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index);
void free_items(Item *item_list, int size);
double average_price(Item *item_list, int size);
void print_items(Item *item_list, int size);

int find_item_by_sku(Item *item_list, int size, char *target_sku, Item *found_item);

#endif 