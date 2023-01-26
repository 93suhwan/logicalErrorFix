
//ANKIT K NISHAD orgn
#include<bits/stdc++.h>
using namespace std;
#include<unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
//ordered_set: T-type; null_type(whether mapped or not); less<T>:lesser(smaller) elements first; use rb tree only;
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define fs first
#define sc second
#define rep(a,b,c) for(int a=b;a<c;a++)
#define pb(v,a)	v.push_back(a);
#define pll pair<ll,ll>
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair(a,b)

#define INF 1000000009
#define MAX 100005
#define pi 3.14159265358979323846
int max(int a,int b){
	return (a>b?a:b);
}
int min(int a,int b){
	return (a<b?a:b);
}



//FACTORIAL (simple)
ll fct(ll n){
	if(n<=1)return 1;
	else
	return n*fct(n-1);
}

//SOLVER
void solve(int TEST){
int n;
cin>>n;
vector<int> v(n);
rep(i,0,n)cin>>v[i];
int f=-1,idx=0;;	
rep(i,0,n){
	if(f<=v[i]){idx=i;f=v[i];}
}
auto it=max_element(v.begin()+idx+1,v.end())-v.begin();
cout<<n-it<<"\n";
}


//drive
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int tt=1;
    cin>>t;
    while(tt<=t){
    solve(tt);
    tt++;
    }
	return 0;
}
