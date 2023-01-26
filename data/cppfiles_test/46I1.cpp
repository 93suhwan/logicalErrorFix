#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second 
#define pb push_back
#define mp make_pair
#define trash trash
#define ALL(x) x.begin(),x.end()
const int oo=1e9;
const int Mod=1e9+7;
const long long OO=1e18;
const int N=1e3+5;
void file()
{
    if(fopen("trash.inp", "r"))
        freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
      // else freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
}
int n , a[N];
void in()
{
  cin >> n;
  int ans = 0;
  for(int i=1; i<=n; i++)
  {
    cin >> a[i];
    if(i%2==0)ans += min(a[i-1], a[i]);
  }
  for(int i=2; i<=n; i+=2)
  {
    int balance = 0;
    for(int j=i+1; j<=n; j+=2)
      {
        int need_left = a[i] + (balance > 0 ? balance : 0);
        int need_right = a[j] + (balance < 0 ? -balance : 0);
        int ok = 1;
        if(a[i-1] < need_left)ok = 0;
        if(a[j+1] < need_right) ok = 0;
        if(ok)ans += min(a[i-1] - need_left + 1, a[j+1] - need_right + 1);
        balance -= a[j] - a[j+1];
      }
  }
  cout << ans ;
}
///////////////////1112<3/////////////////
void solve()
{

}
///////////////////1112<3/////////////////
 main()
{
    file();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
      in();
      solve();
}
