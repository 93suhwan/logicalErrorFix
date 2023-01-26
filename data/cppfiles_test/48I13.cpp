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
    long long inv = inversion_count(v);
    if (inv % 2 == 0)
      ans = true;
    else {
      sort((v).begin(), (v).end());
      for (long long i = 0; i < n - 1; i++)
        if (v[i] == v[i + 1]) ans = true;
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
  return 0;
}
