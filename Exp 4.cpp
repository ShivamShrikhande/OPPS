#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;
int pi[10];
double b[3][3];
int c[1][1];
float a[1][1];
void matmul(float[]);
int main()
{ int i,x,y,tx,ty,sx,sy,angle=10,xmax,ymax,xmid,ymid,op;
int gd=DETECT,gm;
float pi[10]={50,50,100,50,100,100,50,100,50,50};
cout<<"select transformation";
cout<<"translation";
cout<<"rotation";
cout<<"scaling";
cout<<"enter option";
cin>>op;
switch(op)
{ case 1:
cout<<"eneter x translation";
cin>>tx;
cout<<"eneter y translation";
cin>>ty;
break;
case 2 :
cout<<" enter rotation angle";
cin>>angle;
b[0][0]=cos(angle*3.14/180);
b[0][1]=sin(angle*3.14/180);
b[0][2]=0;
b[1][0]=sin(angle*3.14/180);
b[1][1]=cos(angle*3.14/180);
b[1][2]=0;
b[2][0]=0;
b[2][2]=0;
b[2][2]=1;
break;
case 3 :
cout<<"enter x scaling";
cin>>sx;
cout<<"enter y scaling";
cin>>sy;
b[0][0]=sx;
b[0][1]=0;
b[0][2]=0;
b[1][0]=0;
b[1][1]=sy;
b[1][2]=0;
b[2][0]=0;
b[2][1]=0;
b[2][2]=1;
break;
}
initgraph(&gd,&gm, NULL);
xmax=getmaxx();
ymax=getmaxx();
xmid=xmax/2;
ymid=ymax/2;
setcolor(1);
line(xmid,0,xmid,ymax);
line(0,ymid,xmax,ymid);
setcolor(4);
for(i=0;i<8;i=i+2)
{ line(xmid+pi[i],ymid-pi[i+1],
  xmid+pi[i+2],ymid-pi[i+3]);
}
matmul(pi);
setcolor(15);
for(i=0;i<8;i=i+2)
{ line(xmid+pi[i],ymid-pi[i+1],
  xmid+pi[i+2],ymid-pi[i+3]);
}
getch();
closegraph();
return 0;
}
void matmul(float p[10])
{int i ;
for (i=0;i<9;i=i+2)
{
a[0][0]=pi[i];
a[0][1]=pi[i+1];
c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0]+b[2][0];
c[0][0]=a[0][0]*b[0][1]+a[0][1]*b[1][1]+b[2][1];
pi[i]=c[0][0];
pi[i+1]=c[0][1];
}
}




 
