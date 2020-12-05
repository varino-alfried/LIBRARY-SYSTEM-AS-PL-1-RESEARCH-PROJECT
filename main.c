#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*ٍSTART FUNCTION PROTOTYPE DECLARATIONS*/
void load_file();
void Book_insert();
void file_print();
void Book_delete();
void search_book_id();
void search_book_name();
void book_sorted_print();
/*END FUNCTION PROTOTYPE DECLARATIONS*/

struct book
{
    char name [50];
    char id[10];
    int quantity;
}*bptr,Book_new,book_structure,var;
int counter=0;

void create_file()
{
    FILE *fptr;
    fptr = fopen("Books.txt","a");
    fprintf(fptr,"%s %s %d\n",Book_new.name,Book_new.id,Book_new.quantity);
    fclose(fptr);
}

int main()
{
int operation;
char anotherOperation[3];
do
{
    printf("Choose an operation number:\n");
    printf("--------------------------------\n");
    printf("1-Insert a book(name,id,quantity)\n2-Delete a book by id\n3-Search a book by id \n4-Search book by name \n5-Display all books sorted by name \n6-Display all books unsorted as entered \n");
    printf("\nOperation number : ");
    scanf("%d",&operation);
    switch(operation)
    {
        case 1:
            Book_insert();
            break;
        case 2:
            Book_delete();
            break;
        case 3:
            search_book_id();
            break;
        case 4:
            search_book_name();
            break;
        case 5:
            book_sorted_print();
            break;
        case 6:
            file_print();
            break;
        default:
            printf("\nSorry,this operation number is wrong.\n");
    }
    printf("Do you want to do another operation? (yes or no)\n");
    scanf("%s",anotherOperation);
}while(strcmp(anotherOperation,"Yes")==0||strcmp(anotherOperation,"yes")==0);
printf("\n\t Thank you, good bye :) \n");
 return 0;
}



/*START LOADING THE LIST TO FILE FUNCTION*/
void load_file()
{
    FILE *fptr;
    fptr = fopen("Books.txt","rb");
    for (char end = getc(fptr); end != EOF; end = getc(fptr))
    {
        if (end == '\n')
            counter++;
    }
    fclose(fptr);
    fptr = fopen("Books.txt","rb");
    bptr = malloc(counter * sizeof(book_structure));
    for(int i=0;i<counter;i++)
    {
        fscanf(fptr,"%s %s %d\n",Book_new.name,Book_new.id,&Book_new.quantity);
        strcpy(bptr[i].name , Book_new.name);
        strcpy(bptr[i].id , Book_new.id);
        bptr[i].quantity = Book_new.quantity;
    }
    fclose(fptr);
}
/*END LOADING THE LIST TO FILE FUNCTION*/
/*START INSERT A BOOK FUNCTION*/
void Book_insert()
{
    printf("Please, Enter the book name : "); gets(Book_new.name); gets(Book_new.name);
    printf("Enter the book id : "); gets(Book_new.id);
    printf("Enter the quantity of this book : "); scanf("%d",&Book_new.quantity);
    create_file();
}
/*END INSERT A BOOK FUNCTION*/
/*START FILE PRINT FUNCTION*/
void file_print()
{
    load_file();
    for(int i=0;i<counter;i++)
    {
        printf(" \n Name: %s \n Id: %s \n Quantity: %d \n",bptr[i].name,bptr[i].id,bptr[i].quantity);
    }
    counter=0;
}
/*END FILE PRINT FUNCTION*/
/*START DELETE A BOOK FUNCTION*/
void Book_delete()
{
    load_file();
    char book_id[10];
    printf("Please enter the book's id to be deleted : "); gets(book_id);gets(book_id);
    FILE *fptr;
    fptr = fopen("Books.txt","w+");
    for(int i=0; i<counter ; i++)
    {
        if(strcmp(bptr[i].id,book_id)!=0)
        {
            strcpy(Book_new.name,bptr[i].name);
            strcpy(Book_new.id,bptr[i].id);
            Book_new.quantity=bptr[i].quantity;
            fprintf(fptr,"%s %s %d\n",Book_new.name,Book_new.id,Book_new.quantity);
        }
    }
    fclose(fptr);
    counter=0;
    file_print();
}
/*END DELETE A BOOK FUNCTION*/
/*START SEARCH A BOOK BY ID FUNCTION*/
void search_book_id()
{
    load_file();
    char book_id[10];
    printf("Please enter the book's id to search for it: "); gets(book_id); gets(book_id);
    for(int i=0;i<counter;i++)
    {
        if(strcmp(bptr[i].id,book_id)==0)
        {
            printf(" Name: %s\n Quantity: %d\n",bptr[i].name,bptr[i].quantity);
            counter=0;
            return;
        }
    }
    printf("Not found\n");
    counter=0;
}
/*END SEARCH A BOOK BY ID FUNCTION*/
/*START SEARCH A BOOK BY NAME FUNCTION*/
void search_book_name()
{
    int i,j;
    char book_name[50];
    printf("Please,Enter the book's name: "); gets(book_name); gets(book_name);
    load_file();
    for(i=0;i<counter;i++)
    {
        for(j=i;j<counter;j++)
        {
            if(bptr[j].name[0]<bptr[i].name[0])
            {
                strcpy(var.name,bptr[i].name);
                strcpy(bptr[i].name,bptr[j].name);
                strcpy(bptr[j].name,var.name);

                strcpy(var.id,bptr[i].id);
                strcpy(bptr[i].id,bptr[j].id);
                strcpy(bptr[j].id,var.id);

                var.quantity=bptr[i].quantity;
                bptr[i].quantity=bptr[j].quantity;
                bptr[j].quantity=var.quantity;
            }
        }
    }
    int low=0;
    int mid;
    int high=counter;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(strcmp(bptr[mid].name, book_name)==0)
        {
            printf(" The Id is %s \n The Quantity is %d \n",bptr[mid].id, bptr[mid].quantity);
            counter=0;
            return;
        }
        else if (strcmp(bptr[mid].name, book_name)>0)
            high = mid-1;
        else if (strcmp(bptr[mid].name, book_name)<0)
            low = mid+1;
    }
    counter=0;
    printf("Not found\n");
}
/*END SEARCH A BOOK BY NAME FUNCTION*/
/*START DISPLAY SORTED BOOKS BY NAME FUNCTION*/
void book_sorted_print()
{
    load_file();
    int i,j;
    for(i=0;i<counter;i++)
    {
        for(j=i;j<counter;j++)
        {
            if(bptr[j].name[0]<bptr[i].name[0])
            {
                strcpy(var.name,bptr[i].name);
                strcpy(bptr[i].name,bptr[j].name);
                strcpy(bptr[j].name,var.name);

                strcpy(var.id,bptr[i].id);
                strcpy(bptr[i].id,bptr[j].id);
                strcpy(bptr[j].id,var.id);

                var.quantity=bptr[i].quantity;
                bptr[i].quantity=bptr[j].quantity;
                bptr[j].quantity=var.quantity;
            }
        }
    }
    printf("The books sorted by name are:\n");
    for(i=0;i<counter;i++)
    {
        printf("\nName: %s\n",bptr[i].name);
        printf("Id: %s\n",bptr[i].id);
        printf("Quantity: %d\n",bptr[i].quantity);
    }
    counter=0;
}
/*END DISPLAY SORTED BOOKS BY NAME FUNCTION*/
