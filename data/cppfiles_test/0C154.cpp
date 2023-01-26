#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string, int>& a, pair<string, int>& b) {
  int i = 0;
  while (a.first[i] == b.first[i]) {
    i++;
  }
  int x = a.first[i] - 26;
  int y = b.first[i] - 26;
  if (i % 2 == 0) {
    return y > x;
  } else {
    return x > y;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i].first;
    s[i].second = i + 1;
  }
  sort(s.begin(), s.end(), cmp);
  for (int i = 0; i < n; i++) {
    cout << s[i].second << " ";
  }
  cout << endl;
}
