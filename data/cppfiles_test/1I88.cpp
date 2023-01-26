#include<bits/stdc++.h>
#include <stdio.h>
#include <algorithm>

#define all(x) x.begin(),x.end()
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define LL long long
#define LD long double
#define pb push_back
#define F first
#define S second


const double PI=3.1415926535897932384626433;
const int KL=1e5+10;
const LL MOD=1e9+7;


using namespace std;


///2D geometry
int x1,y1;
struct point{
    LD x,y;
    void go(LL x1,LL y1){x=x1;y=y1;}
    void read(){
        sc(x1);sc(y1);
        x=x1,y=y1;
    }
    point operator -(point b){return point{x-b.x,y-b.y};}
    point operator +(point b){return point{x+b.x,y+b.y};}
};


LD fnd_angle(point p){ /// angle x o p  (rad)
    LD len=sqrt(p.x*p.x+p.y*p.y);
    LD angle=acos(fabs(p.x)/len);
    if(p.y<0){
        if(p.x>=0)angle=2*PI-angle;
        else angle+=PI;
    }
    else if(p.x<0)angle=PI-angle;
    return angle;
}

int n,k;
vector <point> A;
vector <pair<LD,LD>> a,b;
multiset<LD>s;
LD ang[KL],dis[KL];
bool ok(LD mid){
    if(k<=0)return 1;
    a.clear();
    b.clear();
    for(int i=0;i<n;i++){
        if(dis[i]>2*mid)continue;
        LD angle=acos(dis[i]/(2.0*mid));
        a.pb({ang[i]-angle,2*angle});
        b.pb({ang[i]+angle,-2.0*angle});
    }
    sort(all(a));
    sort(all(b));
    reverse(all(b));
    int sz=a.size();
    ///for(int i=0;i<sz;i++)a.pb({a[i].F+2*PI,a[i].S});
    ///for(int i=0;i<sz;i++)b.pb({b[i].F-2*PI,b[i].S});
    int mx=0;
    s.clear();
    for(int i=0;i<a.size();i++){
        while(s.size()>0 && *s.begin()<a[i].F)s.erase(s.begin());
        if(s.size()+1>=k)return 1;
        s.insert(a[i].F+a[i].S);
    }
    s.clear();
    for(int i=0;i<b.size();i++){
        while(s.size()>0 && *(--s.end())>b[i].F)s.erase(--s.end());
        if(s.size()+1>=k)return 1;
        s.insert(b[i].F+b[i].S);
    }
    return 0;
}

int main()
{
    sc(n);sc(k);
    for(int i=1;i<=n;i++){
        point pp;pp.read();
        if(pp.x==0 && pp.y==0){k--;continue;}
        A.pb(pp);
    }
    n=A.size();
    for(int i=0;i<n;i++){
        ang[i]=fnd_angle(A[i]);
        dis[i]=sqrt(A[i].x*A[i].x+A[i].y*A[i].y);
    }

    LD lo=0.0,hi=2e5;
    int cnt=35;
    while(cnt--){
        LD mid=(lo+hi)/2.0;
        if(ok(mid))hi=mid;
        else lo=mid;
    }
    double ans=lo;
    printf("%.7f\n",ans);





    return 0;
}
