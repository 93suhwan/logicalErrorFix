#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define izq nod * 2
#define der nod * 2 + 1
#define md (( a + b ) >> 1)
#define oo (1<<30)
#define oo64 (1LL<<62LL)
#define fr first
#define sc second
#define pb push_back
#define m_p make_pair
#define len(X) ((int)((X).size()))
#define all(X) (X).begin(), (X).end()
#define YES cout<<"YES"<<'\n'
#define NO cout<<"NO"<<'\n'
#define NO1 cout<<'-'<<'1'<<'\n'

using namespace std;

typedef long long int64;
typedef unsigned long long unt64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;


const int MX = 200001;
//const int64 MOD = 1000000007; 

int64 A[MX],B[MX];

struct rmq{
    int T[MX][20];
    
    void build(int N, int64* A){
        for(int i=1; i<=N; i++)
            T[i][0] = A[i];
            
        for(int j=0; j < log2(N); j++){
            N -= (1<<j);
            for(int i=1; i<=N; i++)
                T[i][j+1] = __gcd (T[i][j], T[i + (1<<j)][j]);
        }
    }
    
    int query(int a, int b){
        int l = log2(b-a+1);
        return __gcd(T[a][l], T[b - (1<<l) + 1][l]);
    }
}ds;

void solve(){
     int n;
     cin>>n;
     
     for ( int i = 1; i <= n; i++ ){
	      cin>>A[i];
	 }
	 
	 int sol = 1; 
	 
	 for ( int i = 2; i <= n; i++ ){
	     
	      B[i] = A[i] - A[i-1];
	     
	 }
	 
	 ds.build( n , B );
	 
	 for ( int i = 2; i <= n; i++ ){
	     int a = 2,b = i;
	     //cout<<i<<'\n';
	     while ( a <= b ){
			    //cout<<a<<" "<<b<<'\n';
		        if ( ds.query ( md, i ) > 1 ){
				    b = md - 1;
				}
				else a = md + 1;
		 }
		 sol = max ( sol , i - a + 2 ); 
		 //cout<<i<<" "<<a<<'\n';
	 }
	 cout<<sol<<'\n';
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	

	
    int t; cin>>t;
    while( t-- ) 
          solve(); 	
	
return 0;	
}
