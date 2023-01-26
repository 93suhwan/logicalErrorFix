#include <bits/stdc++.h>
using namespace std;
int ttt = 1;
long long n, m, k;
template <class myType>
void print_arr(myType &arr, long long L, string sep) {
  for (long long(i) = (0); (i) < (L); ++(i)) {
    cout << arr[i] << (i < L - 1 ? " " : "\n");
  }
  return;
}
int query_(int i, int j, int k) {
  cout << "? " << i << " " << j << " " << k << endl;
  int x;
  cin >> x;
  return x;
}
void solve() {
  cin >> n;
  vector<int> idx(2, -1);
  vector<int> typ(n + 1, -1), ans(n + 1, -1);
  for (int i = 1; i <= n; i += 3) {
    int x = query_(i, i + 1, i + 2);
    if (idx[x] == -1) idx[x] = i;
    typ[i] = typ[i + 1] = typ[i + 2] = x;
  }
  int x1 = query_(idx[0] + 1, idx[0] + 2, idx[1]);
  int x2 = query_(idx[0] + 2, idx[1], idx[1] + 1);
  int one, zero;
  if (x1 == 1) {
    zero = idx[0];
    one = idx[1];
  } else if (x2 == 1) {
    zero = idx[0] + 1;
    one = idx[1] + 1;
  } else {
    zero = idx[0] + 2;
    one = idx[1] + 2;
  }
  ans[zero] = 0;
  ans[one] = 1;
  for (int i = 1; i <= n; i += 3) {
    if (i <= one && one <= i + 2) {
      for (int k = i; k <= i + 2; k++) {
        if (k == one) continue;
        int x = query_(zero, one, k);
        ans[k] = x;
      }
    } else if (i <= zero && zero <= i + 2) {
      for (int k = i; k <= i + 2; k++) {
        if (k == zero) continue;
        int x = query_(zero, one, k);
        ans[k] = x;
      }
    } else if (typ[i] == 1) {
      int x;
      x = query_(i, i + 1, zero);
      if (x == 1) {
        ans[i] = ans[i + 1] = 1;
        x = query_(i + 2, one, zero);
        ans[i + 2] = x;
      } else {
        ans[i + 2] = 1;
        x = query_(i, one, zero);
        ans[i] = x;
        ans[i + 1] = 1 - x;
      }
    } else {
      int x;
      x = query_(i, i + 1, one);
      if (x == 0) {
        ans[i] = ans[i + 1] = 0;
        x = query_(i + 2, one, zero);
        ans[i + 2] = x;
      } else {
        ans[i + 2] = 0;
        x = query_(i, one, zero);
        ans[i] = x;
        ans[i + 1] = 1 - x;
      }
    }
  }
  int tot = 0;
  for (long long(i) = (1); (i) < (n + 1); ++(i))
    if (ans[i] == 0) tot++;
  cout << "! " << tot;
  for (long long(i) = (1); (i) < (n + 1); ++(i)) {
    if (ans[i] == 0) cout << " " << i;
  }
  cout << endl;
  return;
}
int main() {
  cin >> ttt;
  while (ttt--) solve();
  return 0;
}
