#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 2e5 + 10;
long long ans = 0;
void mergeSort(vector<long long> &v, int st, int end) {
  if (st == end) {
    return;
  }
  int mid = (st + end) / 2;
  mergeSort(v, st, mid);
  mergeSort(v, mid + 1, end);
  vector<int> a, b;
  for (int i = st; i <= mid; i++) {
    a.push_back(v[i]);
  }
  for (int i = mid + 1; i <= end; i++) {
    b.push_back(v[i]);
  }
  int i = 0, j = 0, curr = st;
  int aa = a.size(), bb = b.size();
  while (i < aa or j < bb) {
    if (i < aa and j < bb and a[i] <= b[j]) {
      v[curr++] = a[i++];
    } else if (i < aa and j < bb and a[i] > b[j]) {
      v[curr++] = b[j++];
      ans += aa - i;
    } else if (i < aa) {
      v[curr++] = a[i++];
    } else {
      v[curr++] = b[j++];
    }
  }
}
long long countInversions(vector<long long> &v, int n) {
  mergeSort(v, 0, n - 1);
  return ans;
}
void test_case() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  ans = 0;
  countInversions(v, n);
  set<long long> st(v.begin(), v.end());
  if (st.size() < n or ans % 2 == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    test_case();
  }
  return 0;
}
