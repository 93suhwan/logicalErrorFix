#include <bits/stdc++.h>
using namespace std;
void solution();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int tests = 1;
  while (tests--) solution();
}
void solution() {
  long long int a, b, c, d, e, f, i, j;
  vector<long long int> v, ve;
  cin >> a;
  c = 0;
  set<long long int> second;
  set<long long int> se2;
  second.insert(0);
  se2.insert(0);
  for (i = 0; i < a; i++) {
    cin >> b;
    v.push_back(b);
    c += b;
    second.insert(b);
  }
  for (i = 0; i < a; i++) se2.insert(c - v[i]);
  cin >> a;
  for (i = 0; i < a; i++) {
    long long int ans = LLONG_MAX;
    long long int ans2 = LLONG_MAX;
    cin >> b >> d;
    auto k = second.lower_bound(b);
    if (k != second.end()) ans = max(0ll, d - (c - *k));
    k--;
    ans = min(ans, max(0ll, b - *k) + max(0ll, d - (c - *k)));
    k = se2.lower_bound(d);
    if (k != se2.end()) ans2 = max(0ll, b - (c - *k));
    k--;
    ans2 = min(ans2, max(0ll, c - *k) + max(0ll, b - (c - *k)));
    cout << min(ans, ans2) << "\n";
  }
}
