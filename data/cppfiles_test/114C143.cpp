#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    unordered_set<long long> st(v.begin(), v.end());
    long long req = n / 2;
    for (long long i = 0; i < n; i++) {
      for (long long j = i + 1; j < n; j++) {
        if (st.find(v[j] % v[i]) == st.end()) {
          cout << v[j] << " " << v[i] << endl;
          req--;
        }
        if (req == 0) break;
      }
      if (req == 0) break;
    }
  }
  return 0;
}
