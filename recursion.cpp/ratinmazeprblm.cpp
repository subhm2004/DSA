// find the possible ways to reach the destination position 
#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool issafe(int x, int y, int row, int col, int maze[3][3], vector<vector<bool>>& visited){
    if(((x>=0 && x< row) && (y>=0 && y< col)) && (maze[x][y]== 1) && (visited[x][y]== false)){
        return true;
    }
    else {
        return false;
    }
}

void solvemaze(int maze[3][3], int &row, int &col, int x, int y,vector<string>&path,
               string output= "", vector<vector<bool> > visited= {}){
                // basecase
                if(x== row-1 && y== col-1){ // reached destination co-ordinate
                    path.push_back(output);
                    return;
                }
                // down
                if(issafe(x+1,y,row,col,maze,visited)){
                    visited[x+1][y] = true;
                    solvemaze(maze,row,col,x+1,y,path,output+'D',visited);
                    // function call se wapis aane ke baad backtrack kro
                    visited[x+1][y]= false;
                }
                // left
                if(issafe(x,y-1, row,col,maze, visited)){
                    visited[x][y-1]= true;
                    solvemaze(maze,row,col,x,y-1,path,output+'L',visited);
                    visited[x][y-1]= false;
                }
                // right
                if(issafe(x,y+1,row,col,maze,visited)){
                    visited[x][y+1]= true;
                    solvemaze(maze,row,col,x,y+1,path,output+ 'R',visited);
                    visited[x][y+1]= false;

                }
                // up
                if(issafe(x-1,y, row,col,maze,visited)){
                    visited[x-1][y]= true;
                    solvemaze(maze,row,col,x-1,y,path,output+'U',visited);
                    visited[x-1][y]= false;

                }
 }
int main(){
    int maze[3][3]= {{1,0,0},
                     {0,0,0},
                     {1,1,0},

                    };
    if(maze[0][0]== 0){
        cout<< "no path exists"<< endl;
        return 0;
    }
    // maxe array ki rows and columns
    int row=3, col= 3;
    // x and y co-ordinates of source
    int x=0, y=0;
    // vector that stores all possible paths
    vector<string>path;
    // string jisme har movement ko add krege 
    string output= "";
    // 2-D veector jisme visited mark krege
    vector<vector<bool> > visited(row,vector<bool>(col,false));
    visited[0][0]= true;
    solvemaze(maze,row,col,x,y,path,output,visited);
    for(int i=0; i< path.size(); i++){
        cout<< path[i]<< " ";
    }
    if(path.size()== 0){
        cout<< "no path exists"<< endl;
    }


}