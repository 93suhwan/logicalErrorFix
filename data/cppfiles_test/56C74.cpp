#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int nax = 6000;
int add(int a, int b) {
  a += b;
  while (a >= mod) a -= mod;
  return a;
}
void add_self(int& a, int b) { a = add(a, b); }
int mul(int a, int b) {
  int ans = ((int64_t)a * b) % mod;
  return ans;
}
int sub(int a, int b) {
  a -= b;
  while (a < 0) a += mod;
  return a;
}
void sub_self(int& a, int b) { a = sub(a, b); }
void mul_self(int& a, int b) { a = mul(a, b); }
int binexpo(int a, int64_t b) {
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = mul(ans, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
int modinv(int a) { return binexpo(a, mod - 2); }
int fact[nax];
int ifact[nax];
void initfact() {
  fact[0] = 1;
  for (int i = 1; i < nax; ++i) {
    fact[i] = mul(fact[i - 1], i);
  }
  ifact[nax - 2] = modinv(fact[nax - 2]);
  for (int i = nax - 2; i; --i) {
    ifact[i - 1] = mul(ifact[i], i);
  }
  assert(ifact[37] == modinv(fact[37]));
}
int64_t p2[62];
int main() {
  map<string, int> positions;
  positions["white"] = 0;
  positions["yellow"] = 1;
  positions["green"] = 2;
  positions["blue"] = 3;
  positions["red"] = 4;
  positions["orange"] = 5;
  p2[0] = 1;
  for (int i = 1; i < 62; ++i) {
    p2[i] = p2[i - 1] * 2;
  }
  int k, n;
  cin >> k >> n;
  int64_t mxelem = (1LL << k) - 1;
  auto get_level = [&](int64_t num) {
    int ans = 0;
    while (num >= 1) {
      num >>= 1;
      ans++;
    }
    return ans;
  };
  auto get_to_bottom = [&](int level) {
    int levels_below = k - level + 1;
    return binexpo(4, p2[levels_below] - 2);
  };
  set<int64_t> seen;
  vector<int64_t> og(n);
  set<pair<int64_t, int>, greater<pair<int64_t, int>>> special;
  map<int64_t, array<int, 6>> special_poss;
  for (int i = 0; i < n; ++i) {
    int64_t v;
    string s;
    cin >> v >> s;
    og[i] = v;
    special.insert({v, positions[s]});
    seen.insert(v);
  }
  for (auto a : og) {
    a >>= 1;
    while (seen.count(a) == 0 && a >= 1) {
      seen.insert(a);
      special.insert({a, -1});
      a >>= 1;
    }
  }
  for (auto a : special) {
    if ((a.first << 1) > mxelem) {
      special_poss[a.first][a.second] = 1;
    } else {
      array<int, 6> left_child, right_child;
      if (seen.count(a.first << 1)) {
        left_child = special_poss[a.first << 1];
      } else {
        auto x = get_to_bottom(get_level(a.first << 1));
        for (int& i : left_child) i = x;
      }
      if (seen.count((a.first << 1) + 1)) {
        right_child = special_poss[(a.first << 1) + 1];
      } else {
        auto x = get_to_bottom(get_level((a.first << 1) + 1));
        for (int& i : right_child) i = x;
      }
      array<int, 6> new_one;
      for (int& i : new_one) i = 0;
      for (int i = 0; i < 6; ++i) {
        if (a.second != i && a.second != -1) {
          continue;
        }
        for (int j = 0; j < 6; ++j) {
          if (i == j || i == (j ^ 1)) {
            continue;
          }
          for (int k = 0; k < 6; ++k) {
            if (i == k || i == (k ^ 1)) {
              continue;
            }
            add_self(new_one[i], mul(left_child[j], right_child[k]));
          }
        }
      }
      special_poss[a.first] = new_one;
    }
  }
  int ans = 0;
  for (int i : special_poss[1]) {
    add_self(ans, i);
  }
  cout << ans << "\n";
}
