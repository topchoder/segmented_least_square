#include <bits/stdc++.h>
using namespace std;
struct point
{
	int x,y;
};

bool compareX(point a,point b)
{
	return a.x<b.x;
}

double compute_a(point *points,int low,int high)
{
	int a=0,b=0;
	int sum_of_x=0,sum_of_y=0;
	//sum of x
	for(int i=low;i<=high;i++)
		sum_of_x+=points[i].x;
    
	//sum of y
	for(int i=low;i<=high;i++)
		sum_of_y+=points[i].y;
    
	//sum of xi*yi
	for(int i=low;i<=high;i++)
		a+=points[i].x*points[i].y;
    
	//sum of xi*xi
	for(int i=low;i<=high;i++)
		b+=points[i].x*points[i].x;
    
    	int n=high-low+1;
    	int sqr=sum_of_x*sum_of_x;
    	int sqr1=sum_of_x*sum_of_y;
    	return ((n*a)-sqr1)/((n*b)-(sqr));
}

double compute_b(point *points,int low,int high,double a)
{
	int sum_of_x=0,sum_of_y=0;
	//sum of x
	for(int i=low;i<=high;i++)
		sum_of_x+=points[i].x;
    
	//sum of y
	for(int i=low;i<=high;i++)
		sum_of_y+=points[i].y;
    
	int n=high-low+1;
  
	return (sum_of_y)-(a*sum_of_x)/n;
}

double compute(point *points,int low,int high)
{
	double a,b;
	a=compute_a(points,low,high);
	b=compute_b(points,low,high,a);
        double final=0;
        //Computing ERROR for a segment
        for(int i=low;i<=high;i++)
  	{
      		final+=((points[i].y-a*points[i].x-b)*(points[i].y-a*points[i].x-b));
  	}		
  	return final;
}

double ERROR(point *a,int low,int high,int partitions,double c)
{
	if(low==high)
  	{
	      return 0;
  	}
  
	double error=numeric_limits<double>::max();
  
	for(int i=low;i<high;i++)
	{
        	double err=ERROR(a,low,i,partitions,c)+ERROR(a,i+1,high,partitions+1,c)+compute(a,low,high)+(partitions)*c;
        	if(error>err)
        	{
        	 	error=err;
        	}
	}
	return error;
}

signed main(int argc,char **argv)
{
     int x,y,m;
     cout<<"enter number of points"<<"\n";
     cin>>m;
     
     point *points=new point[m];
     
     for(int i=0;i<m;i++)
     {
     	 cin>>x>>y;
     	 points[i].x=x;
     	 points[i].y=y;
     }
     //sorting points by x coordinate
     sort(points,points+m,compareX);
     
     for(int i=0;i<m;i++)
     {
     	  cout<<points[i].x<<" "<<points[i].y<<"\n";
     }
     
     cout<<"enter constant of error"<<"\n";
     double c;
     cin>>c;
     int partitions=1;
     cout<<ERROR(points,0,m-1,partitions,c)<<"\n";
     return 0;	
}
