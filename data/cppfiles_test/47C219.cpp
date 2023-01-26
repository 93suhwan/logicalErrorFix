#include <bits/stdc++.h>
using namespace std;
void invector(vector<long long> p) {
  cout << " in p : ";
  for (auto x : p) {
    cout << x << " ";
  }
  cout << "\n";
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<long long> trai;
vector<long long> ds[2];
long long ans;
long long k;
long long maxn;
void xuli(vector<long long> &a) {
  if (a.size() == 0) return;
  sort(a.begin(), a.end());
  maxn = max(maxn, a[a.size() - 1]);
  for (long long i = a.size() - 1; i >= 0; i = i - k) {
    long long sum = 0;
    for (long long j = i; j > i - k && j >= 0; j--) {
      sum = max(sum, a[j]);
    }
    ans += sum * 2;
  }
}
void solve() {
  ans = 0;
  maxn = 0;
  long long n;
  cin >> n >> k;
  ds[0].clear();
  ds[1].clear();
  for (long long i = 0; i < n; i++) {
    long long td;
    cin >> td;
    if (td == 0) continue;
    if (td < 0) {
      ds[0].push_back(abs(td));
    } else {
      ds[1].push_back(abs(td));
    }
  }
  xuli(ds[0]);
  xuli(ds[1]);
  cout << ans - maxn << "\n";
}
signed main() {
  srand(time(NULL));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
