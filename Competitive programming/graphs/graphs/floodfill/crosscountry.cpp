#include <bits/stdc++.h>
using namespace std;
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
const long long maxN =2000,maxM = 2000;
//bool visited[maxN][maxM];
bool visited [maxN][maxM];
long long n,m;
long long grid[maxN][maxM];
bool bGrid[maxN][maxM];
long long middle = 99;
long long fcount = 0;
void floodfill(long long r, long long c, long long color){
	if ((r < 0 || r >= n || c < 0 || c >= m)  // if out of bounds
	    || color>middle                           // wrong color
	    || visited[r][c]  // already visited this square
	){return;}

	if(bGrid[r][c])fcount++;
	visited[r][c] = true;  // mark current square as visited
	// recursively call flood fill for neighboring squares
	color = abs(grid[r][c]-grid[r][c+1]);
	floodfill(r, c + 1, color);
	color = abs(grid[r][c]-grid[r][c-1]);
	floodfill(r, c - 1, color);
	color = abs(grid[r][c]-grid[r-1][c]);
	floodfill(r - 1, c, color);
	color = abs(grid[r][c]-grid[r+1][c]);
	floodfill(r + 1, c, color);
}
int main() {
	setIO("ccski");
	cin>>n;
	cin>>m;
	for(long long r =0;r<n;r++){
		for(long long c=0;c<m;c++){
			cin>>grid[r][c];
		}
	}
	long long sCounter = 0;
	for(long long r =0;r<n;r++){
		for(long long c=0;c<m;c++){
			cin>>bGrid[r][c];
			if(bGrid[r][c])sCounter++;
		}
	}
	//middle =20;
	long long l =0,r = 1000000000;

	for(int i=0;i<35;i++){
		middle =l+(r-l)/2;

		floodfill(0,0,0);
		if(fcount == sCounter){
			r =middle;
		}else{
			l=middle;
		}
		fcount = 0;
		fill(&visited[0][0], &visited[0][0] + sizeof(visited) / sizeof(**visited),0);
	}
	cout<<r<<endl;
	//floodfill(0,0,0);
	//cout<<fcount<<endl;

}
