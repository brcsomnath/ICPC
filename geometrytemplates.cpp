#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
#define PI acos(-1)
//Fast Read
inline void read(ll & n)
{
	n = 0;
	char ch = gc; int sign = 1;
	while(ch < '0' || ch > '9'){if(ch == '-') sign = -1; ch = gc; }
	while(ch >= '0' && ch<= '9')
	{
		n = n*10 + ch - '0';
		ch = gc;
	}
	n *= sign;
}

//Fast print
inline void print(ll n)
{
	char ch[15];
	int ind=0;
	if(n<0)
    {
        pc('-');
        n *= -1;
    }
	if(n == 0)
	{
		pc('0');
	}
	while(n > 0)
	{
		ch[ind] = n%10 + '0';
		n /= 10;
		ind++;
	}
	while(ind--) pc(ch[ind]);
	pc('\n');
}
struct point
{ 
	double x,y;
	point(){x=y=0;}
	point(double _x,double _y) : x(_x),y(_y){}
	bool operator < (point other) const
	{
		if(fabs(x-other.x)>EPS)
			return x<other.x;
		return y<other.y;
	}
	bool operator == (point other) const
	{
		return (fabs(y-other.y)<EPS&&fabs(x-other.x)<EPS);
	}
};
double DEG_to_RAD(double theta)
{
	return theta/180*PI;
}
double dist(point p1,point p2)
{
	return hypot(p1.x-p2.x,p1.y-p2.y);
}
point rotate(point p,double theta)
{
	double rad=DEG_to_RAD(theta);
	return point(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
}
struct line
{
	double a,b,c;
	line(){a=b=c=0;}
	line(double _a,double _b,double _c) : a(_a),b(_b),c(_c){}
};
void pointsToLine(point p1,point p2,line &l)
{
	if(fabs(p1.x-p2.x)<EPS)
	{
		l.a=1; l.b=0.0; l.c=-p1.x;
	}
	else
	{
		l.a=-(double)(p1.y-p2.y)/(p1.x-p2.x);
		l.b=1.0;
		l.c=-(double)(l.a*p1.x)-p1.y;
	}
}
bool areParallel(line l1,line l2)
{
	return (fabs(l1.a-l2.a)<EPS&&fabs(l1.b-l2.b)<EPS);
}
bool areSame(line l1,line l2)
{
	return (areParallel(l1,l2)&&fabs(l1.c-l2.c)<EPS);
}
bool areIntersect(line l1,line l2,point &p)
{
	if(areParallel(l1,l2)) return false;
	p.x=(l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
	if(fabs(l1.b)<EPS)
		p.y=-(l1.a*p.x+l1.c);
	else
		p.y=-(l2.a*p.x+l2.c);
	return true;
}
struct vec
{
	double x,y;
	vec(double _x,double _y) : x(_x),y(_y){}
};
vec toVec(point p1,point p2)
{
	return vec(p2.x-p1.x,p2.y-p2.x);
}
vec scale(vec v,double s)
{
	return vec(v.x*s,v.y*s);
}
point translate(point p, vec v)
{
	return point(p.x+v.x,p.y+v.y);
}
double dot(vec a,vec b){return (a.x*b.x+a.y*b.y);}
double norm_sq(vec a){return (a.x*a.x+a.y*a.y);}
double distToline(point p,point a,point b,point &c)
{
	vec ap=toVec(a,p),ab=toVec(a,b);
	double u=dot(ap,ab)/norm_sq(ap);
	c=translate(a,scale(ab,u));
	return dist(p,c);
}
double angle(point a,point o,point b)
{
	vec oa=toVec(o,a),ob=toVec(o,b);
	return acos(dot(oa,ob)/(sqrt(norm_sq(oa)*norm_sq(ob))));
}
double cross(vec a,vec b)
{
	return a.x*b.y-a.y*b.x;
}
bool ccw(point p,point q,point r)
{
	return cross(toVec(p,q),toVec(q,r))>0;
}
bool collinear(point p,point q,point r)
{
	return fabs(cross(toVec(p,q),toVec(q,r)))<EPS;
}
struct circle
{
	point c;
	double r;
	circle(point _c,double _r) : c(_c),r(_r){}
};
bool circle2ptsRad(point p1,point p2,double r,point &c)
{
	double d2=norm_sq(toVec(p1,p2));
	double det=r*r/det-0.25;
	if(det<0.0) return false;
	double h=sqrt(det);
	c.x=(p1.x+p2.x)*0.5+(p1.y-p2.y)*h;
	c.y=(p1.y+p2.y)*0.5+(p1.x-p2.x)*h;
	return true;
}
double area(double a,double b,double c)
{
	double s=0.5*(a+b+c);
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
double perimeter(double a,double b,double c)
{
	return (a+b+c);
}
double rInCircle(double ab,double bc,double ac)
{
	return area(ab,bc,ac)/(0.5*perimeter(ab,bc,ac));
}
double rInCircle(point a,point b,point c)
{
	return rInCircle(dist(a,b),dist(b,c),dist(a,c));
}
ll incircle(point p1,point p2,point p3,point &ctr,double &r)
{
	r=rInCircle(p1,p2,p3);
	if(r<EPS) return 0;
	
	line l1,l2;
	double ratio=dist(p1,p2)/dist(p1,p3);
	point p=translate(p2,scale(toVec(p1,p3),ratio/(1+ratio)));
	pointsToLine(p1,p,l1);
	ratio=dist(p1,p2)/dist(p2,p3);
	p=translate(p1,scale(toVec(p2,p3),ratio/(1+ratio)));
	pointsToLine(p2,p,l2);
	
	areIntersect(l1,l2,ctr);
	return 1;
}
double rCircumCircle(double ab,double ac,double bc)
{
	return ab*bc*ac/(4.0*area(ab,bc,ac));
}
double rCircumCircle(point a,point b,point c)
{
	return rCircumCircle(dist(a,b),dist(b,c),dist(a,c));
}
double perimeter(const vector<point> &P)
{
	double result=0.0,n=(ll)P.size();
	for(ll i=0;i<(ll)P.size();i++)
	{
		result+=dist(P[i],P[(i+1)%n]);			//if P[0] and P[n-1] are equal
	}
	return result;
}
double area(const vector<point> &P)
{
	double result=0.0,x1,x2,y1,y2,n=(ll)P.size();
	for(ll i=0;i<(ll)P.size();i++)
	{
		x1=P[i].x;	y1=P[i].y;
		x2=P[(i+1)%n].x; y2=P[(i+1)%n].y;
		result+=(x1*y2-y1*x2);
	}
	return fabs(result)/2.0;
}
bool isConvex(vector<point> P)
{
	ll sz=(ll)P.size();
	if(sz<=3)
	{
		return false;
	}
	bool isLeft=ccw(P[0],P[1],P[2]);
	for(ll i=1;i<sz-1;i++)
	{
		if(ccw(P[i],P[i+1],P[(i+2)%sz])!=isLeft)
			return false;
	}
	return true;
}
bool inPolygon(point pt,vector<point> P)
{
	double sum=0;
	for(ll i=0;i<(ll)P.size()-1;i++)
	{
		if(ccw(pt,P[i],P[i+1]))
			sum+=angle(P[i],pt,P[i+1]);
		else
			sum-=angle(P[i],pt,P[i+1]);
	}
	return (fabs(sum)-2*PI)<EPS;
}
point pivot(0,0);
bool anglCmp(point a,point b)
{
	if(collinear(pivot,a,b))
		return dist(pivot,a)<dist(pivot,b);
	double d1x=a.x-pivot.x,d1y=a.y-pivot.y;
	double d2x=b.x-pivot.x,d2y=b.y-pivot.y;
	return (atan2(d1y,d1x)-atan2(d2y,d2x))<0;
}
vector<point> CH(vector<point> P)
{
	ll i,j,n=(ll)P.size();
	if(n==3)
	{
		if(!(P[0]==P[n-1]))
			P.push_back(P[0]);
		return P;
	}
	ll PO=0;
	for(i=1;i<n;i++)
	{
		if(P[i].y<P[PO].y||(P[i].y==P[PO].y&&P[i].x>P[PO].x))
			PO=i;
	}
	point temp=P[PO];
	P[PO]=P[0];
	P[0]=temp;
	pivot=P[0];
	sort(++P.begin(),P.end(),anglCmp);
	vector<point> S;
	S.push_back(P[n-1]);S.push_back(P[0]);S.push_back(P[1]);
	i=2;
	while(i<n)
	{
		j=(ll)S.size()-1;
		if(ccw(S[j-1],S[j],P[i]))
			S.push_back(P[i++]);
		else
			S.pop_back();
	}
	return S;
}

int main()
{
	line A(1,1,1);
}	
