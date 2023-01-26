#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  const long long inf = 1000000002;
  long long n, t, k, k1, k2, otv, m, m2;
  vector<long long> v(30, 0);
  string a, b;
  cin >> t;
  char w;
  vector<long long> v1;
  vector<long long> v2;
  while (t > 0) {
    v1.clear();
    v2.clear();
    t--;
    cin >> n;
    vector<long long> v(n);
    long long j = n;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
      cin >> w;
      if (w == 'R')
        v1.push_back(v[i]);
      else
        v2.push_back(v[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    k = v2.size();
    bool q = true;
    for (int i = 0; i < v1.size(); i++) {
      if (v1[i] > k + i + 1) {
        q = false;
        break;
      }
    }
    for (int i = 0; i < v2.size(); i++) {
      if (v2[i] < i + 1) {
        q = false;
        break;
      }
    }
    if (q == true)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
