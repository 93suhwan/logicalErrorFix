#include <bits/stdc++.h>
using namespace std;
long s = 0;
void solve(long n, long d) {
  if (n >= d) {
    if (n % d == 0)
      s++;
    else {
      solve(n, d * 10 + 7);
      solve(n, d * 10 + 4);
    }
  } else
    return;
}
int main() {
  long n, i, j, k, b, t, c = 1, a;
  double sum = 0;
  vector<long> vect;
  string s1, s2, str = "";
  cin >> t;
  unordered_set<long> s;
  map<long, vector<long>> pam;
  while (t--) {
    s.clear();
    vect.clear();
    pam.clear();
    cin >> n >> k;
    vector<long> vect(n);
    long d = 0;
    for (i = 0; i < n; i++) {
      cin >> a;
      pam[a].push_back(i);
      s.insert(a);
      if (pam[a].size() > k) d++;
    }
    b = k;
    auto it = s.begin();
    b = 1;
    long m = n - n % k;
    j = 0;
    d = d - n % k;
    if (d >= 0)
      j = ceil(d * 1.0 / k);
    else
      j = 0;
    do {
      m = n - n % k - (j++) * k;
      b = 1;
      it = s.begin();
      while (it != s.end()) {
        c = pam[*it].size() - k;
        for (auto x : pam[*it]) {
          if (c-- > 0) {
            vect[x] = 0;
            continue;
          }
          if (m > 0) {
            vect[x] = b++;
            if (b > k) b = 1;
            m--;
          } else
            vect[x] = 0;
        }
        it++;
      }
    } while (m > 0);
    for (auto x : vect) cout << x << " ";
    cout << endl;
  }
}
