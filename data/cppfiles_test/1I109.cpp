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
vector <pair<LD,int>> a;
multiset<LD>s;
LD ang[KL],dis[KL];
bool ok(LD mid){
    if(k<=0)return 1;
    a.clear();int cnt=0;
    for(int i=0;i<n;i++){
        if(dis[i]>2*mid)continue;
        LD angle=acos(dis[i]/(2.0*mid));
        LD angle1=ang[i]-angle,angle2=ang[i]+angle;
        while(angle1<0)angle1+=2*PI;
        a.pb({angle1,1});
        a.pb({angle2,-1});
        if(angle1>angle2)cnt++;
    }
    sort(all(a));
    int sz=a.size();
    int mx=cnt;
    for(int i=0;i<a.size();i++){
       cnt+= a[i].S;
       mx=max(mx,cnt);
    }
    return mx>=k;
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
