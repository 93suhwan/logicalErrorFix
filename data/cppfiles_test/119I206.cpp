#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using  namespace std;

#define int           long long
#define vi            vector<int>
#define vpii          vector<pair<int,int>>
#define pii           pair<int,int>
#define all(x)        x.begin(), x.end()
#define ms            multiset
#define pb            push_back
#define pob           pop_back
#define ff            first
#define ss            second
#define setbits(x)    __builtin_popcountll(x)
#define stp(x)        fixed << setprecision(x)
#define fast          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf           1e18
#define mod           1000000007

typedef tree<vpii, null_type, less<vpii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void io(){
  fast

  #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif
}

int32_t main() {

  io();

  int t = 1;
  cin>>t;
  while(t--){
    int n; cin >> n;
    vi a(n);
    int sum = 0;

    for(int i = 0; i < n; i++) cin >>  a[i], sum += a[i];

    cout << sum << " ";
    if(sum % n >= 1)
    {
      cout << 1 << '\n';
    }
    else
    {
      cout << 0 << '\n';  
    }
  }
  return 0;
}