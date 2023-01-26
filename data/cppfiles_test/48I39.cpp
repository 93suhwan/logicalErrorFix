#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int N = 2e5 + 5;
int BIT[N];
void add(int idx, int val) {
  while (idx < N) {
    BIT[idx] += val;
    idx += (idx & (-idx));
  }
}
int query(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += BIT[idx];
    idx -= (idx & (-idx));
  }
  return sum;
}
int inversion_count(vector<long long> arr) {
  int icount = 0;
  int n = arr.size();
  for (long long i = 0; i < n; i++) {
    add(arr[i], 1);
    int a = query(arr[i]);
    icount += (i + 1 - a);
  }
  return icount;
}
void cycle(vector<long long> &v, long long i, long long j, long long k) {
  long long x = v[j], y = v[k];
  v[j] = v[i];
  v[k] = x;
  v[i] = y;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    bool ans = false;
    if (n == 1)
      ans = true;
    else if (n == 2 && v[0] <= v[1])
      ans = true;
    else if (n == 3) {
      long long x = min(v[0], min(v[1], v[2]));
      long long z = max(v[0], max(v[1], v[2]));
      long long y = v[0] + v[1] + v[2] - x - z;
      if (v[0] == x && v[1] == y && v[2] == z) ans = true;
      if (v[0] != x && v[1] != y && v[2] != z) ans = true;
    } else if (n > 3) {
      long long l = -1, r = -1;
      long long mn = 1e18, mx = 0;
      for (long long i = 0; i < n; i++) {
        if (v[i] < mn) {
          mn = v[i];
          l = i;
        }
      }
      if (l != 0) {
        if (l == 1)
          cycle(v, 0, 2, l);
        else
          cycle(v, 0, 1, l);
      }
      for (long long i = 0; i < n; i++) {
        if (v[i] > mx) {
          mx = v[i];
          r = i;
        }
      }
      if (r != n - 1) {
        if (r == n - 2)
          cycle(v, n - 1, n - 3, r);
        else
          cycle(v, n - 1, n - 2, r);
      }
      vector<long long> w;
      for (long long i = 1; i <= n - 2; i++) w.push_back(v[i]);
      long long inv = inversion_count(w);
      if (inv % 2 == 0) ans = true;
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
  return 0;
}
