#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
const ld pi = acos(-1);
const ll inf = 1e8, mod = 1e9 + 7;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const ll N = 2e5 + 100;
vector<string> st;
void permute(string &a, int l, int r) {
  if (l == r)
    st.push_back(a);
  else {
    for (int i = l; i < (r + 1); i++) {
      swap(a[i], a[l]);
      permute(a, l + 1, r);
      swap(a[i], a[l]);
    }
  }
}
void init(int n) {
  string a = "abc";
  permute(a, 0, 2);
  for (int j = 0; j < (5 + 1); j++) {
    string temp;
    temp.push_back(st[j][0]);
    temp.push_back(st[j][1]);
    temp.push_back(st[j][2]);
    for (int i = 1; i < (n / 3 + 1 + 1); i++) {
      st[j].push_back(temp[0]);
      st[j].push_back(temp[1]);
      st[j].push_back(temp[2]);
    }
    st[j].resize(n);
  }
}
void test_case() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  init(n);
  vector<vector<int>> pre(6, vector<int>(n + 1, 0));
  for (int i = 0; i < (5 + 1); i++) {
    for (int j = 1; j < (n + 1); j++) {
      if (st[i][j - 1] == s[j - 1])
        pre[i][j] = pre[i][j - 1];
      else
        pre[i][j] = pre[i][j - 1] + 1;
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    int ans = inf;
    for (int i = 0; i < (5 + 1); i++) {
      ans = min(ans, pre[i][r] - pre[i][l - 1]);
    }
    cout << ans << endl;
  }
}
int32_t main() {
  clock_t begin = clock();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  ll tt = 1;
  while (tt--) {
    test_case();
  }
  clock_t end = clock();
  return 0;
}
