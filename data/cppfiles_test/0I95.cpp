#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define mod 1000000007
#define int long long
#define endl "\n"
ll power(int n,int k){
    if(k==0)return 1;
    ll ans;
    ans=power(n,k/2);
    ans=((ans%mod)*(ans%mod))%mod;
    if(k%2==0)return ans;
    return ((ans%mod)*(n%mod))%mod;
}
int binary_search(vector<int> &v,int target){
        int low=0,high=v.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(v[mid]==target){return mid;}
            if(v[mid]>target){high=mid-1;}
            else{low=mid+1;}
        }
        return -1;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pair<string,int>> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first;
        v[i].second = i+1;
    }

    sort(v.begin(),v.end());

    ///for(int i=0;i<n;i++)
       /// cout<<v[i].first<<" "<<v[i].second<<"\n";
    int idx = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i].first == v[n-1-i].first)
        {
            idx = i;
            break;
        }
    }
    vector<int> a,b;
    for(int i=0;i<=idx;i++)
    {
        a.push_back(v[i].second);
    }
    sort(a.begin(),a.end(),greater<int>());
    for(int i=idx+1;i<n;i++)
    {
        b.push_back(v[i].second);
    }
    sort(b.begin(),b.end());

    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    for(int i=0;i<b.size();i++)
        cout<<b[i]<< " ";
}
int_fast32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
   /// freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
#endif

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
