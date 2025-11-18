#include <stdio.h>
#include<stdlib.h>

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



#define MAX_SIZE 1000
int fib[MAX_SIZE];
int fibonacci(int number){
    if((number==0)||(number==1)) return number;
    if(fib[number]) return fib[number];
    else {
        fib[number] = fibonacci(number - 1) + fibonacci(number - 2);
        return fib[number];
    }
}
int k=0;
int *magicdoors(int ND,int M1,int M2,int*gaterow,int*gatecol,int W){
    static int magicdoor[4]={-1};
    int door;
    for(int i=0;i<ND;i++){
        door=gaterow[i]*W+gatecol[i];
        if(fibonacci(door)==M1){
            magicdoor[0]=gaterow[i];
            magicdoor[1]=gatecol[i];
        }
        else if(fibonacci(door)==M2){
            magicdoor[2]=gaterow[i];
            magicdoor[3]=gatecol[i];
        }
        }
        if(magicdoor[0]==-1){
            for(int i=0;i<4;i++){
                magicdoor[i]=-1;
            }
        }
        for(int i=0;i<4;i++){
        if(magicdoor[i]!=-1)
           k=-1;
        }
        
    return magicdoor;
}
//returning minimum walue;
int minimumdis(int se,int sp1 ,int sp2,int p1e,int p2e){
    int absp1,absp2, abp1e,abp2e;
    int sp1e,sp2e;

    if(sp1<0)absp1=(-1)*sp1;
    else absp1=sp1;
    if(sp2<0)absp2=(-1)*sp2;
    else absp2=sp2;
    if(p1e<0)abp1e=(-1)*p1e;
    else abp1e=p1e;
    if(p2e<0)abp2e=(-1)*p2e;
    else abp2e=p2e;
    // printf("%d %d %d %d %d\n",se,absp1,absp2,abp1e,abp2e);
    //compating if there is discances to end
    if((sp1+p2e)==(absp1+abp2e)) sp1e=sp1+p2e;
    else sp1e= -1;
    if((sp2+p1e)==(absp2+abp1e)) sp2e=sp2+p1e;
    else sp2e= -1;
    //assigning distances to integer array
    static int distances[3];
   // printf("%d %d %d",sp1e,sp2e,se);
    distances[0]=sp1e;
    distances[1]=sp2e;
    distances[2]=se;
    
    fprintf(stderr,"%d %d %d",sp1,sp2,se);

    //calculating minimum distance
    int min=5000;
    for(int i=0;i<3;i++){
      //  printf("%d",distances[i]);
        if(distances[i]==-1)continue;
        else if(distances[i]<min)min=distances[i];
    }
    if(min==5000)return -1;
    else return min;

}

int main() {
    int H, W, S1, S2, E1, E2,TR1,TC1,TR2,TC2,M1,M2,ND;


    scanf("%d %d", &H, &W);
    getchar();
    scanf("%d %d", &S1, &S2);
    getchar();
    scanf("%d %d", &E1, &E2);
    getchar();
    char s[MAX_SIZE * MAX_SIZE + 1];
    //gets(s);
    scanf("%s",s);
    getchar();
    scanf("%d",&M1);
    getchar();
    scanf("%d",&M2);
    getchar();
    scanf("%d",&ND);
    getchar();
  // fprintf(stderr,"%d %d %d %d %d %d %d %d %d %d %d %d %d",H, W, S1, S2, E1, E2,TR1,TC1,TR2,TC2,M1,M2,ND);


    //creating array of gates
    int *gaterow=(int*)malloc(sizeof(int)*ND);
    int *gatecol=(int*)malloc(sizeof(int)*ND);

    //scanning values of gates
    for(int i=0;i<ND;i++){
        scanf("%d %d",&gaterow[i],&gatecol[i]);
        getchar();
    }

    createGrid(s, H, W);
    //  printCharGrid(H, W);
    initIntArray(H, W);
//retruning magic portal array
    int *mg=magicdoors(ND,M1,M2,gaterow,gatecol,W);
    //checking if there exist magic portals
   
    for(int i=0;i<4;i++){
        if(mg[i]==-1){
            printf("The minimum distance from %c to %c is %d",arr1[S1][S2],arr1[E1][E2],floodFill(H, W, E1, E2, S1, S2));
     
            return 0;
        }
    }
    //assigning portal values;
    TR1=mg[0];
    TC1=mg[1];
    TR2=mg[2];
    TC2=mg[3];
    for(int i=0;i<4;i++){
        fprintf(stderr,"%d",mg[i]);
    }
    
    fprintf(stderr,"%d",k);////////////////////
    initIntArray(H,W);
    resetqueue();
    qcount=0;
    int se= floodFill(H, W, E1, E2, S1, S2);
    fprintf(stderr,"%d\n",se);
    
    initIntArray(H,W);
    resetqueue();
    qcount=0;
    int sp1;
if(mg[0]!=-1){
     sp1=floodFill(H,W,TR1,TC1,S1,S2);
    initIntArray(H,W);
    resetqueue();
    qcount=0;
}else sp1=-1;

int sp2;
if(mg[0]!=-1){
     sp2=floodFill(H,W,TR2,TC2,S1,S2);
    initIntArray(H,W);
    resetqueue();
    qcount=0;
}else sp2=-1;
int p1e;
if(mg[0]!=-1){
     p1e= floodFill(H,W,E1,E2,TR1,TC1);
    initIntArray(H,W);
    resetqueue();
    qcount=0;
}else p1e=-1;
int p2e;
if(mg[0]!=-1){
    p2e= floodFill(H,W,E1,E2,TR2,TC2);
}else p2e=-1;
    //printf("%d %d %d %d %d ",se,sp1,sp2,p1e,p2e);
    int distance=minimumdis(se,sp1,sp2,p1e,p2e);
    if(distance>=0){
        printf("The minimum distance from %c to %c is %d",arr1[S1][S2],arr1[E1][E2],distance);
        fprintf(stderr,"The minimum distance from %c to %c is %d",arr1[S1][S2],arr1[E1][E2],distance);
    }
    else {
        printf("There is no possible path from %c to %c",arr1[S1][S2],arr1[E1][E2]);
        fprintf(stderr,"There is no possible path from %c to %c",arr1[S1][S2],arr1[E1][E2]);
    }
    // printf("%d",step5);
    free(gaterow);
    free(gatecol);


    return 0;
}