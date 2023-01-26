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
#define  yes        pf("YES\n")
#define  no         pf("NO\n")
#define all(v)      v.begin(), v.end()
#define unq(v)      v.erase(unique(all(v)),v.end());
#define valid(x,y) x>=0 && y>=0 && x<n && y<m
//int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
//int dx[5] = {1, -1, 0, 0 };
//int dy[5] = {0, 0, 1, -1};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    ll ca;
    cin>>ca;
    while(ca--){
    ll n,i,j,k;
    string st;
    cin>>st;
    n=st.size();
    n--;
    map<char,ll>m;
    ll ans=0;
    for(i=0;i<n;i=i+2){
        if(m[st[i]]==0){
            ans++;
            m[st[i]]++;
        }
    }
    cout<<ans<<endl;
}

    return 0;
}


