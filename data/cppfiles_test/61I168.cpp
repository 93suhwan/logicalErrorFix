        #include <iostream>
        #include <vector>
        #include <cmath>
        #include <string>
        #include <algorithm>
        #include <iomanip>
        #include <map>
        #include <set>
        #include <bitset>
        #include <fstream>
        #include <unordered_set>
        #include <unordered_map>
        #include <ext/pb_ds/assoc_container.hpp>
        #include <stack>
        #include <queue>
        #include <complex>
        #include <random>


        using namespace std;
        using namespace __gnu_pbds;



        /*#pragma GCC optimize("Ofast")
        #pragma GCC optimize("no-stack-protector")
        #pragma GCC optimize("unroll-loops")
        #pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
        #pragma GCC optimize("fast-math")*/

        /*#pragma GCC optimize("Ofast")
        #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,tune=native")
        #pragma GCC target("avx2")
        #pragma GCC optimization("O3")
        #pragma GCC optimization("unroll-loops")*/

        #define int long long
        #define ll long long
        //#define int short int
        #define eb emplace_back
        #define pb push_back
        #define ld long double
        //#define ld double
        #define mp make_pair
        #define f first
        #define s second
        #define gleg(x) return cout << x, 0
        #define pii pair <int, int>
        #define deb(a) cerr << #a << " = " << a << '\n';
        //#define sz(x) (int)s.size();
        #define fast() {     ios_base::sync_with_stdio(0);     cin.tie(0);     cout << fixed << setprecision(9);     cerr << fixed << setprecision(12); }

        template < typename firstType, typename secondType = null_type, class compare = less < firstType > >
        struct sett {
            typedef tree <
                    firstType,
                    secondType,
                    compare,
                    rb_tree_tag,
                    tree_order_statistics_node_update
            > _ ;
        };


        const int INF = 1e18 + 7;
        const ld EPS = 1e-6;
        const int MAXI = 350;
        const int MOD = 998244353;
        const int MOD1 = 1e9 + 7;
        const int MAXST = 2000000;
        const int P = 31;
        const int P1 = 37;
        const int N = 5100000;
        const ld PI = 3.14159265358979323;
        const int bp = 23;
        //const int sz = 1 << bp;


        ostream &operator<<(ostream &stream, const pair <int, int> &p) {
            stream << p.first << ' ' << p.second << ' ';
            return stream;
        }

        int C(int n, int k){
            int ans = 1;
            for (int i = n - k + 1; i <= n; i++){
                ans *= i;
            }

            for (int i = 1; i <= k; i++)
                ans /= i;
            return ans;
        }
        int cnt[1000000];
        vector<int> a[1000000];
        signed main(){
            fast();
            srand(time(0));
        //    #ifdef LOCAL
            //freopen("stacks.in", "r", stdin);
            //freopen("stacks.out", "w", stdout);
        //    #endif
            int t;
            cin >> t;
            while (t--){
                int n;
                cin >> n;
                for (int i = 0; i < n; i++){
                    int l, r;
                    cin >> l >> r;
                    a[l].eb(r);
                    cnt[r]++;
                }

                int ans = C(n, 3);
                for (int i = 0; i <= n; i++){
                    if (a[i].size() < 2)       
                        continue;
                    int k = a[i].size();

                    for (int &j: a[i]){
                        ans -= k * (k - 1) / 2 * max((cnt[j] - 1), 0ll);
                    }
                }
                cout << ans << '\n';
                for (int i = 0; i <= n; i++){
                    for (auto it : a[i])
                        cnt[it] = 0;
                    a[i].clear();
                }
            }
            return 0;
        }