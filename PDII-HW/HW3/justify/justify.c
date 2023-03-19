#include <stdio.h>
#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(void){
    char word[MAX_WORD_LEN+2];
    //printf("1\n");
    int word_len;
    //printf("2\n");
    clear_line();
    //printf("word_len1 %s\n", word);
//    printf("3\n");
    while (1) {
    //printf("4\n");
        read_word(word, MAX_WORD_LEN+1);
        //printf("word_len2 %s\n", word);
    //printf("5\n");
        word_len = strlen(word);
    //printf("word_len3 %d\n", word_len);
        //沒有讀取到word
        if (word_len == 0) {
            printf("7\n");
            flush_line();
            printf("7'\n");
            return 0;
        }
        //溢出變'*'
        if (word_len > MAX_WORD_LEN) {
            printf("8'\n");
                word[MAX_WORD_LEN] = '*';
            printf("8\n");
        }
        //加的word超過line的大小就印出和清空

        if (word_len + 1 > space_remaining()) {
            printf("9\n");
            write_line();
            clear_line();
        printf("9'\n");
        }
        //加word
        add_word(word);
            printf("11\n");
    }
    return 0;
}
