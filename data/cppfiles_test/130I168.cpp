#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    auto _ = [&]() {
      int n;
      cin >> n;
      auto ask = [](int a, int b, int c) {
        cout << "? " << a << ' ' << b << ' ' << c << endl;
        int x;
        cin >> x;
        return x;
      };
      vector<int> ones, zeros, ans(n + 1, -1);
      for (int i = 3; i <= n; i += 3) {
        int x = ask(i - 2, i - 1, i);
        ans[i] = x;
        if (x)
          ones.push_back(i);
        else
          zeros.push_back(i);
      }
      int o = ones[0];
      int z = zeros[0];
      int tot = 0;
      tot += ask(z - 2, z - 1, o);
      tot += ask(z - 2, z - 1, o - 1);
      tot += ask(z - 2, z - 1, o - 2);
      int imp = !tot ? z - 2 : z;
      tot = 0;
      tot += ask(o - 2, o - 1, z);
      tot += ask(o - 2, o - 1, z - 1);
      tot += ask(o - 2, o - 1, z - 2);
      int nimp = tot == 3 ? o - 2 : o;
      vector<int> a(n + 1, -1);
      a[imp] = 0;
      a[nimp] = 1;
      for (int i = 3; i <= n; i += 3) {
        if (!ans[i]) {
          if (i - 2 == nimp) {
            a[i] = a[i - 1] = 0;
          } else if (i == nimp) {
            a[i - 2] = a[i - 1] = 0;
          } else {
            int x = ask(nimp, i - 2, i - 1);
            if (!x) {
              a[i - 2] = a[i - 1] = 0;
              a[i] = ask(nimp, i - 1, i);
            } else {
              a[i] = 0;
              a[i - 1] = ask(nimp, i - 1, i);
              a[i - 2] = a[i - 1] ^ 1;
            }
          }
          continue;
        }
        if (i - 2 == imp) {
          a[i] = a[i - 1] = 1;
          continue;
        }
        if (i == imp) {
          a[i - 2] = a[i - 1] = 1;
          continue;
        }
        int x = ask(imp, i - 2, i - 1);
        if (!x) {
          a[i] = 1;
          a[i - 1] = ask(imp, i, i - 1);
          a[i - 2] = a[i - 1] ^ 1;
        } else {
          a[i - 2] = a[i - 1] = 1;
          a[i] = ask(imp, i, i - 1);
        }
      }
      vector<int> id;
      for (int i = 1; i <= n; ++i) {
        if (!ans[i]) id.push_back(i);
      }
      cout << "! " << id.size() << ' ';
      for (int p : id) cout << p << ' ';
      cout << endl;
      return;
    };
    _();
  }
  return 0;
}
