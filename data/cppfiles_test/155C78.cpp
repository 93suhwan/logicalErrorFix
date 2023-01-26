#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
void sol() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  string s;
  cin >> s;
  vector<long long int> l, h;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == '0')
      l.push_back(v[i]);
    else
      h.push_back(v[i]);
  }
  sort(l.begin(), l.end());
  sort(h.begin(), h.end());
  long long int p = 1;
  map<long long int, long long int> m;
  for (auto &i : l) {
    m[i] = p;
    p++;
  }
  for (auto &i : h) {
    m[i] = p;
    p++;
  }
  for (long long int i = 0; i < n; i++) {
    cout << m[v[i]] << " ";
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    sol();
  }
  return 0;
}
