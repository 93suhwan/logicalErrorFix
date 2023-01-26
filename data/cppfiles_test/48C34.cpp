#include <bits/stdc++.h>
using namespace std;
vector<long long> *adj;
bool *visited;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  unordered_set<long long> s;
  bool as = 1;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    if (s.find(v[i]) != s.end()) {
      as = 0;
    } else {
      s.insert(v[i]);
    }
  }
  if (as == 0) {
    cout << "YES" << endl;
  } else {
    vector<long long> u = v;
    sort(u.begin(), u.end());
    unordered_map<long long, long long> m;
    vector<bool> b(n, 0);
    for (long long i = 0; i < n; i++) {
      m[u[i]] = i;
    }
    vector<long long> ans;
    for (long long i = 0; i < n; i++) {
      if (b[i] == 0) {
        long long j = i;
        long long c = 0;
        b[j] = 1;
        while (1) {
          j = m[v[j]];
          c++;
          b[j] = 1;
          if (j == i) {
            break;
          }
        }
        ans.push_back(c);
      }
    }
    long long tot = 0;
    for (long long i = 0; i < ans.size(); i++) {
      if (ans[i] % 2 == 0) {
        tot++;
      }
    }
    if (tot % 2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
