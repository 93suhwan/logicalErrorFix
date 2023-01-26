#include <bits/stdc++.h>
using namespace std;
long long query(long long a, long long b, long long c) {
  cout << "? " << a << " " << b << " " << c << endl;
  long long r;
  cin >> r;
  return r;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 1], role[n + 1];
    for (long long i = 1; i <= n; i++) role[i] = -1;
    for (long long i = 1; i + 2 <= n; i += 3) a[i] = query(i, i + 1, i + 2);
    long long imp, crew;
    for (long long i = 1; i + 5 <= n; i += 3) {
      if (a[i] != a[i + 3]) {
        a[i + 1] = query(i + 1, i + 2, i + 3),
              a[i + 2] = query(i + 2, i + 3, i + 4);
        for (long long j = i; j < (i + 3); j++) {
          if (a[j] != a[j + 1]) {
            if (a[j] == 0) {
              imp = j;
              crew = j + 3;
              role[j] = 0;
              role[j + 3] = 1;
            } else {
              imp = j + 3;
              crew = j;
              role[j] = 1;
              role[j + 3] = 0;
            }
          }
        }
        break;
      }
    }
    for (long long i = 1; i + 2 <= n; i += 3) {
      if (i == imp || (i + 1) == imp || (i + 2) == imp || i == crew ||
          (i + 1) == crew || (i + 2) == crew) {
        for (long long j = i; j < (i + 3); j++) {
          if (role[j] == -1) {
            role[j] = query(j, crew, imp);
          }
        }
      } else {
        if (a[i] == 0) {
          if (query(i, i + 1, crew) == 1) {
            if (query(i, crew, imp) == 1)
              role[i] = 1, role[i + 1] = 0;
            else
              role[i] = 0, role[i + 1] = 1;
            role[i + 2] = 0;
          } else {
            role[i] = 0, role[i + 1] = 0;
            role[i + 2] = query(i + 2, crew, imp);
          }
        } else {
          if (query(i, i + 1, imp) == 0) {
            if (query(i, crew, imp) == 1)
              role[i] = 1, role[i + 1] = 0;
            else
              role[i] = 0, role[i + 1] = 1;
            role[i + 2] = 1;
          } else {
            role[i] = 1, role[i + 1] = 1;
            role[i + 2] = query(i + 2, crew, imp);
          }
        }
      }
    }
    vector<long long> v;
    for (long long i = 1; i <= n; i++)
      if (role[i] == 0) v.push_back(i);
    cout << "! " << v.size() << ' ';
    for (long long i = 0; i < v.size(); i++) {
      cout << v[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
