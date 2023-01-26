#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  vector<pair<long long, long long>> v;
  for (long long i = 2; i <= n; i++) {
    long long ans1, ans2;
    cout << "and " << 1 << " " << i << endl;
    cin >> ans1;
    cout << "or " << 1 << " " << i << endl;
    cin >> ans2;
    v.push_back({ans1 + ans2, i});
  }
  long long ans1, ans2;
  cout << "and " << 2 << " " << 3 << endl;
  cin >> ans1;
  cout << "or " << 2 << " " << 3 << endl;
  cin >> ans2;
  v.push_back({((v[0].first + v[1].first) - (ans1 + ans2)), 1});
  sort(v.begin(), v.end());
  cout << "finish " << v[k - 1].second << endl;
}
