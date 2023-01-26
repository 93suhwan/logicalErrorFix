#include <bits/stdc++.h>
using namespace std;
int k, A, h, bas[30];
vector<int> fix(vector<int> v, int win) {
  for (int i = 1; i < v.size(); i++) {
    v[i] = v[i] * 2 - 1;
    if (!win && v[i] == 1) v[i] = 2;
  }
  return v;
}
int gethash(vector<int> v, int win = false, int right = false) {
  if (k == 5) {
    v = fix(v, win);
  }
  int ans = 0;
  for (int i = 1; i < v.size(); i++) {
    ans =
        (ans + 1ll * (right ? i + 16 : i) * bas[v[i]] % 998244353) % 998244353;
  }
  return ans;
}
vector<int> eval(int n, int mask) {
  vector<int> v;
  for (int i = 1; i <= n; i++) v.push_back(i);
  vector<int> rnk;
  rnk.assign(n + 1, 0);
  int cur = n / 2 + 1;
  vector<int> tmp;
  for (int i = 0; i < n - 1; i++) {
    int a = v.front();
    v.erase(v.begin());
    int b = v.front();
    v.erase(v.begin());
    if (mask & (1 << i)) {
      tmp.push_back(a);
      rnk[b] = cur;
    } else {
      tmp.push_back(b);
      rnk[a] = cur;
    }
    if (!v.size()) {
      v = tmp;
      tmp.clear();
      cur = cur / 2 + 1;
    }
  }
  rnk[v[0]] = 1;
  return rnk;
}
int main() {
  bas[0] = 1;
  cin >> k >> A >> h;
  for (int i = 1; i < 30; i++) bas[i] = 1ll * bas[i - 1] * A % 998244353;
  if (k != 5) {
    int n = (1 << k);
    for (int i = 0; i < (1 << (n - 1)); i++) {
      auto res = eval(n, i);
      if (gethash(res) == h) {
        for (auto x : res) {
          if (x) cout << x << " ";
        }
        cout << endl;
        return 0;
      }
    }
  } else {
    int half = (1 << (k - 1));
    for (int _ = 0; _ <= 1; _++) {
      map<int, vector<int>> mp;
      for (int i = 0; i < (1 << (half - 1)); i++) {
        auto res = eval(half, i);
        mp[gethash(res, _)] = res;
      }
      for (int i = 0; i < (1 << (half - 1)); i++) {
        auto res = eval(half, i);
        int tmp = (h - gethash(res, !_, 1) + 998244353) % 998244353;
        if (mp.count(tmp)) {
          for (auto x : fix(mp[tmp], _)) {
            if (x) cout << x << " ";
          }
          for (auto x : fix(res, !_)) {
            if (x) cout << x << " ";
          }
          cout << endl;
          return 0;
        }
      }
    }
  }
  puts("-1");
  return 0;
}
