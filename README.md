[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/kLjJ9ncW)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=22869652&assignment_repo_type=AssignmentRepo)
# ECE231_Assignment4
Pointers and structures
# Lab Assignment 4
We will practice more pointers and structures to become more familiar with their usage.  We will create an array of structures.

# Step 1
Create a file called item.h which creates a structure for storing an item in a grocery store database.  The members of the struct should be price, SKU, description, and name.  
```
struct _Item
{
  double price;
  char *sku;
  char *name;
  char *category;
};
typedef struct _Item Item;
```

# Step 2
1. Include this item.h file in your main.c file to access the struct.  
2. Create an array of Items by dynamically allocating space for 5 different items - don't fill up the space yet with real values.
3. Make 4 functions
  - void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
  - void free_items(Item *item_list, int size);
  - double average_price(Item *item_list, int size);
  - void print_items(Item *item_list, int size);
4. Use the add_item function to add 5 different items to the array created in step 2, you will need to allocate memory in this step! You can use the strlen function to get the length of a string to find out how much memory to allocate for each different character array in the Item struct.  Use the index parameter of this function to access the element of the array you want to add data to.
5. Use the print_items function to print all the items to the screen.
6. Use the average_price function to calculate the average price of all your items.
7. Use the free_items function to free the memory you allocated throughout the entire program.

# Step 3
Run the program to get output such as the following (only 2 items shown)
```
###############
item name = reese's cereal
item sku = 19282
item category = breakfast
item price = 5.000000
###############
item name = milk
item sku = 79862
item category = dairy
item price = 3.950000
###############
average price of items = 6.280000
```

# Step 4
1. Modify the main function to take command line arguments
2. Assume the user will run the program like: ./main 14512
3. Use the argument given in the command line (14512 in above) as the SKU to search for
4. Find the item in your item list using a while loop and print the item to the screen.  If not found, print item not found.  

# Some hints
There are multiple ways to implement the while loop, for my implementation this information is important:

There is a difference in a loop from saying
```
while(ct < size && strcmp(item_list[ct].sku,sku) != 0)
```
and

```
while(strcmp(item_list[ct].sku,sku) != 0 && ct < size)
```
Look up short-circuit in programming for an explanation.  If you do this implementation, try it both ways and see what happens.

# Grading Scale
- Struct implemented correctly - 10%
- 4 Functions implemented and used correctly - 50%
- Command line arguments used and searching works - 20%
- Code produces expected output - 20%
