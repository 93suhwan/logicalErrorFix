#include <bits/stdc++.h>
using namespace std;
void fast() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
}
long long md = 1000000007;
bool fn(string l, string r) {
  for (int i = 1; i <= l.size(); i++) {
    if (l[i - 1] != r[i - 1]) {
      return (i % 2 && r[i - 1] < l[i - 1] ||
              i % 2 == 0 && r[i - 1] > l[i - 1]);
    }
  }
}
int main() {
  fast();
  int n, k;
  cin >> n >> k;
  vector<string> s;
  map<string, int> m;
  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    s.push_back(a);
    m[a] = i + 1;
  }
  sort(s.begin(), s.end(), fn);
  reverse(s.begin(), s.end());
  for (auto i : s) {
    cout << m[i] << " ";
  }
}
