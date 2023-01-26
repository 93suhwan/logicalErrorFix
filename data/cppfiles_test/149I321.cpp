// Jai Bajrang Bali

// #pragma GCC optimize("O1")
// #pragma GCC optimize("O2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;;
//````````````````````````````````````````````````````````````````````````````````````````````````````````````
#define db1(x)                cout<<#x<<": "<<x<<"\n"
#define db2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<"\n"
#define db3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<"\n"
#define db4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<"\n"
#define db5(a, b, c, d, e)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<"\n"

//````````````````````````````````````````````````````````````````````````````````````````````````````````````
#define ll long long
#define int long long
#define ld long double
#define ull unsigned long long
#define  mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define setbits(x)      __builtin_popcountll(x)
#define l_zeros(x)      __builtin_clzll(x)
#define t_zeros(x)      __builtin_ctzll(x)
#define fbo(a) find_by_order(a) //will give a-th largest element
#define ook(a) order_of_key(a) //will give no. of elements strictly lesser than a
#define str string
#define fo(i,a,n) for(int i=a;i<n;i++)
#define eb emplace_back
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define sz(x) ((int)(x).size())

//````````````````````````````````````````````````````````````````````````````````````````````````````````````
typedef vector<string> vstr;
typedef vector<long long> vll;
typedef map<long long, vll> mlv;
typedef pair<long long, long long> pll;
typedef vector<pll> vpll;
typedef map<pll, long long>mpll;
typedef map<long long, long long> mll;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
// typedef map < int , tree < int , null_type , less < int > , rb_tree_tag , tree_order_statistics_node_update  > > ordered_map;

//````````````````````````````````````````````````````````````````````````````````````````````````````````````
#define all(a)     a.begin(),a.end()
#define allr(a)    a.rbegin(),a.rend()
#define mem(a,x)   memset(a,x,sizeof(a))
#define sp(x,y)    fixed<<setprecision(y)<<x
#define bhaag_basanti ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//````````````````````````````````````````````````````````````````````````````````````````````````````````````
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int M = 998244353;
const long long inf = 1e18 + 1;

//````````````````````````````````````````````````````````````````````````````````````````````````````````````
void mistakes() {

    // tc to iterate over all multiples of a number is O(log n) not O(sqrt(n)) <- this is for factors
    // directed mai if (x==par) use maat krna. :)
    // mod ke baad sort krne jesa kaam kch maat kro
    // whenever u play with leaf nodes,makes sure to handle ->(n==1) and (root is leaf) cases
    // TREE mai tle dega ki nai isse chk kro (1->2)(1->3)(1->4)..(1->n) wala tree
    // (x^y) isko hamesha bracket mai band rkhna ya koi v bitwise ops ho.
    // if you think your approach is correct (but still wa), generate random tc using generator,and verify youself
    // this will make sure that your implementation is correct or not
    // whenever you are solving a problem of graph, always consider the cases for non-connecetd graph,cycles and related stuff.
}

void purple() {

    // If you have an approach in your mind but there is an issue with that approach,try to get rid of that issue.
    // eg-> kch part m add krna tha and kch m sub, but dono sath m implement ni kr skta tha hence seperate kr dia.

    int n, k, x;
    cin >> n >> k >> x;
    str s;
    cin >> s;
    if (x == 1) {
        str ans;
        fo(i, 0, n)if (s[i] != '*')ans += s[i];
        cout << ans << nl; return;
    }
    vll vals;
    str s1;
    fo(i, 0, n) {
        if (s[i] == '*') {
            s1.pb('*');
            int cnt = 0;
            while (i < n && s[i] == '*') {
                cnt++;
                i++;
            }
            i--;
            vals.pb(cnt * k);
        } else
            s1.pb(s[i]);
    }
    str ans;
    n = sz(s1);
    int nn = sz(vals);
    int suff[nn + 1] = {0};
    suff[nn] = 0;
    int req = x - 1;
    for (int i = nn - 1; i >= 0; i--) {
        suff[i] = vals[i];
        if (i != nn - 1) {
            if (inf / suff[i] > suff[i + 1]) {
                fo(j, 0, i + 1) {
                    suff[i] = inf;
                }
                break;
            }
            suff[i] = suff[i] * suff[i + 1] + vals[i];
        }
    }
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] != '*') {
            ans += s1[i]; continue;
        }
        int taken = 0, t = 1;
        // db1(req);
        while (taken < vals[idx] && req >= suff[idx + 1] + t) {
            ans += 'b';
            taken++;
            req -= (suff[idx + 1] + t);
        }
        idx++;
    }
    cout << ans << nl;
}
int32_t main()
{
    bhaag_basanti
    int t = 1;
    cin >> t;
    // cin.ignore(); must be there when using getline(cin, s)
    while (t--) {
        purple();
    }
}