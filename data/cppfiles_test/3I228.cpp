#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <bits/stdc++.h>
#define ll long long
#define pb pop_back
#define eb emplace_back
#define pii pair<int,int>
#define pil pair<ll,ll>
#define mp make_pair
#define mod 1000000007
#define Max 100000000000000000
#define N 200000
#define fi first
#define se second
#define fo(i,k,n) for(int i=k;i<n;i++)
#define ifo(i,k,n) for(int i=n-1;i>=k;i--)
#define deb(x) cout<<#x<<"="<<x<<"\n";
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<"\n"
#define trav(a,x) for (auto& a : x)
#define all(x) (x).begin(), (x).end()
using namespace __gnu_pbds;
using namespace std;

typedef tree <
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update >
ordered_set;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

ll expo(ll a, ll b) {
    if (b == 0) {return 1;}
    ll z = expo(a, b / 2); z *= z; z %= mod; if (b % 2 != 0) {z *= a; z %= mod;}
    return z;
}
ll gcd(ll a, ll b) {
    if (a == 0)return b;
    return gcd(b % a, a);
}
int solve(int val, char w, int x) {
    int ct = 0;
    if (w == 'X') {
        val += x;
        if (val % 25 == 0) {
            ++ct;
        }
    }
    else if (w == '_') {
        for (int i = 0; i <= 9; i++) {
            int val1 = val + i;
            if (val1 % 25 == 0) {
                ++ct;
            }
        }
    }
    else {
        val += (w - '0');
        if (val % 25 == 0) {
            ++ct;
        }
    }
    return ct;
}
void test() {
    string str;
    cin >> str;
    int n = str.size();
    if (str[0] == '0') {
        cout << (n == 1 ? 1 : 0) << "\n";
        return;
    }
    if (n < 2) {
        if (str[0] == '0' || str[0] == 'X' || str[0] == '_') {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
        return;
    }
    int ct1 = 0;
    trav(z, str) {
        ct1 += (z == 'X' ? 1 : 0);
    }
    ll ans = 0;
    for (int x = 0; x <= 9; x++) {
        ll ans1 = 1;
        for (int i = 0; i < (n - 2); i++) {
            if (str[i] == '_') {
                if (i > 0) {
                    ans1 *= (1ll * 10);
                    ans1 %= mod;
                }
                else {
                    ans1 *= (1ll * 9);
                    ans1 %= mod;
                }
            }
        }
        ll ans2 = 0;
        int last = 0;
        if (str[n - 2] == '_') {
            if (n == 2) {
                //1 to 9
                for (int j = 1; j <= 9; j++) {
                    ans2 += solve(j * 10, str[n - 1], x);
                }
            }
            else {
                //0 to 9
                for (int j = 0; j <= 9; j++) {
                    ans2 += solve(j * 10, str[n - 1], x);
                }
            }
        }
        else if (str[n - 2] == 'X') {
            if (n == 2) {
                if (x == 0) {
                    continue;
                }
                else {
                    last = x * 10;
                    ans2 += solve(last, str[n - 1], x);
                }
            }
            else {
                last = x * 10;
                ans2 += solve(last, str[n - 1], x);

            }
        }
        else {
            last = (str[n - 2] - '0') * 10;
            ans2 += solve(last, str[n - 1], x);
        }
        ans1 *= ans2;
        ans1 %= mod;
        ans += ans1;
        ans %= mod;
    }
    if (ct1 == 0) {
        ans *= expo(1ll * 10, mod - 2);
        ans %= mod;
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        test();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}
//limiting conditions should be placed in order for recursive solutions