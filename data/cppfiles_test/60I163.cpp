#include <bits/stdc++.h>
using namespace std;
long long int INF = 1000000000000000000;
long long int mod = 1000000007;
void fun() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  long long int i, j;
  long long int sum = 0;
  map<long long int, long long int> m;
  set<long long int> s;
  for (i = 0; i < n; i++) {
    cin >> v[i];
    m[v[i]]++;
    sum += v[i];
    s.insert(v[i]);
  }
  sort(v.begin(), v.end());
  sum = 2 * sum / n;
  long long int count = 0;
  for (auto k : s) {
    long long int k1 = sum - k;
    if (k1 < k) continue;
    if (k1 == k) {
      if (m[k] > 1) {
        count += (m[k] * (m[k] - 1)) / 2;
      }
    } else {
      count += (m[k] * m[k1]);
    }
  }
  cout << count << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    fun();
  }
  return 0;
}
