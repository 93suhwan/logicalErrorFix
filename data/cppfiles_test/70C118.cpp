#include <bits/stdc++.h>
using namespace std;
void solve() {
  string t;
  cin >> t;
  vector<long long int> arr(26, 0);
  vector<long long int> brr(26, 0);
  long long int n = t.length();
  for (long long int i = 0; i < n; i++) {
    arr[t[i] - 'a']++;
  }
  string c;
  long long int count1 = 0;
  for (long long int i = 0; i < 26; i++) {
    if (arr[i] > 0) count1++;
  }
  vector<long long int> crr(26, 0);
  for (long long int i = n - 1; i >= 0; i--) {
    if (brr[t[i] - 'a'] == 0) {
      brr[t[i] - 'a']++;
      c += t[i];
      if (count1 != 0) {
        if (arr[t[i] - 'a'] % count1 != 0) {
          cout << "-1" << endl;
          return;
        }
        crr[t[i] - 'a'] = arr[t[i] - 'a'] / count1;
      }
      count1--;
    }
  }
  reverse(c.begin(), c.end());
  vector<long long int> drr(26, 0);
  string d;
  for (long long int i = 0; i < n; i++) {
    if (crr == drr) {
      break;
    } else {
      d += t[i];
      drr[t[i] - 'a']++;
    }
  }
  string buf = d;
  string buf2 = d;
  for (long long int i = 0; i < c.length(); i++) {
    buf.erase(remove(buf.begin(), buf.end(), c[i]), buf.end());
    buf2 += buf;
  }
  if (buf2 != t)
    cout << "-1" << endl;
  else
    cout << d << " " << c << endl;
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
