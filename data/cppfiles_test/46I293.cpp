#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> v(n, 0);
  for (long long &i : v) {
    cin >> i;
  }
  stack<pair<long long, long long>> s;
  s.push({0, 0});
  long long depth = 0;
  long long total = 0;
  for (int i = 0; i + 1 < n; i += 2) {
    long long a = v[i];
    long long b = v[i + 1];
    long long new_depth = depth + a - b;
    total += min(b, depth + a);
    while (!s.empty() && new_depth < s.top().first) {
      total += s.top().second;
      s.pop();
    }
    if (!s.empty() && s.top().first == new_depth) {
      total += s.top().second;
      s.top().second++;
    } else {
      s.push({new_depth, 1});
    }
    depth = new_depth;
    if (depth < 0) {
      depth = 0;
    }
  }
  cout << total << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
