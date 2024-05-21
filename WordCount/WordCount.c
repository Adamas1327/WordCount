#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
  
int main(int argc, char *argv[]) {  
    FILE *file;  
    char ch;  
    int isWord = 0;  
    long charCount = 0;  
    long wordCount = 0;  
  
    if (argc != 3) {  
        fprintf(stderr, "Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  
        return 1;  
    }  
  
    if (strcmp(argv[1], "-c") == 0) {  
        // 打开文件  
        file = fopen(argv[2], "r");  
        if (file == NULL) {  
            perror("Error opening file");  
            return 1;  
        }  
  
        // 读取并统计字符数  
        while ((ch = fgetc(file)) != EOF) {  
            charCount++;  
        }  
  
        // 关闭文件  
        fclose(file);  
  
        // 输出字符数  
        printf("字符数：%ld\n", charCount);  
    } else if (strcmp(argv[1], "-w") == 0) {  
        // 打开文件  
        file = fopen(argv[2], "r");  
        if (file == NULL) {  
            perror("Error opening file");  
            return 1;  
        }  
  
        // 读取并统计单词数  
        while ((ch = fgetc(file)) != EOF) {  
            if (isspace(ch) || ch == ',') {  
                if (isWord) {  
                    wordCount++;  
                    isWord = 0;  
                }  
            } else if (isalpha(ch)) { // 假设单词由字母构成  
                isWord = 1;  
            }  
        }  
  
        // 最后一个单词可能没有结束符，检查并计数  
        if (isWord) {  
            wordCount++;  
        }  
  
        // 关闭文件  
        fclose(file);  
  
        // 输出单词数  
        printf("单词数：%ld\n", wordCount);  
    } else {  
        fprintf(stderr, "Invalid parameter. Use -c for character count or -w for word count.\n");  
        return 1;  
    }  
  
    return 0;  
}