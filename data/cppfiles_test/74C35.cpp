#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e3 + 7, mod = 1e9 + 7, MAXN = 1e6 + 7;
const double eps = 1e-9;
const long long INF = 1e18, inf = 1e15;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long n;
long long a[maxn];
void build_eq(long long id) {
  cout << "YES\n";
  cout << "0 " << a[id] << " ";
  for (long long i = 0; i < n; ++i) {
    if (i == id - 1 || i == id) continue;
    cout << a[i] - a[id] << " ";
  }
  cout << '\n';
  exit(0);
}
void build_even(long long cnt) {
  cout << "YES\n";
  sort(a, a + n, [&](long long p1, long long p2) { return p1 % 2 < p2 % 2; });
  if (cnt < 3) {
    reverse(a + 3, a + n);
  }
  long long b1 = a[0];
  long long b2 = a[1];
  long long b3 = a[2];
  a[0] = (b1 + b3 - b2) / 2;
  a[1] = (b1 + b2 - b3) / 2;
  a[2] = (b2 + b3 - b1) / 2;
  for (long long i = 0; i < 3; ++i) {
    cout << a[i] << " ";
  }
  for (long long i = 3; i < n; ++i) {
    cout << a[i] - a[0] << " ";
  }
  cout << '\n';
  exit(0);
}
long long L;
long long sums[MAXN * 14];
void build_eq_sum(long long mask1, long long mask2) {
  cout << "YES\n";
  vector<long long> xx;
  for (long long i = 0; i < L; ++i) {
    if (!((mask1 >> i) & 1) && !((mask2 >> i) & 1)) xx.push_back(a[i]);
  }
  long long common = mask1 & mask2;
  mask1 ^= common;
  mask2 ^= common;
  for (long long i = L; i < n; ++i) {
    xx.push_back(a[i]);
  }
  for (long long i = 0; i < L; ++i) {
    if ((common >> i) & 1) {
      xx.push_back(a[i]);
    }
  }
  vector<long long> left228, right228;
  for (long long i = 0; i < L; ++i) {
    if ((mask1 >> i) & 1) {
      left228.push_back(a[i]);
    }
    if ((mask2 >> i) & 1) {
      right228.push_back(a[i]);
    }
  }
  cout << 0 << " ";
  long long lst = 0;
  vector<long long> nw;
  for (long long i = 0; i < (long long)left228.size(); ++i) {
    nw.push_back(left228[i]);
    nw.push_back(right228[i]);
  }
  nw.pop_back();
  for (long long i = 0; i < (long long)nw.size(); ++i) {
    cout << nw[i] - lst << " ";
    lst = nw[i] - lst;
  }
  for (auto x : xx) {
    cout << x << " ";
  }
  cout << '\n';
  exit(0);
}
void solve() {
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (long long i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) {
      build_eq(i);
    }
  }
  if (n == 2) {
    cout << "NO\n";
    return;
  }
  long long even = 0;
  for (long long i = 0; i < n; ++i) {
    even += (a[i] % 2 == 0);
  }
  if (n == 3 && even % 2 == 0) {
    cout << "NO\n";
    return;
  }
  if (even) {
    build_even(even);
  }
  L = min(27ll, n);
  for (long long mask = 0; mask < (1 << L); ++mask) {
    if (__builtin_popcount(mask) != L / 2) {
      continue;
    }
    long long sum = 0;
    for (long long bt = 0; bt < L; ++bt) {
      if ((mask >> bt) & 1) {
        sum += a[bt];
      }
    }
    if (sums[sum] != 0) {
      build_eq_sum(sums[sum], mask);
    }
    sums[sum] = mask;
  }
  cout << "NO\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  for (long long i = 0; i < t; ++i) {
    solve();
  }
}
