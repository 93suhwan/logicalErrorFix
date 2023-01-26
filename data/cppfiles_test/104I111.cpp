#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(51);
const long long N = 2e5 + 10;
long long n;
vector<long long> a(N);
vector<long long> ans;
void func(long long i) {
  if (i + 2 >= n) return;
  long long x = a[i] ^ a[i + 1] ^ a[i + 2];
  a[i] = a[i + 1] = a[i + 2] = x;
  ans.push_back(i + 1);
}
void solve() {
  cin >> n;
  ans.clear();
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] == 1) {
    long long i = 0;
    while (1) {
      if (i + 2 >= n) break;
      long long x = a[i] ^ a[i + 1] ^ a[i + 2];
      if (x == 0) {
        for (long long j = i; j >= 0; j -= 2) {
          func(j);
        }
        break;
      }
      if (a[i + 1] == 0) {
        func(i);
      }
      i += 2;
    }
  }
  if (a[0] == 1) {
    cout << "NO\n";
    return;
  }
  long long i = 0;
  while (i + 1 < n) {
    if (a[i] == 0) {
      i++;
      continue;
    }
    if (a[i + 1] == 1) {
      func(i - 1);
    } else {
      func(i);
    }
    i++;
  }
  for (long long i = 0; i < n; i++) {
    if (a[i] == 1) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  cout << ans.size() << endl;
  for (auto to : ans) cout << to << ' ';
  cout << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
