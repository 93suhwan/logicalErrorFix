#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long M = 998244353;
const long long inf = 1e18 + 1;
void mistakes() {}
void change(long long i, long long j, long long k, vector<long long> &temp) {
  long long ele1 = temp[i];
  long long ele2 = temp[j];
  long long ele3 = temp[k];
  temp[i] = ele3;
  temp[j] = ele1;
  temp[k] = ele2;
}
void purple() {
  long long n;
  cin >> n;
  vector<long long> a, b;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back(x);
    b.push_back(x);
  }
  long long cnt = 0;
  sort(b.begin(), b.end());
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    if (a[i] != b[i]) cnt++, v.push_back(a[i]);
  }
  if (cnt == 0) {
    cout << "YES\n";
    return;
  }
  if ((cnt <= 2) or cnt > 9) {
    cout << "NO\n";
    return;
  }
  n = ((long long)(v).size());
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (i == j) continue;
      for (long long k = 0; k < n; k++) {
        if (i == k or k == j) continue;
        vector<long long> temp = v;
        change(i, j, k, temp);
        if (is_sorted(temp.begin(), temp.end())) {
          cout << "YES\n";
          return;
        }
        vector<long long> temp1 = temp, tt;
        sort(temp.begin(), temp.end());
        for (long long ii = 0; ii < n; ii++)
          if (temp[ii] != temp1[ii]) tt.push_back(temp1[ii]);
        long long n1 = ((long long)(tt).size());
        if (n1 <= 2 or n1 > 6) {
          continue;
        }
        for (long long i1 = 0; i1 < n1; i1++) {
          for (long long j1 = 0; j1 < n1; j1++) {
            if (i1 == j1) continue;
            for (long long k1 = 0; k1 < n1; k1++) {
              if (i1 == k1 or k1 == j1) continue;
              change(i1, j1, k1, tt);
              if (is_sorted(tt.begin(), tt.end())) {
                cout << "YES\n";
                return;
              }
              temp1 = tt;
              vector<long long> tt1;
              sort(temp1.begin(), temp1.end());
              for (long long ii = 0; ii < n1; ii++)
                if (tt[ii] != temp1[ii]) tt1.push_back(tt[ii]);
              long long n2 = ((long long)(tt1).size());
              if (n2 <= 2 or n2 > 3) {
                continue;
              }
              for (long long i2 = 0; i2 < n2; i2++) {
                for (long long j2 = 0; j2 < n2; j2++) {
                  if (i2 == j2) continue;
                  for (long long k2 = 0; k2 < n2; k2++) {
                    if (i2 == k2 or k2 == j2) continue;
                    vector<long long> tt2 = tt1;
                    change(i2, j2, k2, tt2);
                    if (is_sorted(tt2.begin(), tt2.end())) {
                      cout << "YES\n";
                      return;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << "NO\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    purple();
  }
}
