#include<iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
using namespace __gnu_pbds;
typedef  vector<int> vi;
typedef  vector<vi> vii;
typedef  vector<tuple<int,int,int>> vti3;


ULL mod1=(1e9+7);
ULL mod2=(1152921504606846976);

#define FOR(i,a,b) for(long i=a;i<b;i++)
#define pb push_back
#define ll long long
#define pob pop_back
#define fi first
#define si second
#define mdeb(x) cout << #x<<' '<< x <<"\n";
#define mdeb2(x,y) cout<< #x<<' '<<x<<' '<< #y<<' '<<y<<"\n";
#define mdeb3(x,y,z) cout<< #x<<' '<<x<<' '<< #y<<' '<<y<<' '<< #z<<' '<<z<<"\n";
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define less(x) order_of_key(x)
#define element(x) find_by_order(x)
#define mii map<int,int>
#define mp make_pair
#define msi map<string,int>
#define musi unorderd_map<string,int>
#define test_n LL N; cin>>N; while(N--)
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end() 
void printans(int f){
	if(f){cout<<"YES\n";}else{ cout<<"NO\n";}
}

 
int n;
 

int main(){
fastio;
 
//Abhishek Verma is the new king of universe and today Im gonna solve more than 3 problems under 1 hour.
//and today I will most probably become specialist on codeforces.
 
//------------------------Blazing sfast----------------------------//


test_n{
	
	cin>>n;
	vector<pair<int,int>> AA,B;
	FOR(i,0,n){int a,b; cin>>a>>b; AA.pb({a,b}); B.pb({-(b-a+1),i});}
	//sort(all(A));
	sort(all(B));

	for(int i=0;i<n;i++){
		//mdeb2("dekh,",i);
		int prev=AA[B[i].si].fi-1;
		if(AA[B[i].si].fi==AA[B[i].si].si){
			cout<<AA[B[i].si].fi<<" "<<AA[B[i].si].si<<" "<<AA[B[i].si].si<<"\n"; continue;
		}
		vector<pair<int,int>> A;
		FOR(j,i+1,n){
			//cout<<j<<"\n";
			A.pb(AA[B[j].si]);
			//mdeb3(B[j].si,AA[B[j].si].fi,AA[B[j].si].si);
		}
		sort(all(A)); bool f=0;
		FOR(j,0,A.size()){
			if(A[j].fi>AA[B[i].si].fi&&prev<A[j].fi-1){
				cout<<AA[B[i].si].fi<<" "<<AA[B[i].si].si<<" "<<min(AA[B[i].si].si,A[j].fi-1)<<"\n"; f=1;break;
			}
			prev=A[j].si;
		}
			if(!f){
				cout<<AA[B[i].si].fi<<" "<<AA[B[i].si].si<<" "<<AA[B[i].si].si<<"\n"; 
			}
	}


cout<<"\n";
}
return 0;}
