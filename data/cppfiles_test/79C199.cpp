#include <bits/stdc++.h>
using namespace std;
bool iSp(int x) {
  long long i;
  for (i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return true;
      exit;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, t, i, r, x, j, ans, s, p, pp, q;
  cin >> t;
  while (t--) {
    string a, c;
    cin >> n >> a;
    s = 1;
    q = -1;
    r = 0;
    vector<long long> v;
    map<string, long long> A;
    for (i = 0; i < n; i++) {
      c = a[i];
      A[c]++;
    }
    for (i = 0; i < a.size(); i++) {
      for (j = i + 1; j < a.size(); j++) {
        c = a[i];
        c += a[j];
        A[c]++;
      }
    }
    if (A["1"] != 0) {
      cout << 1 << endl << 1 << endl;
      continue;
    }
    r = 0;
    for (i = 1; i <= 99; i++) {
      c = "";
      if (i >= 10) c = char((i / 10) + 48);
      c += char((i % 10) + 48);
      if (iSp(i) == true && A[c] != 0) {
        r = i;
        break;
      }
    }
    if (r < 10)
      cout << 1 << endl;
    else
      cout << 2 << endl;
    cout << r << endl;
  }
}
