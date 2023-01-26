#include <bits/stdc++.h>
using namespace std;
bool iSp(int x) {
  long long i;
  for (i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return 1;
      exit;
    }
  }
  return 0;
}
bool IsSub(string a, string b) {
  string c;
  long long i;
  for (i = 0; i <= b.size() - a.size(); i++) {
    c = b.substr(i, a.size());
    if (c == a) {
      return true;
      exit;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, t, i, r, x, j, y, l, ans, s, p;
  cin >> t;
  while (t--) {
    long long a[8];
    map<long long, long long> A;
    for (i = 1; i <= 7; i++) {
      cin >> a[i];
      A[a[i]]++;
    }
    for (i = 1; i <= 7; i++) {
      for (j = i + 1; j <= 7; j++) {
        for (r = j + 1; r <= 7; r++) {
          A[a[i]]--;
          A[a[j]]--;
          A[a[r]]--;
          A[a[i] + a[j]]--;
          A[a[i] + a[r]]--;
          A[a[r] + a[j]]--;
          A[a[i] + a[j] + a[r]]--;
          s = 0;
          for (l = 1; l <= 7; l++) {
            if (A[a[l]] != 0) s++;
          }
          if (s == 0) {
            cout << a[i] << " " << a[j] << " " << a[r] << endl;
            r = i = j = 8;
          }
          A[a[i]]++;
          A[a[j]]++;
          A[a[r]]++;
          A[a[i] + a[j]]++;
          A[a[i] + a[r]]++;
          A[a[r] + a[j]]++;
          A[a[i] + a[j] + a[r]]++;
        }
      }
    }
  }
}
