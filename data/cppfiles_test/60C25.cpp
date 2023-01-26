#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
string s, s1;
char z;
long long n, m, i, j, t, k, a, b, c, x, y, ans;
int main() {
  long long test = 1;
  cin >> test;
  while (test--) {
    v.clear();
    n = m = i = j = t = k = a = b = c = x = y = ans = 0;
    cin >> n;
    map<long long, long long> mp;
    long long A[n + 5];
    for (i = 0; i < n; i++) cin >> A[i], a += A[i];
    if (a * 2 / n * n != a * 2)
      cout << 0 << endl;
    else {
      a *= 2, a /= n;
      for (i = 0; i < n; i++) mp[A[i]]++;
      for (i = 0; i < n; i++)
        if (A[i] <= a) mp[A[i]]--, ans += mp[a - A[i]];
      cout << ans << endl;
    }
  }
  return 0;
}
