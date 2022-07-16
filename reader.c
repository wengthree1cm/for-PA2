/*
 * CSE30 WI22 HW3
 * Username: cse30s122bp(Fill in your username)
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {

    int strcmp (const char* str1, const char* str2);
    int atoi(const char*string);
    ssize_t getline(char** lineptr, size_t* n, FILE*stream);
    size_t strlen(const char *str);

    int result;
    int *column;
    char **buf;
    int countline=0;

    result=strcmp("-c",argv[1]);
    if(result==0){
        column=(int*)malloc(sizeof(int)*(argc-3));
        for(int i=3,j=0;i<argc;i++,j++){
             column[j]=atoi(argv[i]);
        }
        buf=(char **)malloc(sizeof(char *)*atoi(argv[2]));
    }
    else if(result!=1&&result!=0){
        column=(int*)malloc(sizeof(int)*(argc-2));
        for(int u=2,jj=0;u<argc;u++,jj++){
             column[jj]=atoi(argv[u]);
        }
        buf=(char **)malloc(sizeof(char *)*atoi(argv[1]));
    }

    char *lineptr = NULL;
    size_t length=0;
    int max=0;
    while(getline(&lineptr,&length,stdin)!=-1){
        countline++;

        int length1=strlen(lineptr);



        int p=0;  int det=0; int det1=0;
        if(result==0){
            det=argc-3;
            det1=atoi(argv[2]);
        }
        if(result!=1&&result!=0){
            det=argc-2;
            det1=atoi(argv[1]);
        }
        int field=1;
        for(int k=0;k<length1;k++){
            if(lineptr[k]=='\n'){
                lineptr[k]='\0';
            }
        }



        for(int i=0,j=0;i<length1&&j<det1;){
                field=0;
                buf[j]=&lineptr[i];
                while(i<length1&&lineptr[i]!='\0'&&lineptr[i]!='\t'&&lineptr[i]!=' '){
                    i=i+1;
                    field=field+1;
                }
                while(i<length1&&(lineptr[i]=='\0'||lineptr[i]=='\t'||lineptr[i]==' ')){
                    i=i+1;
                }

                j++;
                if(max<field){
                    max=field;
                }
        }



        for(int k=0;k<length1;k++){
            if(lineptr[k]==' '){
                lineptr[k]='\0';
            }
            if(lineptr[k]=='\n'){
                lineptr[k]='\0';
            }
        }



        for(int l=0;l<det;l++){
            if(column[l]<0){
                if(l==det-1){
                    printf("%s",buf[column[l]+det1]);
                }
                else{
                    printf("%s ",buf[column[l]+det1]);
                }

            }
            else{
                if(l==det-1){
                    printf("%s",buf[column[l]]);
                }
                else{
                    printf("%s ",buf[column[l]]);
                }

            }

        }
        printf("\n");





    }
    free(buf); free(column); free(lineptr);
    if(result==0){
        printf("Number of lines: %d\n",countline);
        printf("Longest field: %d characters\n",max);
    }






}
