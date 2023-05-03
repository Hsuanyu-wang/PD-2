#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n,m,count = 0;
    scanf("%d %d", &n, &m);
    char CR[n][m];
    for(int i=0;i<n;i++)
            scanf("%s", CR[i]);

//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            printf("%c", CR[i][j]);
//        }
//        printf("\n");
//    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(CR[i][j] == '.')
            {
                count++;
//                //left
//                if(CR[i][j-1] == '.')
//                {
//                    count--;
//                }
                //right
                if(CR[i][j+1] == '.')
                {
                    count--;
                }
//                //top
//                else if(CR[i-1][j] == '.')
//                {
//                    count--;
//                }
                //down
                if(CR[i+1][j] == '.')
                {
                    count--;
                }
            }
        }
    printf("%d\n", count);

    return 0;
}
