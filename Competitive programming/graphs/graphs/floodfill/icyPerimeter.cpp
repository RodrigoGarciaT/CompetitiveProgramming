#include <bits/stdc++.h>
using namespace std;
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
const long long maxN =2000,maxM = 2000;
//bool visited[maxN][maxM];
map<pair<long long, long long>,bool>visited;
long long n,m;
char grid[maxN][maxM];
long long perimeter = 0;
long long area = 0;
unordered_map<long long, long long>mp;
void floodfill(long long r, long long c, char color){
	if ((r < 0 || r >= n || c < 0 || c >= m)  // if out of bounds
	    || grid[r][c] != color                            // wrong color
	    || visited[{r,c}]  // already visited this square
	){
		
		if((r < 0 || r >= n || c < 0 || c >= m)){
			//cout<<r<<' '<<c<<endl;
			perimeter++;
		}else if(grid[r][c]!=color){
			//cout<<r<<' '<<c<<endl;
			perimeter++;
		}
		visited[{r,c}]=true;
		return;
	}
	
	area++;
	visited[{r,c}] = true;  // mark current square as visited
	// recursively call flood fill for neighboring squares
	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r - 1, c, color);
	floodfill(r + 1, c, color);
}
int main() {
    setIO("perimeter");
	cin>>n;
	m = n;
	for(long long r =0;r<n;r++){
		for(long long c=0;c<m;c++){
			cin>>grid[r][c];
		}
	}
	long long maxArea = 0;
	for(long long r =0;r<n;r++){
		for(long long c=0;c<m;c++){
			if(!visited[{r,c}]&&grid[r][c]=='#'){
				//cout<<"hola"<<endl;
				floodfill(r,c,grid[r][c]);
				if(mp[area]==0)mp[area]=perimeter;

				mp[area]= min(mp[area],perimeter);
				maxArea = max(area, maxArea);
				area = 0;
				perimeter = 0;
			}
		}
	}
	cout<<maxArea<<' '<<mp[maxArea]<<endl;
}
