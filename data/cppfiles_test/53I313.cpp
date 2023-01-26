///..............*****.................///
///   Saiful Alam                      ///
///   Department of CSE                ///
///   Comilla University , Bangladesh. ///
///..............****..................///
#include<bits/stdc++.h>
#define  p5         100005
#define  p6         1000007
#define  PI         acos(-1)
#define  M          1000000007
#define  sc         scanf
#define  ss         second
#define  ff         first
#define  pf         printf
#define  scin(x)    sc("%d",&x)
#define  scin2(x,y) sc("%d%d",&x,&y)
#define  READ(f)    freopen(f, "r", stdin)
#define  WRITE(f)   freopen(f, "w", stdout)
#define  ll         long long
#define  pp         pair <ll,ll>
#define  pq         priority_queue
#define  pb         push_back
#define  mpa         make_pair
#define  yes        cout<<"YES"<<endl
#define  no         cout<<"NO"<<endl
#define all(v)      v.begin(), v.end()
#define  fix(x)     cout<<fixed<<setprecision(x)
#define unq(v)      v.erase(unique(all(v)),v.end());
#define valid(x,y) x>=0 && y>=0 && x<n && y<m
//int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
//int dx[5] = {1, -1, 0, 0 };
//int dy[5] = {0, 0, 1, -1};
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ios_base::sync_with_stdio(false);
    ll ca;
    cin>>ca;
    while(ca--){
    ll n,i,j,k;
    char ch;
    cin>>n>>ch;
    string st;
    cin>>st;
    set<ll>v;
    for(i=0;i<n;i+=2){
        if(st[i]!=ch)v.insert(2);
    }
    for(i=1;i<n;i+=2){
        if(st[i]!=ch)v.insert(n-1);
    }
    cout<<v.size()<<endl;
    for(auto it: v) cout<<it<<" ";
    cout<<endl;
}

    return 0;
}
//https://codeforces.com/blog/entry/95106?mobile=false&fbclid=IwAR1ipVXtJqmcWGOjVqC0N-Qu1DWkB1nSGdH5KiGxaSSnR3JXCKIsVKOprW0


