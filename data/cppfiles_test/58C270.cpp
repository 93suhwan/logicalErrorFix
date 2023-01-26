#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Up, typename... Down>
void dbg_out(Up U, Down... D) {
  cerr << ' ' << U;
  dbg_out(D...);
}
long long fre[100001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long i, j, t, k, n, x, y, z, num, c, cnt = 0;
  set<int> st;
  map<int, int> m;
  vector<vector<string>> all;
  vector<long long> v, v1;
  string s1, s2, s3;
  pair<int, int> p[100000];
  deque<char> deq;
  vector<double> d;
  cin >> t;
  while (t--) {
    cin >> n;
    string s;
    vector<string> ar;
    for (i = 0; i < 2; i++) cin >> s, ar.push_back(s);
    bool flag = true;
    for (j = 0; j < n; j++) {
      if (ar[0][j + 1] == '1' && ar[0 + 1][j + 1] == '1') {
        flag = false;
        break;
      } else
        continue;
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
