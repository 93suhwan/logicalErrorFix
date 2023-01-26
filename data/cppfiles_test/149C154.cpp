#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if ((a == 0) || (b == 0)) return a + b;
  return gcd(min(a, b), max(a, b) % min(a, b));
}
void solve() {
  long long int n, k, p;
  cin >> n >> k >> p;
  string s;
  cin >> s;
  long long int j;
  vector<long long int> temp;
  long long int cnt = 0;
  for (j = 0; j < n; j++) {
    if (s[j] == '*') {
      cnt++;
    } else if (cnt > 0) {
      temp.push_back(cnt * k + 1);
      cnt = 0;
    }
  }
  if (cnt > 0) {
    temp.push_back(cnt * k + 1);
  }
  long long int sz = temp.size();
  p--;
  for (j = sz - 1; j >= 0; j--) {
    if (p > 0) {
      long long int ok = temp[j];
      temp[j] = p % temp[j];
      p /= ok;
    } else {
      temp[j] = 0;
    }
  }
  sz = 0;
  string ans = "";
  for (j = 0; j < n; j++) {
    if (s[j] == 'a') {
      ans += 'a';
    } else {
      while (temp[sz] > 0) {
        ans += 'b';
        temp[sz]--;
      }
      sz++;
      while (j < n && s[j] == '*') {
        j++;
      }
      j--;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
