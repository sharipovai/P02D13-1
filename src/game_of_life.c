#include <stdio.h>
#include <unistd.h>
#define WIDTH 80
#define HEIGHT 25

void view(int a[HEIGHT][WIDTH]);
int neighbors(int a[HEIGHT][WIDTH], int x, int y);
void make_next_table(int a[HEIGHT][WIDTH], int b[HEIGHT][WIDTH]);
void swap_tables(int a[HEIGHT][WIDTH], int b[HEIGHT][WIDTH]);
void start_pic_choice(int a[HEIGHT][WIDTH]);
void read_file(char *name, int a[HEIGHT][WIDTH]);
int cnt_alive(int a[HEIGHT][WIDTH]);
     
int main(void) {
    int cur_table[HEIGHT][WIDTH] = {cur_table[0][0] = 0};
    int next_table[HEIGHT][WIDTH] = {next_table[0][0] = 0};
    int flag = 0, cnt = 0;
    char command, c;
    int velocity = 0;
    start_pic_choice(cur_table);
    printf("Введите скорость 1-5\n");
    rewind(stdin);
    scanf("%d", &velocity);
    while (cnt <= 1000 && cnt_alive(cur_table) != 0) {
        view(cur_table);
        printf("Generation %d\n", cnt);
        make_next_table(cur_table, next_table);
        swap_tables(cur_table, next_table);
        cnt += 1;
        usleep(20000 - 3000 * velocity);
        printf("\033[0d\033[2J");
    }
    return 0;
}

int cnt_alive(int a[HEIGHT][WIDTH]) {
    int cnt = 0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cnt += a[i][j];
        }
        printf("\n");
    }
    return cnt;
} 

void start_pic_choice(int a[HEIGHT][WIDTH]) {
    int flag = 0, game_id = 0, t = 0;
    while (flag == 0) {
        printf("Выберите начальную инициализацию:\n");
        printf("1 - улей\n");
        printf("2 - лист\n");
        printf("3 - пульсар\n");
        printf("4 - глайдер\n");
        printf("5 - планерное ружье Госпер\n");
        if (scanf("%d.%d", &game_id, &t) == 1 && game_id > 0 && game_id < 6) {
            flag = 1;
        } else {
            printf("Ошибка! Повторите попытку!\n");
        }
    }
    char file_names[5][22] = {"bee_hive.txt", "loaf.txt", "pulsar.txt", "glider.txt", "gosper_glider_gun.txt"};    
    switch (game_id) {
        case 1:
            read_file(file_names[0], a);
            break;
        case 2:
            read_file(file_names[1], a);
            break;
        case 3:
            read_file(file_names[2], a);
            break;
        case 4:
            read_file(file_names[3], a);
            break;
        case 5:
            read_file(file_names[4], a);
            break;
    }
}

void read_file(char *name, int a[HEIGHT][WIDTH]) {
    FILE *fptr;
    int cnt = 0;
    char c;
    if ((fptr = fopen(name, "r")) == NULL) {
        printf("Error! Opening file");
    } else {
        while ((c = getc(fptr)) != EOF) {
            if (c == '1') {
                a[cnt / WIDTH][cnt % WIDTH] = 1;
                cnt += 1;
            }
            if (c == '0') {
                a[cnt / WIDTH][cnt % WIDTH] = 0;
                cnt += 1;
            }
       }
       fclose (fptr);
    }            
}
 
void view (int a[HEIGHT][WIDTH]) {
    for (int i = -1; i < HEIGHT + 1; i++) {
        for (int j = -1; j < WIDTH + 1; j++) {
            if (i == -1 || i == HEIGHT) printf("-");
            else if (j == -1 || j == WIDTH) printf("|");
	    else if (a[i][j] == 0) printf(" ");
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
