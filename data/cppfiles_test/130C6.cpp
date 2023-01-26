#include <bits/stdc++.h>
using namespace std;
int hmt() {
  int x = 0;
  int c = getchar(), n = 0;
  for (; !isdigit(c); c = getchar()) n = (c == '-');
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  if (n) x = -x;
  return x;
}
const int N = 10010;
int ans[N];
struct oo {
  int a, b, c, i;
};
int II, OO;
int get(int i, int j, int k) {
  cout << '?' << " " << i << " " << j << " " << k << "\n";
  int x;
  cin >> x;
  return x;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<oo> e;
    for (int i = 1; i <= n; i += 3) {
      int j = get(i, i + 1, i + 2);
      e.push_back({i, i + 1, i + 2, j});
    }
    int I, O;
    for (int i = 0, _b = e.size() - 1; i <= _b; ++i) {
      if (e[i].i == 1)
        I = i;
      else
        O = i;
    }
    if (get(e[I].a, e[I].b, e[O].a) == 0) {
      OO = e[O].a;
      if (get(e[I].a, e[I].c, e[O].a) == 1)
        II = e[I].a;
      else
        II = e[I].b;
    } else if (get(e[I].a, e[I].b, e[O].b) == 0) {
      OO = e[O].b;
      if (get(e[I].a, e[I].c, e[O].b) == 1)
        II = e[I].a;
      else
        II = e[I].b;
    } else {
      II = e[I].a;
      if (get(e[O].a, e[O].b, e[I].a) == 0) OO = e[O].a;
      if (get(e[O].a, e[O].c, e[I].a) == 0) OO = e[O].a;
      if (get(e[O].b, e[O].c, e[I].a) == 0) OO = e[O].b;
    }
    for (int i = 0, _b = e.size() - 1; i <= _b; ++i) {
      if (e[i].i) {
        if (get(e[i].a, e[i].b, OO) == 1) {
          ans[e[i].a] = ans[e[i].b] = 1;
          if (get(e[i].a, e[i].c, OO) == 1) {
            ans[e[i].c] = 1;
          } else
            ans[e[i].c] = 0;
        } else {
          if (get(e[i].a, e[i].c, OO) == 1) {
            ans[e[i].a] = ans[e[i].c] = 1;
            ans[e[i].b] = 0;
          } else {
            ans[e[i].a] = 0;
            ans[e[i].b] = ans[e[i].c] = 1;
          }
        }
      } else {
        if (get(e[i].a, e[i].b, II) == 0) {
          ans[e[i].a] = ans[e[i].b] = 0;
          if (get(e[i].a, e[i].c, II) == 0) {
            ans[e[i].c] = 0;
          } else
            ans[e[i].c] = 1;
        } else {
          if (get(e[i].a, e[i].c, II) == 0) {
            ans[e[i].a] = ans[e[i].c] = 0;
            ans[e[i].b] = 1;
          } else {
            ans[e[i].a] = 1;
            ans[e[i].b] = ans[e[i].c] = 0;
          }
        }
      }
    }
    vector<int> kq;
    for (int i = 1, _b = n; i <= _b; ++i)
      if (ans[i] == 0) kq.push_back(i);
    cout << '!' << " " << kq.size() << " ";
    for (auto &x : kq) cout << x << " ";
    cout << "\n";
  }
}
