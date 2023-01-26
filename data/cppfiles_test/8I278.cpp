#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pbds tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define vl vector<ll>
#define ml map<ll,ll>
#define sl set<ll>
#define pl pair<ll,ll>
#define pql priority_queue<ll>

#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

#define F first
#define S second
#define endl "\n"
#define mod 1000000007

int main()
{
    FIO;
    ll t=1,n,i;
    string s;
    cin>>t;

    while(t--)
    {
        cin>>n;
        if(n%3==0)
        {
            cout<<n/3<<" "<<n/3<<endl;
        }
        else
        {
            ll x=(n+2)/3;
            ll y=(n-1)/3;
            cout<<x<<" "<<y<<endl;
        }

    }

    return 0;
}



