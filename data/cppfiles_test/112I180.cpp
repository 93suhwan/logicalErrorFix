// 20:34:08 Sep 20, 2021
#pragma region
#define MOD 1000000007LL
// #define MOD 998244353LL
#define Interactive false // Interactive?
const int N6 = 1000005, N5 = 100005, N3 = 1005;

#pragma region
#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
#define pb push_back
typedef long long int ll;
typedef long double ld;
#define INF 1e18
#define sp fixed << setprecision(15)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define int long long int
#define ff first
#define ss second
#ifndef Interactive
#define Interactive true
#endif
#ifdef mishra
#define debug(x) cerr << " >> " << #x << ": " << x << " ";
#define debugend() cerr << endl;
#define print_time() cerr << endl                                                            \
                          << endl                                                            \
                          << "time: " << 1000 * (clock() / (double)CLOCKS_PER_SEC) << " ms " \
                          << ctime(&currTime)                                                \
                          << endl                                                            \
                          << endl;
#else
#if (Interactive == false)
#define endl "\n"
#endif
#define debug(x) ;
#define debugend() ;
#define print_time() ;
#endif
bool testcases = false;
int file = 1;
void solve();
void set_operations();
void ioe();

signed main(short argc, char *argv[]) // on my IDE argc is always = 2
{
    set_operations();
    auto currTime = time(NULL);
    if (Interactive == false) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    file = ((argc == 2) ? min(stoll(argv[1]), file) : 0);

    do {
        if (file) {
            ioe();
            cerr << "   >>>   >>>   File : " << file - 1
                 << "   <<<   <<<" << endl;
        }

        int testcase = 1;
        if (testcases)
            cin >> testcase;
        for (int tt = 0; tt < testcase; tt++) {
            // cout << "Case #" << tt + 1 << ": ";
            solve();
        }
    } while (--file > 0);

    print_time();
    return 0;
}
#pragma endregion

string ny[2] = {"NO", "YES"};
vector<pair<int, int>> coord = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, -1}, {-1, -1}, {1, 1}, {-1, 1}, {0, 0}};
inline void ioe()
{
    const char *files[] = {"std.txt", "std1.txt", "std2.txt"};
    if (Interactive == false)
        assert(freopen(files[file - 1], "r", stdin));
    // freopen(files[2], "w", stdout);
}
#pragma endregion

//---------------------CODE STARTS HERE---------------------
const int maxn = N5;
void set_operations()
{
    // file = 3;
    // sieve();

    testcases = true;
}

void solve()
{
    int a[3], m;
    int x = 1;
    cin >> a[0] >> a[1] >> a[2] >> m;
    if (m > 0)
        x--;
    sort(a, a + 3);
    int d = min(m, a[2] - 1);
    a[2] -= (d + 1);
    m -= d;
    int d1 = max(0LL, min(a[1] - a[0] - 1, m));
    a[1] -= (d1 + 1);
    m -= d;
    if (m > (a[0] - 1 + a[1])) {
        cout << ny[0] << endl;
        return;
    }
    sort(a, a + 3);
    if ((x + a[0] + a[1]) < a[2]) {
        cout << ny[0] << endl;
        return;
    }
    cout << ny[1] << endl;

    //--------??--------CLEAR VECTORS--------??--------
}
