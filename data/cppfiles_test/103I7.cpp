#include <bits/stdc++.h>
#define fer(i,a,b) for(re i = a ; i <= b ; ++ i)
#define der(i,a,b) for(re i = a ; i >= b ; -- i)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define sf(x) scanf("%lld",&x)
#define pll pair<int,int> 
#define re register int
#define int long long 
#define pb push_back
#define y second 
#define x first 
using namespace std;
inline void sf2(int &a , int &b) { sf(a) , sf(b) ;}
inline void sf3(int n , int a[]) {fer(i,1,n) sf(a[i]);} ;
inline void de(auto x) {cout << x << "\n" ;}
inline void de2(auto a , auto b) {cout << a << " " << b << "\n" ;}
inline void de3(int n , auto a[]){fer(i,1,n) cout << a[i] << " " ;puts("");}
inline void mo(int &a , int b) {a = (a % b + b) % b ;}
inline int gcd(int a,int b){return b ? gcd(b , a % b) : a ;}
inline int qpow(int a,int b,int c){int res=1%c;a%=c;while(b>0){if(b&1)res=res*a%c;a=a*a%c;b>>=1;}return res;}
inline int qadd(int a,int b,int c){int res=0;a%=c;while(b>0){if(b&1)res=(res+a)%c;a=(a+a)%c;b>>=1;}return res;} 
const int inf = 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f ;
const int N = 1e6 + 10 , M = 10 , mod = 1e9 + 7 ;
const double eps = 1e-7 , pi = acos(-1.0) ;

int t ;
int n , m ;
int f[M][M] ;
char g[M][M] ;
bool st[M][M] ;

int dfs(int x , int y)
{
    if(f[x][y] != -1) return f[x][y] ;
    
    int xx = x , yy = y ;
    
    char hh = g[x][y] ;
    
    if(hh == 'U') xx -- ;
    if(hh == 'D') xx ++ ;
    if(hh == 'R') yy ++ ;
    if(hh == 'L') yy -- ;
    
    if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && !st[x][y])
    {
        st[x][y] = 1 ;
        return f[x][y] = dfs(xx,yy) + 1 ;
        st[x][y] = 0 ;
    }
    else
    {
        if(st[x][y])
        {
            st[x][y] = 1 ;
            return f[x][y] = 0 ;
            st[x][y] = 0 ;
        }
        else
        {
            st[x][y] = 1 ;
            return f[x][y] = 1 ;
            st[x][y] = 0 ;
        }
    }
}

signed main()
{
    cin >> t ;
    while(t--)
    {
        sf2(n,m) ;
        fer(i,1,n)
            fer(j,1,m) 
                f[i][j] = -1 ;
                
        fer(i,1,n) scanf("%s",g[i] + 1) ;
        
        fer(i,1,n)
        {
            fer(j,1,m)
            {
                if(j + 1 <= m && g[i][j] == 'R' && g[i][j + 1] == 'L')
                {
                    f[i][j] = 2 ;
                    f[i][j + 1] = 2 ;
                }
                if(i + 1 <= n && g[i][j] == 'D' && g[i + 1][j] == 'U')
                {
                    f[i][j] = 2 ;
                    f[i + 1][j] = 2 ;
                }
            }
        }
        
        fer(i,1,n)
        {
            fer(j,1,m)
            {
                if(f[i][j] == -1)
                    dfs(i,j) ;
            }
        }
        
        // fer(i,1,n)
        // {
        //     fer(j,1,m)
        //     {
        //         cout << f[i][j] << " " ;
        //     }
        //     puts("") ;
        // }
        
        
        int res = -inf , xx , yy ;
        fer(i,1,n)
        {
            fer(j,1,m)
            {
                if(res < f[i][j])
                {
                    res = f[i][j] ;
                    xx = i ;
                    yy = j ;
                }
            }
        }
        
        
        cout << xx << " " << yy << " " << res << "\n" ;
    }
    return 0;
}


/*
*
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/