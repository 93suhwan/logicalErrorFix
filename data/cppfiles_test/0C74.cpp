#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50, mod = 998244353;
vector<pair<string, int>> s;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string a;
    cin >> a;
    for (int j = 1; j < a.size(); j += 2) a[j] = 'Z' - (a[j] - 'A');
    s.push_back({a, i});
  }
  sort(s.begin(), s.end());
  for (int i = 0; i < s.size(); i++) {
    cout << s[i].second << " ";
  }
  cout << endl;
  return 0;
}
