#include <bits/stdc++.h>
using namespace std;
bool cmp(string x, string y) {
  for (int i = 0; i < x.size(); i++) {
    if (x[i] == y[i]) continue;
    if (i % 2)
      return x[i] > y[i];
    else
      return x[i] < y[i];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int a, b;
  cin >> a >> b;
  map<string, int> v;
  vector<string> s;
  for (int i = 1; i <= a; i++) {
    string t;
    cin >> t;
    v[t] = i;
    s.push_back(t);
  }
  sort(s.begin(), s.end(), cmp);
  for (auto &it : s) cout << v[it] << " ";
  return 0;
}
