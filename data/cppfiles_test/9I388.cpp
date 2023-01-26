#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define loop(i,n)for(i=0;i<n;i++)
#define INF 1000000000


using ll = long long int;
typedef pair<ll,ll> pii;
typedef vector<pii> vii;

typedef vector<ll> vi;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

bool sortsec(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.second==b.second)return a.first>b.first;
    else return (a.second>b.second);
}



#define eb emplace_back
#define mp make_pair
#define pb push_back
#define MAX 1000000
#define MOD 100000000
#define endl '\n'
ll dx[4]={-1,1,0,0};
ll dy[4]={0,0,1,-1};


int main()
{
	    IOS;
	// freopen("input.txt","r",stdin);
ll r = 0; ll g = 0;
string s;cin>>s;
map<char,ll> ma;
for(ll i=0;i<s.size();i++)
{
	ma[s[i]]++;
	if(ma[s[i]]==1)r++;
	else if(ma[s[i]]==2)g++;
}

return 0;
}                                                                                                                                                                                                                                                         

 