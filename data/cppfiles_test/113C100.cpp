#include <bits/stdc++.h>
using namespace std;
long long get(vector<long long>& arr, vector<long long>& v, long long a,
              long long d, long long index) {
  long long n = arr.size();
  if (index >= 0 and index < n) {
    return max(0LL, d - v[index]);
  }
  if (index == n) {
    long long curr = a - arr.back();
    curr += (long long)max(0LL, d - v.back());
    return curr;
  } else if (index == 0LL) {
    long long curr = a - arr[0];
    curr += (long long)max(0LL, d - v[0]);
    return curr;
  }
  return 9223372036854775807LL;
}
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
  vector<pair<long long, long long> > store;
  vector<long long> ans(m, 9223372036854775807LL);
  for (long long i = 0; i < m; i++) {
    long long defense, attack;
    cin >> attack >> defense;
    store.push_back({attack, defense});
    long long index =
        lower_bound((arr).begin(), (arr).end(), attack) - arr.begin();
    if (index != n) {
      ans[i] = min(ans[i], max(0LL, defense - v[index]));
    } else {
      long long curr = attack - arr.back();
      curr += (long long)max(0LL, defense - v.back());
      ans[i] = min(ans[i], curr);
    }
    index = lower_bound((v1).begin(), (v1).end(), defense) - v1.begin();
    if (index != n) {
      ans[i] = min(ans[i], max(0LL, attack - arr1[index]));
    } else {
      long long curr = defense - v1.back();
      curr += (long long)max(0LL, attack - arr1.back());
      ans[i] = min(ans[i], curr);
    }
  }
  for (long long i = 0; i < m; i++) {
    long long defense = store[i].second, attack = store[i].first;
    long long index =
        lower_bound((arr).begin(), (arr).end(), attack) - arr.begin();
    index--;
    if (index >= 0) {
      long long curr = attack - arr[index];
      curr += (long long)max(0LL, defense - v[index]);
      ans[i] = min(ans[i], curr);
    }
    index = lower_bound((v1).begin(), (v1).end(), defense) - v1.begin();
    index--;
    if (index >= 0) {
      long long curr = defense - v1[index];
      curr += (long long)max(0LL, attack - arr1[index]);
      ans[i] = min(ans[i], curr);
    }
    cout << ans[i] << "\n";
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
