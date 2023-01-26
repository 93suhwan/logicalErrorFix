#include <bits/stdc++.h>


using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define sz(v) (long long)(v).size()
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,x,n) for(int i=(x);i<=(n);i++)
#define ff first
#define ss second
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long 

#define disp(v) for(auto i:v)cout<<i<<" ";cout<<"\n";
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<'\n';
#define show(l) for(auto it = l.begin(); it != l.end(); it++)cout<<*it<<" ";cout<<"\n";
#define dispvp(v) for(auto i:v)cout<<i.first<<" "<<i.second<<endl;
#define dispv2(v) for(int i=0; i<(int)v.size(); i++){ db1(i);for(int j:v[i]) cout<<j<<" "; cout<<endl;}
#define dispp(x) cout<<(x).first<<" "<<(x).second<<"\n";
#define logarithm2(n) floor(log2((long double)n))
#define input(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define inputvp(v, n) for(int i=0; i<n; i++) cin>>v[i].first>>v[i].second;
#define setBits(n) __builtin_popcountll(n)

void solve()
{
    int n;
    cin>>n;

    vector<pair<int,int>> v(n);

    inputvp(v, n);

    vector<int> res(n, -1);
    for(int i=0; i<n; i++)
    {
        int d = v[i].ss - v[i].ff;

        if(v[i].ff == v[i].ss)
        {
            res[i] = v[i].ff;
            continue;
        }
        for(int j=0; j<n; j++)
        {
            if(j == i)
            {

            }
            else
            {
                int nd = v[j].ss - v[j].ff;

                if(nd < d && (v[j].ff == v[i].ff))
                {
                    res[i] = max(res[i], v[j].ss + 1);
                }
                else if(nd < d && (v[j].ss == v[i].ss))
                {
                    res[i] = max(v[j].ff - 1, res[i]);
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<v[i].ff<<" "<<v[i].ss<<" "<<res[i]<<endl;
    }
    cout<<endl;
}

int32_t main()
{
    speed;
    int t = 1;
    cin>>t;

    for(int tc = 1; tc <= t; tc++)
    {
        //cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}
