#include <bits/stdc++.h>
using namespace std;
vector<int> w;
int check(int i, int j, int k) {
  int res;
  cout << "? " << i << ' ' << j << ' ' << k << endl;
  cout.flush();
  cin >> res;
  return res;
}
pair<int, int> scheme1(int i0, int j0, int k0, int i1) {
  w[i1] = 3;
  w[k0] = 2;
  if (check(i0, k0, i1) == 1) {
    w[i0] = 3;
    w[j0] = 2;
    return make_pair(j0, i0);
  } else {
    w[i0] = 2;
    w[j0] = 3;
    return make_pair(i0, j0);
  }
}
pair<int, int> find1(int i0, int j0, int k0, int i1, int j1, int k1) {
  if (check(i0, j0, i1) == 1) {
    return scheme1(i0, j0, k0, i1);
  } else if (check(i0, j0, j1) == 1) {
    w[i1] = 2;
    return scheme1(i0, j0, k0, j1);
  } else {
    w[i0] = 2;
    w[j0] = 2;
    if (check(i0, i1, j1) == 1) {
      w[i1] = 3;
      w[j1] = 3;
      return make_pair(i0, i1);
    } else {
      w[k1] = 3;
      return make_pair(i0, k1);
    }
  }
}
void solve(int n) {
  int k, i, res, first0 = -1, first1 = -1;
  w.assign(n + 1, -1);
  for (i = 1; i <= n; i += 3) {
    res = check(i, i + 1, i + 2);
    if (res == -1) return;
    w[i] = w[i + 1] = w[i + 2] = res;
    if (first0 < 0 && res == 0) first0 = i;
    if (first1 < 0 && res == 1) first1 = i;
    if (first0 > 0 && first1 > 0) break;
  }
  pair<int, int> r =
      find1(first0, first0 + 1, first0 + 2, first1, first1 + 1, first1 + 2);
  k = 0;
  for (i = 1; i <= n; ++i) {
    if ((w[i] >= 0) && (w[i] < 2) && (i % 3 == 0)) {
      if (w[i] == 0 && w[i - 1] + w[i - 2] > 4) w[i] = 2;
      if (w[i] == 1 && w[i - 1] + w[i - 2] < 6) w[i] = 3;
    }
    if (w[i] < 2) w[i] = 2 + check(r.first, r.second, i);
    k += 3 - w[i];
  }
  cout << "! " << k;
  for (i = 1; i <= n; ++i)
    if (w[i] == 2) cout << ' ' << i;
  cout << endl;
  cout.flush();
}
int main() {
  int t = 1, n;
  cin >> t;
  while (t--) {
    cin >> n;
    solve(n);
  }
  return 0;
}
