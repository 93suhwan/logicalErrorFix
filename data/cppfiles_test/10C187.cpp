#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    map<long long, vector<long long>> mp;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]].push_back(i);
    }
    long long col[n];
    memset(col, 0, sizeof(col));
    vector<long long> vect;
    for (auto i : mp) {
      auto v1 = i.second;
      if (v1.size() >= k) {
        long long c = 0;
        for (auto j : v1) {
          if (c < k) {
            col[j] = c + 1;
            c++;
          } else {
            break;
          }
        }
      } else {
        for (auto j : v1) {
          vect.push_back(j);
        }
      }
    }
    long long z = vect.size();
    z = z / k;
    long long p = 0;
    for (long long i = 0; i < z; i++) {
      for (long long j = 0; j < k; j++) {
        col[vect[p++]] = j + 1;
      }
    }
    for (long long i = 0; i < n; i++) {
      cout << col[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
