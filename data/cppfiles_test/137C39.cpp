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
    map<vector<int>, int> mp;
    v1 = fun(x);
    v2 = fun(y);
    queue<vector<int> > q;
    q.push(v1);
    mp[v1] = 1;
    while (!q.empty()) {
      vector<int> v = q.front();
      q.pop();
      if (v.size() >= 100) continue;
      vector<int> v3 = v;
      v3.push_back(0);
      while (v3[v3.size() - 1] == 0) v3.pop_back();
      reverse(v3.begin(), v3.end());
      if (mp[v3] == 0) {
        mp[v3] = 1;
        q.push(v3);
      }
      v3 = v;
      v3.push_back(1);
      reverse(v3.begin(), v3.end());
      if (mp[v3] == 0) {
        mp[v3] = 1;
        q.push(v3);
      }
    }
    if (mp[v2])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
