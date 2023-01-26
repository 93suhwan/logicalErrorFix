#include <bits/stdc++.h>
using namespace std;
long long int N = 1e5;
void test_case() {
  int n, k;
  cin >> n >> k;
  int s[3] = {0};
  vector<int> v(n);
  int x;
  cout << "or 1 2" << endl;
  cin >> x;
  s[0] += x;
  cout << "and 1 2" << endl;
  cin >> x;
  s[0] += x;
  cout << "or 1 3" << endl;
  cin >> x;
  s[1] += x;
  cout << "and 1 3" << endl;
  cin >> x;
  s[1] += x;
  cout << "or 2 3" << endl;
  cin >> x;
  s[2] += x;
  cout << "and 2 3" << endl;
  cin >> x;
  s[2] += x;
  v.push_back((s[0] + s[1] - s[2]) / 2);
  v.push_back(s[0] - v[0]);
  v.push_back(s[1] - v[0]);
  for (int i = 4; i <= n; i++) {
    int sum = 0;
    cout << "or " << 1 << ' ' << i << endl;
    cin >> x;
    if (x == -1) return;
    sum += x;
    cout << "and " << 1 << ' ' << i << endl;
    cin >> x;
    if (x == -1) return;
    sum += x;
    v.push_back(sum - v[0]);
  }
  sort(v.begin(), v.end());
  k--;
  cout << v[k] << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    test_case();
  }
}
