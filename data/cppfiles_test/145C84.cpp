#include <bits/stdc++.h>
using namespace std;
int n, k;
const int max_n = 2e5 + 2;
int arr[max_n];
int piv[max_n];
int get(int x) {
  if (piv[x] == x)
    return x;
  else
    return piv[x] = get(piv[x]);
}
void merge(int a, int b) {
  int A = get(a);
  int B = get(b);
  if (A == B) return;
  if (arr[B] < arr[A]) swap(A, B);
  piv[B] = A;
}
void solve() {
  cin >> n >> k;
  map<int, vector<pair<int, int> > > mx, my;
  int x, y, t;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y >> t;
    arr[i] = t;
    mx[x].push_back(make_pair(y, i));
    my[y].push_back(make_pair(x, i));
  }
  for (int i = 1; i <= n; i++) piv[i] = i;
  for (auto now : mx) {
    vector<pair<int, int> > v = now.second;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++) {
      if (v[i + 1].first - v[i].first <= k) merge(v[i + 1].second, v[i].second);
    }
  }
  for (auto now : my) {
    vector<pair<int, int> > v = now.second;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++) {
      if (v[i + 1].first - v[i].first <= k) merge(v[i + 1].second, v[i].second);
    }
  }
  vector<int> time;
  for (int i = 1; i <= n; i++) {
    if (piv[i] == i) time.push_back(arr[i]);
  }
  sort(time.begin(), time.end());
  int mn = time.size() - 1;
  for (int i = 0; i < time.size(); i++) {
    mn = min(mn, max(time[i], (int)(time.size() - i - 2)));
  }
  cout << mn << "\n";
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
