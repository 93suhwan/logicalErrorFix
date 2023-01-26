#include <bits/stdc++.h>
using namespace std;
long long REMINDER = 1000000007;
void solve() {
  long long n, i, j, cnt = 0, a7a = 0;
  a7a++;
  cin >> n;
  vector<pair<long long, long long>> zeby(n);
  for (i = 0; i < n; i++) {
    cin >> zeby[i].first;
    zeby[i].second = i;
  }
  string s;
  cin >> s;
  sort(zeby.begin(), zeby.end());
  long long baba = n;
  for (i = n - 1; i >= 0; i--) {
    if (s[zeby[i].second] == '1') {
      zeby[i].first = baba--;
    }
  }
  for (i = n - 1; i >= 0; i--) {
    if (s[zeby[i].second] == '0') {
      zeby[i].first = baba--;
    }
  }
  for (i = n - 1; i >= 0; i--) {
    swap(zeby[i].first, zeby[i].second);
  }
  sort(zeby.begin(), zeby.end());
  for (i = 0; i < n; i++) cout << zeby[i].second << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test_case = 1;
  cin >> test_case;
  while (test_case--) {
    solve();
  }
  return 0;
}
