#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data{
    char name[100];
    char atb[6];
    int atk;
    int HP;
};

int cmpfunc1 (const void * a, const void * b)
{
    struct data *pa = (struct data*)a;
    struct data *pb = (struct data*)b;
    int result = strcmp(pa->name, pb->name);
    if (result > 0) {
        return 1;
    }
    else if (result < 0) {
        return -1;
    }
    else {
        return 0;
    }
}
void name_sort(struct data arr[], int n){
    qsort(arr, n, sizeof(struct data), cmpfunc1);
}

//int cmpfunc2 (const void * a, const void * b)
//{
//    struct data *pa = (struct data*)a;
//    struct data *pb = (struct data*)b;
//    int num1 = pa->HP;
//    int num2 = pb->HP;
//    return (int)(num1 - num2);
//}
void atb_sort(struct data arr[], int n){
    struct data temp[n];
    int pos=0;
    for(int i=0; i<n; i++)
        temp[i] = arr[i];
    for(int i=0;i<n;i++)
        if(!strcmp(arr[i].atb, "WATER")){
            temp[pos]=arr[i];
            pos++;
        }
    for(int i=0;i<n;i++)
        if(!strcmp(arr[i].atb, "FIRE")){
            temp[pos]=arr[i];
            pos++;
        }
    for(int i=0;i<n;i++)
        if(!strcmp(arr[i].atb, "EARTH")){
            temp[pos]=arr[i];
            pos++;
        }
    for(int i=0;i<n;i++)
        if(!strcmp(arr[i].atb, "LIGHT")){
            temp[pos]=arr[i];
            pos++;
        }
    for(int i=0;i<n;i++)
        if(!strcmp(arr[i].atb, "DARK")){
            temp[pos]=arr[i];
            pos++;
        }
    for(int i=0; i<n; i++)
        arr[i] = temp[i];
}

int cmpfunc3 (const void * a, const void * b)
{
    struct data *pa = (struct data*)a;
    struct data *pb = (struct data*)b;
    int num1 = pa->atk;
    int num2 = pb->atk;
    return (int)(num2 - num1);
}
void atk_sort(struct data arr[], int n){
    qsort(arr, n, sizeof(struct data), cmpfunc3);
}

int cmpfunc4 (const void * a, const void * b)
{
    struct data *pa = (struct data*)a;
    struct data *pb = (struct data*)b;
    int num1 = pa->HP;
    int num2 = pb->HP;
    return (int)(num1 - num2);
}
void HP_sort(struct data arr[], int n){
    qsort(arr, n, sizeof(struct data), cmpfunc4);
}

void printArray(struct data arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%s %s %d %d\n", arr[i].name, arr[i].atb, arr[i].atk,arr[i].HP);
}

int main()
{
    int n,m;
    char sort_qry[100];
    //fprintf(stderr,"(#pokemon, #sorting queries):\n");
    scanf("%d %d", &n, &m);
    struct data pokemon[n];
    for(int i=0;i<n;i++){
        //fprintf(stderr,"(name, attribute, attack, HP):\n");
        scanf("%s %s %d %d", pokemon[i].name, pokemon[i].atb, &pokemon[i].atk, &pokemon[i].HP);
    }
    for(int j=0;j<m;j++){
        scanf("%s", sort_qry);
        if(!strcmp(sort_qry,"NAME")){
            printf("Case #%d:\n",j+1);
            name_sort(pokemon, n);
            printArray(pokemon, n);
        }
        else if(!strcmp(sort_qry,"ATTRIBUTE")){
            printf("Case #%d:\n",j+1);
            HP_sort(pokemon, n);
            atb_sort(pokemon, n);
            printArray(pokemon, n);
        }
        else if(!strcmp(sort_qry,"ATTACK")){
            printf("Case #%d:\n",j+1);
            atk_sort(pokemon, n);
            printArray(pokemon, n);
        }
        else if(!strcmp(sort_qry,"HP")){
            printf("Case #%d:\n",j+1);
            HP_sort(pokemon, n);
            printArray(pokemon, n);
        }
//        else{
//            j--;
//            continue;
//        }
    }
	return 0;
}
