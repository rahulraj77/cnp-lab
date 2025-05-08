/*Program to implement character/Byte Stuffing and De-stuffing*/ 
#include <stdio.h> 
#include <string.h> 
#define SCH 1
#define STX 2 
#define EOT 4
int  main() 
 
{
    char ch; 
    char arr[100]={SCH,STX}; 
    int i=2,j; 
    printf("\nEnter the data stream(CTRL+A->SCH, CTRL+B->STX, CTRL+D->EOT):\n");
    do
    { 
        scanf("%c", &ch);
        if(ch == '\n')
            break; 
        printf("char is ",ch); 
        if(ch =='\n')
            break; 
        if(ch == SCH) 
        { 
            arr[i++]=SCH;
            printf("SCH");
        } 
        else if(ch == 2)
            printf("STX"); 
        else if(ch == 4) 
            printf("ETX"); 
        else 
            printf("%c",ch); 
        arr[i++]=ch; 
    } while(ch!='\n'); 
    arr[i++]=SCH; 
    arr[i++]=EOT;
     
    printf("\nThe stuffed stream is \n");
    for(j=0; j < i; j++) 
    { 
        if(arr[j] == SCH) 
            printf("SCH"); 
        else if(arr[j] == STX) 
            printf("STX"); 
        else if(arr[j] == EOT) 
            printf("EOT"); 
        else
            printf("%c",arr[j]);
    }
    printf("\nThe de-stuffed data is \n"); 
    for(j=2; j < i-2; j++) 
    {  
        if(arr[j] == SCH) 
        { 
            printf("SCH"); 
            j++; 
        } 
        else if(arr[j] == STX) 
            printf("STX"); 
        else if(arr[j] == EOT) 
            printf("EOT");
        else
            printf("%c", arr[j]);
    } 
    return 0; 
}