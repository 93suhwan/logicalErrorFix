#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define fast() ios_base::sync_with_stdio(false),cin.tie(NULL);

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

void solve()
{
    ll n,x,m,i,j,k,mx=-1e18,mn=1e18,a,b,sum =0 ,f=0;
    vector<ll>v;
    ordered_set mp;
    set<int>st;
    cin>> n>>m;
    for(i = 0 ;i<m ;i++)
    {
        cin >>x;
        if(st.find(x)==st.end())
            mp.insert(x);
        st.insert(x);
        sum += mp.order_of_key(x);
    }
    cout<<sum<<endl;

}
int main()
{
	fast();
	int t;
 	cin >> t;
	while(t--)
	solve();
}

