/*Encryption by Transposition Method */ 
#include <stdio.h>  
#include <string.h> 
 
void main() 
{ 
    char data[100]; 
    char wrd[]="MEGABUCK"; 
    char cipher[20][8]; 
    int seq[8]; 
    int i,j,k,cnt; 
    for(i=0; i<strlen(wrd); i++) 
    { 
        cnt=0; 
        for(j=0; j < 8; j++) 
            if(wrd[i] > wrd[j]) 
                ++cnt;
        seq[i]=cnt; 
    }

    printf("\nEnter data : "); 
    fgets(data, sizeof(data), stdin); 
    cnt=strlen(data); 
    for(i=0; i < cnt; i++) 
        cipher[i/strlen(wrd)][i%strlen(wrd)] = data[i]; 
    if(i % strlen(wrd)!=0) 
    { 
        for(j=i % strlen(wrd);j<strlen(wrd);j++) 
        { 
            cipher[i/strlen(wrd)][j]='.';
            cnt++; 
        } 
    } 
    printf("Encrypted data : "); 
    for(i=0;i<8;i++) 
    { 
        for(j=0; j < 8; j++) 
            if(seq[j] == i) 
                break;
        for(k=0;k<cnt/8||k==0;k++) 
            printf("%c",cipher[k][j]); 
    } 
}