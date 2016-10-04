#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
class dda_algo
{
	public:
	int  xa,ya,xb,yb,s,dx,dy,xi,yi,k,q,w,wx,wy,i;
	float x,y;

	void getdata()
	{
		cout<<"Enter the cordinates of first \n";
		cin>>xa>>ya;
		cout<<"Enter the cordinates of second \n";
		cin>>xb>>yb;
	}

	void dda_line(int q)
	{
		dx=xb-xa;
		dy=yb-ya;
		if(abs(dx)>=abs(dy))																						  if(abs(dx)>abs(dy))
		{
			s=abs(dx);
		}
		else
		{
			s=abs(dy);
		}
		xi=dx/s;
		yi=dy/s;
		x=xa;
		y=ya;
		putpixel(x,y,14);
		for(k=1;k<=s;k++)
		{
			x=x+xi;
			y=y+yi;
			if(k%q!=0)
			putpixel(x,y,14);
		}
	}

	void thick()
	{
	       cout<<"\nEnter the thickness";
	       cin>>w;
	       dx=xb-xa;
		dy=yb-ya;
	       /*	if(abs(dx)>=abs(dy))																						  if(abs(dx)>abs(dy))
		{
			s=abs(dx);
		}
		else
		{
			s=abs(dy);
		}
	       xi=dx/s;
	       yi=dy/s;
		  */
		if((dx/dy)<1)
		{
		 wy=(w-1)*sqrt(pow((xb-xa),2)+pow((yb-ya),2))/(2*fabs(xb-xa));

		 for(i=0;i<wy;i++)
		 {
		 line(xa,ya-i,xb,yb-i);
		 line(xa,ya+i,xb,yb+i);
		 }
		}
		else
		{
		 wx=(w-1)*sqrt(pow((xb-xa),2)+pow((yb-ya),2))/(2*fabs(yb-ya));
		 for(i=0;i<wx;i++)
		 {
		 line(xa-i,ya,xb-i,yb);
		 line(xa-i,ya,xb+i,yb);
		 }
		}
	}
};
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	detectgraph(&gd,&gm);
	dda_algo obj;
	int choice;
	char yn;
	do
	{
		cout<<" MENU \n 1.Simple line \n 2.Dotted line \n 3.dashed line \n";
		cout<<"\n4.Thick line\n5.Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
			obj.getdata();
			obj.dda_line(10000);
			break;
			case 2:
			obj.getdata();
			obj.dda_line(2);
			break;
			case 3:
			obj.getdata();
			obj.dda_line(5);
			break;
			case 4:
			obj.getdata();
			obj.thick();
			break;
			case 5:
			break;
		}
		cout<<" Enter y or Y to continue \n ";
		cin>>yn;
//		cleardevice();
//		clrscr();
	}
	while(choice=='y' || choice=='Y');
	getch();
	closegraph();
	return 0;
}

