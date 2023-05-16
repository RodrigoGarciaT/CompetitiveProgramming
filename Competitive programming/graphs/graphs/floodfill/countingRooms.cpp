#include <bits/stdc++.h>
using namespace std;
const long long maxN =2000,maxM = 2000;
bool visited[maxN][maxM];
long long n,m;
char grid[maxN][maxM];

void floodfill(int r, int c, int color){
	if ((r < 0 || r >= n || c < 0 || c >= m)  // if out of bounds
	    || grid[r][c] != color                            // wrong color
	    || visited[r][c]  // already visited this square
	)
		return;

	visited[r][c] = true;  // mark current square as visited

	// recursively call flood fill for neighboring squares
	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r - 1, c, color);
	floodfill(r + 1, c, color);
}
int main() {
	cin>>n>>m;

	for(long long r =0;r<n;r++){
		for(long long c=0;c<m;c++){
			cin>>grid[r][c];
		}
	}
	long long count =0;
	for(long long r =0;r<n;r++){
		for(long long c=0;c<m;c++){
			if(!visited[r][c]&&grid[r][c]=='.'){
				count++;
				floodfill(r,c,grid[r][c]);
			}
		}
	}

	cout<<count<<endl;
}
