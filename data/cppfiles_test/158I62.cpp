#include <bits/stdc++.h>
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
template <typename T>
vector<vector<T>> vec2d(int n, int m, T v) {
  return vector<vector<T>>(n, vector<T>(m, v));
}
template <typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v) {
  return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}
template <typename T>
void print_vector(vector<T> v, char delimiter = ' ') {
  if (v.empty()) {
    cout << endl;
    return;
  }
  for (int i = 0; i + 1 < v.size(); i++) cout << v[i] << delimiter;
  cout << v.back() << endl;
}
using P = pair<int, int>;
using T = tuple<int, int, int>;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  vector<int> pcnt(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) pcnt[i]++;
    }
  }
  vector<int> cnt(1 << n);
  vector<vector<int>> indices(1 << n);
  for (int i = 0; i < m; i++) {
    int t = 0;
    for (int j = 0; j < n; j++) {
      if (s[j][i] == '1') {
        t += 1 << j;
      }
    }
    indices[t].push_back(i);
    cnt[t]++;
  }
  long long ans = 0;
  int all_student = (1 << n) - 1;
  vector<int> ans_v(m);
  for (int s = 0; s < (1 << n); s++) {
    int others = all_student - s;
    int cur = m;
    vector<T> vp;
    long long tmp = 0;
    for (int i = 0; i < n; i++) {
      if (s & (1 << i))
        tmp += x[i];
      else
        tmp -= x[i];
    }
    for (int t = 0; t < (1 << n); t++) {
      int correct_pos = pcnt[s & t];
      int correct_neg = pcnt[others & t];
      vp.push_back(T(correct_pos - correct_neg, cnt[t], t));
    }
    sort(vp.begin(), vp.end(), greater<T>());
    for (auto [cnt_pos, x, t] : vp) {
      long long l = cur - x + 1, r = cur;
      long long sum = ((l + r) * x) / 2;
      tmp += sum * cnt_pos;
      cur -= x;
    }
    if (chmax(ans, tmp)) {
      int cur = m;
      for (auto [cnt_pos, x, t] : vp) {
        for (int idx : indices[t]) {
          ans_v[idx] = cur;
          cur--;
        }
      }
    }
    assert(cur == 0);
  }
  cerr << "line" << 108 << ":<" << __func__ << ">:"
       << "ans"
       << "=" << ans << endl;
  print_vector(ans_v);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(10) << fixed;
  int t;
  cin >> t;
  while (t--) solve();
}
