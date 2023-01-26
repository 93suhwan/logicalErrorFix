#include <bits/stdc++.h>
using namespace std;
const unsigned long long MAX = (1e5) + 10;
const unsigned long long mod = 998244353;
const unsigned long long oo = 1000000000000000002;
int ar[MAX];
int fth[MAX];
int ans[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  int Q = sqrt(n);
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    fth[ar[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    int pos = i;
    for (int j = 0; j < Q; j++) {
      pos = ar[pos];
    }
    ans[i] = pos;
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int a, b;
      cin >> a >> b;
      swap(ar[a], ar[b]);
      swap(ans[a], ans[b]);
      fth[ar[a]] = a;
      fth[ar[b]] = b;
      int pos = a;
      int pos1 = b;
      for (int j = 0; j < Q; j++) {
        pos = ar[pos];
        pos1 = ar[pos1];
      }
      ans[a] = pos;
      ans[b] = pos1;
      int p1 = a, p2 = ans[a];
      for (int i = 0; i < Q; i++) {
        ans[p1] = p2;
        p1 = fth[p1];
        p2 = fth[p2];
      }
      p1 = b, p2 = ans[b];
      for (int i = 0; i < Q; i++) {
        ans[p1] = p2;
        p1 = fth[p1];
        p2 = fth[p2];
      }
    } else {
      int a, k;
      cin >> a >> k;
      k--;
      int res = a;
      while (k >= Q) {
        k -= Q;
        res = ans[res];
      }
      for (int i = 0; i < k; i++) {
        res = ar[res];
      }
      cout << ar[res] << "\n";
    }
  }
  return 0;
}
