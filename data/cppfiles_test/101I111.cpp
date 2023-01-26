#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long N = 1e6 + 1;
bool check(long long n, long long m) {
  long long ans = (n * (n + 1)) / 2;
  if (m - ans > 0) return 1;
  return 0;
}
void solve() {
  long long q;
  cin >> q;
  long long count = 0;
  while (q--) {
    count++;
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    string s;
    cin >> s;
    map<long long, long long> mr, mb;
    vector<long long> b, r;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'B') {
        mb[v[i]]++;
        b.push_back(v[i]);
      } else {
        mr[v[i]]++;
        r.push_back(v[i]);
      }
    }
    sort(b.begin(), b.end());
    ;
    sort(r.begin(), r.end());
    ;
    long long mnr, mxr;
    long long mnb, mxb;
    if (b.size() != 0) {
      mnb = b[0];
      mxb = b[b.size() - 1];
    } else {
      mnb = 1;
      mxb = 0;
    }
    if (r.size() != 0) {
      mnr = r[0];
      mxr = r[r.size() - 1];
    } else {
      mnr = n + 1;
      mxr = n;
    }
    if (mnb < 1 || mxr > n) {
      cout << "NO" << endl;
      goto l;
    }
    for (auto it : mr) {
      if (n - it.first + 1 < it.second) {
        cout << "NO" << endl;
        goto l;
      }
    }
    for (auto it : mb) {
      if (it.first < it.second) {
        cout << "NO" << endl;
        goto l;
      }
    }
    if (mnr - mxb > 1) {
      cout << "NO" << endl;
      goto l;
    }
    cout << "YES" << endl;
  l:;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
