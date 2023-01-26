#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<long long , null_type,less<long long >, rb_tree_tag,tree_order_statistics_node_update>
/*find_by_order()  order_of_key(k)*/
#define ll long long
#define ull unsigned long long
#define ld long double
#define PI acos(-1)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define tc() int test; cin >> test; while (test--)
#define mod 1000000007
#define  sq(n) sqrt(n);
#define fix()  cout <<fixed<<setprecision(9)
#define MAX_NODES 1000006
#define ceil(x,y)                        (x+y-1)/y   //int number
#define round1(x,y)                        (x+y/1)/y   //int number if x >0
#define round2(x,y)                        (x-y/1)/y   //int number if x <0
#define maxall(v)                      *max_element(all(v))
#define minall(v)                      *min_element(all(v))
#define UB(a,x)                        (upper_bound(all(a),x)-a.begin())
#define LB(a,x)                        (lower_bound(all(a),x)-a.begin())
#define NP(a)                          next_permutation(all(a))
#define sz(v)				((int)((v).size()))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define MP					make_pair
using namespace std;
const ll OO = 1e9;
void H_O()
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
}
void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
}
ll n,e;
const int dx[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
const ll MAX = 100;
bool valid(ll i, ll j)
{
    return (i>=0&&j>=0&&i<n&&j<n);
}
char maze[MAX][MAX];
bool vis[MAX][MAX];
vector< vector<ll> > adj;
vector<bool>visited;


int main()
{
    H_O();

    file();
    vector<ll>v;
    ll k=1e6;

    ll sum=0;
    for(int i=0; i<1e6; i++)
    {

        v.push_back((sum^i));
        sum+=i;

    }
    tc()
    {
        cin>>n>>e;
        n--;
        ll kk=v[n];
        ll ans=v[n+2];
        ll ans1=kk^e;

        if(kk==e)
        {
            cout <<n+1<<"\n";
        }
        else  if(e==ans||(n+1)!=ans1)
        {
               cout <<n+2<<"\n";

        }
        else
        {
                cout <<n+3<<"\n";

        }




    }





}
