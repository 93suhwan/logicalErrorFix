#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int c1 = 0;
  int arr[26] = {0};
  int n = s.length();
  for (int i = 0; i < n; i++) {
    arr[s[i] - 'a']++;
  }
  int uq = 0;
  int pq = 0;
  for (int i = 0; i < 26; i++) {
    if (arr[i] == 1) uq++;
    if (arr[i] >= 2) pq++;
  }
  cout << uq / 2 + pq << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
