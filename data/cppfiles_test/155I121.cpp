#include <bits/stdc++.h>
using namespace std;
struct seq {
  char type;
  long long index;
  long long p;
  long long q;
};
bool cmp1(seq a, seq b) { return a.type < b.type; }
bool cmp2(seq a, seq b) { return a.p < b.p; }
bool cmp3(seq a, seq b) { return a.index < b.index; }
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    seq S[n];
    int num = 0;
    for (int j = 0; j < n; j++) {
      cin >> S[j].p;
      S[j].index = j + 1;
    }
    getchar();
    for (int j = 0; j < n; j++) {
      S[j].type = getchar();
      if (S[j].type == '0') num++;
    }
    sort(S, S + n, cmp1);
    if (num > 0) sort(S, S + num - 1, cmp2);
    if (num < n) sort(S + num, S + n, cmp2);
    for (int j = 0; j < n; j++) {
      S[j].q = j + 1;
    }
    sort(S, S + n, cmp3);
    for (int j = 0; j < n; j++) {
      cout << S[j].q << ' ';
    }
    cout << endl;
  }
  return 0;
}
