#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define IN_LINE_COMMENT 1
#define IN_BLOCK_COMMENT 2
#define IN_STRING 4
#define IN_ID 8

#define MAX_ID_LEN 64
#define MAX_IDS 1024

#define TEST 1  // 1 - dla testowania,  0 - dla automatycznej oceny

int index_cmp(const void*, const void*);
int cmp(const void*, const void*);

char tab[MAX_IDS][MAX_ID_LEN];

char *keywords[] = {
	"auto", "break", "case", "char",
	"const", "continue", "default", "do",
	"double", "else", "enum", "extern",
	"float", "for", "goto", "if",
	"int", "long", "register", "return",
	"short", "signed", "sizeof", "static",
	"struct", "switch", "typedef", "union",
	"unsigned", "void", "volatile", "while"
};

int find_idents(FILE *stream)
{
    char ids[MAX_IDS][MAX_ID_LEN+1];
    char curr[MAX_ID_LEN+1];
    int currids = 0;
    char lastc,c;
    lastc = getc(stream);
    c = getc(stream);
    int flag;
    int j;
    while((c != EOF))
    {
        if(lastc == 92)
        {
            lastc = c;
            c = getc(stream);
            lastc = c;
            c = getc(stream);
        }
        else if(lastc == 39)
        {
            lastc = c;
            c = getc(stream);
            while(lastc == 92)
            {
                lastc = c;
                c = getc(stream);
                lastc = c;
                c = getc(stream);
            }
            while(lastc != 39)
            {
                lastc = c;
                c = getc(stream);
                while(lastc == 92)
                    {
                        lastc = c;
                        c = getc(stream);
                        lastc = c;
                        c = getc(stream);
                    }
            }
            lastc = c;
            c = getc(stream);
        }
        else if(lastc == 34)
        {
            lastc = c;
            c = getc(stream);
            while(lastc == 92)
            {
                lastc = c;
                c = getc(stream);
                lastc = c;
                c = getc(stream);
            }
            while(lastc != 34)
            {
                lastc = c;
                c = getc(stream);
                while(lastc == 92)
                    {
                        lastc = c;
                        c = getc(stream);
                        lastc = c;
                        c = getc(stream);
                    }
            }
            lastc = c;
            c = getc(stream);
        }
        else if(lastc == '/' && c == '*')
        {
            lastc = c;
            c = getc(stream);
            lastc = c;
            c = getc(stream);
            while(lastc == 92)
            {
                lastc = c;
                c = getc(stream);
                lastc = c;
                c = getc(stream);
            }
            while(lastc != '*' || c != '/')
            {
                if(c == EOF)
                    return currids;
                lastc = c;
                c = getc(stream);
                while(lastc == 92)
                {
                    lastc = c;
                    c = getc(stream);
                    lastc = c;
                    c = getc(stream);
                }
            }
            lastc = c;
            c = getc(stream);
            lastc = c;
            c = getc(stream);
        }
        else if(lastc == '/' && c == '/')
        {
            while(c != EOF && lastc != '\n')
            {
                lastc = c;
                c = getc(stream);
            }
        }
        else if((lastc > 64 && lastc < 91) || (lastc > 96 && lastc < 123) || (lastc == 95))
        {
            j = 0;
            while(curr[j] != '\0')
            {
                curr[j] = '\0';
                j++;
            }
            strncat(curr,&lastc,1);
            while(c != EOF && ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123) || (c == 95)))
            {
                strncat(curr,&c,1);
                lastc = c;
                c = getc(stream);
            }
            flag = 0;
            for(int i = 0; i < currids; i++)
                if(strcmp(curr,ids[i]) == 0)
                {
                    flag++;
                    break;
                }
            if(flag == 0)
            {
                for(int i = 0; i < 32; i++)
                    if(strcmp(curr,keywords[i]) == 0)
                        {
                            flag++;
                            break;
                        }
                if(flag == 0)
                {
                    strcpy(ids[currids],curr);
                    currids++;
                }
            }
            lastc = c;
            c = getc(stream);
        }
        else
        {
            lastc = c;
            c = getc(stream);
        }
    }
    scanf("%s",curr);
    return currids;
}

int cmp(const void* first_arg, const void* second_arg) {
	char *a = *(char**)first_arg;
	char *b = *(char**)second_arg;
	return strcmp(a, b);
}

int index_cmp(const void* first_arg, const void* second_arg) {
	int a = *(int*)first_arg;
	int b = *(int*)second_arg;
	return strcmp(tab[a], tab[b]);
}

int main(void) {
	char file_name[40];
	FILE *stream;

  if(TEST)  stream = stdin;
  else {
      scanf("%s",file_name);
      stream = fopen(file_name,"r");
      if(stream == NULL) {
          printf("fopen failed\n");
          return -1;
      }
  }
	printf("%d\n", find_idents(stream));
	return 0;
}

