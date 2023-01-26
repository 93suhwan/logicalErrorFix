#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TT;
  cin >> TT;
  for (int tt = 1; tt <= TT; tt++) {
    cin >> n;
    a.resize(n);
    for (auto& i : a) cin >> i;
    cin >> s;
    vector<long long> r, b;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R')
        r.push_back(a[i]);
      else
        b.push_back(a[i]);
    }
    sort(r.begin(), r.end(), greater<long long>());
    sort(b.begin(), b.end());
    bool yes = 1;
    for (int i = 0; i < b.size(); i++) {
      if (b[i] < i + 1) yes = 0;
    }
    for (int i = 0; i < r.size(); i++) {
      if (r[i] > n - i) yes = 0;
    }
    cout << (yes ? "yes\n" : "no\n");
  }
  return 0;
}
