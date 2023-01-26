#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) { return x > y; }
const int maxn = 3e5 + 100;
vector<int> v[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i < maxn; i++)
    for (int j = i; j < maxn; j += i) v[j].push_back(i);
  v[1].push_back(1);
  int t;
  cin >> t;
  while (t--) {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    int check[n + 1];
    memset(check, 0, sizeof(check));
    int cnt = 0;
    for (int i = 0; i < n; i++)
      if (s[i] != c) {
        cnt++;
        for (auto j : v[i + 1]) check[j] = 1;
      }
    if (!cnt) {
      cout << 0 << endl;
      continue;
    }
    int cc = 0;
    for (int i = 2; i <= n; i++)
      if (!check[i] && s[i - 1] == c) cc = i;
    if (!cc)
      cout << 2 << endl << n << ' ' << n - 1 << endl;
    else
      cout << 1 << endl << cc << endl;
  }
  return 0;
}
