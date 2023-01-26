#include <bits/stdc++.h>
const long long N = 2e5 + 1;
using namespace std;
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void init_code() {}
signed main() {
  startTime = clock();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      mp[v[i]] = i;
    }
    if (mp.size() < n) {
      cout << "YES"
           << "\n";
      continue;
    }
    vector<long long> temp = v;
    sort(temp.begin(), temp.end());
    long long swaps = 0;
    for (long long i = 0; i < n; i++) {
      if (temp[i] != v[i]) {
        swaps++;
        long long pos = mp[temp[i]];
        mp[temp[i]] = i;
        mp[v[i]] = pos;
        swap(v[i], v[pos]);
      }
    }
    if (swaps % 2)
      cout << "NO";
    else
      cout << "YES";
    cout << "\n";
  }
}
