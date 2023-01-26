#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
#include <chrono>

#define int long long
#define ld long double
#define db double
#define endl "\n"
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

using namespace __gnu_pbds; 
using namespace std;
using namespace chrono;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void deb_out() { 
    cout << endl; 
}
template <typename Head, typename... Tail>
void deb_out(Head H, Tail... T) {
    cout << " " << H;
    deb_out(T...);
}
#ifdef LOCAL
    #define deb(...) cout << "[" << #__VA_ARGS__ << "]:", deb_out(__VA_ARGS__);
#else
    #define deb(...) ;
#endif

const long double PI = 3.14159265358979323846264338;
const long long INF = 1000000000000000000;
const long long INF1 = 1000000000;
// const long long MOD = 1000000007;
const long long MOD = 998244353;

inline int cl(int a, int b){
    if(a % b)
        return 1 + a / b;
    return a / b;
}
        
int mpow(int a, int b){
    a %= MOD;
    if(!b)
        return 1;
    int temp = mpow(a, b / 2);
    temp = (temp * temp) % MOD;
    if(b % 2)
        return (a * temp) % MOD;
    return temp;
}
int _pow(int a, int b){
    if(!b)
        return 1;
    int temp = _pow(a, b / 2);
    temp = (temp * temp);
    if(b % 2)
        return (a * temp);
    return temp;
}
inline int mod_in(int n){
    return mpow(n, MOD - 2);
}

void remove(int x, int y, int row[][2], int col[][2], int val, int r[], int c[], int poss[]) {
    int ux = y % 2, uy = x % 2;
    int vx = 1 - ux, vy = 1 - uy;   
    if (val == 1) {
        row[x][ux]--;
        col[y][uy]--;
        if (row[x][1] == 0 && row[x][0] == 0) {
            r[2]++;
            r[1]--;
        }
        if (row[x][ux] == 0 && row[x][vx]) {
            r[1]++;
            r[0]--;
        }
        if (col[y][1] == 0 && col[y][0] == 0) {
            c[2]++;
            c[1]--;
        }
        if (col[y][uy] == 0 && col[y][vy]) {
            c[1]++;
            c[0]--;
        }
        int parity = (ux + uy) % 2;
        if (parity == 0) {
            poss[0]--;
        } else {
            poss[1]--;
        }
    } else {
        row[x][vx]--;
        col[y][vy]--;
        if (row[x][1] == 0 && row[x][0] == 0) {
            r[2]++;
            r[1]--;
        }
        if (row[x][vx] == 0 && row[x][ux]) {
            r[1]++;
            r[0]--;
        }
        if (col[y][1] == 0 && col[y][0] == 0) {
            c[2]++;
            c[1]--;
        }
        if (col[y][vy] == 0 && col[y][uy]) {
            c[1]++;
            c[0]--;
        }
        int parity = (ux + uy) % 2;
        if (parity == 1) {
            poss[0]--;
        } else {
            poss[1]--;
        }
    }
}

// 1 # #
// # # #
// # # #


// 1 #
// # #

// 1 1
// # #

// 1 1
// 1 #

// 0 1
// 1 #

// 0 #
// 1 #

const int N = 1e6 + 6;
int row[N][2], col[N][2];   


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Tests = 1;
    // cin >> Tests;
    while (Tests--) {
        int n, m, k;
        cin >> n >> m >> k;
        map<pair<int, int>, int> M;
        int r[3], c[3];
        r[0] = 0;
        c[0] = 0;
        r[2] = n;
        r[1] = 0;
        c[2] = m;
        c[1] = 0;
        int fix = 0;
        int poss[2] = {0};
        while (k--) {
            int x, y, t;
            cin >> x >> y >> t;
            x--;
            y--;
            int ux = y % 2, uy = x % 2;
            int vx = 1 - ux, vy = 1 - uy;
            int parity = (ux + uy) % 2;
            deb(r[1], r[2], c[1], c[2])
            if (t == 1) {
                if (M.find({x, y}) != M.end() && M[{x, y}] != -1) {
                    remove(x, y, row, col, M[{x, y}], r, c, poss);
                    fix--;
                }
                M[{x, y}] = 1;
                fix++;
                row[x][ux]++;
                col[y][uy]++;
                if (row[x][ux] == 1 && row[x][vx]) {
                    r[0]++;
                    r[1]--;
                }
                if (row[x][ux] == 1 && row[x][vx] == 0) {
                    r[2]--;
                    r[1]++;
                }
                if (col[y][uy] == 1 && col[y][vy]) {
                    c[0]++;
                    c[1]--;
                }
                if (col[y][uy] == 1 && col[y][vy] == 0) {
                    c[2]--;
                    c[1]++;
                }
                if (parity == 0) {
                    poss[0]++;
                } else {
                    poss[1]++;
                }
                deb(x, ux, vx, row[x][0], row[x][1])
            } else if (t == 0) {
                if (M.find({x, y}) != M.end() && M[{x, y}] != -1) {
                    remove(x, y, row, col, M[{x, y}], r, c, poss);
                    fix--;
                }
                M[{x, y}] = 0;
                fix++;
                row[x][vx]++;
                col[y][vy]++;
                if (row[x][vx] == 1 && row[x][ux]) {
                    r[0]++;
                    r[1]--;
                }
                if (row[x][vx] == 1 && row[x][ux] == 0) {
                    r[2]--;
                    r[1]++;
                }
                if (col[y][vy] == 1 && col[y][uy]) {
                    c[0]++;
                    c[1]--;
                }
                if (col[y][vy] == 1 && col[y][uy] == 0) {
                    c[2]--;
                    c[1]++;
                }
                if (parity == 1) {
                    poss[0]++;
                } else {
                    poss[1]++;
                }
            } else {
                remove(x, y, row, col, M[{x, y}], r, c, poss);
                M[{x, y}] = -1;
            }
            assert(r[0] + r[1] + r[2] == n);
            assert(c[0] + c[1] + c[2] == m);
            deb(r[0], r[1], r[2], c[0], c[1], c[2])
            int ans1 = mpow(2, r[2]) * ((r[1] + r[2] == n));
            int ans2 = mpow(2, c[2]) * ((c[1] + c[2] == m));
            deb(ans1, ans2, poss[0], poss[1])
            cout << (ans1 + ans2 - (poss[0] == 0) - (poss[1] == 0) + MOD) % MOD << endl;

        }
    }
}
