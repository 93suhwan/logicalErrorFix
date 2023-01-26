#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &output, const vector<T> &v) {
  if (v.empty()) return output;
  for (int i = 0; i < v.size() - 1; i++) output << v[i] << " ";
  output << v.back();
  return output;
}
template <typename T>
istream &operator>>(istream &input, vector<T> &v) {
  for (auto &i : v) cin >> i;
  return input;
}
void __sol() {
  int n;
  cin >> n;
  vector<int> v(n);
  cin >> v;
  int right = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (v[i] > v[i + 1])
      right++;
    else
      break;
  }
  int left = 1;
  for (int i = 1; i < n; i++) {
    if (v[i - 1] < v[i])
      left++;
    else
      break;
  }
  if (left & 1 && right & 1)
    cout << "Alice";
  else if (left % 2 == right % 2)
    cout << "Bob";
  else
    cout << "Alice";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  while (tc--) __sol();
  return 0;
}
