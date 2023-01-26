#include <bits/stdc++.h>
using namespace std;
string s2;
unordered_map<string, int> visited;
bool solver(string s1) {
  if (visited[s1]) return false;
  if (s1.back() == '1' and s1.size() > s2.size()) return false;
  if (s1 == s2) return true;
  visited[s1] = 1;
  string s12 = s1;
  s1 = s1 + "1";
  reverse(s1.begin(), s1.end());
  if (solver(s1)) return true;
  while (s12.back() == '0') s12.pop_back();
  reverse(s12.begin(), s12.end());
  if (solver(s12)) return true;
  return false;
}
string solve() {
  long long int x, y;
  cin >> x >> y;
  string s1;
  while (x) {
    s1 = ((x & 1) ? "1" : "0") + s1;
    x = x >> 1;
  }
  while (y) {
    s2 = ((y & 1) ? "1" : "0") + s2;
    y = y >> 1;
  }
  if (s2.back() == '0') return "NO";
  if (solver(s1)) return "YES";
  return "NO";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    cout << solve() << "\n";
  }
  return 0;
}
