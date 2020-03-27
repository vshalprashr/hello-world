#include <iostream>
using namespace std;

void mark(vector<int> A[], bool** visited, int i, int j, int n, int m){
    visited[i][j] = true;
    
    if(i>0 && j>0 && A[i-1][j-1] && !visited[i-1][j-1]){
        mark(A, visited, i-1, j-1, n, m);
    }
    if(i>0 && A[i-1][j] && !visited[i-1][j]){
        mark(A, visited, i-1, j, n, m);
    }
    if(i>0 && j<m-1 && A[i-1][j+1] && !visited[i-1][j+1]){
        mark(A, visited, i-1, j+1, n, m);
    }
    if(j>0 && A[i][j-1] && !visited[i][j-1]){
        mark(A, visited, i, j-1, n, m);
    }
    
    if( j<m-1 && A[i][j+1] && !visited[i][j+1]){
        mark(A, visited, i, j+1, n, m);
    }
    if( i<n-1 && j>0 && A[i+1][j-1] && !visited[i+1][j-1]){
        mark(A, visited, i+1, j-1, n, m);
    }
    if( i<n-1 && A[i+1][j] && !visited[i+1][j]){
        mark(A, visited, i+1, j, n, m);
    }
    if( i<n-1 && j<m-1 && A[i+1][j+1] && !visited[i+1][j+1]){
        mark(A, visited, i+1, j+1, n, m);
    }
}

int findIslands(vector<int> A[], int n, int m)
{
    
    // Your code here
    bool** visited = new bool*[50];
    for(int i=0 ; i<50 ; i++)
        visited[i] = new bool[50]();
    int count = 0;
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(A[i].at(j) && !visited[i][j]){
                mark(A,visited,i,j,n,m);
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<int> arr;
    
    return 0;
}