#include <stdio.h>
#define WIDTH 80
#define HEIGHT 25

void view(int a[HEIGHT][WIDTH]);
int neighbors(int a[HEIGHT][WIDTH], int x, int y);
void make_next_table(int a[HEIGHT][WIDTH], int b[HEIGHT][WIDTH]);
void swap_tables(int a[HEIGHT][WIDTH], int b[HEIGHT][WIDTH]);
void glider(int a[HEIGHT][WIDTH]);
void bee_hive(int a[HEIGHT][WIDTH]);
void gosper_glider_gun(int a[HEIGHT][WIDTH]);
void hwss(int a[HEIGHT][WIDTH]);
  
int main(void) {
    int cur_table[HEIGHT][WIDTH] = {cur_table[0][0] = 0};
    int next_table[HEIGHT][WIDTH] = {next_table[0][0] = 0};
    gosper_glider_gun(cur_table);
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

void glider(int a[HEIGHT][WIDTH]) {
    a[1][1] = 1;
    a[1][3] = 1;
    a[2][2] = 1;
    a[2][3] = 1;
    a[3][2] = 1;
}

void bee_hive(int a[HEIGHT][WIDTH]) {
    a[1][2] = 1;
    a[1][3] = 1;
    a[2][1] = 1;
    a[2][4] = 1;
    a[3][2] = 1;
    a[3][3] = 1;
}

void gosper_glider_gun (int a[HEIGHT][WIDTH]) {
    a[5][1] = 1;
    a[6][1] = 1;
    a[5][2] = 1;
    a[6][2] = 1;
    a[5][11] = 1;
    a[6][11] = 1;
    a[7][11] = 1;
    a[4][12] = 1;
    a[8][12] = 1;
    a[3][13] = 1;
    a[9][13] = 1;
    a[3][14] = 1;
    a[9][14] = 1;
    a[6][15] = 1;
    a[4][16] = 1;
    a[8][16] = 1;
    a[5][17] = 1;
    a[6][17] = 1;
    a[7][17] = 1;
    a[6][18] = 1;
    a[3][21] = 1;
    a[4][21] = 1;
    a[5][21] = 1;
    a[3][22] = 1;
    a[4][22] = 1;
    a[5][22] = 1;
    a[2][23] = 1;
    a[6][23] = 1;
    a[1][25] = 1;
    a[2][25] = 1;
    a[6][25] = 1;
    a[7][25] = 1;
    a[3][35] = 1;
    a[4][35] = 1;
    a[3][36] = 1;
    a[4][36] = 1;
}

void hwss(int a[HEIGHT][WIDTH]) {
    a[1][4] = 1;
    a[1][5] = 1;
    a[2][2] = 1;
    a[2][7] = 1;
    a[3][1] = 1;
    a[4][1] = 1;
    a[4][7] = 1;
    a[5][1] = 1;
    a[5][2] = 1;
    a[5][3] = 1;
    a[5][4] = 1;
    a[5][5] = 1;
    a[5][6] = 1;
}