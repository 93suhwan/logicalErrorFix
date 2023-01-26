#include <bits/stdc++.h>
using namespace std;
long long int mod1(long long int x) {
  return (((x % 1000000007) + 1000000007) % 1000000007);
}
long long int mul(long long int a, long long int b) {
  return mod1(mod1(a) * mod1(b));
}
void solve();
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (auto& i : a) cin >> i;
  vector<vector<long long int>> ans;
  for (long long int i = 0; i < n; i++) {
    long long int max_ind = max_element(a.begin(), a.end()) - a.begin();
    if (max_ind != n - i - 1) {
      ans.push_back({max_ind + 1, n - i, 1});
    }
    a.erase(a.begin() + max_ind);
  }
  cout << ans.size() << "\n";
  for (auto i : ans) cout << i[0] << " " << i[1] << " " << i[2] << "\n";
}
void solve1() {
  long long int n;
  cin >> n;
  vector<long long int> a(n), b(n);
  for (auto& i : a) cin >> i;
  b = a;
  sort(b.begin(), b.end());
  if (a == b) {
    cout << "0\n";
    return;
  }
  vector<long long int> d;
  vector<pair<long long int, long long int>> p;
  long long int k = 0;
  for (long long int i = 0; i < n; i++) {
    vector<long long int>::iterator it = max_element(a.begin(), a.end() - i);
    if (a[i] == b[i]) continue;
    k++;
    p.push_back({(it - a.begin() + 1), n - i});
    long long int dif = (it - a.begin()) - i;
    d.push_back(dif);
    long long int temp = (*it);
    for (long long int j = (it - a.begin()); j < (n - i - 1); j--) {
      a[j] = a[j + 1];
    }
    a[n - i] = temp;
  }
  cout << k << "\n";
  if (k) {
    for (int i = 0; i < p.size(); i++)
      cout << p[i].first << " " << p[i].second << " 1\n";
  }
}
