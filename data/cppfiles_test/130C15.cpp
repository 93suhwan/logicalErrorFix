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
  for (i = 1; i <= n; i += 3) {
    if (w[i] == -1) {
      w[i] = 2 + check(i, r.first, r.second);
      w[i + 1] = 2 + check(i + 1, r.first, r.second);
      w[i + 2] = 2 + check(i + 2, r.first, r.second);
      continue;
    }
    if (w[i] + w[i + 1] + w[i + 2] == 0) {
      if (check(r.second, i, i + 1) == 0) {
        w[i] = 2;
        w[i + 1] = 2;
        w[i + 2] = 2 + check(i + 2, r.first, r.second);
      } else {
        w[i] = 2 + check(i, r.first, r.second);
        w[i + 1] = 5 - w[i];
        w[i + 2] = 2;
      }
      continue;
    }
    if ((w[i] * w[i + 1] * w[i + 2]) == 1) {
      if (check(r.first, i, i + 1) == 1) {
        w[i] = 3;
        w[i + 1] = 3;
        w[i + 2] = 2 + check(i + 2, r.first, r.second);
      } else {
        w[i] = 2 + check(i, r.first, r.second);
        w[i + 1] = 5 - w[i];
        w[i + 2] = 3;
      }
      continue;
    }
    w[i] = w[i] > 1 ? w[i] : (2 + check(i, r.first, r.second));
    w[i + 1] = w[i + 1] > 1 ? w[i + 1] : (2 + check(i + 1, r.first, r.second));
    w[i + 2] = w[i + 2] > 1 ? w[i + 2] : (2 + check(i + 2, r.first, r.second));
  }
  k = 0;
  for (i = 1; i <= n; ++i) k = k + (w[i] == 2 ? 1 : 0);
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
