#include <bits/stdc++.h>
using namespace std;
const vector<pair<int, int> > dir = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0},
                                     {1, 0},   {-1, 1}, {0, 1},  {1, 1}};
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
void Peter_Torki() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
int n;
bool is_valid(int idx) { return idx >= 0 && idx < n; }
void solve() {
  string s;
  cin >> s;
  long long int cnt = 0;
  for (int i = 0; i < s.size(); i++) cnt += (s[i] == 'N');
  if (cnt == 1)
    cout << "NO\n";
  else
    cout << "YES\n";
}
int main() {
  Peter_Torki();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
