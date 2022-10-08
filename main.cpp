#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<conio.h>
using namespace std;


class Encrypt {        
  public:              
    Encrypt(string& msg) {
        int n=msg.length();
        for(int i=0;i<n;i++){
            int c=(msg[i]-'a')+2;
            c%=26;
            msg[i]='a'+c;
        }
        cout<<"\n\nENCRYPTED PASSWORD : "<<msg<<"\n\n\n";
    }
};

class User {
    public:
    string username,password,number;
    long int bal;
    int lt=0;
    public:
    User(string name, string pword, string number ,long int ibal,int lt1) {
        username = name;
        Encrypt enc(pword);
        password = pword;
        number = number;
        bal = ibal;
    }
};

vector<User> users;

class Register {
    public:
    string username,password,cpass,number;
    public:
    Register(string name, string pword, string cpass, string number ,long int ibal,int lt) {
        if(pword==cpass) {
            if(ibal<10000)  {
                here:
                cout<<"***************\n\tInitial deposite must be greater than 10000\n***************\n";
                cout<<"\n\nDeposite More : ";
                int tem;
                cin>>tem;
                if(tem+ibal<10000) goto here;
                else {
                    User u1(name,pword,number,ibal,lt);
                    users.push_back(u1);
                    cout<<"***************\n\tRegistration Sucessful\n***************\n"; 
                }
            }
            else{
            User u1(name,pword,number,ibal,lt);
            users.push_back(u1);
	        cout<<"***************\n\tRegistration Sucessful\n***************\n";  }
        }
    }
};

class Login {
    public:
    string username,password;
    int i,f=0;
    public:
    Login(string name, string pword) {
        username = name;
        Encrypt enc(pword);
        password = pword;
        for(i=0;i<users.size();++i) {
            if(users[i].username==username && users[i].password==password) {
            	system("CLS");
	            cout<<"******************\n\tLOGGED IN SUCCESSFULLY\n******************\n"; 
				users[i].lt+=1; 
				cout<<"\nNo.Of Login's : "<<users[i].lt<<"\n\n\n";
                f=1;
                if(users[i].lt>5){
                	cout<<"\t\t!!! WARNING ,LOGGED IN MANY TIME -- CHANGE PASSWORD....\n\n";
                	cout<<"\n\n YOUR CHOICE [Y/N] : ";
                	char opt;
                	cin>>opt;
                	if(opt=='y'){
                		retry:
                		string Npass;
                		cout<<"ENTER THE NEW PASSWORD : ";
                		cin>>Npass;
                		if(Npass==users[i].password){
                			cout<<"\t\t!!! WARNING , TRY NEW PASSWORD ....\n\n";
                			goto retry;
                	
						}
                		users[i].password=Npass;
						cout<<"\t\tCHANGED SUCCESSFULLY, THANK YOU !!\n\n";
                		
					}
					else{
						cout<<"\t\tPLEASE DO IT AFTER SOMETIME !!\n\n";
					}
				}
                break;
            }
        }
        if(f==0) cout<<"Invalid Credintials";
    }
};


int main() {
	Home:
	cout<<"******************\n\tWELCOME TO 313 BANK\n******************\n";          
	cout<<"\n CHOOSE THE WAY ON ENTRY : \n\n";
	cout<<"1 > Login \n2 > Register\n3 > CLOSE APP\n";
	int c;
	cout<<"\nYour Option : ";
	cin>>c;
	string Lname,Lpass;
	string name,pass,Cpass,mob;
    long int ibal;
	int lt=0;
	switch(c){
		case 1:
			Login:
			system("CLS");
			cout<<"******************\n\t\tLOGIN\n******************\n";  
			cout<<"\n\nEnter Your USERNAME :";			
			cin>>Lname;
			cout<<"\n\nEnter Your PASSWORD :";
			cin>>Lpass;
            Login(Lname,Lpass);
            goto Home;
			break;
		case 2:
			system("CLS");
			cout<<"******************\n\t\t REGISTRATION\n******************\n";
			cout<<"\n\nEnter Your USERNAME :";			
			cin>>name;
			cout<<"\n\nEnter Your MOBILE NUMBER :";
			cin>>mob;
			cout<<"\n\nEnter Your PASSWORD :";
			cin>>pass;
			cout<<"\n\nEnter Your CONFIRM PASSWORD :";
			cin>>Cpass;
			cout<<"\n\nEnter Your INITIAL DEPOSITE :";
			cin>>ibal;
            Register(name,pass,Cpass,mob,ibal,lt);
            goto Login;
			break;
		
		case 3:
			return 0;
			
	}
	
}