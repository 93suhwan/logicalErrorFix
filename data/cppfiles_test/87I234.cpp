#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; --i)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; --i)
#define trav(a, x) for (auto &a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1'000'000'007;
const char nl = '\n';
const int MX = 100001;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max_num = arr[0], max_idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= max_num)
        {
            max_num = arr[i];
            max_idx = i;
        }
    }
    if (max_num > 0)
        cout << max_num - max_idx - 1 << endl;
    else
    {
        cout << "0" << endl;
    }
}

void input()
{
}

void output()
{
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int TC = 1;
    cin >> TC;
    while (TC--)
    {
        input();
        solve();
        output();
    }

    return 0;
}