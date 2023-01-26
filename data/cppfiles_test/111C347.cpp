#include <bits/stdc++.h>
using namespace std;
int N;
void exe(int tc) {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) cout << '(';
    for (int j = 0; j < i; j++) cout << ')';
    for (int j = i; j < N; j++) cout << '(';
    for (int j = i; j < N; j++) cout << ')';
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; i++) exe(i);
}
