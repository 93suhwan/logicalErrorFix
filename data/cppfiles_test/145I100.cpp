#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int par[M];
ll timer[M], connectedTimer[M];

int FindParent(int n)
{
    if(par[n] == n)return n;
    return par[n]=FindParent(par[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k,x,y;
    int ans,i,n,px,py,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        map<ll,deque<pair<ll,int>>>col, row;
        for(i=1;i<=n;i++)
        {
            par[i]=i, connectedTimer[i]=LLONG_MAX;
            cin >> x >> y >> timer[i];
            row[x].emplace_back(y,i);
            col[y].emplace_back(x,i);
        }
        for(auto [c,dq] : col)
        {
            sort(dq.begin(),dq.end());
            while(!dq.empty())
            {
                x=dq.front().first, px=FindParent(dq.front().second), dq.pop_front();
                while(!dq.empty()  &&  dq.front().first <= x+k)
                {
                    y=dq.front().first, py=FindParent(dq.front().second), dq.pop_front();
                    if(px != py)par[py]=px, x=y;
                }
            }
        }
        for(auto [r,dq] : row)
        {
            sort(dq.begin(),dq.end());
            while(!dq.empty())
            {
                x=dq.front().first, px=FindParent(dq.front().second), dq.pop_front();
                while(!dq.empty()  &&  dq.front().first <= x+k)
                {
                    y=dq.front().first, py=FindParent(dq.front().second), dq.pop_front();
                    if(px != py)par[py]=px, x=y;
                }
            }
        }
        for(i=1;i<=n;i++)px=FindParent(i), connectedTimer[px]=min(connectedTimer[px], timer[i]);
        deque<ll>dq;
        for(i=1;i<=n;i++)
        {
            if(connectedTimer[i] < LLONG_MAX)dq.emplace_back(connectedTimer[i]);
        }
        sort(dq.begin(),dq.end());
        ans=-1;
        while(!dq.empty())
        {
            ++ans;
            while(!dq.empty()  &&  dq.front() == ans)dq.pop_front();
            if(!dq.empty())dq.pop_back();
        }
        cout << ans << '\n';
    }
    return 0;
}
