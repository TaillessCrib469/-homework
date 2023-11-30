#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "func.h"
void create(journal **arr, int *n){
    printf("n=");
    scanf("%d",n);
    if(*n<=0){
        printf("Друг мой, ну введи ты число больше 0, пожалуйста\n");
        return;
    }
    *arr=(journal*)calloc(*n,sizeof(journal));
    for(int i=0;i<*n;i++){
        printf("Название=");
        scanf("%s",(*arr)[i].name);
        printf("Автор=");
        scanf("%s",(*arr)[i].author);
        printf("Просмотры=");
        scanf("%d",&(*arr)[i].views);
    }
}

void read(journal **arr, int *n){
    FILE *fp=fopen("file.txt","r");
    if(!fp) return;
    if(fscanf(fp,"%d",n)!=1){
        fclose(fp);
        return;
    }
    if(*n<=0){
        fclose(fp);
        return;
    }
    *arr=(journal*)calloc(*n,sizeof(journal));
    for(int i=0;i<*n;i++){
        if(fscanf(fp,"%s %s %d",(*arr)[i].name,(*arr)[i].author,&(*arr)[i].views)!=3)
        break;
    }
    fclose(fp);
}

void write(journal *arr,int n){
    FILE *fp=fopen("file.txt","w");
    if(!fp) return;
    fprintf(fp,"%d\n",n);
    for(int i=0;i<n;i++){
        fprintf(fp,"%s %s %d\n",arr[i].name,arr[i].author,arr[i].views);
    }
    fclose(fp);
}

void search(journal *arr, int n){
	int key;
	printf("Ща как найду: 1 - По названию статьи, 2 - По автору, 3 - по количеству просмотров\n");
	scanf("%d",&key);
	switch(key){
		case 1:{
			int flag=1;
			char namef[40];
			printf("Скажи мне название статьи: \n");
			scanf("%s",namef);
			for(int i=0;i<n;i++){
				if(!strcmp(arr[i].name,namef)){
					printf("%s %s %d\n", arr[i].name,arr[i].author, arr[i].views);
					flag=0;
				}
			}
			if(flag){
				printf("Братка, ничего не нашел, сорян\n");
			}
			break;
		}
		case 2:{
			int flag=1;
			char namef[40];
			printf("Скажи мне имя автора, и я переверну все верх дном, но найду его: \n");
			scanf("%s",namef);
			for(int i=0;i<n;i++){
				if(!strcmp(arr[i].author,namef)){
					printf("%s %s %d\n", arr[i].name,arr[i].author, arr[i].views);
					flag=0;
				}
			}
			if(flag){
				printf("Братка, ничего не нашел, сорян\n");
			}
			break;
		}
		case 3:{
			int flag=1;
			int count=0;
			printf("Скажи мне число просмотров, родной: \n");
			scanf("%d",&count);
			for(int i=0;i<n;i++){
				printf("pidor");
				if(arr[i].views==count){
					printf("fuck");
					printf("%s %s %d\n", arr[i].name,arr[i].author, arr[i].views);
					flag=0;
				}
			}
			if(flag){
				printf("Братка, ничего не нашел, сорян\n");
				return;
			}
			break;
		}
		default:
		break;
	}
}