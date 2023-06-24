#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
#define f first
#define s second

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;


	int a[n],d[n];

	vector<pair<int,int>>customers;
	stack<int>freeRooms;
	map<pair<int,int>,stack<int>>couple;
	unordered_map<int, stack<int>>endTime;
	unordered_map<int, stack<int>>occupied;
	//unordered_map<int, stack<int>>
	for(int i =0; i<n;i++){
        cin>>a[i]>>d[i];
		customers.push_back({a[i],d[i]});
		endTime[a[i]].push(d[i]);
	}

	sort(a, a+n);
	sort(d, d+n);
	
	int it1 = 0,it2 = 0,end;
	int room = 0, maxRoom = 0;
	while(it1<n){
		if(a[it1] <=d[it2]){
			room++;
			if(room > maxRoom)maxRoom = room;
            end =endTime[a[it1]].top();
			endTime[a[it1]].pop();
			if(freeRooms.size()){
				couple[{a[it1],end}].push(freeRooms.top());
				occupied[end].push(freeRooms.top());
				freeRooms.pop();
			}else{
				couple[{a[it1],end}].push( maxRoom );
				occupied[end].push( maxRoom );
			}
			it1++;
		}else{
			room--;
			freeRooms.push(occupied[d[it2]].top());
			occupied[d[it2]].pop();
			it2++;
		}
	}

	cout<<maxRoom<<endl;
	int fi,en;
	for(int i =0;i<n-1;i++){
		fi = customers[i].first;
		en = customers[i].second;
		cout<<couple[{fi,en}].top()<<' ';
		couple[{fi,en}].pop();
	}
	cout<<couple[{customers[n-1].first,customers[n-1].second}].top()<<endl;
	return 0;
}
