#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (string &x : a) cin >> x;
  vector<pair<string, int>> b;
  for (int i = 0; i < n; i++) b.push_back({a[i], i});
  sort(b.begin(), b.end(),
       [&](const pair<string, int> &i, const pair<string, int> &j) {
         if (i.first == j.first) return i.second < j.second;
         for (int c = 0; c < m; c++) {
           if (i.first[c] == j.first[c]) continue;
           if (c % 2 == 0) return i.first[c] < j.first[c];
           return i.first[c] > j.first[c];
         }
       });
  for (pair<string, int> &x : b) cout << x.second + 1 << " ";
}
