#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define sll set<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define endl "\n"
#define present(c,x)   ((c).find(x) != (c).end())       // set & map
#define cpresent(c,x)  (find(all(c),x) != (c).end())    // vector
using namespace __gnu_pbds;  // find_by_order(),order_of_key()
typedef tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll maxn = 2*1e5+5;
const ll MOD=1000000007;
/*******************************************************************************/
ll mod_sum() { return 0LL; }
template < typename T, typename... Args >
T mod_sum(T a, Args... args) { return ((a + mod_sum(args...))%MOD + MOD)%MOD; }
ll mod_prod() { return 1LL; }
template< typename T, typename... Args >
T mod_prod(T a, Args... args) { return (a * mod_prod(args...))%MOD; }

void printVecll(vector<ll> &a){
    for (auto i : a) cout << i << " ";
    cout << endl;
}
/*******************************************************************************/

int main()
{
    fastio; //remove for interactive
    ll t;

    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        string s[n];
        for (ll i = 0; i < n-2; i++)
        {
            cin>>s[i];
        }
        string ans;
        ll f=0;
        ans+=s[0][0];
        for (ll i = 1; i < n-2; i++)
        {
            if(s[i-1][1] == s[i][0])
                ans+=s[i][0];
            else
                ans+=s[i-1][1],
                f=1,
                ans+=s[i][0];
        }
        ans+=s[n-1][1];

        if(f)
        cout<<ans+s[n-3][1]<<endl;
        else
        ans+=char('a'),
        cout<<ans<<endl;
    }
    

    return 0;
}