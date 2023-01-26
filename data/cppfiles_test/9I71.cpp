#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
vector<int> adj[1000001];
void comp() {
  string s;
  cin >> s;
  int i, l = s.length();
  map<char, int> m;
  for (i = 0; i < l; i++) m[s[i]]++;
  int cnt = 0;
  for (pair<char, int> p : m) {
    cnt++;
  }
  if (cnt >= l / 2)
    cout << l / 2 << "\n";
  else
    cout << cnt << "\n";
}
int main() {
  fast();
  int t = 1;
  cin >> t;
  while (t--) {
    comp();
  }
  return 0;
}
