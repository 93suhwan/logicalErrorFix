#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;

const int rt=315;

int child[M],p[M],sqrtChild[M],sqrtParent[M];

int Query(int i)
{
    for(int j=0;j<rt;j++)i=child[i];
    return i;
}

void Update(int x)
{
    int sqChildX=sqrtChild[x];
    sqrtParent[sqChildX]=x;
    for(int i=0;i<rt;i++)
    {
        x=child[x], sqChildX=child[sqChildX];
        sqrtChild[x]=sqChildX, sqrtParent[sqChildX]=x;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,n,t,q,x,y;
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> p[i], child[i]=p[i];
    for(i=1;i<=n;i++)sqrtChild[i]=Query(i), sqrtParent[sqrtChild[i]]=i;
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> x >> y;
            swap(p[x], p[y]);
            child[x]=p[x], child[y]=p[y];
            Update(sqrtParent[x]), Update(sqrtParent[y]);
            sqrtChild[x]=Query(x), sqrtChild[y]=Query(y);
        }
        else
        {
            cin >> i >> k;
            while(k >= rt)i=sqrtChild[i], k -= rt;
            while(k--)i=p[i];
            cout << i << '\n';
        }
    }
    return 0;
}