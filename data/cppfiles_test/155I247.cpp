#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 9;
const long long INF = 1000000000;
void solve() {
  long long n;
  string s;
  cin >> n;
  vector<long long> a(n);
  map<long long, long long> m;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]] = i;
  }
  cin >> s;
  vector<long long> ones;
  for (long long i = n - 1; i >= 0; i--) {
    if (s[i] == '1') {
      ones.push_back(a[i]);
    }
  }
  sort(ones.begin(), ones.end());
  long long p = n;
  for (long long i = ones.size() - 1; i >= 0; i--) {
    long long tmp = a[m[ones[i]]];
    a[m[ones[i]]] = a[m[p]];
    a[m[p]] = tmp;
    --p;
  }
  for (long long i = 0; i < n; i++) cout << a[i] << ' ';
  cout << endl;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
