#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
const int INF = 1E9 + 5;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n), pos(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
    pos[p[i]] = i;
  }
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    int k = (pos[i] - i + n) % n;
    cnt[k]++;
  }
  auto check = [&](int shift) {
    vector<int> q;
    for (int i = n - shift; i < n; i++) q.push_back(i);
    for (int i = 0; i < n - shift; i++) q.push_back(i);
    int ret = n;
    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        ret--;
        int j = i;
        while (!vis[j]) {
          vis[j] = true;
          j = pos[q[j]];
        }
      }
    }
    if (ret <= m) return true;
    return false;
  };
  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (cnt[i] >= n / 3)
      if (check(i)) res.push_back(i);
  }
  cout << (int)res.size() << ' ';
  for (int x : res) cout << x << ' ';
  cout << '\n';
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) solve();
}
