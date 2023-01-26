#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e+16;
const int SMALL_INF = 1998244353;
const long long NSIZE = 2 * 1e+5 + 1000;
const long long MOD = 998244353;
const long double EPS = 1e-12;
const int MAX = 1e+6 + 1000;
const long double PI = atan(1) * 4;
const long long HZ = 692281337;
const long long UNUSED = SMALL_INF;
int __pow(int a, int n) {
  if (n == 0)
    return 1;
  else if (n == 1) {
    return a % MOD;
  } else if (n % 2 == 0) {
    long long prepow = __pow(a, n / 2);
    return (long long)prepow * prepow % MOD;
  } else if (n % 2 == 1) {
    return (long long)__pow(a, n - 1) * a % MOD;
  }
}
int getBit(int a, int i) { return (a >> i) & 1; }
int fromItoP(int i) {
  if (i == 0) return 1;
  return (1 << (i - 1)) + 1;
}
void brute_force(int level_now, int acc, int k,
                 unordered_map<int, vector<int> > &usa, vector<int> &collect,
                 int a, unordered_set<int> &check_key) {
  if (level_now == k) {
    usa[acc] = collect;
    check_key.insert(acc);
    return;
  }
  for (int i = 0; i <= (1 << level_now); i++) {
    brute_force(level_now + 1, acc, k, usa, collect, a, check_key);
    acc = ((long long)MOD + acc + __pow(a, fromItoP(level_now)) -
           __pow(a, fromItoP(k))) %
          MOD;
    collect.push_back(level_now);
  }
  for (int i = 0; i <= (1 << level_now); i++) collect.pop_back();
}
void arrange(int k, int inst, int posnow, int v, vector<int> &pos,
             int level_now) {
  if (level_now == k - 1) {
    pos[v + 1 - (1 << (k - 1))] = posnow;
  } else {
    if (!getBit(inst, v)) {
      arrange(k, inst, posnow, v * 2 + 1, pos, level_now + 1);
      arrange(k, inst, level_now + 1, v * 2 + 2, pos, level_now + 1);
    } else {
      arrange(k, inst, level_now + 1, v * 2 + 1, pos, level_now + 1);
      arrange(k, inst, posnow, v * 2 + 2, pos, level_now + 1);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int k, a, h;
  cin >> k >> a >> h;
  unordered_map<int, vector<int> > usa;
  unordered_set<int> check_key;
  vector<int> collect;
  brute_force(0, 0, k, usa, collect, a, check_key);
  for (int i = 0; i < 1 << ((1 << (k - 1)) - 1); i++) {
    vector<int> poses(1 << (k - 1));
    arrange(k, i, 0, 0, poses, 0);
    int acc = 0;
    vector<int> ans(1 << k + 1);
    for (int j = 0; j < 1 << (k - 1); j++) {
      acc = ((long long)acc +
             (long long)__pow(a, fromItoP(poses[j])) * (j * 2 + 1) +
             (long long)__pow(a, fromItoP(k)) * (j * 2 + 2)) %
            MOD;
      ans[j * 2 + 1] = fromItoP(poses[j]);
      ans[j * 2 + 2] = fromItoP(k);
    }
    int modneed = (MOD + (h - acc)) % MOD;
    if (check_key.find(modneed) != check_key.end()) {
      multiset<int> change;
      for (auto j : usa[modneed]) {
        change.insert(fromItoP(j));
      }
      for (int j = 1; j <= 1 << k; j += 2) {
        if (change.empty()) break;
        if (change.find(ans[j]) != change.end()) {
          swap(ans[j], ans[j + 1]);
          change.erase(ans[j]);
        }
      }
      for (int j = 1; j <= 1 << k; j++) cout << ans[j] << " ";
      return 0;
    }
  }
  cout << -1;
}
