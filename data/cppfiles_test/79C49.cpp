#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
#pragma GCC target("avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long Linf = 0x7f7f7f7f7f7f7f7f;
const int Inf = 0x3f3f3f3f;
int n;
string s;
map<char, int> mp = {{'1', 1}, {'4', 1}, {'6', 1}, {'8', 1}, {'9', 1}};
int js[10];
vector<vector<int>> vec;
int is_prime(int x) {
  if (x == 1) return false;
  if (x == 2) return true;
  int top = sqrt(x);
  for (int i = 2; i <= top; i++)
    if (x % i == 0) return false;
  return true;
}
void doit() {
  cin >> n >> s;
  vec.clear();
  vec.resize(15);
  int tot = 0;
  memset(js, 0, sizeof js);
  for (auto ch : s) {
    js[ch - '0']++;
    if (mp[ch])
      return cout << 1 << '\n' << ch << '\n', void();
    else
      vec[ch - '0'].push_back(tot);
    tot++;
  }
  for (int i = 1; i <= 9; i++) {
    if (js[i] >= 2) return cout << 2 << '\n' << i * 10 + i << '\n', void();
  }
  string tp = "2357";
  do {
    for (int i = 1; i < (1 << 4); i++) {
      string num = "";
      for (int j = 0; j < 4; j++) {
        if ((i >> j) & 1) num += tp[j];
      }
      if (is_prime(stoi(num))) continue;
      int pre = -1, flag = 1;
      for (auto ch : num) {
        if (vec[ch - '0'].size() == 0) {
          flag = 0;
          break;
        }
        if (upper_bound(vec[ch - '0'].begin(), vec[ch - '0'].end(), pre) ==
            vec[ch - '0'].end()) {
          flag = 0;
          break;
        } else {
          pre = vec[ch - '0'][upper_bound(vec[ch - '0'].begin(),
                                          vec[ch - '0'].end(), pre) -
                              vec[ch - '0'].begin()];
        }
      }
      if (flag) {
        cout << num.size() << '\n' << num << '\n';
        return;
      }
    }
  } while (next_permutation(tp.begin(), tp.end()));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  cin >> _;
  while (_--) doit();
  return 0;
}
