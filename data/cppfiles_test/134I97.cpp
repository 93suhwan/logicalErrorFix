#include<bits/stdc++.h>

using namespace std;

#define db(m)  cout<<#m<<" = "<<m<<"\n"

void bang() {
  int n;
  cin >> n;
  vector<long long> v(n);
  vector<long long> temp;
  for(int i = 0; i < n; i++) cin >> v[i];
  temp = v;
  long long GCD = 0;
  for(int i = 0; i < n; i++) GCD = __gcd(v[i], GCD);
  for(int i = 0; i < n; i++) temp[i] /= GCD;
  for(int i = 1; i < n; i++) {
    if(temp[i] == temp[i - 1]) {
      cout << 0 << "\n";
      return;
    }
  }
  for(int i = 0; i < n; i++) {
    if(v[i] == 1) continue;
    vector<int> marked(n, 0);
    long long k = v[i];
    for(int j = 0; j < n; j++) {
      if(v[j] % k == 0) {
        marked[j] = 1;
      }
    }
    bool flag = false;
    for(int j = 1; j < n; j++) {
      if(marked[j] == marked[j - 1]) {
        flag = true;
        break;
      }
    }
    if(!flag) {
      cout << k << "\n";
      return;
    }
  }
  cout << 0 << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int q; cin >> q;
  while(q--)
    bang();
    
  return 0;
}
