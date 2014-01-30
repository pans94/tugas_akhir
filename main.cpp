#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std; 

//posisi katak yang akan melompat = x
char batu[7]={'J','J','J','_','B','B','B'};
char temp;

//ket : posisi awal katak betina di kanan
//ket : posisi awal katak jantan di kiri
void lompat(int x)
{
     if(batu[x]=='B')
     {
         //gerak lompat untuk betina 
         if(batu[x-1]=='J'&&batu[x-2]=='_')
         { 
            temp=batu[x];
            batu[x]=batu[x-2];
            batu[x-2]=temp;
            //mencari betina yang belum bergerak
            for(int i=6;i>=x+1;i--)
             {
              if (batu[i]=='B')
              temp=i;
             }
                   for(int i=0;i<=6;i++)
                   {
                   cout<<batu[i];
                   }
                    cout<<"\nbatu yang kosong "<<x+1<<endl<<endl;
              lompat(temp); //rekursi, betina bergerak
          }
          else
          //gerak geser untuk betina
             if(batu[x-1]=='_')
             { 
                 temp=batu[x];
                 batu[x]=batu[x-1];
                 batu[x-1]=temp;
                 //mencari jantan pertama giliran
                 for(int i=0;i<=6;i++)
                 {
                    if (batu[i]=='J')
                     temp=i;
                 }
                       for(int i=0;i<=6;i++)
                       {
                       cout<<batu[i];
                       }
                        cout<<"\nbatu yang kosong "<<x+1<<endl<<endl;
                 lompat(temp);//rekursi, jantan bergerak
              }
         }
                    
     else if(batu[x]=='J')
     {
         //gerak lompat untuk jantan
         if(batu[x+1]=='B'&&batu[x+2]=='_')
         { 
            temp=batu[x];
            batu[x]=batu[x+2];
            batu[x+2]=temp;
            //mencari jantan yang belum bergerak
            if (x!=0) //kalau nol, maka gantian betina bergerak
            {
             for(int i=0;i<=x;i++)
             {
              if (batu[i]=='J')
              temp=i;
             }
            }
             for(int i=0;i<=6;i++)
             {           
               cout<<batu[i];
             }
                 cout<<"\nbatu yang kosong "<<x+1<<endl<<endl;
              lompat(temp); //rekursi, jantan bergerak
          }
          else
          //gerak geser untuk jantan
             if(batu[x+1]=='_')
             { 
                 temp=batu[x];
                 batu[x]=batu[x+1];
                 batu[x+1]=temp;
                 //mencari betina pertama giliran
                 for(int i=6;i>=0;i--)
                 {
                    if (batu[i]=='B')
                     temp=i;
                 }
                       for(int i=0;i<=6;i++)
                       {
                       cout<<batu[i];
                       }
                       cout<<"\nbatu yang kosong "<<x+1<<endl<<endl;
                 lompat(temp);//rekursi, betina bergerak
              }
         }
}


void betina(int x)
{
         //gerak lompat untuk betina
         if(batu[x-1]=='J'&&batu[x-2]=='_')
         { 
            temp=batu[x];
            batu[x]=batu[x-2];
            batu[x-2]=temp;
            //mencari betina yang belum bergerak
            for(int i=x;i<=6;i++)
             {
              if (batu[i]=='B')
              temp=i;
             }
                   for(int i=0;i<=6;i++)
                   {
                   cout<<batu[i];
                   }
                    cout<<"\nbatu yang kosong "<<x+1<<endl<<endl;
              lompat(temp); //rekursi, betina bergerak
          }
          else
          //gerak geser untuk betina
             if(batu[x-1]=='_')
             { 
                 temp=batu[x];
                 batu[x]=batu[x-1];
                 batu[x-1]=temp;
               
                       for(int i=0;i<=6;i++)
                       {
                       cout<<batu[i];
                       }
                        cout<<"\nbatu yang kosong "<<x+1<<endl<<endl;
                       
                 lompat(x+2);//rekursi, jantan bergerak
                 }
}

void jantan(int x)
{
   //gerak lompat untuk jantan
         if(batu[x+1]=='B'&&batu[x+2]=='_')
         { 
            temp=batu[x];
            batu[x]=batu[x+2];
            batu[x+2]=temp;
            //mencari jantan yang belum bergerak
            if (x!=0) //kalau nol, maka gantian betina bergerak
            {
             for(int i=0;i<=x;i++)
             {
              if (batu[i]=='J')
              temp=i;
             }
            }
             for(int i=0;i<=6;i++)
             {           
               cout<<batu[i];
             }
                 cout<<"\nbatu yang kosong "<<x+1<<endl<<endl;
              lompat(temp);
              //rekursi, jantan bergerak
          }
          else
          //gerak geser untuk jantan
             if(batu[x+1]=='_')
             { 
                 temp=batu[x];
                 batu[x]=batu[x+1];
                 batu[x+1]=temp;
                 //mencari jantan pertama giliran
                 for(int i=6;i>=0;i--)
                 {
                    if (batu[i]=='J')
                     temp=i;
                 }
                       for(int i=0;i<=6;i++)
                       {
                       cout<<batu[i];
                       }
                       cout<<"\nbatu yang kosong "<<x+1<<endl<<endl;
                 lompat(temp);
              }
       }

int main()
{

   cout<<"=============================================\n\n";
   cout<<" Program Jump Frog Dengan Greedy\n\n";
   cout<<"---------------------------------------------\n\n";
 
cout<<"Keterangan :"<<endl;
cout<<"J : Katak Jantan     B : Katak Betina"<<endl;
cout<<"1 : Batu 1           4 : Batu 4 "<<endl;
cout<<"2 : Batu 2           5 : Batu 5 "<<endl;
cout<<"3 : Batu 3           6 : Batu 6 "<<endl;
cout<<"_ : Batu yang kosong"<<endl<<endl;

   cout<<"=======================================================================\n";
   cout<<"Awal posisi katak J J J _ B B B\n";
   cout<<"=======================================================================\n\n";


 lompat(4); 
      cout<<endl;
     
      betina(1);
      cout<<endl;
     
      jantan(4);
   

   cout<<"=======================================================================\n";
   cout<<"Akhir posisi katak B B B _ J J J\n";
   cout<<"=======================================================================\n\n\n\n";
   cout<<"---------------------------------------------\n\n";
   cout<<"Nama  : Riyan Herdian        NIM :10112154\n";
   cout<<"Nama  : Pandu Pramura Hardi  NIM :10112162\n\n";
   cout<<"Kelas : IF 5\n\n";
   cout<<"---------------------------------------------\n\n";

system("pause");
}
