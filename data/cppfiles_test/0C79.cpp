#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<string, int> s[1000005];
bool cmp(const pair<string, int> p1, const pair<string, int> p2) {
  string s1 = p1.first, s2 = p2.first;
  for (int i = 0; i < m; i++) {
    if (s1[i] != s2[i]) {
      if (i % 2 == 0)
        return s1[i] < s2[i];
      else
        return s1[i] > s2[i];
    }
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i].first;
    s[i].second = i;
  }
  sort(s + 1, s + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    cout << s[i].second << " ";
  }
  cout << endl;
  return 0;
}
