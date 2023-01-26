#include <bits/stdc++.h>
using namespace std;
vector<int> fun(long long x) {
  vector<int> v;
  while (x) {
    v.push_back(x % 2);
    x /= 2;
  }
  reverse(v.begin(), v.end());
  return v;
}
pair<int, int> ck(vector<int> v1, vector<int> v2) {
  int ans = 0, i, l, r, n1, n2, j;
  n1 = v1.size();
  n2 = v2.size();
  for (i = 0; i < n2; i++) {
    j = 0;
    int i1 = i;
    while (v1[j] == v2[i1] && i1 < n2 && j < n1) j++, i1++;
    if (j == n1) return {i, i1 - 1};
  }
  return {-1, -1};
}
int main() {
  int t = 1, fac = 1;
  while (t--) {
    long long n, i, x, y;
    vector<int> v1, v2;
    cin >> x >> y;
    v1 = fun(x);
    v2 = fun(y);
    if (v1.size() <= v2.size()) {
      pair<int, int> ans = ck(v1, v2);
      int f = 1, pre = 0, suf = 0;
      for (i = 0; i < ans.first; i++) {
        if (v2[i] == 0)
          f = 0;
        else
          pre = 1;
      }
      for (i = ans.second + 1; i < v2.size(); i++) {
        if (v2[i] == 0)
          f = 0;
        else
          suf = 1;
      }
      if (suf == 0 && pre == 1 && v1[v1.size() - 1] == 0) f = 0;
      if (f)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
      for (i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
          break;
        }
      }
      int f = 1;
      for (; i < v2.size(); i++) {
        if (v2[i] == 1) f = 0;
      }
      if (f)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
