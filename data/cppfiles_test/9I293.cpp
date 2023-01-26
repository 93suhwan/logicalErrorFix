#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
int main(int argc, char* argv[]) {
  if (argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
  if (argc == 3) freopen(argv[2], "w", stdout);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    set<char> s1;
    for (auto c : s) s1.insert(c);
    int m = s1.size();
    cout << min(m, n / 2) << endl;
  }
  return 0;
}
