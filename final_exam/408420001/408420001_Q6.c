#include<stdio.h>
#include <stdlib.h>

int main()
{
    int n,count=0;
    char c;
    char ban_word[128];
    scanf("%d", &n);
    char name[n][20], message[nn][4074];
    int ban[n];
    scanf("%s", ban_word);
    if(1 <= n && n <= 1000)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s: ", name[i]);
            fgets(message[i],4074,stdin);
//            printf("%s", name[i]);
//            printf("%s\n", message[i]);

        }
    }
    for(int i=0;i<n;i++)
    {

    }
    return 0;
}
