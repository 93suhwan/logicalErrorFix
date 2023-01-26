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
int ck(vector<int> v1, vector<int> v2) {
  int ans = 0, i;
  for (i = 0; i < v1.size() && i < v2.size(); i++) {
    if (v1[i] != v2[i]) break;
  }
  if (i == v1.size()) {
    int f = 1;
    for (; i < v2.size(); i++)
      if (v2[i] == 0) f = 0;
    if (f) ans = 1;
    return ans;
  } else {
    if (i == v2.size()) {
      int f = 1;
      for (; i < v2.size(); i++)
        if (v2[i] == 1) f = 0;
      if (f) ans = 1;
      return ans;
    } else
      return 0;
  }
}
int main() {
  int t = 1, fac = 1;
  while (t--) {
    long long n, i, x, y;
    vector<int> v1, v2;
    cin >> x >> y;
    v1 = fun(x);
    v2 = fun(y);
    int ans = ck(v1, v2);
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    int ans1 = ck(v1, v2);
    if (ans || ans1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
