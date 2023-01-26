#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897932384626433;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T> >;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
struct maintainer {
  int n, bad, good, empty;
  vector<vector<vector<int> > > v;
  vector<bool> is_bad, is_good, is_empty;
  maintainer(int n) {
    this->n = n;
    bad = good = 0;
    empty = n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      v[i].resize(2);
      for (int j = 0; j < 2; j++) v[i][j].resize(2);
    }
    is_bad.resize(n + 1, false);
    is_good.resize(n + 1, false);
    is_empty.resize(n + 1, true);
  }
  void add(int r, int c, int val) {
    c &= 1;
    if (is_empty[r]) {
      is_empty[r] = 0;
      empty--;
      is_good[r] = 1;
      good++;
    } else if (is_good[r]) {
      if (v[r][c][1 ^ val] > 0 || v[r][1 ^ c][val] > 0) {
        is_good[r] = 0;
        good--;
        is_bad[r] = 1;
        bad++;
      }
    }
    v[r][c][val]++;
  }
  void rem(int r, int c, int val) {
    c &= 1;
    if (v[r][0][0] + v[r][0][1] + v[r][1][0] + v[r][1][1] == 1) {
      is_good[r] = 0;
      good--;
      is_empty[r] = 1;
      empty++;
      v[r][c][val]--;
    } else if (is_bad[r]) {
      v[r][c][val]--;
      if ((v[r][0][0] == 0 || v[r][0][1] == 0) &&
          (v[r][1][0] == 0 || v[r][1][1] == 0) &&
          (v[r][0][0] == 0 || v[r][1][0] == 0) &&
          (v[r][0][1] == 0 || v[r][1][1] == 0)) {
        is_bad[r] = 0;
        bad--;
        is_good[r] = 1;
        good++;
      }
    } else
      v[r][c][val]--;
  }
  int get_empty_rows() {
    if (bad > 0) return -1;
    return empty;
  }
};
const long long N = 1e6 + 6, p = 998244353;
long long pw[N], n, m, k, x[2][2];
bool have_common() {
  if ((x[0][0] == 0 || x[0][1] == 0) && (x[1][0] == 0 || x[1][1] == 0) &&
      (x[0][0] == 0 || x[1][0] == 0) && (x[0][1] == 0 || x[1][1] == 0))
    return 1;
  return 0;
}
void func() {
  cin >> n >> m >> k;
  long long z = max(n, m);
  pw[0] = 1;
  for (long long i = 1; i < z + 1; i++) pw[i] = (pw[i - 1] * 2LL) % p;
  maintainer rows(n), columns(m);
  map<pair<long long, long long>, long long> mp;
  for (long long i = 1; i < k + 1; i++) {
    int r, c, val;
    cin >> r >> c >> val;
    map<pair<long long, long long>, long long>::iterator it =
        mp.find(make_pair(r, c));
    if (it != mp.end()) {
      long long org_val = it->second;
      if (val == -1) {
        rows.rem(r, c, org_val);
        columns.rem(c, r, org_val);
        x[(r + c) & 1][org_val]--;
        mp.erase(it);
      } else if (val != org_val) {
        rows.rem(r, c, org_val);
        columns.rem(c, r, org_val);
        x[(r + c) & 1][org_val]--;
        rows.add(r, c, val);
        columns.add(c, r, val);
        x[(r + c) & 1][val]++;
        it->second = val;
      }
    } else {
      if (val != -1) {
        rows.add(r, c, val);
        columns.add(c, r, val);
        x[(r + c) & 1][val]++;
        mp[make_pair(r, c)] = val;
      }
    }
    long long val1 = rows.get_empty_rows(), val2 = columns.get_empty_rows();
    if (val1 == -1 && val2 == -1)
      cout << "0\n";
    else if (val1 != -1 && val2 != -1) {
      if ((long long)mp.size() > 0) {
        if (have_common())
          cout << ((pw[val1] + pw[val2] - 1 + p) % p) << "\n";
        else
          cout << ((pw[val1] + pw[val2]) % p) << "\n";
      } else
        cout << ((pw[val1] + pw[val2] - 2 + p) % p) << "\n";
    } else if (val1 != -1)
      cout << pw[val1] << "\n";
    else if (val2 != -1)
      cout << pw[val2] << "\n";
  }
}
int main() {
  {
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }
  cout << fixed << setprecision(8);
  long long ntc = 1;
  for (long long i = 1; i < ntc + 1; i++) {
    func();
  }
  return 0;
}
