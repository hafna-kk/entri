#include<stdio.h>
/*
Write function to count:

Number of vowels

Number of consonants
*/
/*
void vowel(char str[]){
  
    int vowel_count=0 ;
    int cons_count=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i] == 'a' || str[i] =='e' || str[i] =='i' || str[i] == 'o' || str[i] =='u' || str[i] == 'A' || str[i] =='E' || str[i] =='I' || str[i] == 'O' || str[i] =='U') {
        vowel_count++;
    }
    else if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z') {
        cons_count++;
    }
   
}
    printf("vowels: %d \n",vowel_count);
    printf("consenets:%d ",cons_count);
}
int main(){
    char word[100];
    printf("type your word: ");
    scanf("%s",word);
    vowel(word);
   
    return 0;

}

*/

//Reverse a string (without using strrev())
#include <string.h>
/*
void reverse(char str[]){
    int length=strlen(str);
    int start=0;
    int end=length-1;
   
   while(start<end){
       char temp=str[start];
       str[start]=str[end];
       str[end]=temp;   
       start++;
       end--;
      
    }
     printf("reversed string:%s",str);
}

int main(){
    char word[100];
    printf("Enter a string:");
    scanf("%s",word);
    reverse(word);
    return 0;
}
    */

//Check if a string is palindrome.
/*
void check_palindrom(char str[]){
    int length=strlen(str);
    int start=0;
    int end=length-1;
    int flag=1; //palindrom
    while(start<end){
        if(str[start]!=str[end]){
            flag=0;
            break;
        }

        start++;
        end--;
    }
   
    if( flag == 1){
        printf("word is palindrom");
    }
    else {
        printf("word is not palindrom");
    }
  
   
}
int main(){
    char word[100];
    printf("Enter a word:");
    scanf("%s",word);
    check_palindrom(word);
    return 0;
}

*/
//Remove all spaces from a string.
/*
void remove_space(char str[]){

    int length=strlen(str);
    int start=0;
    int end=length-1; 
    int i,j=0;
    for(i=0;str[i]!='\0';i++){
        if(str[i] !=' '){
           str[j]=str[i];
           j++;
        }
       

        
    }
     str[j]='\0';
     printf("After removing space:%s",str);
}
int main(){
    char word[100];
    printf("Enter a word:");
   
    fgets(word,100,stdin);
    word[strcspn(word,"\n")]='\0';
    remove_space(word);
    return 0;
}
*/

//Count number of words in a sentence.


void count_word(char str[]){

    int i;
    int count=0;
    for(i=0;str[i]!='\0';i++){
        if(str[i]!= ' ' && (i==0 || str[i-1]== ' ')){
            count++;
        }
    }

    printf("count:%d",count);
}

int main(){
    char sentence[100];
    printf("Enter the sentence:");
    fgets(sentence,100,stdin);
    count_word(sentence);
    return 0;
}