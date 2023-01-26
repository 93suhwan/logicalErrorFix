/*
    Author : UntilOver
    Topic: 
    Prerequisite:
    Algorithm:
    TimeComplexity:
*/




#include "bits/stdc++.h"
using namespace std;
 
#define ll long long 
#define ull unsigned long long
#define debug(x)       { cerr << #x << " = " << x << endl; } 
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 
const int Max = (int)2e5+5;
 
//functions
ll lcm(ll a,ll b) {if(a==0 || b==0){return 0;}else{return (a*b)/__gcd(a,b);}}
int bigmod(int a,int b,int m) {if(b==0) { return 1; } int x = bigmod(a,b/2,m); x = (x*x)%m; if(b%2==1) {x = (x*a)%m;} return x; }
 
//direction arry
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
 
//____________________________________________________________________________________________________
 
 
void solve(){
    int n; cin>>n;
    vector<string> v(n-2);
    
    for(int i=0;i<n-2;i++){
    	cin>>v[i];
    }
    if(n==3){
    	string ans = v[0];
    	char x = v[0][1];
    	ans+=x;
    	cout<<ans<<endl;
    	return;
    }
    string s = "";
    for(int i=0;i<n-3;i++){
    	char x = v[i][1];
    	char y = v[i+1][0];
    	// cout<<x<<" "<<y<<endl;
    	if(x!=y){
    		s+=x;
    		s+=y;
    	}else{
    		s+=x;
    	}
    }
    s+=v[n-3][1];
    s = v[0][0]+s;
    cout<<s<<endl;
}
 
int main(){
    fastread;
    int tc=1;
    cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}