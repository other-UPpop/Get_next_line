
#define BUFFER_SIZE 32

// ここにget_next_line関数とその他の関数の実装を含めてください
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

#define NUM_FILES 3 // 読み込むファイルの数

int main(void)
{
    int     fd[NUM_FILES];
    char    *line;
    int     i;
    int     j;

    // ファイルを開く
    fd[0] = open("1.text", O_RDONLY);
    fd[1] = open("2.text", O_RDONLY);
    fd[2] = open("3.text", O_RDONLY);

    if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0)
    {
        perror("open");
        return (1);
    }

    // 各ファイルから1行ずつ読み込んで表示
    for (i = 0; i < NUM_FILES; i++)
    {
        printf("Contents of file %d:\n", i + 1);
        while ((line = get_next_line(fd[i])) != NULL)
        {
            printf("%s", line);
            free(line); // メモリの解放
        }
        printf("\n");
    }

    // ファイルを閉じる
    for (j = 0; j < NUM_FILES; j++)
        close(fd[j]);

    return (0);
}

