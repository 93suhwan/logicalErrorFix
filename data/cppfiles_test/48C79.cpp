#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
const long long N = 1e5 + 5;
long long n, m, t, u, v, k, l;
map<long long, long long> mp;
vector<long long> a;
vector<long long> sorted_a;
void place(long long j, long long i) {
  long long k;
  if (i + 1 != j) {
    k = i + 1;
  } else {
    k = i + 2;
  }
  long long temp = a[i];
  a[i] = a[j];
  mp[a[i]] = i;
  a[j] = a[k];
  mp[a[j]] = j;
  a[k] = temp;
  mp[a[k]] = k;
}
void solve(long long tc) {
  cin >> n;
  mp.clear();
  a = vector<long long>(n);
  for (int i = 0; i < (int)(n); ++i) {
    cin >> a[i];
    mp[a[i]] = i;
  }
  sorted_a = a;
  {
    sort((sorted_a).begin(), (sorted_a).end());
    sorted_a.erase(unique((sorted_a).begin(), (sorted_a).end()),
                   sorted_a.end());
  };
  if (int((sorted_a).size()) != int((a).size())) {
    cout << "YES\n";
    return;
  }
  for (int i = 0; i < (int)(n); ++i) {
    if (sorted_a[i] != a[i]) {
      if (i >= n - 2) {
        cout << "NO\n";
        return;
      }
      place(mp[sorted_a[i]], i);
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  t = 1;
  cin >> t;
  for (int i = 0; i < (int)(t); ++i) {
    solve(t);
  }
}
