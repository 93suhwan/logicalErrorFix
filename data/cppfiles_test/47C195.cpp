#include <bits/stdc++.h>
using namespace std;
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << "\n"; }
void Yes(bool t = 1) { cout << YesNo[t] << "\n"; }
void yes(bool t = 1) { cout << yesno[t] << "\n"; }
const long long mod = 1e9 + 7;
const long long mxN = 2e6 + 5;
long long n, m;
long long a[mxN], b[mxN];
string s, t;
void code() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> v1, v2;
  for (long long i = 0; i < n; i++) {
    if (a[i] < 0) {
      v1.push_back(-a[i]);
    } else {
      v2.push_back(a[i]);
    }
  }
  if (v1.size()) sort(v1.begin(), v1.end());
  if (v2.size()) sort(v2.begin(), v2.end());
  long long cnt = m;
  long long j = (long long)v1.size() - 1;
  vector<long long> v;
  while (j >= 0) {
    v.push_back(v1[j]);
    while (j >= 0 && cnt--) j--;
    cnt = m;
  }
  j = (long long)v2.size() - 1;
  cnt = m;
  while (j >= 0) {
    v.push_back(v2[j]);
    while (j >= 0 && cnt--) j--;
    cnt = m;
  }
  long long ans = 0;
  sort(v.begin(), v.end());
  for (long long i = 0; i < (long long)v.size() - 1; i++) ans += v[i];
  cout << 2 * ans + v[(long long)v.size() - 1] << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) code();
}
