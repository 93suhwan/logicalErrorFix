#include <bits/stdc++.h>
using namespace std;
const int INF = 1e6;
const int maxn = 100;
const int LOG = 20;
const unsigned long long mod = 1000000007;
bool comp(pair<string, int> x, pair<string, int> y) {
  string s1 = x.first;
  string s2 = y.first;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] != s2[i]) {
      if (i % 2 == 0) {
        return s1[i] < s2[i];
      } else
        return s1[i] > s2[i];
    }
  }
}
void solve() {
  int a, m;
  cin >> a >> m;
  vector<pair<string, int>> b(a);
  for (int i = 0; i < a; i++) {
    cin >> b[i].first;
    b[i].second = i + 1;
  }
  sort(b.begin(), b.end(), comp);
  for (int i = 0; i < a; i++) cout << b[i].second << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
    cout << '\n';
  }
}
