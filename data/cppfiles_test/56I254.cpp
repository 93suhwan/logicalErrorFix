//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pii pair<int, int>
#define pb push_back
#define ll int
#define S second
#define ull unsigned long long
#define F first
#define ld long double
//#define int ll
#define sqr(x) (x)*(x)
#define all(x) (x).begin(),(x).end()

using namespace std;
using namespace __gnu_pbds;


template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 gen(chrono::high_resolution_clock().now().time_since_epoch().count());


const int MOD = 998244353;
#ifdef LOCAL
const int inf = 1e3 + 7;
const int N = (1 << 10);
#else
const int inf = 1e6 + 7;
const int N = (1 << 21);
#endif // LOCAL
int x = 0, y = 0;
bool f = 0;

bool f2 = 0;
bool f3 = 0;
int cnt = 0;
int go(int dx, int dy) {
    x+=dx;
    y+=dy;
    if(x == 8){
        cout << " " <<  cnt <<"\n";
        exit(0);
    }
    cout << 1 + x << " "<< y + 1 << "\n";
    cout.flush();
    string s;
    cin >> s;
    if(s == "Done") {
        f = 1;
        exit(0);
        return 1;
    }
    if(s == "Right" || s == "Down-Right" || s == "Up-Right") {
        f2 = 1;
    cnt++;
    }
    if(s == "Left" || s == "Down-Left" || s == "Up-Left") {
        cnt--;
        f3 = 1;
    }

    return 0;
}
main() {

//#ifdef LOCAL
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//#else
////    freopen("trie.in","r",stdin);
////    freopen("trie.out","w",stdout);
//#endif LOCAL

//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    ll t;
    cin >> t;
    while(t--) {
        f2=  0;
        f = 0;
        x = 1;
        y = 0;
        int ok = 0;
        ok =go(0, 0);
        while(!f && !ok) {
            if(x == 8) break;
            f2 = 0;
            f3 = 0;
            if(y > 0) {
                go(0, -y);
            }
            if(f) continue;
            for(int j = 0; j < 7; j++){
                if(f3) break;
                if(f2) break;
                if(f) break;
                go(0, 1);
            }
            if(f) continue;
            if(f3) continue;
            if(f2){
                go(1,0);
                continue;
            }
            if(f) continue;
//            if(x != 6)
            go(1, 0);
        }
    }

//    cout << ans <<"\n";
    return 0;
}
