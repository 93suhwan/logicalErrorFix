#include <bits/stdc++.h>
using namespace std;
set<long long> nums;
pair<long long, long long> cnt(vector<long long> p) {
  long long a = 0, b = 0;
  for (long long i = 2; i < p.size(); i++) {
    if (p[i - 2] < p[i - 1] && p[i - 1] > p[i]) {
      a++;
    }
    if (p[i - 2] > p[i - 1] and p[i - 1] < p[i]) {
      b++;
    }
  }
  return {a, b};
}
void rev(vector<long long>& ans) {
  long long n = ans.size();
  for (long long i = 0; i < n; i++) {
    ans[i] = n + 1 - ans[i];
  }
}
void solve() {
  long long n, a, b;
  cin >> n >> a >> b;
  long long a0 = a, b0 = b;
  vector<long long> ans;
  for (long long i = 1; i < n + 1; i++) {
    nums.insert(i);
  }
  bool can = 1;
  long long swapd = (a > b);
  if (abs(a - b) > 1 || a + b + 2 > n) {
    can = 0;
    cout << -1 << "\n";
    return;
  }
  long long nxt = 3;
  ans.push_back(1);
  for (long long i = 1; i < n - 1; i += 2) {
    if (a > swapd) {
      ans.push_back(nxt);
      ans.push_back(nxt - 1);
      a--;
    } else {
      ans.push_back(nxt - 1);
      ans.push_back(nxt);
    }
    nxt += 2;
  }
  if (ans.size() < n) {
    ans.push_back(nxt - 1);
  }
  long long ax = cnt(ans).first, bx = cnt(ans).second;
  if (bx < b0) {
    swap(ans[n - 1], ans[n - 2]);
    rev(ans);
  }
  if (ax < a0) {
    swap(ans[n - 1], ans[n - 2]);
  }
  ax = cnt(ans).first, bx = cnt(ans).second;
  for (long long i = 0; i < n; i++) {
    nums.erase(ans[i]);
    cout << ans[i] << " ";
  }
  cout << "\n";
}
signed main() {
  long long t = 1000;
  cin >> t;
  srand(time(NULL));
  while (t--) {
    solve();
  }
}
