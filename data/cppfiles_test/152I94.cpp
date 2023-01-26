#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e6 + 7;
const int INF = (int)1e9 + 7;
int n;
int a[N];
int b[N];
int aib[N];
void upd(int i, int x) {
  i = 2 * n + 1 - i;
  while (i < N) {
    aib[i] = max(aib[i], x);
    i += i & (-i);
  }
}
int get(int i) {
  i = 2 * n + 1 - i;
  int sol = 0;
  while (i) {
    sol = max(sol, aib[i]);
    i -= i & (-i);
  }
  return sol;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int tc = 1; tc <= tt; tc++) {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
      aib[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      b[i] = -a[i];
      a[i] += n;
      b[i] += n + 1;
      assert(1 <= a[i] && a[i] <= 2 * n);
      assert(1 <= b[i] && b[i] <= 2 * n);
    }
    vector<int> sol;
    for (int i = 1; i <= n; i++) {
      if (get(b[i]) <= 1) {
        upd(b[i], get(b[i]) + 1);
        sol.push_back(b[i]);
        continue;
      }
      if (get(a[i]) <= 1) {
        upd(a[i], get(a[i]) + 1);
        sol.push_back(a[i]);
        continue;
      }
      break;
    }
    if ((int)sol.size() != n) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (auto &it : sol) {
      if (it <= n) {
        it -= (n + 1);
      } else {
        it -= n;
      }
      cout << it << " ";
    }
    cout << "\n";
  }
  return 0;
}
