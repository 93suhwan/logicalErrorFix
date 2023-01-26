#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
void solve() {
  int n;
  cin >> n;
  string s;
  vector<pair<int, int>> pushes(n);
  vector<pair<int, int>> pos, neg;
  for (long long i = 0; i < n; i++) {
    cin >> pushes[i].first;
    pushes[i].second = i;
  }
  cin >> s;
  int cnt = 1;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      pos.push_back(make_pair(pushes[i].first, i));
    } else {
      neg.push_back(make_pair(pushes[i].first, i));
    }
  }
  sort(neg.begin(), neg.end());
  sort(pos.begin(), pos.end());
  for (long long i = 0; i < neg.size(); i++) {
    pushes[neg[i].second].first = cnt;
    cnt++;
  }
  for (long long i = 0; i < pos.size(); i++) {
    pushes[pos[i].second].first = cnt;
    cnt++;
  }
  for (long long i = 0; i < n; i++) {
    cout << pushes[i].first << " ";
  }
  cout << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
