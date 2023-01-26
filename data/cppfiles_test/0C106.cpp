#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  pair<string, int> p[n];
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j < s.size(); j += 2) {
      s[j] = 'Z' - (s[j] - 'A');
    }
    p[i].first = s;
    p[i].second = i;
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    cout << p[i].second + 1 << " ";
  }
}
