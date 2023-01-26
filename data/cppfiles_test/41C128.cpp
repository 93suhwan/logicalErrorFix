#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int power(long long x, unsigned int y, int p) {
  int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void fun() {
  int len = 200001;
  string s = "";
  while (len--) s += "abc";
  v.push_back(s);
  s.clear();
  len = 200001;
  while (len--) s += "bac";
  len = 200001;
  v.push_back(s);
  s.clear();
  while (len--) s += "cba";
  len = 200001;
  v.push_back(s);
  s.clear();
  while (len--) s += "bca";
  len = 200001;
  v.push_back(s);
  s.clear();
  while (len--) s += "acb";
  len = 200001;
  v.push_back(s);
  s.clear();
  while (len--) s += "cab";
  v.push_back(s);
  s.clear();
}
int main() {
  fun();
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<vector<int>> vf;
  for (int i = 0; i < v.size(); i++) {
    vector<int> vec(n, 0);
    if (s[0] != v[i][0]) vec[0] = 1;
    for (int j = 1; j < s.length(); j++) {
      if (s[j] != v[i][j])
        vec[j] = vec[j - 1] + 1;
      else
        vec[j] = vec[j - 1];
    }
    vec.insert(vec.begin(), 0);
    vf.push_back(vec);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int ans = INT_MAX;
    for (int i = 0; i < vf.size(); i++) {
      ans = min(ans, vf[i][r] - vf[i][l - 1]);
    }
    cout << ans << endl;
  }
  return 0;
}
