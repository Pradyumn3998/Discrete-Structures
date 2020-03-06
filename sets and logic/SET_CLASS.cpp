#include <iostream>
#include <cmath>

using namespace std;

class Set{
public:
  int uni[10]={0,1,2,3,4,5,6,7,8,9};
  int A[10];
  int x;

  void Enter(){
       cout<<"Enter the number of elements in Set : \n";
       cin>>x;
      for (int i = 0; i < x; i++) {
          cout<<"Enter Now:\n";
          cin>>A[i];
    }
  }

  void chksbst(const Set &B){
    int z=0;
    int y=0;
    for(int i=0;i<x;i++){
      for(int j=0;j<B.x;j++){
        if(A[i]==B.A[j]){
        z=1;
        break;
      }
      else
      z=0;
    }
      y+=z;
    }
    if(y==x)
    cout<<"A is the Subset of B\n";
    else
    cout<<"A is not the Subset of B\n";
  }
  void cmp(){
      int s=0;
    for(int i=0;i<10;i++){
      for(int j=0;j<x;j++){
        if(A[j]==uni[i]){
                s=0;
            break;}
        else
            s=1;
      }
          if(s==1){
          cout<<"\t"<<uni[i];
          s=0;
          }
      }

       cout<<endl;
    }

  void diff (const Set &B){
      for(int i=0;i<x;i++){
      int z=0;
      for(int j=0;j<B.x;j++){
        if(A[i]==B.A[j]){
          z=1;break;
        }
      }
      if(z!=1)
      cout<<"\t"<<A[i];

 }
}

  void dif(const Set &B){
    cout<<"Difference between two sets:";
    for(int i=0;i<x;i++){
      int z=0;
      for(int j=0;j<B.x;j++){
        if(A[i]==B.A[j]){
          z=1;break;
        }
      }
      if(z!=1)
      cout<<"\t"<<A[i];
    }
          cout<<endl;

          cout<<"Symmetric Difference between two sets:";
          for(int i=0;i<x;i++){
            int z=0;
            for(int j=0;j<B.x;j++){
              if(A[i]==B.A[j]){
                z=1;break;
              }
            }
          if(z!=1)
          cout<<"\t"<<A[i];
  }
  for(int i=0;i<B.x;i++){
    int z=0;
    for(int j=0;j<x;j++){
      if(B.A[i]==A[j]){
        z=1;break;
      }
    }
  if(z!=1)
  cout<<"\t"<<B.A[i];
}
cout<<endl;
}

void cart(const Set &B){
  cout<<"Cartesian Product of Sets :\n{ ";
  for(int i=0;i<x;i++){
    for(int j=0;j<B.x;j++){
      cout<<"( "<<A[i]<<","<<B.A[j]<<" )  ";
    }
  }
  cout<<" }\n";

}

void UnI(const Set &B){

  cout<<"Intersection of Sets:\n\t{ ";
  for(int i=0;i<x;i++){
    int g=0;
    for(int j=0;j<B.x;j++){
      if(A[i]==B.A[j]){
        g=1;
        break;
      }
    }if(g==1)
    cout<<A[i]<<" ";
  }
cout<<"}\n";

  cout<<"Union of Sets:\n\t{ ";
    for(int i=0;i<x;i++){
    int g=0;
    for(int j=0;j<B.x;j++){
      if(A[i]==B.A[j]){
        g=1;
        break;
      }
    }if(g==1)
    cout<<A[i]<<" ";

    }
  }


  void get (){
    for (int i = 0; i < x; i++) {
          cout<<"\t"<<A[i]<<"\t{ ";
    }
  }

};

int main()
{
   Set one;

   Set two;
   char d;
   int ch;

   do{
   cout<<"\n\n\tMENU\n1\tTo check For Subset\n2\tTo Find Union and Intersection of Sets\n3\tTo Find Complement of Set\n4\tTo Find Difference And Symmetric Difference of two Sets\n5\tTo find Cartesian Product of Sets\n\n\n";
   cin>>ch;
   switch(ch){
     case 1:
         one.Enter();
         two.Enter();
     one.chksbst(two);
     cout<<"Do Want to perform another Function (Y / N)\n";
     cin>>d;
     break;
     case 2:
        one.Enter();
        two.Enter();
     one.UnI(two);
     one.diff(two);
     two.diff(one);
     cout<<" }\n";
     cout<<"Do Want to perform another Function (Y / N)\n";
     cin>>d;
     break;
     case 3:
     one.Enter();
     one.cmp();
     cout<<"Do Want to perform another Function (Y / N)\n";
     cin>>d;
     break;
     case 4:
        one.Enter();
        two.Enter();
     one.dif(two);
     cout<<"Do Want to perform another Function (Y / N)\n";
     cin>>d;
     break;
     case 5:
        one.Enter();
        two.Enter();
     one.cart(two);
     cout<<"Do Want to perform another Function (Y / N)\n";
     cin>>d;
     break;
     default:
     cout<<"Wrong Choice\n";
     cout<<"Do Want to perform another Function (Y / N)\n";
     cin>>d;
   }
 }while (d=='y'||d=='Y');
 return 0;
}

