//------------project--------------
//--------Inventory Management System-----------
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_ITEMS 100

struct Item 
{
    int id;
    char name[50];
    float price;
};
struct Item items[MAX_ITEMS];
int count = 0;

void addItem();
void displayItems();
void searchByName();
void searchByID();
void main() 
{
    int choice;
    printf("Inventory Management System\n");
    do
    {
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item by Name\n");
        printf("4. Search Item by ID\n");
        printf("0. Exit\n");
        printf("----------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                searchByName();
                break;
            case 4:
                searchByID();
                break;
            case 0:
				exit(0);
			default:
				printf("\nInvalid choice!\n");
				break;
        }
    }
    while (choice != 0);
}

void addItem() 
{
    if (count < MAX_ITEMS) 
    {
        struct Item new_item;
        
        printf("Enter item ID: ");
        scanf("%d", &new_item.id);
        
        printf("Enter item name: ");
        fflush(stdin);
        fgets(new_item.name, sizeof(new_item.name), stdin);
        new_item.name[strcspn(new_item.name, "\n")] = '\0';
        
        printf("Enter item price: ");
        scanf("%f", &new_item.price);
        
        items[count] = new_item;
        count++;
        
        printf("Item added successfully!\n\n");
        printf("\n---------------------------------------------------\n");
    } 
    else 
    {
        printf("Inventory is full, cannot add more items.\n\n");
    }
}

void displayItems() 
{
    if (count == 0) 
    {
        printf("No items in inventory.\n\n");
    } 
    else 
    {
        printf("\nInventory List:\n");
        int i;
        for (i = 0; i < count; i++) 
        {
            printf("ID: %d\n", items[i].id);
            printf("Name: %s\n",items[i].name);
            printf("Price: %.2f\n\n",items[i].price);
        }
        printf("\n--------------------------------------------------------------\n");
    }
}

void searchByName() 
{
    char searchName[50];
    printf("Enter the name of the item to search: ");
    fflush(stdin);
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    
    int found = 0;
    int i;
    for (i = 0; i < count; i++) 
    {
        if (strcmp(items[i].name, searchName) == 0) 
        {
            printf("\nItem found: \n\n");
            printf("ID: %d\n", items[i].id);
            printf("Name: %s\n",items[i].name);
            printf("Price: %.2f\n",items[i].price);
            found = 1;
        }
    }
    printf("\n-------------------------------------------\n");
    
    if (!found) 
    {
        printf("Item not found.\n\n");
    }
}

void searchByID() 
{
    int searchID;
    printf("Enter the item ID to search: ");
    scanf("%d", &searchID);
    
    int found = 0;
    int i;
    for (i = 0; i < count; i++) 
    {
        if (items[i].id == searchID) 
        {
            printf("\nItem found: \n\n");
            printf("ID: %d\n", items[i].id);
            printf("Name: %s\n",items[i].name);
            printf("Price: %.2f\n",items[i].price);
            found = 1;
        }
    }
    printf("\n-------------------------------------------\n");
    
    if (!found) 
    {
        printf("Item not found.\n\n");
    }
}
