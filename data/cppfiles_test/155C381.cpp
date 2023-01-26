#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n], b[n];
    vector<long long> ones, zeroes;
    map<long long, long long> map;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
      map[a[i]] = i;
    }
    string s;
    cin >> s;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '0')
        zeroes.push_back(a[i]);
      else
        ones.push_back(a[i]);
    }
    sort(zeroes.rbegin(), zeroes.rend());
    sort(ones.rbegin(), ones.rend());
    sort(a, a + n, greater<long long>());
    long long i;
    for (i = 0; i < ones.size(); i++) {
      b[map[ones[i]]] = a[i];
    }
    for (long long j = 0; j < zeroes.size(); j++) {
      b[map[zeroes[j]]] = a[i];
      i++;
    }
    for (long long i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;
  }
  return 0;
}
