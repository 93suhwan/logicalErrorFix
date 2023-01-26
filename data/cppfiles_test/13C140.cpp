#include <bits/stdc++.h>
using namespace std;
void opv(vector<int> &v) {
  for (auto i : v) cout << i << ' ';
  cout << endl;
}
void ipv(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) cin >> v[i];
}
void oppv(vector<pair<int, int>> &v) {
  for (auto i : v) {
    cout << i.first << ' ' << i.second;
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    string s;
    cin >> s;
    int c = count(s.begin(), s.end(), 'B');
    int d = count(s.begin(), s.end(), 'A');
    d += count(s.begin(), s.end(), 'C');
    if (c > d) {
      cout << "NO" << endl;
      continue;
    }
    if (c * 2 >= s.length())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
