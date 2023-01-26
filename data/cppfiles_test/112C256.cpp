#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int max1 = a - 1 + b - 1 + c - 1;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
    int min1 = v[2] - 1 - v[1] - v[0];
    if (m <= max1 && m >= min1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
