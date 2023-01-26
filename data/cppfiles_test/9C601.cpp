#include <bits/stdc++.h>
using namespace std;
long long MAX = 1e9 + 7;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
long long powM(long long x, long long y, long long m) {
  long long ans = 1, r = 1;
  x = x % m;
  while (r > 0 && r <= y) {
    if (r & y) {
      ans = ans * x;
      ans = ans % m;
    }
    r = r << 1;
    x = x * x;
    x = x % m;
  }
  ans = ans % m;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long T = 0; T < t; T++) {
    string s;
    cin >> s;
    int n = s.size();
    int freq[26] = {};
    for (int i = 0; i < n; i++) {
      freq[s[i] - 'a']++;
    }
    int ans = 0, rem = 0;
    for (int i = 0; i < 26; i++) {
      if (freq[i] > 1)
        ans++;
      else if (freq[i])
        rem++;
    }
    ans += rem / 2;
  done:
    cout << ans << endl;
  }
  return (0);
}
