#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
long long pmp(long long x, long long n) {
  long long a = 1;
  while (n > 0) {
    if (n & 1) a = (a * x) % M;
    x = (x * x) % M;
    n = n >> 1;
  }
  return a;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> inv(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
    inv[a[i]] = i;
  }
  for (long long i = 0; i < n; i++) {
    if (i % 2 != a[i] % 2) {
      cout << "-1\n";
      return;
    }
  }
  vector<long long> op;
  long long nxt = n - 1;
  while (nxt) {
    long long last = inv[nxt];
    long long prev = inv[nxt - 1];
    if (last == nxt && prev == nxt - 1) {
      nxt -= 2;
      continue;
    }
    if (last > prev || last) {
      op.push_back(last + 1);
      reverse(a.begin(), a.begin() + last + 1);
      prev = last - prev;
      last = 0;
    }
    if (prev - 1) {
      op.push_back(prev);
      reverse(a.begin(), a.begin() + prev);
      last = prev - 1 - last;
    }
    if (last < prev) {
      op.push_back(prev + 2);
      reverse(a.begin(), a.begin() + prev + 2);
    }
    op.push_back(3);
    reverse(a.begin(), a.begin() + 3);
    op.push_back(nxt + 1);
    reverse(a.begin(), a.begin() + nxt + 1);
    nxt -= 2;
    for (long long i = 0; i < nxt + 1; i++) inv[a[i]] = i;
  }
  cout << op.size() << "\n";
  for (auto x : op) cout << x << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
