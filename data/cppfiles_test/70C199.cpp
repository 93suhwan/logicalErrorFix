#include <bits/stdc++.h>
using namespace std;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
string all;
int check(int l, int r, vector<vector<int>> &left, vector<vector<int>> &right,
          vector<int> &init, int mm) {
  vector<int> vec;
  for (int i = l; i <= r; i++) {
    int flag = 0;
    int count = 0, cc = 0;
    char x;
    for (int j = 0; j < 26; j++) {
      if ((left[i][j] - init[j]) == 0) {
        if (right[i + 1][j] > 0) {
          flag = 1;
          break;
        }
      } else if (right[i + 1][j] % (left[i][j] - init[j]) == 0) {
        vec.push_back(right[i + 1][j] / (left[i][j] - init[j]));
        if (right[i + 1][j] == 0) x = 'a' + j;
      } else {
        flag = 1;
        break;
      }
    }
    sort(vec.begin(), vec.end());
    if (vec.size() == mm) {
      for (int j = 0; j < mm; j++) {
        if (vec[j] != j) {
          flag = 1;
          break;
        }
      }
    } else {
      flag = 1;
    }
    if (flag == 0) {
      for (int j = 0; j < 26; j++) {
        init[j] = left[i][j];
      }
      all += x;
      if (check(i + 1, r, left, right, init, mm - 1))
        return i;
      else
        return -1;
    }
    vec.clear();
  }
  return -1;
}
void build(string &s, int ind, string &cur) {
  if (ind == all.size()) return;
  int n = cur.size();
  string ss;
  for (int i = 0; i < n; i++) {
    if (cur[i] != all[ind]) {
      s += cur[i];
      ss += cur[i];
    }
  }
  if (s.size() > 500005) return;
  return build(s, ind + 1, ss);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  int tt = T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    int flag = 0;
    for (int i = 1; i <= n - 1; i++) {
      if (s[i] != s[i - 1]) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      cout << s << " " << s[0] << "\n";
      continue;
    }
    vector<vector<int>> v(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
      v[i][s[i] - 'a']++;
    }
    vector<vector<int>> left(n, vector<int>(26, 0));
    vector<vector<int>> right(n + 1, vector<int>(26, 0));
    for (int j = 0; j < 26; j++) {
      left[0][j] = v[0][j];
      right[n - 1][j] = v[n - 1][j];
    }
    for (int i = 1; i <= n - 1; i++) {
      for (int j = 0; j < 26; j++) {
        left[i][j] = left[i - 1][j] + v[i][j];
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        right[i][j] = right[i + 1][j] + v[i][j];
      }
    }
    int mm = 0;
    for (int i = 0; i < 26; i++) {
      if (left[n - 1][i]) {
        mm++;
      }
    }
    vector<int> init(26, 0);
    int ans = check(0, n - 1, left, right, init, mm);
    if (ans >= 0) {
      string kk;
      for (int i = 0; i < ans + 1; i++) kk += s[i];
      string final = kk;
      build(final, 0, kk);
      if (final == s) {
        cout << kk << " " << all << "\n";
      } else
        cout << "-1\n";
    } else
      cout << "-1\n";
    all = "";
  }
}
