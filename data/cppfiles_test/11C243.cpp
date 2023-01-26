#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long score(string s, char k) {
  long long ret = 0;
  for (auto it : s)
    if (it == k)
      ++ret;
    else
      --ret;
  return ret;
}
void solve() {
  long long n;
  cin >> n;
  vector<string> s;
  for (long long i = 0; i < (long long)n; ++i) {
    string tp;
    cin >> tp;
    s.push_back(tp);
  }
  long long ans = 0;
  sort(s.begin(), s.end(),
       [](string a, string b) { return score(a, 'a') > score(b, 'a'); });
  long long here = 0, choose = 0;
  for (auto it : s) {
    here += score(it, 'a');
    if (here > 0) {
      ++choose;
    }
  }
  ans = max(ans, choose);
  sort(s.begin(), s.end(),
       [](string a, string b) { return score(a, 'b') > score(b, 'b'); });
  here = 0, choose = 0;
  for (auto it : s) {
    here += score(it, 'b');
    if (here > 0) {
      ++choose;
    }
  }
  ans = max(ans, choose);
  sort(s.begin(), s.end(),
       [](string a, string b) { return score(a, 'c') > score(b, 'c'); });
  here = 0, choose = 0;
  for (auto it : s) {
    here += score(it, 'c');
    if (here > 0) {
      ++choose;
    }
  }
  ans = max(ans, choose);
  sort(s.begin(), s.end(),
       [](string a, string b) { return score(a, 'd') > score(b, 'd'); });
  here = 0, choose = 0;
  for (auto it : s) {
    here += score(it, 'd');
    if (here > 0) {
      ++choose;
    }
  }
  ans = max(ans, choose);
  sort(s.begin(), s.end(),
       [](string a, string b) { return score(a, 'e') > score(b, 'e'); });
  here = 0, choose = 0;
  for (auto it : s) {
    here += score(it, 'e');
    if (here > 0) {
      ++choose;
    }
  }
  ans = max(ans, choose);
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(0));
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
