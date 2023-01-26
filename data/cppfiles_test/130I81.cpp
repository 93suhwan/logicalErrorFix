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
      vector<int> ones, zeros;
      for (int i = 3; i <= n; i += 3) {
        int x = ask(i - 2, i - 1, i);
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
      vector<int> a = {imp};
      for (int i = 1; i <= n; ++i) {
        if (i == imp || i == nimp) {
          continue;
        }
        int x = ask(imp, nimp, i);
        if (!x) a.push_back(i);
      }
      cout << "! " << a.size() << ' ';
      for (int p : a) cout << p << ' ';
      cout << endl;
      return;
    };
    _();
  }
  return 0;
}
