#include <bits/stdc++.h>
using namespace std;
int N, arr[200005], l, r, x;
string s;
bool lb, rb;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + N);
  cin >> s;
  lb = rb = s[0] == 'L';
  for (int i = 1; i < N; ++i) {
    x += s[i] != s[i - 1];
  }
  l = r = x;
  cout << arr[x] << " " << s[0] << endl;
  for (int i = 1; i < N; ++i) {
    if (s[i] != s[i - 1]) {
      cout << arr[++r] << " " << ("RL"[rb ^= 1]) << endl;
    } else {
      cout << arr[--l] << " " << ("RL"[lb ^= 1]) << endl;
    }
  }
  return 0;
}
