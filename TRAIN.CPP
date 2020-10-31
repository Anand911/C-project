//Railway ticket reservation system
//programmed by Anand C A
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<string.h>
#include<iomanip.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>
#include<dos.h>
char date[9];
int check1=0,check2=0,check3=0,check4=0;
void adtrain();
void dtrain();
void modtrain();
void deltrain();
void reserve();
void cancel();
void report();
class login
     {
     protected:
     char password[10];
     public:
	   int rtuser(char us[10])
	       {
	       return strcmp(us,"railadmin");
	       }
	   char* rtpass()
	       {
	       strcpy(password,"SBOA123");
	       return password;
	       }
     };
     login l;
class passenger
     {
     int cnumber,coN;
     char caddress[50];
     char cphone[15];
     char cname[10];
     char pname[10][10];
     char sex[10][10];
     int age[10];
     char trname[20];
     public:
	   long tno;
	   int nos,st;
	   float f;
	   char ca,dot[10],srce[10],des[10],pclass[15];
	   int rtno()
	       {
	       return cnumber;
	       }
	   int resfile(int trno);
	   void display();

     };
     passenger p;
class train
      {
      float tnumber;
      char tname[25],source[20],dest[20],tclass[20];   //destination
      char date1[10],date2[10],date3[10];
      float tcap,cap1,cap2,caps,capg;
      float fare1,fare2,fares,fareg,fare,tfare;
      public:
	    int nos1,nos2,noss,nosg,n;      //number of seats occupied
	    void readtrain();
	    void moddetails();
	    void disptrain();
	    int seatscheck(int ns,char clas[20]);
	    void trdates();
	    float calcfare(int ag[10]);
	    void seatschange(int ps);
	    float trainno()
		{return tnumber;}
	    char* scrrt()
		{return source;}
	    char* destrt()
		{return dest;}

      };
      train t;
void train::readtrain()
{
textcolor(1);
clrscr();
long tno;
ifstream ifile;
ifile.open("TRAIN.DAT");
start:
int flag=0;
cout<<"enter the train number: ";
cin>>tno;
while(!ifile.eof())
     {
     ifile.read((char*)&t,sizeof(t));
     if(tnumber==tno)
       {
       //cout<<"Train number already exist"<<endl;
       flag=1;
       break;
       }
     }
if(flag==1)
  {
  cout<<"\ntrain number already exist";
  goto start;
  }
  else
   tnumber=tno;
cout<<"\nEnter the train Name: ";
gets(tname);
cout<<"\nEnter the source: ";
gets(source);
cout<<"\nEnter the destination: ";
gets(dest);
cout<<"\nEnter the total capacity: ";
cin>>tcap;
cap1=(0.1)*tcap;
cap2=tcap*(0.2);
caps=tcap*(0.5);
capg=tcap*(0.2);
cout<<"\nNOTE:\nCapacity per class is deafaulty assigned as given below"<<endl;
cout<<"A/C First class capacity="<<cap1<<"(10% of total capacity)"<<endl;
cout<<"A/C second class capacity="<<cap2<<"(20% of total capacity)"<<endl;
cout<<"sleeper class capacity="<<caps<<"(50% of total capacity)"<<endl;
cout<<"Genral quota capacity="<<capg<<"(20% of total capacity)"<<endl;
cout<<"\nEnter the number of seats occupied and fare per ticket"<<endl;
cout<<"A/C First class=";
cin>>nos1>>fare1;
cout<<"\nA/C second class=";
cin>>nos2>>fare2;
cout<<"\nsleeper class capacity=";
cin>>noss>>fares;
clrscr();
cout<<"\nGenral quota capacity=";
cin>>nosg>>fareg;
textcolor(5);cputs("NOTE:");
cout<<"As per the guidelines a train will run upto 3 days a week.";
cout<<"The admin can\ndecidethe no. of days and dates the train will function";
cout<<"\nEnter the number of times the train should function"<<endl;
cin>>n;
cout<<"\n\nEnter the dates the train will run"<<endl;
gets(date1);
if(n>=2)
  gets(date2);
if(n==3)
  gets(date3);
}
void train::moddetails()
{
char tnm[20],soc[20],det[20],d1[10],d2[10],d3[10];
float tca,f1,f2,fs,fg;
int n1,n2,ns,ng;
cout<<"\nEnter the new train Name:";
textcolor(RED+128);cputs("(PRESS '.' TO RETAIN OLD NAME)");
gets(tnm);
cout<<"\nEnter the new source:";
cputs("(PRESS '.' TO RETAIN OLD SOURCE)");
gets(soc);
cout<<"\nEnter the new destination:";
cputs("(PRESS '.' TO RETAIN OLD DESTINATION)");
gets(det);
cout<<"\nEnter the total capacity:";
cputs("(PRESS '-1' TO RETAIN OLD CAPACITY)");
cin>>tca;
if(strcmp(tnm,".")!=0)
  strcpy(tnm,tname);
if(strcmp(soc,".")!=0)
  strcpy(soc,source);
if(strcmp(det,".")!=0)
  strcpy(det,dest);
if(tca!=-1)
  {
  tcap=tca;
  cap1=(0.1)*tca;
  cap2=tca*(0.2);
  caps=tca*(0.5);
  capg=tca*(0.2);
  }
cout<<"\nEnter the new number of seats occupied and new fare per ticket"<<endl;
cputs("(PRESS '-1' TO RETAIN OLD SEATS OCCUPIED AND '-2' TO RETAIN FARE)");
cout<<"A/C First class=";
cin>>n1>>f1;
cout<<"\nA/C second class=";
cin>>n2>>f2;
cout<<"\nsleeper class capacity=";
cin>>ns>>fs;
//clrscr();
cout<<"\nGenral quota capacity=";
cin>>ng>>fg;
if(n1!=-1)
  nos1=n1;
if(f1!=-2)
  fare1=f1;
if(n2!=-1)
  nos2=n2;
if(f2!=-2)
  fare2=f2;
if(ns!=-1)
  noss=ns;
if(fs!=-2)
  fares=fs;
if(ng!=-1)
  nosg=ng;
if(f1!=-2)
  fareg=fg;
cout<<"\n\nEnter the new dates the train will run"<<endl;
cputs("(PRESS '.' TO RETAIN OLD DATE)");
gets(d1);cout<<endl;
if(strcmp(d1,".")!=0)
  strcpy(d1,date1);
if(n>=2)
  {
  cputs("(PRESS '.' TO RETAIN OLD DATE)");
  gets(d2);cout<<endl;
  if(strcmp(d2,".")!=0)
    strcpy(d2,date2);
  }
if(n==3)
  {
  cputs("(PRESS '.' TO RETAIN OLD DATE)");cout<<endl;
  gets(d3);
  if(strcmp(d3,".")!=0)
     strcpy(d3,date3);
  }
}
void train::disptrain()
{
textcolor(9);
clrscr();
textcolor(RED);
cputs("TRAIN DETAILS:");cout<<"\n\n";
cputs("TRAIN NUMBER:");cout<<tnumber;
gotoxy(25,3);cputs("TRAIN NAME:");cout<<tname<<endl;
cputs("SOURCE:");cout<<source;
gotoxy(20,4);cputs("DESTINATION:");cout<<dest;
gotoxy(45,4);cputs("TOTAL CAPACITY=");cout<<tcap<<"\n\n";
gotoxy(9,8);cputs("A/C FIRST CLASS   A/C SECOND CLASS   SLEEPER CLASS   GENRAL QUOTA");cout<<endl;
gotoxy(0,10);cputs("CAPACITY   ");gotoxy(16,9);cout<<cap1;
gotoxy(32,9);cout<<cap2;gotoxy(47,9);cout<<caps;gotoxy(67,9);cout<<capg<<endl;
cputs("SEATS OCCUPIED");gotoxy(16,10);cout<<nos1;
gotoxy(32,10);cout<<nos2;gotoxy(47,10);cout<<noss;gotoxy(67,10);cout<<nosg<<endl;
cputs("TRAIN RUNNING DATES:");cout<<date1<<endl;gotoxy(21,12);cout<<date2;
gotoxy(21,13);cout<<date3<<endl;
}
void train::trdates()
		 {
		 char dat[10];
		 int choice;
		 cout<<"\nBoarding Point:"<<scrrt()<<"\t\tDestination:"<<destrt();
		 cout<<"\nThe train will run on the following dates:"<<endl;
		 cout<<"1."<<date1<<endl;
		 if(n>=2)
		 cout<<"2."<<date2<<endl;
		 if(n==3)
		   cout<<"3."<<date3<<endl;
		 cout<<"Enter the (choice)date of travel: ";
		 cin>>choice;
		 switch(choice)
		       {
		       case 1:strcpy(p.dot,date1);
			      break;
		       case 2:strcpy(p.dot,date2);
			      break;
		       case 3:strcpy(p.dot,date3);
			      break;
		       }
		 }
int train::seatscheck(int ns,char clas[20])
		{
		int c,sl1,sl2,sls,slg;
		if(strcmpi(clas,"A/C first class")==0)
		  {
		  p.ca='A';
		  fare=fare1;
		  sl1=cap1-nos1;
		  p.st=sl1;
		  if(sl1>=ns)
		    {
		    c=1;
		    check1=p.nos;
		    }
		  }
		  else
		 if(strcmpi(clas,"A/C second class")==0)
		  {
		  p.ca='B';
		  fare=fare2;
		  sl2=cap2-nos2;
		  p.st=sl2;
		  if(sl2>=ns)
		    {
		    c=1;
		    check2=p.nos;
		    }
		   }
		  else
		if(strcmpi(clas,"sleeper class")==0)
		  {
		  p.ca='S';
		  fare=fares;
		  sls=caps-noss;
		  p.st=sls;
		  if(sls>=ns)
		     {
		     c=1;
		     check3=p.nos;
		     }
		  }
		   else
		if(strcmpi(clas,"genral quota")==0)
		  {
		  p.ca='G';
		  fare=fareg;
		  slg=capg-nosg;
		  p.st=slg;
		  if(slg>=ns)
		    {
		    c=1;
		    check4=p.nos;
		    }
		   }
		   else
		    c=0;
		   if(c==1)
		     strcpy(clas,p.pclass);
		   return c;
		}
float train::calcfare(int ag[10])
	    {
	    tfare=0;
	    for(int j=1;j<=p.nos;j++)
	       {
	       if((ag[j]<=12)||(ag[j]>=65))
		 tfare=tfare+(fare/2);
	       else
		 tfare=tfare+fare;
	       }
	    return tfare;
	    }
void train::seatschange(int ps)
     {
     ofstream ofile;
     ofile.open("TRAIN.DAT");
     t.nos1=t.nos1+check1;
     t.nos2=t.nos2+check2;
     t.noss=t.noss+check3;
     t.nosg=t.nosg+check4;
     ofile.seekp(ps,ios::beg);
     ofile.write((char*)&t,sizeof(t));
     ofile.close();
     }
int passenger::resfile(int trno)
	       {
		int i,a[10],x=0;
		int book;
		char ch1;
		ofstream pfile1;
		pfile1.open("PASSENGER.DAT",ios::app);
		srand(time(0));
		cout<<"Enter the User name:";
		cin>>cname;
		cnumber=rand()%1000+1;
		cout<<"\nYour pesronal reservation id is:"<<cnumber<<endl;
		textcolor(4+128);
		cputs("*");
		cout<<"Do not share your peronal id with anyone";
		cout<<" it contains personal and booking\ninformation";
		sleep(3);
		cout<<"\nEnter the address:"<<endl;
		gets(caddress);
		cout<<"\nenter the phone number:+91 ";
		gets(cphone);
		tno=trno;
		cout<<"\nEnter the train name:";
		gets(trname);
		strcpy(des,t.destrt());
		t.trdates();
		strcpy(srce,t.scrrt());
		res:
		cout<<"\nEnter the class"<<endl;
		gets(pclass);
		cout<<"\nEnter the number of seats(1-9)"<<endl;
		cin>>nos;
		book=t.seatscheck(nos,pclass);
		if(book==1)
		  {
		clrscr();
		while(!kbhit())
		     {
		     clrscr();
		     gotoxy(x,1);
		     textcolor(2);
		     cputs("SEATS ARE AVAILABLE!!");
		     delay(100);
		     x++;
		     if(x>=80)
		       x=0;
		     }
		cout<<"\nEnter the details of the passenger"<<endl;
		for(i=1;i<=nos;i++)
		    {
		  cout<<"\nEnter the passenger"<<i<<" name:";
		  gets(pname[i]);
		  cout<<"\nEnter the sex:";
		  gets(sex[i]);
		  cout<<"\nEnter the age:";
		  cin>>age[i];
		  a[i]=age[i];
		  if((age[i]<=12)||(age[i]>=65))
		    cout<<"\nYou have a cocession of 50%\n";
		     }
		  coN=rand()%10+1;
		  f=t.calcfare(a);
		    }
		else
		 if(book==0)
		 {
		 cout<<"\nNo seats are avialable"<<endl;
		 cout<<"\nDo you want to check the availability of other"<<endl;
		 cin>>ch1;
		 if(ch1=='y')
		   goto res;
		  }
		pfile1.write((char*)&p,sizeof(p));
		    return book;
	       }
void passenger::display()
	  {
	  textcolor(1);
	  clrscr();
	  textcolor(RED);
	  cout<<"\nJOURNEY TICKETS:\n\n";
	  cout<<"\tUSER NAME:"<<cname<<"\n\tUSER PHONE:+91 "<<cphone;
	  cout<<"\n_________________________________________________________\n|\t\t";
	  cputs("   STUDENTS RAILWAYS");
	  cout<<"\t\t\t|\n|\t\t\t\t\t\t\t|";
	  cout<<"\n|\tTRAIN NUMBER:"<<tno<<setw(15)<<"TRAIN NAME:"<<trname;
	  cout<<"\t|\n|\tBOARDING POINT:"<<srce<<"\tDESTINATION:"<<des;
	  cout<<"\t|\n|\tDATE OF TRAVEL:"<<dot<<"\tCLASS:"<<pclass<<"\t|";
	  cout<<"\n|\t\t\t\t\t\t\t|";
	  cout<<"\n|\tPASSENGER"<<"\tSEX"<<"\tAGE"<<"\tCOACH"<<"\tSEAT NO\t|\n";
	  for(int i=1;i<=nos;i++)
	     {
	     cout<<"|\t"<<pname[i]<<"\t\t"<<sex[i]<<"\t"<<age[i]<<"\t"<<ca<<coN<<"\t"<<st<<"\t|";
	     if(st>1)
		st=st-1;
	     if(i!=nos)
	       cout<<"\n";
	     }
	  cout<<"\n|_______________________________________________________|\n\n";
	     sleep(5);
	  }
void user()
{
int cu;
do
 {
textcolor(9);
clrscr();
textcolor(12);
cputs("================================================================================");
gotoxy(1,3);
cputs("================================================================================");
textcolor(GREEN);
gotoxy(30,2);cputs("***USER MENU***");
cout<<"\n\n\n\n\t\t\t  1.RESERVE TICKETS"<<endl;
cout<<"\t\t\t  2.CANCEL TICKETS"<<endl;
cout<<"\t\t\t  3.REPORT"<<endl;
cout<<"\t\t\t  4.BACK"<<endl;
cout<<"\t\t\t  ENTER THE CHOICE:";
cin>>cu;
switch(cu)
      {
      case 1:reserve();
	     break;
      case 2:cancel();
	     break;
      case 3:report();
	     break;
      }
 }while(cu<=3);
}
void admin()
   {
   int flag=0,w=0;
   char user[15],pass[15];
   error:
   textcolor(9);
   clrscr();
   gotoxy(24,9);cout<<"__________________________________";
   gotoxy(24,15);cout<<"|________________________________|";
   textcolor(RED);
   gotoxy(24,10);cout<<"|                                |";
   gotoxy(35,10);
   cputs("ADMIN LOGIN");
   gotoxy(24,11);cout<<"|                                |";
   gotoxy(24,12);cout<<"|                                |";
   gotoxy(30,12);
   cout<<"USERNAME:";
   gotoxy(24,13);cout<<"|                                |";
   gotoxy(30,13);
   cout<<"PASSWORD:";
   gotoxy(24,14);cout<<"|                                |";
   gotoxy(39,12);gets(user);
   gotoxy(39,13);gets(pass);
   if((l.rtuser(user)==0)&&(strcmp(l.rtpass(),pass)==0))
     {
     textcolor(13);
     gotoxy(28,14);
     cputs("PROCESSING");
     for(int i=0;i<6;i++)
	{
	cputs(".");
	sleep(1);
	}
     int cu;
     do
      {
     textcolor(1);
     clrscr();
     textcolor(12);
     cputs("================================================================================");
     gotoxy(1,3);
     cputs("================================================================================");
     textcolor(4);
     gotoxy(28,2);
     cputs("***ADMIN MENU***");gotoxy(30,5);
     cout<<"1.ADD TRAINS";gotoxy(30,6);
     cout<<"2.DISPLAY TRAINS";gotoxy(30,7);
     cout<<"3.MODIFY TRAIN";gotoxy(30,8);
     cout<<"4.DELETE TRAIN";gotoxy(30,9);
     cout<<"5.Back";gotoxy(30,10);
     cout<<"ENTER THE CHOICE:";
     cin>>cu;
     switch(cu)
	   {
	   case 1:adtrain();
		  break;
	   case 2:dtrain();
		  break;
	   case 3:modtrain();
		  break;
	   case 4:deltrain();
		  break;
	   }
      }while(cu<=4);
      flag=1;
     }
    if(flag!=1)
      {
       textcolor(13+128);
       gotoxy(28,14);
       cputs("WRONG USERNAME OR PASSWORD");
       sleep(3);
       w++;
       if(w>3)
	 {
	 cout<<"\n\n\nYOU HAVE ENETERED INNCORRECT PASSWORD OR USER NAME INCORRECTLY";
	 cout<<"FOR MORE THAN 3\nTIMES!!";cputs("EXITING THE PROGRAM!!");
	 sleep(6);
	 exit(0);
	 }
       goto error;
      }
}
void about()
     {
     textcolor(9);
     clrscr();
     char ch[200];
     float x=0;
     textcolor(2);
     cputs("================================================================================");
     gotoxy(1,3);
     cputs("================================================================================");
     textcolor(5);
     gotoxy(33,2);
     cputs("ABOUT US");
     ifstream ifile;
     ifile.open("ABOUT.TXT");
     cout<<"\n\n";
     while(!ifile.eof())
	  {
	  ifile>>ch;
	  cout<<ch<<" ";
	  x=x+strlen(ch)+1;
	  if(x>=73)
	    {
	    cout<<"\n";
	    x=0;
	    }
	  }
     cout<<endl;
     textcolor(RED);
     gotoxy(23,25);
     cputs("COPYRIGHT(C)2018 ALL RIGHTS RESERVED");
     ifile.close();
     getch();
     }
void main()
{
	clrscr();
	int c;
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	_strdate(date);
	do
	{
	system("cls");
	cout<<date<<endl;
	setbkcolor(WHITE);
	textcolor(12);
	cputs("================================================================================");
	gotoxy(1,4);
	cputs("================================================================================");
	textcolor(RED);
	gotoxy(13,3);
	cputs("******WELCOME TO RAILWAY TICKET RESERVATION SYSTEM******");
	textcolor(9);
	cout<<"\n";
	gotoxy(30,6);
	cputs("1.USER MODE");gotoxy(30,7);
	cputs("2.ADMIN MODE");gotoxy(30,8);
	cputs("3.ABOUT US");gotoxy(30,9);
	cputs("4.EXIT");gotoxy(30,10);
	cputs("ENTER A CHOICE:");
	textcolor(4);
	gotoxy(23,25);
	cputs("COPYRIGHT(C)2018 ALL RIGHTS RESERVED");
	gotoxy(45,10);cin>>c;
	switch(c)
	      {
	      case 1:user();
		     break;
	      case 2:admin();
		     break;
	      case 3:about();
		     break;
	      case 4:exit(0);
	      }
	}while(c!=4);
	getch();
	closegraph();
}
void adtrain()
{
	ofstream tfile;
	tfile.open("TRAIN.DAT",ios::binary|ios::app);
	if(!tfile)
	{
	cout<<"\nUnable to open"<<endl;
	exit(0);
	}
	t.readtrain();
	tfile.write((char*)&t,sizeof(t));
	tfile.seekp(0);
	tfile.close();
}
void dtrain()
     {
     clrscr();
     float trn,i=1,flag=0;
     ifstream tfile;
     tfile.open("TRAIN.DAT",ios::binary);
     cout<<"\n\n\nENTER THE TRAIN NUMBER:"<<endl;
     cin>>trn;
     while(!tfile.eof())
	  {
	  tfile.read((char*)&t,sizeof(t));
	  if(t.trainno()==trn)
	    {
	    if(i==1)
	      t.disptrain();
	    flag=1;
	    i++;
	    }
	  }
     tfile.close();
     if(flag!=1)
	cout<<"\n\nNO TRAINS FOUND";
     system("pause");
     }
void modtrain()
     {
     textcolor(1);
     clrscr();
     float tn;
     int pos;
     char found='n';
     fstream iofile;
     iofile.open("TRAIN.DAT",ios::in|ios::out|ios::binary);
     cout<<"\n\n\nENTER THE TRAIN NUMBER:"<<endl;
      cin>>tn;
      while(!iofile.eof())
	  {
	  pos=iofile.tellg();
	  iofile.read((char*)&t,sizeof(t));
	  if(t.trainno()==tn)
	    {
	    t.moddetails();
	    iofile.seekg(pos,ios::beg);
	    iofile.write((char*)&t,sizeof(t));
	    found='f';
	    break;
	    }
	  }
      if(found=='n')
	cout<<"\nNO TRAINS FOUND";
      else
	if(found=='f')
	  cputs("\nTHE TRAIN IS MODIFIED");
     sleep(5);
     iofile.close();
     }
void deltrain()
     {
      textcolor(1);
      clrscr();
      char c;
      float tn;
      int flag=0;
      ifstream tfile;
      ofstream tmfile;
      tfile.open("TRAIN.DAT",ios::binary);
      tmfile.open("TEMP.DAT");
      cout<<date;
      cout<<"\n\n\nENTER THE TRAIN NUMBER:"<<endl;
      cin>>tn;
      while(!tfile.eof())
	  {
	  tfile.read((char*)&t,sizeof(t));
	  if(t.trainno()!=tn)
	    tmfile.write((char*)&t,sizeof(t));
	  if(t.trainno()==tn)
	    flag=1;
	  }
      if(flag==1)
	{
	cout<<"ARE YOU SURE TO DELETE THE TRAIN"<<endl;
	cout<<"PRESS 'C' TOCONFIRM"<<endl;
	cin>>c;
	if(c=='c')
	  {
	  tfile.close();
	  tmfile.close();
	  remove("TRAIN.DAT");
	  rename("TEMP.DAT","TRAIN.DAT");
	  textcolor(2+128);cout<<"\n\t\t";
	  cputs("THE TRAIN HAS BEEN DELETED....");
	  }
	 if(c!='c')
	   {
	   tfile.close();
	   tmfile.close();
	   remove("TEMP.DAT");
	   cout<<"\nTHE TRAIN WAS NOT DELETED!!"<<endl;
	   }
	 }
      else
       cout<<"\nNO TRAINS FOUND!!CHECK AGAIN LATER";
       sleep(5);
     tfile.close();
     tmfile.close();
     }


void reserve()
{
	textcolor(9);
	clrscr();
	float tn;
	char ch1,pay[5];
	int d,i,book=0,flag=0,pos;
	ifstream trfile;
	trfile.open("TRAIN.DAT",ios::binary);
	textcolor(12);
	cputs("--------------------------------------------------------------------------------");
	gotoxy(1,3);
	cputs("--------------------------------------------------------------------------------");
	textcolor(2);
	gotoxy(29,2);
	cputs("RESERVATION PAGE");
	cout<<"\n\n\nEnter the train number:";
	cin>>tn;
	while(!trfile.eof())
	     {
	     trfile.read((char*)&t,sizeof(t));
	     if(t.trainno()==tn)
	       {
		pos=trfile.tellg();
		book=p.resfile(tn);
		t.seatschange(pos);
		flag=1;
		if(book==1)
		  {
		   cout<<"\nYOU HAVE TO PAY="<<p.f;
		   cout<<"\n\nType 'PAY' to proceed your payment"<<endl;
		   cin>>pay;
		   cout<<"\nPAYMENT ON PROCESS";
		   for(i=0;i<5;i++)
		      {
		      cout<<".";
		      sleep(1);
		      }
		   cout<<"\nPAYMENT SUCCESFUL!!\n\t\t\t"<<endl;
		   textcolor(RED+128);   //128 is the value for BLINK
		   cputs("**YOUR SEATS HAVE BEEN RESVERED**");
		   sleep(3);
		   cout<<"\n\nCheck and Print your tickets through Report";
		   break;
		  }
	       }
	     }
	     if(flag!=1)
	       cout<<"\n\nNo trains found";
	       cout<<"\nREDRICTING TO USER MENU...";
	       sleep(5);
trfile.close();
}
void report()
     {
     clrscr();
     int rno,flag=0;
     ifstream file;
     file.open("PASSENGER.DAT",ios::binary);
     cout<<date;
     cout<<"\nENTER YOUR RESERVATION ID TO GET REPORTS"<<endl;
     cin>>rno;
     while(!file.eof())
	  {
	  file.read((char*)&p,sizeof(p));
	  if(p.rtno()==rno)
	    {
	    p.display();
	    textcolor(5+128);
	    cout<<"\n\t\t\t";
	    cputs("HAPPY JOURNEY!!");
	    cout<<endl;
	    flag=1;
	    break;
	    }
	  }
     if(flag!=1)
       {
       cout<<"\nWRONG RESERVATION ID";
       cout<<"\nCHECK AGAIN LATER\n\n";
       }
       sleep(3);
       system("pause");
       file.close();
     }
void cancel()
{
      textcolor(9);
      clrscr();
      int rno,tf,x=0;
      char ch;
      ifstream file;
      ofstream tmfile;
      file.open("PASSENGER.DAT",ios::binary);
      tmfile.open("TEMP.DAT");
      cout<<date<<endl;
      textcolor(12);
      cputs("-z-------------------------------------------------------------------------------");
      gotoxy(1,4);
      cputs("--------------------------------------------------------------------------------");
      textcolor(2);
      gotoxy(29,3);
      cputs("CANCELATION PAGE");
      cout<<"\n\n\nENTER YOUR RESERVATION ID TO CANCEL THE TICKETS"<<endl;
      cin>>rno;
      while(!file.eof())
	  {
	  file.read((char*)&p,sizeof(p));
	  if(p.rtno()!=rno)
	    {
	     tmfile.write((char*)&p,sizeof(p));
	    }
	  if(p.rtno()==rno)
	    tf=p.f;
	  }
      if(p.rtno()==rno)
	{
      cout<<"\nYOUR DETAILS:\n\n\n";
      p.display();
      cout<<"\n\n";
      while(!kbhit())
	   {
	   clrscr();
	   gotoxy(x,1);
	   textcolor(12);
	   cputs("ARE YOU SURE TO CANCEL...YOU WILL BE REFUNDED ONLY");
	   cout<<"'80% OF THE TOTAL FARE'";
	   delay(100);
	   x++;
	   if(x>=80)
	     x=0;
	   }
      delay(3);
      cout<<"\n\nPRESS 'C' to confirm"<<endl;
      cin>>ch;
       if(ch=='c')
	 {
	float refund;
	refund=tf*(0.8);
	file.close();
	tmfile.close();
	remove("PASSENGER.DAT");
	rename("TEMP.DAT","PASSENGER.DAT");
	cout<<"\nYOU PAID:RS "<<tf;
	cout<<"\nYOU WILL BE REFUNDED=RS "<<refund;
	cout<<"\nYOU ARE AMMOUNT HAS BEEN REFUNDED";
	sleep(2);
	cout<<"\n\n\t\t";
	textcolor(12+128);
	cputs("YOUR TICKETS HAVE BEEN CANCELLED");
	sleep(8);
	 }
	if(ch!='c')
	  cout<<"\n\tYOUR TICKETS WAS NOT CANCELLED";
	}
      else
	cout<<"\nWRONG RESERVATION ID";
      file.close();
      tmfile.close();
      remove("TEMP.DAT");
      sleep(5);
}