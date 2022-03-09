#include <stdio.h>

#define n 100
#define m 100
int main()
{
    int x = 100;
    char line[x];
    char matrix[n][m];
    char a = '*';
    char b = '*';
    int str = 0;
    int stb = 0;
    FILE* in = fopen("matrix.txt", "r");
    FILE* out = fopen("graf.gv", "w");
    fputs("graph idz2 {", out);
    fgets(line, x, in);
    while (fgets(line, x, in)) {
        stb = 0;
        for (int i = 0; line[i]; i++) {
            if (line[i] != ' ') {
                matrix[str][stb] = line[i];
                stb++;
            }
        }
        str++;
    }
    for (int i = 1; i < stb; i++) {
        for (int j = 0; j < str; j++) {
            if (matrix[j][i] == '1') {
                b = a;
                a = matrix[j][0];
            }
        }
        fputs("\n", out);
        fputs("\t", out);
        fprintf(out, "%c", b);
        fputs("--", out);
        fprintf(out, "%c", a);
        fputs(";", out);
    }
    fputs("\n", out);
    fputs("}", out);
    fclose(out);
    fclose(in);
    return 0;
}
