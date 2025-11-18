#include <stdio.h>

#define MAX_SIZE 1000 //defining a value (should be large)

char arr1[MAX_SIZE][MAX_SIZE];//getting array for a map
int integer_array[MAX_SIZE][MAX_SIZE];//getting integer array for simplyfy the map

void createGrid(char *array, int H, int W) {//making a grid
    int i, j;
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            arr1[i][j] = *array++;
        }
    }
}

void initIntArray(int H, int W) {//setting 1 for only we wanted area(for see clear)
    int i, j;
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            integer_array[i][j] = 1;
        }
    }
}

void printCharGrid(int H, int W) {//for print char array(only for checking)
    int i, j;
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            printf("%c ", arr1[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int H, int W, int r, int c, int new_r, int new_c) {//checking move is valid
    if (new_r >= 0 && new_r < H && new_c >= 0 && new_c < W) {
        int diff = arr1[new_r][new_c] - arr1[r][c];
        if (-3 <= diff && diff <= 2 && integer_array[new_r][new_c] == 1) {
            return 1;
        }
    }
    return 0;
}

int qcount = 0;//row of queue
int queue[MAX_SIZE * MAX_SIZE][3];//making a queue

void insert_queue(int arr[]) {//insterting value to queue
    for (int i = 0; i < 3; i++) {
        queue[qcount][i] = arr[i];
    }
    qcount++;
}
int output[3];
int *remove_queue() {//removing value from queue

    for (int j = 0; j < 3; j++) {
        output[j] = queue[0][j];
    }
    for (int k = 0; k < qcount - 1; k++) {
        for (int l = 0; l < 3; l++) {
            queue[k][l] = queue[k + 1][l];
        }
    }
    qcount--;
    return output;
}
void resetqueue(){
    for(int i=0;i<1000;i++){
        for(int j=0;j<3;j++){
            queue[i][j]=0;
        }
    }
}

int floodFill(int H, int W, int E1, int E2, int S1, int S2) {//setting flood fill algorithim to count the steps
    int totalstep = 0;
    int detail[3] = {S1, S2, totalstep};
    insert_queue(detail);
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (qcount) {
        int *output = remove_queue();
        int r = output[0];
        int c = output[1];
        int steps = output[2];

        if (r == E1 && c == E2) {

            return steps;
        }

        if (integer_array[r][c] == 0) {
            continue;
        }

        integer_array[r][c] = 0;

        for (int k = 0; k < 4; k++) {
            int new_r = r + dir[k][0];
            int new_c = c + dir[k][1];
            if (is_valid_move(H, W, r, c, new_r, new_c)) {
                detail[0] = new_r;
                detail[1] = new_c;
                detail[2] = steps + 1;
                insert_queue(detail);
            }
        }
    }

    return -1;
}

int main() {
    int H, W, S1, S2, E1, E2,TR1,TC1,TR2,TC2;

    scanf("%d %d", &H, &W);
    getchar();
    scanf("%d %d", &S1, &S2);
    getchar();
    scanf("%d %d", &E1, &E2);
    getchar();
    char s[MAX_SIZE * MAX_SIZE + 1];
    //gets(s);
    scanf("%s",s);
    createGrid(s, H, W);
    //  printCharGrid(H, W);
    initIntArray(H, W);

    scanf("%d %d",&TR1,&TC1);
    scanf("%d %d",&TR2,&TC2);
    initIntArray(H,W);
    resetqueue();
    qcount=0;
    int step1 = floodFill(H, W, E1, E2, S1, S2);
    initIntArray(H,W);
    resetqueue();
    qcount=0;

    int step2=floodFill(H,W,TR1,TC1,S1,S2);
    initIntArray(H,W);
    resetqueue();
    qcount=0;
    int step3=floodFill(H,W,TR2,TC2,S1,S2);
    initIntArray(H,W);
    resetqueue();
    qcount=0;

    int step4= floodFill(H,W,E1,E2,TR1,TC1);
    initIntArray(H,W);
    resetqueue();
    qcount=0;
    int step5= floodFill(H,W,E1,E2,TR2,TC2);


    printf("%d %d %d %d %d",step1,step2,step3,step4,step5);

   // printf("%d",step5);



    return 0;
}