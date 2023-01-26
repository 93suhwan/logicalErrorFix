#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long double PI = acos((long double)-1);
string mat[55];
void solve(int tc = 1) {
  long long n;
  string s;
  cin >> n >> s;
  long long cnt[3] = {0};
  for (long long i = 0; i < n; i++) {
    ++cnt[s[i] - '0'];
  }
  for (long long i = 0; i < n; i++) {
    mat[i] = string(n, '=');
    mat[i][i] = 'X';
  }
  if (cnt[2] == 1 || cnt[2] == 2) {
    cout << "NO" << '\n';
    return;
  } else if (cnt[2] >= 3) {
    vector<long long> inds;
    for (long long i = 0; i < n; ++i) {
      if (s[i] == '2') inds.push_back(i);
    }
    for (long long i = 0; i < inds.size(); ++i) {
      long long next = (i + 1) % inds.size();
      mat[inds[i]][inds[next]] = '+';
      mat[inds[next]][inds[i]] = '-';
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) cout << mat[i] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
  return 0;
}
