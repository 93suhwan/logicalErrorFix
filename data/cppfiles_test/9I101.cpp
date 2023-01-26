#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define m7 1000000007
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a; i<b; i++)
#define forn(n) for(int i=0; i<n; i++)

void fastIO(){ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

bool pof2(int n){ if(n & n-1) return false; return true; }

int main() {

    fastIO();

    

        int n, m, k; cin >> n >> m >> k;
        int a[n][m];
        int b[k];
        int c[m] = {};

        rep(i,0,n)
            rep(j,0,m){
                cin >> a[i][j];
                if(a[i][j] == 2)
                    c[j]++;
            }

        forn(k){
            cin >> b[i];
            b[i]--;
        }

        int ans[n];
        forn(k){
            int x = 0, y = b[i];
            if(c[y] == n)
                ans[i] = y;
            else{
                while(x < n){
                    if(a[x][y] == 1){
                        a[x][y] = 2;
                        c[y]++;
                        y += 1;
                    }
                    else if(a[x][y] == 3){
                        a[x][y] = 2;
                        c[y]++;
                        y -= 1;
                    }
                    else
                        x += 1;
                }
                ans[i] = y;
            }
        }

        forn(k)
            cout << ans[i] + 1 << ' ';
        cout << endl;
    
}