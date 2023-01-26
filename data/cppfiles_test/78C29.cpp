#include <bits/stdc++.h>
using namespace std;
vector<int> get_divisors(int num) {
  vector<int> divisors(1, 1);
  for (int i = 2; (i * i) <= num; ++i) {
    if ((num % i) == 0) {
      divisors.push_back(i);
      int other = num / i;
      if (other > i) {
        divisors.push_back(other);
      }
    }
  }
  if (num > 1) {
    divisors.push_back(num);
  }
  return divisors;
}
vector<int> solve(const vector<int>& a) {
  int n = a.size();
  vector<int> can(n + 1, 0);
  int tot = 0;
  for (int bi = 0; bi < 30; ++bi) {
    int cnt = 0;
    for (int x : a) {
      cnt += (x >> bi) & 1;
    }
    if (cnt == 0) continue;
    tot++;
    vector<int> divisors = get_divisors(cnt);
    for (int d : get_divisors(cnt)) {
      can[d]++;
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    if (can[i] == tot) {
      ans.push_back(i);
    }
  }
  return ans;
}
void test_case() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> ans = solve(a);
  for (int i = 0; i < int(ans.size()); ++i) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    test_case();
  }
}
