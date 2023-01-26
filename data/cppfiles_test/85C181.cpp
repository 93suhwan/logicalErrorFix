#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
void solve() {
  string s;
  cin >> s;
  int left = 0;
  int right = s.size() - 1;
  int p1, p2;
  while (left < s.size() - 1 && s[left] == s[left + 1]) {
    left++;
  }
  if (left == s.size() - 1 && s[left] == s[right]) {
    int c1 = (s[left] - 48) ^ 1;
    cout << c1 << endl;
    return;
  }
  while (right > 1 && s[right] == s[right - 1]) {
    right--;
  }
  if (right == 0 && s[left] == s[right]) {
    int c2 = (s[right] - 48) ^ 1;
    cout << c2 << endl;
    return;
  }
  p1 = left + 1;
  p2 = right - 1;
  bool zero = false, one = false;
  while (p1 <= p2) {
    if (s[p1] == '0' || s[p2] == '0') {
      zero = true;
    }
    if (s[p1] == '1' || s[p2] == '1') {
      one = true;
    }
    p1++;
    p2--;
  }
  int three = 0;
  if (zero && one) {
    three = 2;
  } else if (zero) {
    three = 1;
  } else if (one) {
    three = 0;
  } else {
    int c1 = (s[left] - 48) ^ 1;
    int c2 = (s[right] - 48) ^ 1;
    cout << min(2, c1 + c2 + three) << endl;
    return;
  }
  int c1 = (s[left] - 48) ^ 1;
  int c2 = (s[right] - 48) ^ 1;
  cout << min(2, c1 + c2 + three) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
