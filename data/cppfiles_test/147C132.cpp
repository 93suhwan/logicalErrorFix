#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int xx = 2e5 + 10;
long long int a[305][305];
long long int dx[] = {1, 0, -1, 0};
long long int dy[] = {0, 1, 0, -1};
long long int check(vector<long long int>& a) {
  long long int mn = INT_MAX;
  long long int indx = -1;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] < mn) {
      mn = a[i];
      indx = i;
    }
  }
  return indx;
}
void solve() {
  string s;
  cin >> s;
  long long int c = 0;
  long long int n = s.length();
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'N') c++;
  }
  if (c == 1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}
int main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
