#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
class book
{ public:
char bname[40], publ[25], lang[15], auth[20], genre, stat[20];
int bno, edition, price;
public:
void enter()
{
cout<<"Enter the book details "<<endl;
cout<<"Book No. ";
cin>>bno;
cout<<"Publisher ";
gets(publ);
cout<<"Book Name ";
gets(bname);
cout<<"Language ";
cin>>lang;
cout<<"Author's Name ";
gets(auth);
cout<<"Genre ";
cin>>genre;
cout<<"Edition ";
cin>>edition;
cout<<"Price ";
cin>>price;
strcpy(stat,"available");
}
void output()
{
cout<<"Book No. "<<bno<<endl;
cout<<"Publisher "<<publ<<endl;
cout<<"Book Name "<<bname<<endl;
cout<<"Language "<<lang<<endl;
cout<<"Author's Name "<<auth<<endl;
cout<<"Genre "<<genre<<endl;
cout<<"Edition "<<edition<<endl;
cout<<"Price "<<price<<endl;
}
}bbook;
class member
{
public:
int mid, mtotal, issuedbno;
long int contact;
char fname[15], sname[15], madd[50];
member()
{
mtotal=0;
}
void newmem()  //entry
{
cout<<"enter member details"<<endl;
mtotal++;
mid++;
cout<<"member's name\n"<<"   first name  ";
gets(fname);
cout<<"   surname  ";
gets(sname);
cout<<"contact number";
cin>>contact;
cout<<"member's address";
gets(madd);
}
void dispmem()
{
cout<<"___Member details___"<<endl;
cout<<"First Name - "<<fname<<endl;
cout<<"Last Name - "<<sname<<endl;
cout<<"ID no. - "<<mid<<endl;
cout<<"Contact no. - "<<contact<<endl;
cout<<"Address - "<<madd<<endl;
}
}mem;

void main()
{                             //1
 int mach;
 clrscr();
 do
 {
 clrscr();
 cout<<endl<<"\t\t\t***Main MENU***"<<endl<<endl<<endl;
 cout<<"1. Books"<<endl;
 cout<<"2. Membership"<<endl;
 cout<<"3. Issuing"<<endl;
 cout<<"4. Returning"<<endl;
 cout<<"5. Exit"<<endl;
 cin>>mach;
 switch(mach)
  {                               //2
  case 1:
  int boch;
  do
   {                                 //3
   clrscr();
   cout<<endl<<"\t\t\t***BOOK MENU***"<<endl<<endl<<endl;
   cout<<"1. Enter new books"<<endl;
   cout<<"2. Search books"<<endl;
   cout<<"3. Delete books"<<endl;
   cout<<"4. Back"<<endl;
   cin>>boch;
   switch(boch)
    {                                   //4
    case 1:
    ofstream fout;
    fout.open("pro.dat", ios::binary|ios::app);
    bbook.enter();
    fout.write((char*)&bbook, sizeof(bbook));
    fout.close();
    break;
    case 2:
    char ent, s1[40];
    int r1=0;
    ifstream fin;
    fin.open("pro.dat", ios::binary);
    cout<<"Search books thru n(name)/a(author)/l(language) ";
    cin>>ent;
    switch(ent)
     {                                      //5
      case 'n':
      cout<<"enter the book name";
      gets(s1);
      fin.seekg(0);
      while(fin.read((char*)&bbook,sizeof(bbook)))
       {                                             //6
	if(strcmp(bbook.bname,s1)==0)
	 {                                            //7
	  r1=1;
	  bbook.output();
	 }                                              //c7
       }                                                 //c6
      if(r1==0)
      cout<<"|*_*|  not found";
      fin.close();
      getch();
      break;
      case 'a':
      cout<<"enter the author name";
      gets(s1);
      fin.seekg(0);
      while(fin.read((char*)&bbook,sizeof(bbook)))
       {                                                //8
	if(strcmp(bbook.auth,s1)==0)
	 {                                                  //9
	  r1=1;
	  bbook.output();
	 }                                            //c9
       }                                                  //c8
      if(r1==0)
      cout<<"|*_*|  not found";
      fin.close();
      getch();
      break;
      case 'l':
      cout<<"enter the language of book";
      gets(s1);
      fin.seekg(0);
      while(fin.read((char*)&bbook,sizeof(bbook)))
       {                                                 //10
	if(strcmp(bbook.lang,s1)==0)
	 {                                           //11
	  r1=1;
	  bbook.output();
	 }                                       //c11
       }                                              //c10
      if(r1==0)
      cout<<"|*_*|  not found";
      fin.close();
      getch();
      break;
     }                                   //c5
    break;
    case 3:
    ifstream afile;
    ofstream bfile;
    afile.open("pro.dat",ios::binary|ios::in);
    bfile.open("temp1.dat",ios::out|ios::app|ios::binary);
    int bookno;
    cout<<"enter the book no. to be deleted";
    cin>>bookno;
    afile.seekg(0);
    while(afile.read((char*)&bbook, sizeof(bbook)))
     {                                          //12
      if(bbook.bno!=bookno)
       {                                               //13
	bfile.write((char*)&bbook, sizeof(bbook));
       }                                             //c13
     }                                         //c12
    afile.close();
    bfile.close();
    remove("pro.dat");
    rename("temp1.dat", "pro.dat");
    break;
    case 4:
    break;
   }                                   //c4
   }while(boch<4);                         //c3
  break;
  case 2:
  clrscr();
  int memch;
  do
  {
  clrscr();
  cout<<endl<<"\t\t\tMembership MENU"<<endl<<endl<<endl;
  cout<<"1. New Member Details "<<endl;
  cout<<"2. Search existing members"<<endl;
  cout<<"3. Renew Member details"<<endl;
  cout<<"4. Delete existing members"<<endl;
  cout<<"5. Back"<<endl;
  cin>>memch;
  switch(memch)
   {                         //14
    case 1:
    ofstream fout1;
    fout1.open("pro2.dat",ios::binary||ios::app);
    mem.newmem();
    fout1.write((char*)&mem,sizeof(mem));
    fout1.close();
    break;
    case 2:
    char s2[15];
    int r2=0;
    ifstream fin1;
    fin1.open("pro2.dat",ios::binary);
    cout<<"enter the first name";
    gets(s2);
    fin1.seekg(0);
    while(fin1.read((char*)&mem,sizeof(mem)))
     {                                   //15
      if(strcmp(mem.fname,s2)==0)
       {                         //16
	r2=1;
	cout<<"**********************************************************************";
	mem.dispmem();
	cout<<"**********************************************************************";
       }                         //c16
     }                                //c15
    if(r2==0)
    cout<<"|*_*|   not found";
    fin1.close();
    getch();
    break;
    case 3:
    clrscr();
    int rch, memid;
    long int newcont;
    char newadd[60];
    fstream f;
    f.open("pro2.dat", ios::binary|ios::in|ios::out);
    cout<<"1. Renew contact no."<<endl;
    cout<<"2. Renew address "<<endl;
    cin>>rch;
    cout<<"Enter member id ";
    cin>>memid;
    if(rch==1)
     {                     //17
      f.seekg(0);
      while(f.read((char*)&mem, sizeof(mem)))
       {                      //18
	if(mem.mid==memid)
	 {                      //19
	  cout<<"Existing contact no. "<<mem.contact;
	  cout<<"Enter the new contact no. ";
	  cin>>newcont;
	  int t=f.tellg();
	  t=t-sizeof(mem);
	  f.seekg(t);
	  mem.contact=newcont;
	  f.write((char*)&mem, sizeof(mem));
	 }                         //c19
       }                           //c18
     }                                     //c17
    if(rch==2)
     {                                    //20
      f.seekg(0);
      while(f.read((char*)&mem, sizeof(mem)))
       {                                      //21
	if(mem.mid==memid)
	 {                                        //22
	  cout<<"existing address\n"<<mem.madd;
	  cout<<"enter the new address";
	  gets(newadd);
	  int x=f.tellg();
	  x=x-sizeof(mem);
	  f.seekg(x);
	  strcpy(mem.madd, newadd);
	  f.write((char*)&mem, sizeof(mem));
	 }                             //c22
       }                             //c21
     }                               //c20
    f.close();
    break;
    case 4:
    ifstream a1file;
    ofstream b1file;
    a1file.open("pro2.dat",ios::binary|ios::app);
    b1file.open("temp2.dat",ios::out|ios::binary);
    int m2id;
    cout<<"enter the member id to be deleted    ";
    cin>>m2id;
    a1file.seekg(0);
    while(a1file.read((char*)&mem, sizeof(mem)))
     {                                 //23
      if (mem.mid!=m2id)
       {                              //24
	b1file.write((char*)&mem, sizeof(mem));
       }                                 //c24
     }                                   //c23
    mem.mtotal--;
    a1file.close();
    b1file.close();
    remove("pro2.dat");
    rename("temp2.dat","pro2.dat");
    break;
    case 5:
    break;
   }                              //c14
   }while(memch<5);
  break;
  case 3:
  fstream fin2, fin3;
  fin3.open("pro2.dat", ios::binary|ios::in|ios::out);
  fin2.open("pro.dat",ios::binary|ios::in|ios::out);
  int ino, flag2=0, imember;
  cout<<endl<<"\t\t\tIssue books "<<endl<<endl<<endl;
  cout<<"enter book no. ";
  cin>>ino;
  fin2.seekg(0);
  while(fin2.read((char*)&bbook, sizeof(bbook)))
   {                         //25
    if(bbook.bno==ino)
     {                            //26
      if(strcmp(bbook.stat,"available")==0)
       {                                //27
	cout<<"OK"<<endl;
	flag2=1;
	int z=fin2.tellg();
	z=z-sizeof(bbook);
	fin2.seekg(z);
	strcpy(bbook.stat,"unavailable");
	fin2.write((char*)&bbook, sizeof(bbook));
       }                                        //c27
      else
       {                          //28
	cout<<"unavailable";
	flag2=0;
       }                             //c28
     }                                 //c26
   }                                    //c25
  if(flag2==1)
   {                                                 //30
    cout<<"enter member id  ";
    cin>>imember;
    fin3.seekg(0);
    while(fin3.read((char*)&mem, sizeof(mem)))
     {                                           //29
      if(mem.mid==imember)
       {                                         //31
	int y=fin3.tellg();
	y=y-sizeof(mem);
	fin3.seekg(y);
	mem.issuedbno=ino;
	fin3.write((char*)&mem, sizeof(mem));
	cout<<bbook.bname<<"has been issued to "<<mem.fname<<endl;
       }                                        //c31
     }                                               //c29
   }                                                      //c30
  fin3.close();
  fin2.close();
  break;
  case 4:
  int rno, sh=0;
  fstream _f1, _f2;
  _f1.open("pro.dat", ios::binary|ios::in|ios::out);
  _f2.open("pro2.dat",ios::binary|ios::in|ios::out);
  cout<<endl<<"\t\t\tReturn Books"<<endl<<endl<<endl;
  cout<<"enter the book no. to be returned  ";
  cin>>rno;
  while(_f2.read((char*)&mem, sizeof(mem)))
   {                                                        //32
    if (mem.issuedbno==rno)
     {                                           //33
      int pq=_f2.tellg();
      pq=pq-sizeof(mem);
      mem.issuedbno=0;
      _f2.write((char*)&mem, sizeof(mem));
      sh=1;
     }                     //c33
   }                         //c32
  if(sh==1)
   {                                  //34
    while(_f1.read((char*)&bbook, sizeof(bbook)))
     {                                    //35
      if(bbook.bno==rno)
       {                                      //36
	int mn=_f1.tellg();
	mn=mn-sizeof(bbook);
	strcpy(bbook.stat,"available");
	_f1.write((char*)&bbook, sizeof(bbook));
	cout<<rno<<" (book) has been returned sucessfully."<<endl;
       }                             //c36
     }                                    //c35
   }                                          //c34
  break;
  case 5:
  exit(0);
 }                                        //c2
 }while(mach<5);
getch();
}                                             //c1