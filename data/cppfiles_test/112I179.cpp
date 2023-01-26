#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long a, s, d, f;
    cin >> a >> s >> d >> f;
    long long c = max(a, max(s, d));
    if (c - 1 <= f && f > 0 && c > 1) {
      f -= c - 1;
      if (a == c)
        a = 0;
      else if (c == s)
        s = 0;
      else if (c == d)
        d = 0;
    } else if (f && c > 1) {
      if (a == c)
        a -= f + 1;
      else if (c == s)
        s -= f + 1;
      else if (c == d)
        d -= f + 1;
      f = 0;
    }
    c = max(a, max(s, d));
    if (c - 1 <= f && f > 0 && c > 1) {
      f -= c - 1;
      if (a == c)
        a = 0;
      else if (c == s)
        s = 0;
      else if (c == d)
        d = 0;
    } else if (f && c > 1) {
      if (a == c)
        a -= f + 1;
      else if (c == s)
        s -= f + 1;
      else if (c == d)
        d -= f + 1;
      f = 0;
    }
    c = max(a, max(s, d));
    if (c - 1 <= f && f > 0 && c > 1) {
      f -= c - 1;
      if (a == c)
        a = 0;
      else if (c == s)
        s = 0;
      else if (c == d)
        d = 0;
    } else if (f && c > 1) {
      if (a == c)
        a -= f + 1;
      else if (c == s)
        s -= f + 1;
      else if (c == d)
        d -= f + 1;
      f = 0;
    }
    long long arr[3];
    arr[0] = a;
    arr[1] = s;
    arr[2] = d;
    sort(arr, arr + 3);
    if (f || arr[2] > arr[1] + 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
