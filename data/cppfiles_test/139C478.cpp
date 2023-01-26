#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
long long int ceil(long long int r, long long int d) {
  return (r / d) + (bool)(r % d);
}
void inputAArray(int siz, vector<int> &arr) {
  for (int i = 0; i < siz; i++) arr[i] = 1 + rand();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (n & 1) {
      cout << "NO" << endl;
      continue;
    }
    if (s.substr(0, n / 2) == s.substr(n / 2))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
