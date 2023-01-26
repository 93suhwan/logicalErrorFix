#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", \
                     "no-stack-protector")
#pragma GCC target( \
    "f16c,xop,fma,fma4,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
long long n, a[200010], lft = 0, rht = 0;
bool res = true;
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long i, j, k;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  cin >> s;
  k = 1;
  for (i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1]) {
      k++;
    }
  }
  j = n - k;
  reverse(a, a + j);
  k = 0;
  for (i = 0; i < n; i++) {
    if (i == 0 || s[i] != s[i - 1]) {
      cout << a[j] << " " << s[i] << endl;
      if (s[i] == 'L') {
        lft += a[j];
      } else {
        rht += a[j];
      }
      j++;
    } else {
      cout << a[k] << " ";
      if (s[i] == 'L') {
        if (lft > rht + a[k]) {
          cout << "R\n";
          rht += a[k];
        } else {
          cout << "L\n";
          lft += a[k];
        }
      } else {
        if (rht > lft + a[k]) {
          cout << "L\n";
          lft += a[k];
        } else {
          cout << "R\n";
          rht += a[k];
        }
      }
      k++;
    }
  }
  return 0;
}
