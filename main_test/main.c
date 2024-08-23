#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
# include <unistd.h>

// get_next_line関数のプロトタイプ宣言
char *get_next_line(int fd);

int main()
{
    int fd = open("main.1", O_RDONLY);
    char *line;
     
    if (fd == -1)  // ファイルが開けなかった場合のエラーチェック
    {
        perror("Error opening file");
        return (1);
    }

    line = get_next_line(fd);  // 1行目を取得
    if (line)
    {
        printf("%s", line);
        free(line);  // メモリを解放
    }

    line = get_next_line(fd);  // 2行目を取得
    if (line)
    {
        printf("%s", line);
        free(line);  // メモリを解放
    }
    
    line = get_next_line(fd);  // 2行目を取得
    if (line)
    {
        printf("%s", line);
        free(line);  // メモリを解放
    }

    close(fd);  // ファイルを閉じる
    return (0);
}

