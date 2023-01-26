#include <bits/stdc++.h>
using namespace std;
struct seq {
  int type;
  long long index;
  long long p;
  long long q;
};
bool cmp1(seq a, seq b) {
  if (a.type != b.type)
    return a.type < b.type;
  else
    return a.p < b.p;
}
bool cmp2(seq a, seq b) { return a.index < b.index; }
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    seq S[n];
    for (int j = 0; j < n; j++) {
      cin >> S[j].p;
      S[j].index = j + 1;
    }
    getchar();
    for (int j = 0; j < n; j++) {
      scanf("%1d", &S[j].type);
    }
    sort(S, S + n, cmp1);
    for (int j = 0; j < n; j++) {
      S[j].q = j + 1;
    }
    sort(S, S + n, cmp2);
    for (int j = 0; j < n; j++) {
      cout << S[j].q << ' ';
    }
    cout << endl;
  }
  return 0;
}
