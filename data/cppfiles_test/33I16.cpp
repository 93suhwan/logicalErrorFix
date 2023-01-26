/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifndef LOCAL 
	#pragma GCC optimize("Ofast") 
#endif
#define MX 1000005
#define INF (1<<30)
#define INF64 (1ll<<62)
#define EPS 1e-9
#define MOD 1000000007
#define mid (x+xend)/2
#define izq nod*2
#define der nod*2+1
#define fr first
#define sc second
#define pb push_back
#define mp make_pair
#define len(X) ((int)((X).size()))
#define all(X) (X).begin(), (X).end()
#define chmax(X, Y) X = max((X), (Y))
#define chmin(X, Y) X = min((X), (Y))
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
#ifdef LOCAL 
	#include "debug.h"
#endif
using namespace std;
using namespace __gnu_pbds;

typedef long long int64;
typedef unsigned long long unt64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;

int N;
int A[MX];
bool mk[5005][10005];
bool sol[10005];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
	scanf("%d", &N);
	for(int i=1; i<=N; i++)
		scanf("%d", &A[i]);
		
	int ma = *max_element(A+1, A+N+1);
		
	for(int i=0; i<=2*ma; i++)
		mk[i][0] = true;
	sol[0] = true;
	
	for(int i=1; i<=N; i++){
		for(int j=0; j<=ma; j++){
			if( mk[ A[i] ][j] ){
				sol[ j ^ A[i] ] = true;
				
				for(int k=A[i]+1; k<=ma; k++){
					if( !mk[k][ j ^ A[i] ] )
						mk[k][ j ^ A[i] ] = true;
					else
						break;
				}
			}
		}
	}
	
	vector<int> vec;
	for(int i=0; i<=2*ma; i++)
		if( sol[i] ) vec.pb(i);
	
	printf("%d\n", len(vec));
	for(int i=0; i < len(vec); i++)
		printf(i==len(vec)-1 ? "%d\n" : "%d ", vec[i]);
		
		
   return 0;
}
