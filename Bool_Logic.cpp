#include<iostream>

using namespace std;
char AND(char ,char );
char OR(char ,char );
char XOR(char ,char );
char NOT(char );
char Conditional(char ,char );
char Biconditional(char , char );
/**
 * @brief      { function_description }
 *
 * @param      p     { parameter_description }
 * @param      q     The quarter
 */
void Enter(char p[],char q[]){
	for(int i=0;i<4;i++){
		if(i<2){
			p[i] = 'F';
		}

		else
			p[i]='T';
	}
	for(int i=0;i<4;i++){
		if(i%2==0){
			q[i] = 'F';
		}
		else
			q[i]='T';
	}

}
void Print(){
}
int main(){

	char p[8],q[8],x,y;
	int size,ch=0;
x:
	cout<<"\n##########################################";
	cout<<"\n##	        TRUTH TABLE'S MENU      ##";
	cout<<"\n##########################################";
	cout<<"\n1 . AND ";
	cout<<"\n2 . OR ";
	cout<<"\n3 . NOT ";
	cout<<"\n4 . XOR ";
	cout<<"\n5 . Conditional";
	cout<<"\n6 . Biconditional";
	cout<<"\n7 . Exit ";

	cout<<"\nENTER YOUR CHOICE : ";
	cin >> ch;
	Enter(p,q);


	if(ch == 1){
        int ch2;
        cout<<"\n##   OPTION  ##";
        cout<<"\n1. Truth Table";
        cout<<"\n2. User Input";
        cout<<"\n Enter your choice::";
        cin >> ch2;
        if(ch2==1){
            cout<<"\n| p\t| q\t| result\t| ";
            for(int i=0; i<4;i++ )
            {
                cout<<"\n "<<p[i]<<"\t"<<q[i]<<"\t"<<AND(p[i],q[i]);
            }
		}
		else if(ch2==2){
            cout<<"\nEnter value of 1'st('T/F')::";
            cin>> x;
            cout<<"\nEnter value of 2'nd('T/F')::";
            cin>> y;
            cout<<"\n\n INPUT 1 :: "<<x<<" | INPUT 2 :: "<<y<<" | Result :: "<<AND(x,y);
		}
	}
    else if(ch == 2){
        int ch2;
        cout<<"\n##   OPTION  ##";
        cout<<"\n1. Truth Table";
        cout<<"\n2. User Input";
        cin >> ch2;
        if(ch2==1){
            cout<<"\n| p\t| q\t| result\t| ";
            for(int i=0; i<4;i++ )
            {
                cout<<"\n "<<p[i]<<"\t"<<q[i]<<"\t"<<OR(p[i],q[i]);
            }
		}
		else if(ch2==2){
            cout<<"\nEnter value of 1'st('T/F')::";
            cin>> x;
            cout<<"\nEnter value of 2'nd('T/F')::";
            cin>> y;
            cout<<"Result :: "<<OR(x,y);
		}
	}
    else if(ch == 3){
        int ch2;
        cout<<"\n##   OPTION  ##";
        cout<<"\n1. Truth Table";
        cout<<"\n2. User Input";
        cin >> ch2;
        if(ch2==1){
            cout<<"\n| p\t| q\t| result\t| ";
            for(int i=0; i<4;i++ )
            {
                cout<<"\n "<<p[i]<<"\t"<<q[i]<<"\t"<<XOR(p[i],q[i]);
            }
		}
		else if(ch2==2){
            cout<<"\nEnter value of 1'st('T/F')::";
            cin>> x;
            cout<<"\nEnter value of 2'nd('T/F')::";
            cin>> y;
            cout<<"Result :: "<<XOR(x,y);
		}
	}

	else if(ch == 4){
		cout<<"\n| p\t | result\t| ";
		for(int i=0; i<2;i++ )
		{
			cout<<"\n "<<q[i]<<"\t"<<NOT(q[i]);
		}

    }

    else if(ch==5){
     	int ch2;
        cout<<"\n##   OPTION  ##";
        cout<<"\n1. Truth Table";
        cout<<"\n2. User Input\n";
        cin >> ch2;
        if(ch2==1){
            cout<<"\n| p\t| q\t| result\t| ";
            for(int i=0; i<4;i++ )
            {
                cout<<"\n "<<p[i]<<"\t"<<q[i]<<"\t"<<Conditional(p[i],q[i]);
            }
		}
		else if(ch2==2){
            cout<<"\nEnter value of 1'st('T/F')::";
            cin>> x;
            cout<<"\nEnter value of 2'nd('T/F')::";
            cin>> y;
            cout<<"Result :: "<<Conditional(x,y);
		}
 	 }

 	else if(ch==6){
     	        int ch2;
        cout<<"\n##   OPTION  ##";
        cout<<"\n1. Truth Table";
        cout<<"\n2. User Input";
        cin >> ch2;
        if(ch2==1){
            cout<<"\n| p\t| q\t| result\t| ";
            for(int i=0; i<4;i++ )
            {
                cout<<"\n "<<p[i]<<"\t"<<q[i]<<"\t"<<Biconditional(p[i],q[i]);
            }
		}
		else if(ch2==2){
            cout<<"\nEnter value of 1'st('T/F')::";
            cin>> x;
            cout<<"\nEnter value of 2'nd('T/F')::";
            cin>> y;
            cout<<"Result :: "<<Biconditional(x,y);
		}
 	 }
 	 else if (ch>=7){
        exit(0);
 	 }
 goto x;
	return 0;
}

char AND(char p,char q){
	char result;
	if(p == q && p == 'T'){
		result = 'T';
	}
	else{
		result = 'F';
	}
	return result;
}
char OR(char p,char q){
	char result;
	if(p == q && p == 'F'){
		result = 'F';
	}
	else{
		result = 'T';
	}
	return result;
}
char XOR(char p,char q){
	char result;
	if(p == q ){
		result = 'F';
	}
	else{
		result = 'T';
	}
	return result;
}
char NOT(char q){
	char result;
	if(q == 'T'){
		result = 'F';
	}
	else{
		result = 'T';
	}
	return result;
}

char Conditional(char p,char q){
	char result;

	if(p == 'F' && p!=q){
		result = 'F';
	}
	else{
		result = 'T';
	}
	return result;

}



char Biconditional(char p,char q){
	char result;

	if((p == 'F'||q=='F') && p!=q  ){
		result = 'F';
	}
	else{
		result = 'T';
	}
	return result;

}
