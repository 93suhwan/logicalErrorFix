#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void init() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
long long Gcd(long long a, long long b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
long long Lcm(long long a, long long b) { return (a * b) / Gcd(a, b); }
int main() {
  long long t;
  cin >> t;
  while (t--) {
    int alpha[26] = {0};
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      alpha[s[i] - 'a']++;
    }
    int a = 0, b = 0;
    for (int i = 0; i < 26; i++) {
      if (alpha[i] >= 2)
        a++;
      else if (alpha[i] == 1)
        b++;
    }
    cout << a + b / 2 << "\n";
  }
}
