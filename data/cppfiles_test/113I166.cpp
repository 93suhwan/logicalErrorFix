#include <bits/stdc++.h>
using namespace std;
void Saraff() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort((arr).begin(), (arr).end());
  long long sum = accumulate((arr).begin(), (arr).end(), 0LL);
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    v.push_back(sum - arr[i]);
  }
  vector<long long> arr1((arr).begin(), (arr).end());
  vector<long long> v1((v).begin(), (v).end());
  reverse((arr1).begin(), (arr1).end());
  reverse((v1).begin(), (v1).end());
  long long m;
  cin >> m;
  while (m--) {
    long long ans = 9223372036854775807LL, defense, attack;
    cin >> attack >> defense;
    long long index =
        lower_bound((arr).begin(), (arr).end(), attack) - arr.begin();
    if (index != n) {
      ans = min(ans, max(0LL, defense - v[index]));
    } else {
      long long curr = attack - arr.back();
      curr += (long long)max(0LL, defense - v.back());
      ans = min(ans, curr);
    }
    index = lower_bound((v1).begin(), (v1).end(), defense) - v1.begin();
    if (index != n) {
      ans = min(ans, max(0LL, attack - arr1[index]));
    } else {
      long long curr = defense - v1.back();
      curr += (long long)max(0LL, attack - arr1.back());
      ans = min(ans, curr);
    }
    cout << ans << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  long long test = 1;
  for (long long t = 1; t <= test; t++) {
    Saraff();
  }
}
