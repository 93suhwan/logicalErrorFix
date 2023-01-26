#include <bits/stdc++.h>
using namespace std;
void printv(vector<string>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}
void assign(vector<int>& v, int n, int i) {
  while (n < v.size()) {
    if (v[n] == 0) {
      v[n] = i;
    } else {
      break;
    }
    n += n & (-n);
  }
}
int check(vector<int>& v, int n) {
  while (n > 0) {
    if (v[n] > 0) {
      return v[n];
    }
    n -= n & (-n);
  }
  return 0;
}
vector<string> myPrint(int n) {
  if (n == 1) {
    return {"()"};
  } else {
    vector<string> v = myPrint(n - 1);
    string t = v[0];
    for (int i = 0; i < v.size(); i++) {
      v[i] = v[i] + "()";
    }
    v.push_back("(" + t + ")");
    return v;
  }
}
int main() {
  int ti;
  cin >> ti;
  while (ti--) {
    int n;
    cin >> n;
    vector<string> v = myPrint(n);
    printv(v);
  }
}
