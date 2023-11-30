#include <stdlib.h>
#include <stdio.h>
#include "func.h"
int main(){
    journal *arr=NULL;
    int n=0;
    int stop=0;
    while(stop!=1){
        int key;
        printf("1 - create, 2 - read, 3 - search\n");
        scanf("%d", &key);
        switch(key){
            case 1:{
                int key2;
                printf("1 - create DB, 2 - read DB from file\n");
                scanf("%d",&key2);
                if(key2==1){
                    create(&arr,&n);
                    if(!arr)printf("create error\n");
                    else printf("created %d elem\n",n);
                    write(arr,n);
                }
                else{
                    read(&arr,&n);
                    if(!arr) printf("read error\n");
                    else printf("created %d elem\n",n);
                }
                break;
            }
            case 2:
            for(int i=0;i<n;i++) 
                printf("%s %s %d\n", arr[i].name,arr[i].author, arr[i].views);
                break;
            case 3:
                search(arr,n);
                break;
            default:
            stop=1;
            break;
        }
    }
}