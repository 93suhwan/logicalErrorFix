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
template <class T>
bool ckmin(T& a, T& b) {
  bool r = a > b;
  a = min(a, b);
  return r;
}
template <class T>
bool ckmax(T& a, T& b) {
  bool r = a < b;
  a = max(a, b);
  return r;
}
const int MOD = 1e9 + 7;
const long long INF = 1e18;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int rowtm = 0;
    if (rb <= rd) {
      rowtm = rd - rb;
    } else {
      rowtm = n - rb + n - rd;
    }
    int coltm = 0;
    if (cb <= cd) {
      coltm = cd - cb;
    } else {
      coltm = m - cb + m - cd;
    }
    42;
    cout << min(rowtm, coltm) << '\n';
    ;
  }
}
