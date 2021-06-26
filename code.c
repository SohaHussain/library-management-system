#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

void welcome()
{
    
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    
}

void create()
{
    FILE *fp = NULL;
    fp= fopen("Library","wb");
    fclose(fp);

    
}
typedef struct
{
int bookid;
char bookname[50];
char authorname[50];
char available[5];

} bi;

void add_book()
{   printf("\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                         ADD BOOKS\n");
    printf("\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\tENTER BOOK DETAILS BELOW\n\n");
    bi addinfo={0};
    FILE *fp = NULL;
    fp=fopen("Library","ab+");
    printf("\t\t\tBook ID no. = ");
    fflush(stdin);
    scanf("%d",&addinfo.bookid);
    printf("\n\t\t\tBook Name  = ");
    fflush(stdin);
    fgets(addinfo.bookname,50,stdin);
     printf("\n\t\t\tAuthor Name  = ");
    fflush(stdin);
    fgets(addinfo.authorname,50,stdin);
    printf("\n\t\t\tAvailablity (y/n) = ");
    fflush(stdin);
    fgets(addinfo.available,5,stdin);
    fwrite(&addinfo,sizeof(addinfo),1,fp);
    fclose(fp);


}

void view_data()
{
    char bookname[50] = {0};
     bi addinfo ={0};
     FILE *fp = NULL;
    printf("\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                         VIEW DATA\n");
    printf("\t\t\t  ---------------------------------------------------------\n");
     fp = fopen("Library","rb");
     if(fp == NULL)
    {
        printf("File is not opened\n");
        
    }
    while (fread (&addinfo, sizeof(addinfo), 1, fp))
    {
        printf("\t\t\tBook id = %d",addinfo.bookid);
        printf("\n\t\t\tBook name = %s",addinfo.bookname);
        printf("\t\t\tBook authorName = %s",addinfo.authorname);
        printf("\t\t\tAvailablity = %s\n",addinfo.available);
    }
    fclose(fp);
    fflush(stdin);
    
        
}

void search_book()
{
    int found = 0;
     char book[50] = {0};
    bi addinfo = {0};
    FILE *fp = NULL;
     fp = fopen("Library","rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
       
    }
    printf("\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                         SEARCH BOOK\n");
    printf("\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\tEnter Book Name to search:");
    fflush(stdin);
    fgets(book,50,stdin);
    
    while (fread (&addinfo, sizeof(addinfo), 1, fp))
    {
        if(!strcmpi(addinfo.bookname, book))
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("\n\t\t\tBook id = %d\n",addinfo.bookid);
        printf("\t\t\tBook name = %s",addinfo.bookname);
        printf("\t\t\tAuthor Name = %s",addinfo.authorname);
        printf("\t\t\tAvailablity = %s",addinfo.available);
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    
    
}

void delete_book()
{
    int found = 0;
    int bookDelete = 0;
    char bookname[50] = {0};
    bi addinfo = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    printf("\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                         DELETE BOOK\n");
    printf("\t\t\t  ---------------------------------------------------------\n");
    fp = fopen("Library","rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        
    }
    tmpFp = fopen("tmp.bin","wb");
    if(tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        
    }
    printf("\n\t\t\tEnter Book ID NO. for delete:");
    scanf("%d",&bookDelete);
     while (fread (&addinfo, sizeof(addinfo), 1, fp))
    {
        if(addinfo.bookid != bookDelete)
        {
            fwrite(&addinfo,sizeof(addinfo), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmpFp);
    remove("Library");
    rename("tmp.bin","Library");

}

void issue()
{   
    int found = 0;
    char book[50];
    char student[50];
    bi addinfo = {0};
    
    
    FILE *fp = NULL;
   
    fp = fopen("Library","rb");
    


    printf("\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                         ISSUE BOOK\n");
    printf("\t\t\t  ---------------------------------------------------------\n");
    
    
        printf("\n\t\t\tEnter Book name to issue :");
        fflush(stdin);
        fgets(book,50,stdin);
        
        
        while (fread (&addinfo, sizeof(addinfo), 1, fp))
    {
        if(!strcmpi(addinfo.bookname, book))
        {
            found = 1;
            break;
        }
        
    }
        if(found)
        {
            if(!strcmpi(addinfo.available,"y"))
            {
              printf("\n\t\t\tEnter your name : ");
              
              scanf("%s",&student);
              printf("\n\t\t\tIssue Successful");
           }
           else
           printf("\n\t\t\tNot Available!!");
        }
        else
        printf("\n\t\t\tNOT FOUND");
    
    
    fclose(fp);
    
}



void menu()
{
    char s[3];
    int choice = 0;
    jump:
    printf("\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                         MAIN MENU\n");
    printf("\t\t\t  ---------------------------------------------------------\n");
     printf("\n\t\t\t1.Add Books");
     printf("\n\t\t\t2.Search Books");
     printf("\n\t\t\t3.View Books");
     printf("\n\t\t\t4.Issue Book");
     printf("\n\t\t\t5.Delete Book");
     printf("\n\t\t\t6.Exit");
     
     printf("\n\n\t\t\tEnter choice => ");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1:
         add_book();
         break;
         case 2:
         search_book();
         break;
         case 3:
         view_data();
         break;
         case 4:
         issue();
         break;
         case 5:
         delete_book();
         break;
         case 6:
         printf("\n\t\t\t               !!! THANK YOU !!!");
         exit(1);
         default:
         printf("\n\t\t\tINVALID");

     }

     printf("\n\t\t\tWANT TO GO BACK TO MAIN MENU Y/N : ");
     gets(s);
     if(!strcmpi(s,"Y"))
     {
         goto jump;
     }
     else
     printf("\n\t\t\t                   !!! THANK YOU !!!");
     exit(1);

}


int main()
{
    welcome();
    menu();
    return 0;
}