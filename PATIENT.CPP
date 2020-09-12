
// project for patient management

#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<stdlib.h>
	struct date
	{
		int dd,mm,yy;
	};
	struct patient
	{
		int pno;
		char name[20];
		struct date doa;
	       char desise[10];
		char address[15];
	       int floor;
	       int room;
	}p;

       /*	struct modl
	{
		char model[10];
		char facility[30];
	}m;
       */

class box                                  //program to create box
{
		char tl,tr,bl,br,v,h;
		int bt;
	public:
	       box(int,int,int,int,int);
 };
 box::box(int r1=1, int c1=1, int r2=24, int c2=80, int bt=1)
 {
	if(bt==1)
	{
		tl=218; tr=191;
		bl=192; br=217;
		v=179; h=196;
	}
	else
	{
		tl=201; tr=187;
		bl=200; br=188;
		v=186; h=205;
	}
		int i;
	gotoxy(c1,r1);
	cout<<tl;
	gotoxy(c1,r2);
	cout<<bl;
	for(i=c1+1;i<c2;++i)
	{
		gotoxy(i,r1);
		cout<<h;
		gotoxy(i,r2);
		cout<<h;
	}
	for(i=r1+1;i<r2;++i)
	{
		gotoxy(c1,i);
		cout<<v;
		gotoxy(c2,i);
		cout<<v;
	}
	{
		gotoxy(c2,r1);
		cout<<tr;
		gotoxy(c2,r2);
		cout<<br;
	 }
 }


void menu();
void main()
{
	void welcomec();
	clrscr();
	textbackground(WHITE);
	welcomec();
}
	void welcomec()
	{
		int cho;
		do
		{
			box z1(1,14,14,68,2);
			box z2(11,25,13,55,1);
			gotoxy(25,3);
			textcolor(BLUE+BLINK);
			cprintf("  WELCOME TO XYZ HOSPITAL");
			textcolor(BROWN);
			gotoxy(16,5);
			cprintf("      A projact created by Rahul Kundu");
			textcolor(RED);
			gotoxy(30,8);
			cprintf("Press <1> for MENU");
			gotoxy(30,10);
			cprintf("Press <2> for EXIT");
			gotoxy(28,12);
			cprintf("Enter your choice<1-2>:");
			cin>>cho;
			switch(cho)
			{
				case 1:
					menu();
					break;
				case 2:
					clrscr();
					box r1(1,24,10,60,2);
					textcolor(BLUE+BLINK);
					gotoxy(25,3);
					cprintf(" THANKS FOR VISITING THE PROJECT");
					gotoxy(30,5);
					printf("Created by-----");
					gotoxy(35,7);
					cprintf("Rahul Kundu");
					getch();
					return;
			}
			clrscr();
		}while(cho!=2);
}


void addf();
void list1();
void submenu();
void erasef();
void menu()                 //program to create main menu
{
	int cho, r=27;
	do
	{
		clrscr();
		box b1(1,15,19,70,2);
	   //	getch();
		box d2(16,16,18,68,1);
	    //	getch();
		gotoxy(r+5,3);
		textcolor(BLUE+BLINK);
		cprintf("****** M E N U ******");
		textcolor(RED);
		gotoxy(r,5);
		cprintf("1.ADD PATIENT DETAILS");
		textcolor(RED);
		gotoxy(r,7);
		cprintf("2.DISPLAY PATIENT DETAILS");
		textcolor(RED);
		gotoxy(r,9);
		cprintf("3.SEARCH");
		textcolor(RED);
		gotoxy(r,11);
		cprintf("4.DELETE");
		textcolor(RED);
		gotoxy(r,13);
		cprintf("5.Exit");
		gotoxy(r-2,17);
		cprintf("Enter your choice(1-5):-");
		cin>>cho;
	switch(cho)
	{
		case 1:
			addf();
			break;
		case 2:
			list1();
			break;
		case 3:
			submenu();
			break;
		case 4:
			erasef();
			break;
		case 5:
			return;
	}
	clrscr();
	}while(cho!=6);
}



void addf()                    //program to add patient details
	{
		char cho;
		FILE *fp;
		fp=fopen("patient.dat","ab");
	do
	{
		clrscr();
		 box x(2,20,25,60,1);
	       //	 getch();
		gotoxy(30,5);
		textcolor(RED);
		cprintf("Add Customer Details:");
		gotoxy(35,7);
		textcolor(BLUE);
		cprintf("Patient no:");
		scanf("%d",&p.pno);
		gotoxy(41,9);
		cprintf("Name:");
		scanf("%s",&p.name);
		gotoxy(38,11);
		cprintf("Address:");
		scanf("%s",&p.address);
		gotoxy(29,13);
		cprintf("Date of Admission:");
		scanf("%d%d%d",&p.doa.dd,&p.doa.mm,&p.doa.yy);
		gotoxy(39,15);
		cprintf("Disease:");
		scanf("%s",&p.desise);
		gotoxy(38,17);
		cprintf("Floor no:");
		scanf("%d",&p.floor);
		gotoxy(38,19);
		cprintf("Room No:");
		scanf("%d",&p.room);
		fwrite(&p,sizeof(p),1,fp);
		gotoxy(25,21);
		textcolor(RED);
		cprintf("Wants to continue...(Y/N):");
		cin>>cho;
	}while(cho=='y');
	fclose(fp);
	}




	void list1()               //program to display  patient details
	{
		FILE *fp;
		int rc=1;
		void head();
		fp=fopen("patient.dat","rb");
		clrscr();
		head();
		rc=2;
		while(fread(&p,sizeof(p),1,fp)!=NULL)
		{
			if(rc%19 !=0)
			{
			printf("%-10d  %-10s %-5s %15d-%2d-%4d %-8s %-6d %6d\n",p.pno,p.name,p.address,p.doa.dd,p.doa.mm,p.doa.yy,p.desise,p.floor,p.room);
			rc++;
			}
			else
			{
			printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("Press any kye to continue...");
			getch();
			clrscr();
			head();
			rc=4;
			}
		 }
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Press any key...");
		fclose(fp);
		getch();
	}
	void head()
	{
		textcolor(RED+BLINK);
		cprintf("        List of Customer ");
		printf("\n\t\t\t\t\tDate:-%s\n",__DATE__);
		textcolor(BLUE);
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		cprintf("Patient NO   NAME      Address      DATE_OF_Admision  Desise Floor_No Room_NO");
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}


void search();
void search_char();
void submenu()                      //subprogram for search menu
{
	int cho, r=27;
	do
	{
		clrscr();
		box b1(1,15,13,70,1);
	   //	getch();
		box d2(10,17,12,68,1);
	    //	getch();
		gotoxy(r+5,3);
		textcolor(BLUE+BLINK);
		cprintf("****** S E A R C H ******");
		textcolor(RED);
		gotoxy(r,5);
		cprintf("1.SEARCH BY Patient NO");
		textcolor(RED);
		gotoxy(r,7);
		cprintf("2.SEARCH BY Patient NAME");
		textcolor(RED);
		gotoxy(r,9);
		cprintf("3.BACK");
		gotoxy(r-2,11);
		cprintf("Enter your choice(1-3):-");
		cin>>cho;
	switch(cho)
	{
		case 1:
			search();
			break;
		case 2:
			search_char();
			break;
		case 3:
			return;
	}
	clrscr();
	}while(cho!=3);
}


	void search()                     //program for search by number
	{
		FILE *fp;
		int found=0,ino;
		void get();
		fp=fopen("patient.dat","rb");
		clrscr();
		cout<<"\n Enter Patient no to be search:";
		cin>>ino;
		//head();
		while(fread(&p,sizeof(p),1,fp)!=NULL)
		{
			if(p.pno==ino)
			{
			get();
			printf("%-10d  %-10s %-5s %15d-%2d-%4d %-8s %-6d %6d\n",p.pno,p.name,p.address,p.doa.dd,p.doa.mm,p.doa.yy,p.desise,p.floor,p.room);
			found=1;
			break;
			}

		 }
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Press any key...");
		if(found==0)
		{
			printf("Record Not Found");
		}
		fclose(fp);
		getch();
	}
	void get()
	{
		textcolor(RED+BLINK);
		printf("\n");
		cprintf("         Customer Details");
		printf("\n\t\t\t\t\tDate:-%s\n",__DATE__);
		textcolor(BLUE);
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		cprintf("Patient NO   NAME      Address      DATE_OF_Admision  Desise Floor_No Room_NO");
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}


	void search_char()                  //program for search by name
	{
		FILE *fp;
		int found=0;
		char cname[20];
		void get1();
		fp=fopen("patient.dat","rb");
		clrscr();
		cout<<"\n Enter Name to be search:";
		cin>>cname;
		//head();
		while(fread(&p,sizeof(p),1,fp)!=NULL)
		{
			if(strcmpi(p.name,cname)==0)
			{
			get1();
			printf("%-10d  %-10s %-5s %15d-%2d-%4d %-8s %-6d %6d\n",p.pno,p.name,p.address,p.doa.dd,p.doa.mm,p.doa.yy,p.desise,p.floor,p.room);
			found=1;
			break;
			}

		 }
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Press any key...");
		if(found==0)
		{
			printf("Record Not Found");
		}
		fclose(fp);
		getch();
	}
	void get1()
	{
		textcolor(RED+BLINK);
		printf("\n");
		cprintf("         Customer Details");
		printf("\n\t\t\t\t\tDate:-%s\n",__DATE__);
		textcolor(BLUE);
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		cprintf("Patient NO   NAME      Address      DATE_OF_Admision  Desise Floor_No Room_NO");
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		}


void erasef()                               //program for deletion
{
	int drno;
	clrscr();
	cout<<"\n Enter an Patient NO to be delete:";
	cin>>drno;
	FILE *fp;
	FILE *ft;
	fp=fopen("patient.dat","rb");
	ft=fopen("temp.dat","wb");
	while(fread(&p,sizeof(p),1,fp)!=NULL)
	{
		if(p.pno!=drno)
		{
			fwrite(&p,sizeof(p),1,ft);
		}
	}
	//fclose(fp);
	//fclose(ft);
	remove("custin.dat");
	rename("temp.dat","custin.dat");
	cout<<"\n------------------------------------------------------";
	cout<<"\nItem Deleted Successfully";
	cout<<"\n------------------------------------------------------";
	fclose(fp);
	fclose(ft);
       getch();
}

