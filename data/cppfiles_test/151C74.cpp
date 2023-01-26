#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long int ans = power(a, b / 2);
  if (b % 2 == 0) return (ans * ans) % 1000000007;
  return ((ans * ans) % 1000000007 * a) % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q, p = 0, i;
  cin >> q;
  map<int, vector<int>> m;
  while (q--) {
    int f, x, y;
    cin >> f;
    if (f == 1) {
      cin >> x;
      p++;
      m[x].push_back(p);
    } else {
      cin >> x >> y;
      if (x != y) {
        if (m[x].size() > m[y].size()) m[x].swap(m[y]);
        vector<int> vt;
        vt = m[x];
        for (i = 0; i < vt.size(); i++) {
          m[y].push_back(vt[i]);
        }
        m.erase(x);
      }
    }
  }
  vector<pair<int, int>> v;
  for (auto it = m.begin(); it != m.end(); it++) {
    vector<int> vt;
    int r = it->first;
    vt = m[r];
    for (i = 0; i < vt.size(); i++) {
      v.push_back(make_pair(vt[i], r));
    }
  }
  sort(v.begin(), v.end());
  for (i = 0; i < v.size(); i++) {
    cout << v[i].second << " ";
  }
  cout << "\n";
  return 0;
}
