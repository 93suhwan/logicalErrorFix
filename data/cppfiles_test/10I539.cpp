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
    long m = n % k;
    for (i = 0; i < n; i++) {
      cin >> a;
      pam[a].push_back(i);
      s.insert(a);
    }
    b = k;
    auto it = s.begin();
    b = 1;
    while (it != s.end()) {
      for (auto x : pam[*it]) {
        if (m-- > 0)
          vect[x] = 0;
        else {
          vect[x] = b++;
          if (b > k) b = 1;
        }
      }
      it++;
    }
    for (auto x : vect) cout << x << " ";
    cout << endl;
  }
}
