#include <bits/stdc++.h>
using namespace std;
long long t = 1, n;
string s;
bool nprm[500];
void seive() {
  for (int i = 2; i <= 400; i++) {
    if (!nprm[i]) {
      for (int j = i * i; j <= 400; j += i) {
        nprm[j] = true;
      }
    }
  }
}
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> t;
  seive();
  while (t--) {
    cin >> n >> s;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (i == j && nprm[s[i] - '0']) {
          ans = s[i] - '0';
          i = n;
          break;
        }
        if (i < j && nprm[(s[i] - '0') * 10 + (s[j] - '0')]) {
          ans = (s[i] - '0') * 10 + (s[j] - '0');
          break;
        }
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
