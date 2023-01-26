#include <bits/stdc++.h>
int dx[8] = {0, 1};
int dy[8] = {1, 0};
long long gcd(long long x, long long y) { return (!y ? x : gcd(y, x % y)); }
long long lcm(long long x, long long y) { return x / gcd(x, y) * y; }
using namespace std;
const long long LLOO = 0x3f3f3f3f3f3f3f3f;
const long long OO = 0x3f3f3f3f;
const long double ESP = 1e-8;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int n;
vector<long long> arr, bit;
void add(int indx, int toadd) {
  for (int i = indx; i <= n; i += (i & -i)) {
    if (arr[i] > toadd) bit[i] += toadd;
  }
}
long long getprfix(long long indx) {
  int sum = 0;
  for (int i = indx; i > 0; i -= (i & -i)) {
    sum += bit[i];
  }
  return sum;
}
long long rangesum(int l, int r) { return (getprfix(r) - getprfix(l - 1)); }
void buil() {
  bit = vector<long long>(n + 1, 0);
  for (int i = 1; i <= n; i++) add(i, arr[i]);
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) {
    int ba = 0, ab = 0, c = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b') ab++;
      if (s[i] == 'b' && s[i + 1] == 'a') ba++;
    }
    if (ab == ba)
      cout << s << "\n";
    else if (ab > ba) {
      for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b') {
          s[i] = 'b';
          c++;
        }
        if (c == ab - ba) break;
      }
    } else {
      for (int i = 0; i < s.size() - 1; i++) {
        if (c == ba - ab) break;
        if (s[i] == 'b' && s[i + 1] == 'a') {
          s[i] = 'a';
          c++;
        }
      }
      cout << s << "\n";
    }
  }
}
