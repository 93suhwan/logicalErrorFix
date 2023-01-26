#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fr(x, l, r) for(int x = l; x <= r; x++)
#define rf(x, l, r) for(int x = l; x >= r; x--)
#define fe(x, y) for(auto& x : y)

#define fi first
#define se second
#define m_p make_pair
#define pb push_back
#define pw(x) (ull(1) << ull(x))
#define all(x) (x).begin(),x.end()
#define sz(x) (int)x.size()
#define ve vector

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll,ll> pll;
typedef pair <int,int> pii;
typedef tree <ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> oset;
template<typename T>
bool umn(T& a, T b) { return a > b ? a = b, 1 : 0; }
template<typename T>
bool umx(T& a, T b) { return a < b ? a = b, 1 : 0; }

const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ld eps = 0.00000001;
const ll N = 501;


int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#else
//    freopen("tree.in","r",stdin);
//    freopen("tree.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    int q;
    cin >> q;
    while(q--){
        string s, s1;
        cin >> s >> s1;
        bool f = 0;
        fr(l, 0, sz(s) - 1){
            fr(p, 0, sz(s)){
                string st = "", ss = "";
                if (l + p > sz(s))break;
                st = s.substr(l, p);
                if (sz(st) > sz(s1))break;
                if (p + l - (sz(s1) - sz(st)) - 1 < 0)continue;

                ss = s.substr(p + l - (sz(s1) - sz(st)) - 1, (sz(s1) - sz(st)));
//                cout << "st = "<< st;
                reverse(all(ss));
//                cout << ss << endl;
                if (st + ss == s1){
                    cout << "YES" << endl;
                    f = 1;
                }
            }
//            cout << endl;

            if (f)break;
        }
        if (!f)cout << "NO" << endl;
    }

    return 0;
}
