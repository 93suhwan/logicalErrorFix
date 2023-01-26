#include <bits/stdc++.h>
using namespace std;
long long t, n, m, v;
void lets_do_it() {
  cin >> n;
  map<pair<long long, long long>, bool> ma;
  vector<pair<long long, long long>> s;
  for (int i = 0; i < n; i++) {
    cin >> v >> m;
    s.push_back({v, m});
    ma[{v, m}] = 1;
  }
  for (auto it = s.begin(); it != s.end(); it++) {
    for (int i = it->first; i <= it->second; i++) {
      if ((i == it->second || ma[{i + 1, it->second}]) &&
          (ma[{it->first, i - 1}] || i == it->first)) {
        cout << it->first << " " << it->second << " " << i << endl;
        break;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    lets_do_it();
  }
  return 0;
}
