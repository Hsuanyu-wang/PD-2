//輸入皆為同樣位數
//0不為開頭

#include <math.h>
#include <stdio.h>

struct data{
    int ID;
    int score;
};

/* insertion sort function*/
//sorting sequence : small -> big
void insertionSort(struct data arr[], int n)
{
    //declaration
	int i, j;
	struct data key;
	//check the array value sequence and sort it
	for (i = 1; i < n; i++) {
        //set key as the going through head for array
		key = arr[i];
        //j is the front item of key
		j = i - 1;
		//while loop is inserting but need to find sorted data just bigger than the data and then insert in front of it
		//namely, search back and compare from j until the first item or the data just bigger than target
		while (j >= 0 && arr[j].ID > key.ID) {
            //if left is bigger than give the value to the right
			arr[j + 1] = arr[j];
            //go to the previous item
			j--;
		}
		//insert target from right to final left position
		//j+1 instead j, because in while loop did the last j-- and do not get in while loop
		arr[j + 1] = key;
	}
}

void printArray(struct data arr[], int n)
{
    printf("ID\tscore\n");
    int i;
    for (i = 0; i < n; i++)
        printf("%d\t%d\n", arr[i].ID,arr[i].score);
}

/* Driver program to test insertion sort */
int main()
{
    int num;
    fprintf(stderr,"Number of records you want to key in:");
    scanf("%d", &num);
    struct data list[num];
    for(int i=0;i<num;i++){
        fprintf(stderr,"Enter ID & score:");
        scanf("%d %d", &list[i].ID, &list[i].score);
    }
    insertionSort(list, num);
	printArray(list, num);

	return 0;
}
