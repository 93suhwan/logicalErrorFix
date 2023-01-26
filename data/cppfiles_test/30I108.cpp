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

#define FI(idx, start, end) for (int idx{(start)}; idx <= (end); ++idx)
#define FD(idx, start, end) for (int idx{(start)}; idx >= (end); --idx)

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
    string s;
    cin >> n >> s;

    auto check = [&](string s, char c) -> int
    {
        int left{0}, right{n - 1}, cnt{0};
        vector<bool> correct(n, true);
        while (left < right)
        {
            if (s[left] != s[right] && s[left] == c)
            {
                cnt++, correct[left] = 0;
            }
            else if (s[left] != s[right] && s[right] == c)
            {
                cnt++, correct[right] = 0;
            }
            left++, right--;
        }

        left = 0, right = n - 1;
        while (left < right)
        {
            if (correct[left] == 0)
            {
                left++;
                continue;
            }
            if (correct[right] == 0)
            {
                right--;
                continue;
            }

            if (s[left] != s[right])
            {
                return -1;
            }
            left++, right--;
        }
        return cnt;
    };

    int answer{-1};
    FI(i, 0, 25)
    {
        int cur{check(s, i + 'a')};
        if (answer == -1)
        {
            answer = cur;
        }
        else if (cur != -1)
        {
            answer = min(answer, cur);
        }
    }
    cout << answer << "\n";
    return;
}

int main()
{
    IOS;

    // setI("");
    // setO("");

    int number_of_test_cases{1};
    cin >> number_of_test_cases;

    // cout << fixed << setprecision(12);

    for (int test_case_number{1}; test_case_number <= number_of_test_cases; ++test_case_number)
    {
        // cout << "Case : #" << test_case_number << "\n";
        solve_test_case();
    }

    return 0;
}