#include<iostream>

int board[8][8] = {0};


bool secure(int x, int y){
    return board[x][y] == 0;
}

void allocateSquares(int m,int n, int val){
   for(int i = n; i<8; i++){ 
        if(board[m][i] == 0){
            board[m][i] = val;
        }
    }
    int p = m;
    int q = n;
       while(1){ 
        if(p == 0 || q == 7) break;
        p--;
        q++;
        if(board[p][q] == 0){
            board[p][q] = val;
        }
    }
    while(true){ 
        if(m == 7 || n == 7) break;
        m++;
        n++;
        if(board[m][n] == 0){
            board[m][n] = val;
        }
    }
}
void deallocateSquares(int z){
    for (int i =0; i<8; i++){
        for(int j = 0; j< 8; j++){
            if(board[i][j] == z)
                board[i][j] = 0;
        }
    }
}
void solve(int &solution){
    for(int a = 0; a <8; a++ ){
        allocateSquares(a,0,1);
    
    for(int b = 0; b <8; b++ ){
        if(!secure(b,1)) continue;
        allocateSquares(b,1,2);
    for(int c = 0; c <8; c++ ){
        if(!secure(c,2)) continue;
        allocateSquares(c,2,3);
    for(int d = 0; d <8; d++ ){
        if(!secure(d,3)) continue;
        allocateSquares(d,3,4);
    for(int e = 0; e <8; e++ ){
        if(!secure(e,4)) continue;
        allocateSquares(e,4,5);
    for(int f = 0; f <8; f++ ){
        if(!secure(f,5)) continue;
        allocateSquares(f,5,6);
    for(int g = 0; g <8; g++ ){
        if(!secure(g,6)) continue;
        allocateSquares(g,6,7);
    for(int h = 0; h<8; h++){
        if(!secure(h,7)) continue;
        solution++;
        std::cout<<"A = "<<a<<"\tB = "<<b<<"\tC = "<<c<<"\tD = "<<d<<"\tE = "<<e<<"\tF = "<<f<<"\tG = "<<g<<"\tH = "<<h<<std::endl;
        }
        deallocateSquares(7);
        }
        deallocateSquares(6);
        }
        deallocateSquares(5);
        }
        deallocateSquares(4);
        }
        deallocateSquares(3);
        }
        deallocateSquares(2);
        }
        deallocateSquares(1);
    }
}
int main(){
    int solutionCount = 0;
    solve(solutionCount);
    std::cout<<solutionCount<<" Solutions";
}
