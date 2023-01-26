#include <bits/stdc++.h>
using namespace std;
long long C(long long n, long long k) {
  double res = 1;
  for (int i = 1; i <= k; ++i) res = res * (n - k + i) / i;
  return (long long)(res + 0.01);
}
vector<vector<long long int> > readGraph(long long n, long long m) {
  vector<vector<long long int> > g(n);
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  return g;
}
vector<vector<long long int> > readTree(int n) { return readGraph(n, n - 1); }
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  set<char> ss;
  for (long long i = 0; i < n; i++) {
    ss.insert(s[i]);
  }
  if (ss.size() == 1) {
    for (long long i = 0; i < n; i++) {
      if (i & 1)
        cout << "B";
      else
        cout << "R";
    }
    cout << "\n";
    return;
  }
  for (long long i = 0; i < n - 1; i++) {
    if (s[i] == 'R' && s[i + 1] == '?') {
      s[i + 1] = 'B';
    }
    if (s[i] == 'B' && s[i + 1] == '?') {
      s[i + 1] = 'R';
    }
  }
  for (long long i = n - 1; i > 0; i--) {
    if (s[i] == 'R' && s[i - 1] == '?') {
      s[i - 1] = 'B';
    }
    if (s[i] == 'B' && s[i - 1] == '?') {
      s[i - 1] = 'R';
    }
  }
  cout << s << "\n";
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
