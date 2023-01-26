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
int main() {
  int t = 1, fac = 1;
  while (t--) {
    long long n, i, x, y;
    vector<int> v1, v2;
    cin >> x >> y;
    v1 = fun(x);
    v2 = fun(y);
    for (i = 0; i < v1.size() && i < v2.size(); i++) {
      if (v1[i] != v2[i]) break;
    }
    if (i == v1.size()) {
      int f = 1;
      for (; i < v2.size(); i++)
        if (v2[i] == 0) f = 0;
      if (f)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
      if (i == v2.size()) {
        int f = 1;
        for (; i < v2.size(); i++)
          if (v2[i] == 1) f = 0;
        if (f)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      } else
        cout << "NO" << endl;
    }
  }
}
