// Department Store Management System (DSMS) using C
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function declarations
void control_panel();
void add_item();
void display_item();
void check_item();
void update_item();
void delete_item();

// control panel
void control_panel() {
    system("Color 0A");
    system("cls");
    printf("**********************************************************************");
    printf("\n\n\t\t\tDepartment Store Management System");
    printf("\n\n\t\t\t\t  Our Menu l\n");
    printf("\n**********************************************************************\n");
    printf("\n\n 1. Add New Item");
    printf("\n 2. Display Items");
    printf("\n 3. Check Specific Item");
    printf("\n 4. Update Item");
    printf("\n 5. Delete Item");
    printf("\n 6. Exit");
}

// add item
void add_item() {
    system("cls");
    system("Color 0A");
    FILE *file;
    int no_item, Item_Id;
    char itm_name[50], c_name[50];

    printf("\n\n\t\t\t\t Add New Item: \n");
    printf("------------------------------------------------------------\n");
    printf(" Item Code (Six digit Integer) : ");
    scanf("%d", &Item_Id);
    printf("------------------------------------------------------------\n");
    printf("\n\n Item Name: ");
    scanf("%s", itm_name);
    printf("\n\n Company Name: ");
    scanf("%s", c_name);
    printf("\n\n No. Of Item: ");
    scanf("%d", &no_item);

    file = fopen("D://item.txt", "a");
    if (file != NULL) {
        fprintf(file, " %d %s %s %d\n", Item_Id, itm_name, c_name, no_item);
        fclose(file);
    }
    printf("============================================================\n");
}

// display item
void display_item() {
    system("cls");
    system("Color 0A");
    FILE *file;
    int no_item, Item_code;
    char itm_name[50], c_name[50];

    file = fopen("D://item.txt", "r");
    if (file == NULL) {
        printf("File Opening Error....");
    } else {
        printf("--------------------------------------------------\n");
        printf(" Item Code    Item    Company    No. of Item\n");
        printf("--------------------------------------------------\n");
        while (fscanf(file, "%d %s %s %d", &Item_code, itm_name, c_name, &no_item) != EOF) {
            printf("   %d        %s       %s        %d\n", Item_code, itm_name, c_name, no_item);
        }
        printf("==================================================\n");
        fclose(file);
    }
}

// check specific item
void check_item() {
    system("cls");
    system("Color 0A");
    FILE *file;
    int count = 0;
    int Item_code, no_item, It_code;
    char itm_name[50], c_name[50];

    printf("\n\n\t\t\t\t Check Specific Product\n");
    printf("------------------------------------------------------------\n");
    file = fopen("D://item.txt", "r");
    if (file == NULL) {
        printf("File Opening Error....");
    } else {
        printf("\n\n Item Code: ");
        scanf("%d", &It_code);
        printf("\n------------------------------------------------------------\n");

        while (fscanf(file, "%d %s %s %d", &Item_code, itm_name, c_name, &no_item) != EOF) {
            if (It_code == Item_code) {
                system("cls");
                printf("\n\n\t\t\t\tCheck Specific Product");
                printf("\n\n Item Code : %d", Item_code);
                printf("\n\nItem Name : %s", itm_name);
                printf("\n\n Company : %s", c_name);
                printf("\n\n No. of Item : %d", no_item);
                count++;
                break;
            }
        }
        fclose(file);
        if (count == 0) {
            printf("Item Not Found....");
        }
    }
}

// update item
void update_item() {
    system("cls");
    system("Color 0A");
    FILE *file, *file1;
    int no_copy, no_co, count = 0;
    char itm_name[50], b_na[50], a_name[50], a_na[50];
    char newitm_idd[20], newitm_id[20];

    printf("\n\n\t\t\t\tUpdate Item Record\n");
    printf("------------------------------------------------------------\n");

    file1 = fopen("D://book1.txt", "w");
    file = fopen("D://item.txt", "r");

    if (file == NULL) {
        printf("\n\n File Opening Error...");
    } else {
        printf("\n\n Item Code : ");
        scanf("%s", newitm_id);
        printf("\n------------------------------------------------------------\n");

        while (fscanf(file, "%s %s %s %d", newitm_idd, itm_name, a_name, &no_copy) != EOF) {
            if (strcmp(newitm_id, newitm_idd) == 0) {
                system("cls");
                printf("\n\n\t\t\t\tUpdate Item Record");
                printf("\n\n New Item Name : ");
                scanf("%s", b_na);
                printf("\n\n\t\t\tCompany Name : ");
                scanf("%s", a_na);
                printf("\n\n No. of Items : ");
                scanf("%d", &no_co);

                fprintf(file1, " %s %s %s %d\n", newitm_id, b_na, a_na, no_co);
                count++;
            } else {
                fprintf(file1, " %s %s %s %d\n", newitm_idd, itm_name, a_name, no_copy);
            }
        }
        if (count == 0)
            printf("\n\n Item Code Not Found...");
    }

    fclose(file);
    fclose(file1);

    remove("D://item.txt");
    rename("D://book1.txt", "D://item.txt");
}

// delete item
void delete_item() {
    system("cls");
    system("Color 0A");
    FILE *file, *file1;
    int no_copy, count = 0;
    char newitm_id[20], newitm_idd[20], itm_name[50], a_name[50];

    printf("\n\n\t\t\t\tDelete Item Record");
    printf("\n------------------------------------------------------------\n");

    file1 = fopen("D://book1.txt", "w");
    file = fopen("D://item.txt", "r");

    if (file == NULL) {
        printf("\n\n File Opening Error...");
    } else {
        printf("\n\n Item Code : ");
        scanf("%s", newitm_id);
        printf("\n------------------------------------------------------------\n");

        while (fscanf(file, "%s %s %s %d", newitm_idd, itm_name, a_name, &no_copy) != EOF) {
            if (strcmp(newitm_id, newitm_idd) == 0) {
                system("cls");
                printf("\n\n\t\t\t\tDelete Item Record");
                printf("\n\n One Item is Deleted Successfully...");
                count++;
            } else {
                fprintf(file1, " %s %s %s %d\n", newitm_idd, itm_name, a_name, no_copy);
            }
        }
        if (count == 0)
            printf("\n\n Item Code Not Found...");
    }
    fclose(file);
    fclose(file1);

    remove("D://item.txt");
    rename("D://book1.txt", "D://item.txt");
}

// main function
int main() {
    int choice;
    char x;
    while (1) {
    p:
        control_panel();
        printf("\n\n Your Choice : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            do {
                add_item();
                printf("Do You Want To Add Another Item (y/n) : ");
                scanf(" %c", &x);
            } while (x == ('y' || "Y" || "yes" || "YES" || "Yes");
            break;
        case 2:
            display_item();
            break;
        case 3:
            check_item();
            break;
        case 4:
            update_item();
            break;
        case 5:
            delete_item();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\n\n Invalid Value....Please Try again");
        }

        printf("\n");
        getch();
        goto p;
    }
    return 0;
}

