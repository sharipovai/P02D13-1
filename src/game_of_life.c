#include <stdio.h>
#define WIDTH 80
#define HEIGHT 25

void view(int a[HEIGHT][WIDTH]);
int neighbors(int a[HEIGHT][WIDTH], int x, int y);
void make_next_table(int a[HEIGHT][WIDTH], int b[HEIGHT][WIDTH]);
void swap_tables(int a[HEIGHT][WIDTH], int b[HEIGHT][WIDTH]);
 
int main(void) {
    int cur_table[HEIGHT][WIDTH] = {cur_table[0][0] = 0};
    int next_table[HEIGHT][WIDTH] = {next_table[0][0] = 0};
    cur_table[2][3] = 1;
    cur_table[3][3] = 1;
    cur_table[4][3] = 1;
    int flag = 0;
    char command;
    while (flag == 0) {
        view(cur_table);
        make_next_table(cur_table, next_table);
        swap_tables(cur_table, next_table);
        scanf("%c", &command);
        if (command == '\n')
            flag = 0;
        else
            flag = 1;  
    }
    return 0;
}

void view (int a[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (a[i][j] == 0) printf(" ");
            else printf("#");
        }
        printf("\n");
    }
}

int neighbors(int a[HEIGHT][WIDTH], int x, int y) {
    int cnt = 0;
    int line = 0, col = 0;
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (i < 0) line = HEIGHT - 1;
            else if (i >= HEIGHT) line = 0;
            else line = i;
            if (j < 0) col = WIDTH - 1;
            else if (j >= WIDTH) col = 0;
            else col = j;
            cnt += a[line][col];
        }
    }
    cnt -= a[y][x];
    return cnt;
}

void make_next_table(int a[HEIGHT][WIDTH], int b[HEIGHT][WIDTH]) {
    int nb = 0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            nb = neighbors(a, j, i); 
            if (a[i][j] == 0 && nb == 3) {
                b[i][j] = 1;
            }
            if (a[i][j] == 1 && (nb >= 2 || nb <= 3)) {
                b[i][j] = 1;
            }     
            if (a[i][j] == 1 && (nb < 2 || nb > 3)) {
                b[i][j] = 0;
            }
        }
    }
}

void swap_tables(int a[HEIGHT][WIDTH], int b[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            a[i][j] = b[i][j];
        }
    }
}
 
