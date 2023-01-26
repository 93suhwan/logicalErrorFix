#include <bits/stdc++.h>
using namespace std;
long long t;
long long dd[200005];
struct hdz {
  long long i, j;
};
hdz A[200005];
bool cmp(hdz a, hdz b) { return a.j < b.j; }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n + 2];
    map<long long, long long> m;
    vector<long long> v[n + 2];
    set<long long> s;
    for (long long i = 1; i <= n; i++) {
      dd[i] = 0;
      A[i].i = 0;
      A[i].j = 0;
      cin >> a[i];
      m[a[i]]++;
      v[a[i]].push_back(i);
      s.insert(a[i]);
    }
    long long tmp = 0;
    for (long long i : s) {
      A[++tmp].i = i;
      A[tmp].j = m[i];
    }
    if (k == n) {
      for (long long i = 1; i <= n; i++) {
        cout << i << ' ';
      }
      cout << '\n';
      continue;
    }
    sort(A + 1, A + 1 + tmp, cmp);
    for (long long i = tmp; i >= 1; i--) {
      long long tmp = k;
      if (tmp > A[i].j) {
        long long d = 0;
        long long res = 0;
        bool kt = false;
        for (long long j = i; j >= 1; j--) {
          res += A[j].j;
          if (res >= tmp) {
            kt = true;
            break;
          }
        }
        long long j = i;
        if (kt)
          while (1) {
            if (tmp > A[j].j) {
              tmp -= A[j].j;
              A[j].j = 0;
              for (long long k = 0; k < v[A[j].i].size(); k++) {
                long long f = v[A[j].i][k];
                if (dd[f] != 0) continue;
                dd[f] = 1;
                a[f] = ++d;
              }
            } else {
              A[j].j = A[j].j - tmp;
              for (long long q = 0; q < v[A[j].i].size(); q++) {
                long long f = v[A[j].i][q];
                if (dd[f] != 0) continue;
                dd[f] = 1;
                if (d == k) break;
                a[f] = ++d;
              }
              break;
            }
            j--;
          }
      } else {
        long long d = 0;
        for (long long j = 0; j < (long long)v[A[i].i].size(); j++) {
          if (d == k) break;
          long long f = v[A[i].i][j];
          if (dd[f] != 0) continue;
          dd[f] = 1;
          a[f] = ++d;
        }
      }
    }
    for (long long i = 1; i <= n; i++) {
      if (dd[i] != 0)
        cout << a[i] << ' ';
      else
        cout << 0 << ' ';
    }
    cout << '\n';
  }
}
