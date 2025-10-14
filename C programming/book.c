#include<stdio.h>

typedef struct{
     char book_title[50];
    char author_name[50];
    int book_price;
}Book;

int main(){
    Book book1={"Aadujeevitham","Benyamin",250};
    Book book2={"Aarachaar","M. T. Vasudevan Nair ",650};
    Book book3={"Randamoozham","M. T. Vasudevan Nair",500};

if (book1.book_price>=book2.book_price && book1.book_price>=book3.book_price){
    printf("\nThe book with the highest price is:%s",book1.book_title);
    }
else if(book2.book_price>=book3.book_price && book2.book_price>=book1.book_price ){
    printf("\nThe book with the highest price is:%s",book2.book_title);  
    }
else if(book3.book_price>=book1.book_price && book3.book_price>=book2.book_price)
    {
        printf("\nThe book with the highest price is:%s",book3.book_title); 
    }
    return 0;
}


	
