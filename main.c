#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int id;
char name[50];
int quantity;
}books;
books book_arr[100];
int count=0;

void Load_books_data(char *fileInputName,books *books_data);
void insert();

int main()
{
    int operation;
    FILE *bptr; //bookPointerFile

/*TO INPUT THE FILE NAME AND CONTINUE ASKING IF IT WAS WRONG*/
char fileInputName[50];
while(1)
{
    printf("Enter the file name to open \n");
    gets(fileInputName);

    bptr = fopen(fileInputName,"r");
    if(bptr != NULL) //file is opened correctly so break
    {
        break;
    }
    else
    {
        printf("Sorry,This file %s is not existed.\n",fileInputName);
        printf("\n");
    }
}
/*END OF FILE NAME INPUT*/
/*LOADING THE LIST INTO THE ARRAY OF STRUCTURE*/
int listLength=1;
int curChar;
while((curChar=fgetc(bptr))!=EOF)
{
    if(curChar=='\n')
        listLength++;
}
fclose(bptr);
books *books_data=malloc(sizeof(books)*(listLength)); //making enough memory to store the data from text file
if(books_data == NULL){
    printf("Sorry,Error occured while making enough memory");
    exit(1);
}
Load_books_data(fileInputName,books_data); //saving the data
while(1)
{
    printf("Choose an operation number:\n");
    printf("--------------------------------\n");
    printf("1-Insert a book(id,name,quantity)\n2-Delete a book by id\n3-Search a book by id \n4-Display all books sorted by name\n5-Display all books unsorted as entered \n");
    printf("\nOperation number : ");
    scanf("%d",&operation);
    switch(operation)
    {
        case 1:
            insert();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("\nSorry,this operation number is wrong.\n");
    }
}
}


/*LOADING DATA FUNCTION START*/
void Load_books_data(char *fileInputName,books *books_data)
{
    FILE *bptr = fopen(fileInputName,"r");
    if(fileInputName==NULL)
    {
        printf("Sorry,This file %s is not existed.\n",fileInputName);
        printf("\n");
        exit(1);
    }
    int i=0,j,k;
    //THIS LOOP GETS THE DATA FROM TEXT FILE AND STORE IT IN book_data
    while(fscanf(bptr,"%d %s %d",&(books_data+i)->id,(books_data+i)->name,&(books_data+i)->quantity) != EOF )
    {
        i++;
    }
    fclose(fileInputName);
    printf("THE DATA IS LOADED COMPLETELY. \n");
}

/*END OF LOADING DATA FUNCTION */

/*INSERT FUNCTION START*/
void insert()
{
    if(count==100)
    {
        printf("\nSorry,No more space.\n");
        return;
    }
    else
    {
        printf("\nEnter the new book ID\n");
        fscanf("%d",&books.id);
        printf("\nEnter the new book NAME\n");
        fgets(books.name);
        printf("\nEnter the new book QUANTITY\n");
        fscanf("%d",&books.quantity);
        count++;
    }
}
/*END OF INSERT FUNCTION*/
