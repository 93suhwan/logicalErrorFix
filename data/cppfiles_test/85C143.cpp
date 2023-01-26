#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using vp = vector<pll>;
using qp = queue<pll>;
using pqll = priority_queue<ll>;
using pqp = priority_queue<pll>;
inline void init_setting() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int t;
string s;
int main() {
  init_setting();
  cin >> t;
  while (t--) {
    cin >> s;
    ll n = s.size();
    ll check = s[0] == '0';
    for (int i = 1; i <= n - 1; i++)
      if (s[i] == '0' && s[i - 1] != s[i]) check++;
    if (check < 2)
      cout << check;
    else
      cout << 2;
    cout << '\n';
  }
}
