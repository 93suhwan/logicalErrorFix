#include <bits/stdc++.h>
using namespace std;
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
  cerr << '\n';
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
void run() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e5 + 5, mod = 1e9 + 7, mod2 = 998244353, MAXN = 100000 + 29;
void files() {}
int arr[N], n;
bool go(bool f) {
  if (f)
    for (int i = 0; i < n - 1; i += 2) {
      if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
    }
  else
    for (int i = 1; i < n - 1; i += 2) {
      if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
    }
  bool ret = true;
  for (int i = 0; i < n; ++i) {
    ret &= arr[i] == (i + 1);
  }
  return ret;
}
int a, b;
bool solve(int i, int j, int k, bool t) {
  if (i < 0 || j < 0) return 0;
  if (i == 0 && j == 0) {
    return k == 0;
  }
  if (k < 0) return 0;
  if (t) {
    return solve(i - 1, j, k, t ^ 1) || solve(i, j - 1, k - 1, t ^ 1);
  } else
    return solve(i, j - 1, k, t ^ 1) || solve(i - 1, j, k - 1, t ^ 1);
}
void solve() {
  cin >> a >> b;
  int diff = abs(a - b);
  vector<int> v;
  for (int i = diff / 2; i <= a + b - diff / 2;) {
    v.push_back(i);
    i += 1 + (diff % 2 == 0);
  }
  cout << v.size() << '\n';
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << ' ';
  }
  cout << '\n';
}
int main() {
  files();
  int t = 1;
  cin >> t;
  while (t--) solve();
}
