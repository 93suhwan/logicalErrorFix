#include <bits/stdc++.h>

using namespace std;

void setI(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
}

void setO(string name)
{
    freopen((name + ".out").c_str(), "w", stdout);
}

#define IOS ios::sync_with_stdio(false), cin.tie(NULL)

#define ff first
#define ss second
#define ef emplace_front
#define eb emplace_back
#define pf pop_front
#define pb pop_back
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define FI(idx, start, end) for (ll idx{(start)}; idx <= (end); ++idx)
#define FD(idx, start, end) for (ll idx{(start)}; idx >= (end); --idx)

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const ld PIE = asin(1) * 2;
const ll MAX = 100'000 + 1;
const ll MOD = 1'000'000'007;
// const ll MOD = 998'244'353;

void solve_test_case()
{
    int n;
    cin >> n;

    vector<int> a(n);
    FI(i, 0, n - 1)
    {
        cin >> a[i];
    }
    sort(all(a));

    ll p{0}, sum{0};
    FI(i, 0, n - 2)
    {
        if (a[i + 1] - a[i] >= a[i])
        {
            p++, sum += (a[i] - sum);
        }
        else
        {
            break;
        }
    }
    cout << a[p] - sum << "\n";
    return;
}

int main()
{
    IOS;

    // setI("");
    // setO("");

    int number_of_test_cases{1};
    cin >> number_of_test_cases;

    // cout.fixed, cout.precision(12); // Precision
    // cout.flush(); // Interactive

    for (int test_case_number{1}; test_case_number <= number_of_test_cases; ++test_case_number)
    {
        // cout << "Case : #" << test_case_number << "\n";
        solve_test_case();
    }

    return 0;
}