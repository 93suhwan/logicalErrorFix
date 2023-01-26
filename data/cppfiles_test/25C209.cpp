#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
int q, n, m;
string s, t;
long long compute_hash(string const& s) {
  const long long p = 31;
  const long long m = 1e9 + 9;
  long long hash_value = 0;
  long long p_pow = 1;
  for (char c : s) {
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return hash_value;
}
void solve() {
  n = s.length();
  m = t.length();
  if (s == t) {
    cout << "YES";
    return;
  }
  const long long p = 31;
  const long long m = 1e9 + 9;
  long long hashT = compute_hash(t);
  for (int i = 0; i < n; i++) {
    if (s[i] == t[0]) {
      long long hash_value = 0;
      long long p_pow = 1;
      for (int j = i; j >= 0; j--) {
        hash_value = (hash_value + (s[j] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        if (hash_value == hashT) {
          cout << "YES";
          return;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == t[0]) {
      long long hash_value = 0;
      long long p_pow = 1;
      for (int j = i; j < n; j++) {
        hash_value = (hash_value + (s[j] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        long long temp_hash = hash_value;
        long long temp_pow = p_pow;
        if (temp_hash == hashT) {
          cout << "YES";
          return;
        }
        for (int k = j - 1; k >= 0; k--) {
          temp_hash = (temp_hash + (s[k] - 'a' + 1) * temp_pow) % m;
          temp_pow = (temp_pow * p) % m;
          if (temp_hash == hashT) {
            cout << "YES";
            return;
          }
        }
      }
    }
  }
  cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> q;
  while (q--) {
    cin >> s >> t;
    solve();
    cout << "\n";
  }
  return 0;
}
