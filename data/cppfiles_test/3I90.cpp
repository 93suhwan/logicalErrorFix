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
vector<int>X;
int solve(int x, char w) {
    int ct = 0;
    if (w == 'X') {
        trav(z, X) {
            int val = x + z;
            if (val % 25 == 0) {
                ct++;
            }
        }
    }
    else if (w == '_') {
        for (int i = 0; i <= 9; i++) {
            int val = x + i;
            if (val % 25 == 0) {
                ct++;
            }
        }
    }
    else {
        int val = x + (w - '0');
        if (val % 25 == 0) {
            ct++;
        }
    }
//    deb2(x, w);
//    deb(ct);
    return ct;
}
void test() {
    string str;
    cin >> str;
    X.clear();
    int n = str.size();
    if (str[0] == '0') {
        if (n > 1) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
        //    deb("ok0");
        return;
    }
    if (n < 2) {
        //      deb("0k1");
        if (str[0] == '_' || str[0] == 'X') {
            cout << 1 << endl;
            return;
        }
        cout << "0\n";
        return;
    }

    int ct = 0;
    int last = 0;
    if (str[n - 2] != 'X' && str[n - 1] != 'X') {
        if (str[0] == 'X') {
            for (int i = 1; i <= 9; i++) {
                X.eb(i);
            }
        }
        else {
            for (int i = 0; i <= 9; i++) {
                X.eb(i);
            }
        }

    }
    else if (str[n - 2] != 'X' && str[n - 1] == 'X') {
        if (str[0] == 'X') {
            X.eb(5);
        }
        else {
            X.eb(0);
            X.eb(5);
        }
    }
    else if (str[n - 2] == 'X' && str[n - 1] != 'X') {
        if (str[0] == 'X') {
            X.eb(2);
            X.eb(5);
            X.eb(7);
        }
        else {
            X.eb(0);
            X.eb(2);
            X.eb(5);
            X.eb(7);
        }
    }
    else if (str[n - 2] == 'X' && str[n - 1] == 'X') {
        if (str[0] == 'X') {
            cout << 0 << "\n";
            //      deb("ok3");
            return;
        }
        X.eb(0);
    }
    ll ans = 1;
    for (int i = 0; i < n - 2; i++) {
        if (str[i] == '_') {
            if (i == 0) {
                ans *= (1ll * 9);
            }
            else {
                ans *= (1ll * 10);
            }
        }
        else if (str[i] == 'X') {
            ans *= (1ll * X.size());
        }
    }
    cout << endl;
    ll ans1 = 0;
    for (int i = n - 2; i < (n - 1); i++) {
        if (str[i] != 'X' && str[i] != '_') {
            last = (str[i] - '0') * 10;
            int ans2 = solve(last, str[n - 1]);
            ans1 += ans2;
        }
        else if (str[i] == 'X') {
            trav(z, X) {
                last = 10 * z;
                //  deb(last);
                int ans2 = solve(last, str[n - 1]);
                //              deb2(last, ans2);
                ans1 += ans2;
            }
        }
        else {
            if (n == 2) {
                for (int i = 1; i <= 9; i++) {
                    last = i * 10;
                    int ans2 = solve(last, str[n - 1]);
                    //                deb2(last, ans2);
                    ans1 += ans2;
                }
            }
            else {
                for (int i = 0; i <= 9; i++) {
                    last = i * 10;
                    int ans2 = solve(last, str[n - 1]);
                    //              deb2(last, ans2);
                    ans1 += ans2;
                }
            }
        }
    }
    ans *= (ans1);
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