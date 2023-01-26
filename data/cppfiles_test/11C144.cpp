#include <bits/stdc++.h>
using namespace std;
const int N = 201005;
struct WordA {
  int cnt[5];
  bool operator<(const WordA &a) const {
    if (cnt[0] != a.cnt[0])
      return cnt[0] > a.cnt[0];
    else {
      int sum = 0;
      int suma = 0;
      for (int i = 0; i < (int)(5); ++i) {
        sum += cnt[i];
        suma += a.cnt[i];
      }
      return sum < suma;
    }
  }
} WordsA[N];
struct WordB {
  int cnt[5];
  bool operator<(const WordB &a) const {
    if (cnt[1] != a.cnt[1])
      return cnt[1] > a.cnt[1];
    else {
      int sum = 0;
      int suma = 0;
      for (int i = 0; i < (int)(5); ++i) {
        sum += cnt[i];
        suma += a.cnt[i];
      }
      return sum < suma;
    }
  }
} WordsB[N];
struct WordC {
  int cnt[5];
  bool operator<(const WordC &a) const {
    if (cnt[2] != a.cnt[2])
      return cnt[2] > a.cnt[2];
    else {
      int sum = 0;
      int suma = 0;
      for (int i = 0; i < (int)(5); ++i) {
        sum += cnt[i];
        suma += a.cnt[i];
      }
      return sum < suma;
    }
  }
} WordsC[N];
struct WordD {
  int cnt[5];
  bool operator<(const WordD &a) const {
    if (cnt[3] != a.cnt[3])
      return cnt[3] > a.cnt[3];
    else {
      int sum = 0;
      int suma = 0;
      for (int i = 0; i < (int)(5); ++i) {
        sum += cnt[i];
        suma += a.cnt[i];
      }
      return sum < suma;
    }
  }
} WordsD[N];
struct WordE {
  int cnt[5];
  bool operator<(const WordE &a) const {
    if (cnt[4] != a.cnt[4])
      return cnt[4] > a.cnt[4];
    else {
      int sum = 0;
      int suma = 0;
      for (int i = 0; i < (int)(5); ++i) {
        sum += cnt[i];
        suma += a.cnt[i];
      }
      return sum < suma;
    }
  }
} WordsE[N];
int Calc(vector<string> v, char C) {
  vector<int> a;
  int sum = 0;
  int ret = 0;
  for (string x : v) {
    int tmp = 0;
    for (char y : x) {
      if (y == C)
        tmp++;
      else
        tmp--;
    }
    if (tmp > 0) {
      ret++;
      sum += tmp;
    } else {
      a.push_back(tmp);
    }
  }
  sort(a.begin(), a.end(), greater<int>());
  for (int x : a) {
    if (sum + x > 0) {
      ret++;
      sum += x;
    }
  }
  return ret;
}
void solve() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<string> vs(n);
    for (int i = 0; i < (int)(n); ++i) {
      cin >> vs[i];
    }
    int ret = 0;
    ret = max(ret, Calc(vs, 'a'));
    ret = max(ret, Calc(vs, 'b'));
    ret = max(ret, Calc(vs, 'c'));
    ret = max(ret, Calc(vs, 'd'));
    ret = max(ret, Calc(vs, 'e'));
    cout << ret << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(13);
  solve();
  return 0;
}
