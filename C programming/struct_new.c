#include<stdio.h>
#pragma pack(1)
typedef struct{
    int roll_no: 2;
    char name[50];
    double mark;
}student;

int main(){
    student hafna={23,"hafna_kk",99};
    printf("roll number of student hafna:%d",hafna.roll_no);
    printf("\nsize of struct:%d",sizeof(student));
    return 0;
}