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

/* insertion sort function*/
//sorting sequence : small -> big
//void InsertionSort(struct data arr[], int n)
//{
//    //declaration
//	int i, j;
//	struct data key;
//	//check the array value sequence and sort it
//	for (i = 1; i < n; i++) {
//        //set key as the going through head for array
//		key = arr[i];
//        //j is the front item of key
//		j = i - 1;
//		//while loop is inserting but need to find sorted data just bigger than the data and then insert in front of it
//		//namely, search back and compare from j until the first item or the data just bigger than target
//		while (j >= 0 && arr[j].ID > key.ID) {
//            //if left is bigger than give the value to the right
//			arr[j + 1] = arr[j];
//            //go to the previous item
//			j--;
//		}
//		//insert target from right to final left position
//		//j+1 instead j, because in while loop did the last j-- and do not get in while loop
//		arr[j + 1] = key;
//	}
//}

void name_sort(struct data arr[], int n){
    int i, j;
	struct data key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && strcmp(arr[j].name, key.name)>0) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void atb_sort(struct data arr[], int n){
    int i, j;
	struct data key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && strcmp(arr[j].atb, key.atb)>0) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void atk_sort(struct data arr[], int n){
    int i, j;
	struct data key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j].atk < key.atk) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void HP_sort(struct data arr[], int n){
	int i, j;
	struct data key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j].HP > key.HP) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
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
    fprintf(stderr,"(#pokemon, #sorting queries):\n");
    scanf("%d %d", &n, &m);
    struct data pokemon[n];
    for(int i=0;i<n;i++){
        fprintf(stderr,"(name, attribute, attack, HP):\n");
        scanf("%s %s %d %d", pokemon[i].name, pokemon[i].atb, &pokemon[i].atk, &pokemon[i].HP);
    }
    for(int j=0;j<m;j++){
        scanf("%s", sort_qry);
        if(!strcmp(sort_qry,"NAME")){
            printf("Case #1:\n");
            name_sort(pokemon, n);
            printArray(pokemon, n);
        }
        else if(!strcmp(sort_qry,"ATTRIBUTE")){
            printf("Case #2:\n");
            atb_sort(pokemon, n);
            printArray(pokemon, n);
        }
        else if(!strcmp(sort_qry,"ATTACK")){
            printf("Case #3:\n");
            atk_sort(pokemon, n);
            printArray(pokemon, n);
        }
        else if(!strcmp(sort_qry,"HP")){
            printf("Case #4:\n");
            HP_sort(pokemon, n);
            printArray(pokemon, n);
        }
        else{
            j-1;
            continue;
        }
    }
	return 0;
}
