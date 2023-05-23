#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll t, n;

void solve(){
	
	vector<ll>sol(n+4),a(n+1);
	for(ll i =0; i<n;i++){
		cin>>a[i];
	}
	a[n] = 0;
	for(ll i = n-1;i>=0;i--){
		ll case1 =a[i]+ sol[i+2];
		ll case2 = a[i]+ sol[i+3];
		ll case3 = a[i]+a[i+1]+ sol[i+3];
		ll case4 = a[i]+ a[i+1]+ sol[i+4];
		ll ans = min(min(case1, case2), min(case3, case4));
		sol[i] = ans;
	}

	cout<<sol[0]<<endl;
}
int main() {
	cin>>t;
	while(t--){
		cin>>n;
		solve();
	}	
}

/*

el amigo es una distraccion y como no hay que contar nada de el empezando en cada punto solo hay un calculo
y sse puede usar dp

tmb se puede con  greedy



To recognize that this problem can be solved using dynamic programming (DP), you can look for the following signs:

Overlapping subproblems: If you observe that the problem can be broken down into smaller subproblems that have overlapping solutions, it indicates the potential for using DP. In this problem, the minimum skip points required to reach a boss depend on the minimum skip points required to reach the previous bosses, indicating overlapping subproblems.

Optimal substructure: If the optimal solution to the problem can be constructed from the optimal solutions of its subproblems, it suggests the use of DP. In this problem, the minimum skip points required to reach a boss can be calculated by considering different cases based on the previous bosses' skip points, indicating optimal substructure.

Recursive or iterative formulation: If you can formulate a recursive or iterative relationship between the problem and its subproblems, it suggests the application of DP. In this problem, the minimum skip points for a boss can be expressed in terms of the minimum skip points for the previous bosses, leading to a recursive or iterative formulation.

Memoization or tabulation: If you need to store and reuse the solutions to the subproblems, either through memoization (top-down) or tabulation (bottom-up), it indicates the use of DP. In this problem, the code uses a vector sol to store the solutions for each boss, which is a form of tabulation.

By considering these signs and analyzing the problem's structure and requirements, you can identify it as a DP problem and apply the appropriate techniques to solve it efficiently.



Certainly! Let's go through each point and see how it applies to the given problem:

Overlapping subproblems:

In the problem, the minimum skip points required to reach a boss depend on the minimum skip points required to reach the previous bosses.
The calculation of skip points for each boss is based on the solutions to the subproblems of reaching the previous bosses.
For example, in the code sol[i] = min(min(case1, case2), min(case3, case4)), the values of sol[i+2], sol[i+3], sol[i+1], and sol[i+4] are reused, indicating overlapping subproblems.
Optimal substructure:

The optimal solution for the problem can be constructed from the optimal solutions of its subproblems.
The minimum skip points required to reach a boss can be calculated by considering different cases based on the previous bosses' skip points.
The optimal solution for a boss is determined by selecting the minimum skip points among the cases, which depends on the optimal solutions for the previous bosses.
Recursive or iterative formulation:

The problem can be formulated using a recursive or iterative relationship between the problem and its subproblems.
The minimum skip points for a boss can be expressed in terms of the minimum skip points for the previous bosses.
In the given code, the iterative formulation is used with the loop iterating backward from the second-to-last boss to the first boss.
Memoization or tabulation:

The solutions to the subproblems are stored and reused through memoization or tabulation.
In the given code, the vector sol is used to store the solutions for each boss.
The values in sol are updated iteratively, starting from the second-to-last boss and moving towards the first boss.
By considering these points, we can observe that the problem exhibits overlapping subproblems, has an optimal substructure, can be formulated recursively or iteratively, and requires storing and reusing solutions through tabulation. These characteristics indicate the use of dynamic programming to solve the problem effectively.
*/
