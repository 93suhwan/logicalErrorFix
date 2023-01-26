///  In the name of ALLAH
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
#define PB push_back
#define PF push_front
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define all(a) (a).begin(),(a).end()
 
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define fix fixed<<setprecision(10)
 
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};
 
ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return a*(b/__gcd(a,b)); }
 
/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree< ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
*/
 
/**************************************************************start*********************************************************/

void Solution(void){

	int n;
	cin>>n;

	string s1,s2;
	cin>>s1>>s2;

	int cnt=0;

	for(int i=0; i<n; i++){
		if(s1[i]!=s2[i]){
			cnt+=2;
		}
		else if(s1[i]==s2[i] && s1[i]=='0'){
			cnt++;
		}
		else{
			while(s1[i]==s2[i] && s1[i]=='1' && s2[i]=='1'){
				i++;
			}
			if(i!=n){
				cnt+=2;
			}
		}
	}

	cout<<max(cnt,2)<<endl;

	return;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
	
	optimize();

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int testcase;
	cin>>testcase;

	for(int tc=1; tc<=testcase; tc++){
		Solution();
	}

	return 0;
}

/// ALHAMDULILLAH;