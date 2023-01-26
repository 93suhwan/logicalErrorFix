#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void test() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string a;
  a = s;
  sort(s.begin(), s.end());
  int count = 0;
  int size = s.length();
  for (int i = 0; i < size; i++) {
    if (s[i] != a[i]) count++;
  }
  cout << count << endl;
}
int main() {
  init_code();
  int t;
  cin >> t;
  ;
  while (t--) {
    test();
  }
}
