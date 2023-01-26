#include <bits/stdc++.h>                                           

using namespace std;

#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define mp make_pair
#define f first
#define s second

const int N = (int)1e6 + 100;
const int M = (int)1e4 + 100;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

 
int n, dp[M], f[M];
pii a[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].f, a[i].s = i;
    sort(a + 1, a + n + 1);

    for(int i = 0; i < M; i++) f[i] = inf;
    f[0] = -1;                            

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i].f == a[i - 1].f){
            cnt++;
        }else{
            cnt = 0;
        }
        
        if(cnt >= 20) continue;
        
        for(int val = 0; val < M; val++){
            if(f[val] < a[i].s)
                f[val ^ a[i].f] = min(f[val ^ a[i].f], a[i].s);
        }        
    }

    int ans = 0;
    for(int i = 0; i < M; i++)
        ans += (f[i] != inf);

    cout << ans << "\n";
    for(int i = 0; i < M; i++)
        if(f[i] != inf)
            cout << i << " ";
    
    cout << "\n";
}

main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  //cin >> t;
  while (t--) 
    solve();
}