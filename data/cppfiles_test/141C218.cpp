#include <bits/stdc++.h>
using namespace std;
bool isvowel(char &c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
  return false;
}
void solve() {
  string a, s;
  cin >> a >> s;
  string b = "";
  long long j = s.length() - 1;
  bool flg = true;
  for (int i = a.size() - 1; i >= 0; i--) {
    if (j < 0) {
      flg = false;
      break;
    }
    if (s[j] >= a[i]) {
      b += char((s[j] - '0') - (a[i] - '0') + '0');
      j--;
    } else {
      if (j < 1 || s[j - 1] != '1') {
        flg = false;
        break;
      } else {
        b += char((10 + s[j] - '0') - (a[i] - '0') + '0');
        j -= 2;
      }
    }
  }
  if (!flg) {
    cout << "-1"
         << "\n";
    return;
  }
  while (j >= 0) {
    b += s[j];
    j--;
  }
  while (b.back() == '0') b.pop_back();
  reverse(b.begin(), b.end());
  cout << b << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
