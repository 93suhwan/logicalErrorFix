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
  if (abs(a - b) > 1 || a + b + 2 > n) {
    cout << "-1\n";
    return;
  }
  set<long long> nums;
  for (long long i = 0; i < n; i++) {
    nums.insert(i + 1);
  }
  vector<long long> ans;
  long long mn = 1, mx = n;
  ans.push_back(mn++);
  bool sw = 0;
  if (a < b) {
    swap(a, b);
    sw = 1;
  }
  while (ans.size() < n) {
    if (b > 0) {
      ans.push_back(mx--);
      b--;
    }
    if (a > 0) {
      ans.push_back(mn++);
      a--;
    } else {
      ans.push_back(mx--);
    }
  }
  if (sw) {
    rev(ans);
  }
  auto tt = cnt(ans);
  for (long long i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}
signed main() {
  long long t = 1;
  cin >> t;
  srand(time(NULL));
  while (t--) {
    solve();
  }
}
