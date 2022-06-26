#include<bits/stdc++.h>
#define MIN_BALANCE 500
using namespace std;
class Account{
    long accountNumber;
    string firstName,lastName;
    float balance;
    static long count;
    public:
    Account(){}
    Account(string first_name,string last_name,float balance_){
        count++;
        firstName=first_name;
        lastName=last_name;
        balance=balance_;
        accountNumber=count;
    }
    static void setLastAccountNumber (long accountNumber){
        count=accountNumber;
    }
    static long getLastAccountNumber (){
        return count;
    }
    long getAccount(){return accountNumber;}
    string getFirstName(){return firstName;}
    string getLastName(){return lastName;}
    float getBalance(){return balance;}
    void deposit(float amount){balance+=amount;}
    void withdraw(int amount){
        if(balance-amount>0&&balance-amount<MIN_BALANCE){
            balance-=amount;
            cout<<"\n error: you have insufficient fund\n";
            return;
        }
        if(balance-amount<0){
            cout<<"\n error: can't process this transaction as you have insufficient amount of money in your account\n";
            return;
        }
        balance-=amount;
    }
    
friend ofstream & operator<< (ofstream & ofs, Account & acc);
friend ifstream & operator>> (ifstream & ifs, Account & acc);
friend ostream & operator<< (ostream & os, Account & acc);
   

};
long Account:: count=0;
class Bank{
    map<long,Account> accounts;
    public:
    Bank(){
        Account acc;
        ifstream in("BankData.txt");
        if(!in){
            cout<<"No Such file\n";
            return;
        }
        while(!in.eof()){
            in>>acc;
            accounts.insert(pair<long,Account>(acc.getAccount(),acc));

        }
        Account::setLastAccountNumber(acc.getAccount());
        in.close();

    }
    Account openAccount(string first_name,string last_name,float balance_){
        ofstream outfile;
    Account account (first_name, last_name, balance_);
    accounts.insert (pair < long, Account > (account.getAccount(), account));
    outfile.open ("BankData.txt", ios::trunc);
    map < long, Account >::iterator itr;
    for (itr = accounts.begin (); itr != accounts.end (); itr++){
        outfile << itr->second;
    }
    outfile.close ();
    return account;

    }
    Account balanceEnquiry(long accountNumber){
        map<long,Account>::iterator it=accounts.find(accountNumber);
        Account acc;
        if(it==accounts.end()){
            cout<<"no account found";
            return acc;
        }
        return it->second;
    }
    Account deposit(long accountNumber,int amount){
        map<long,Account>::iterator it=accounts.find(accountNumber);
        Account acc;
        if(it==accounts.end()){
            cout<<"no account found";
            return acc;
        }
        it->second.deposit(amount);
        return it->second;
    }
    Account withdraw(long accountNumber,int amount){
        map<long,Account>::iterator it=accounts.find(accountNumber);
        Account acc;
        if(it==accounts.end()){
            cout<<"no account found";
            return acc;
        }
        it->second.withdraw(amount);
        return it->second;
    }
    void closeAccount(long accountNumber){
        map<long,Account>::iterator it=accounts.find(accountNumber);
        if(it==accounts.end()){
            cout<<"no account found";
            return;
        }
        cout<<"Deleting account "<<it->second;
        accounts.erase(accountNumber);
    }

    void showAccounts(){
        map<long,Account>::iterator it;
        for ( it = accounts.begin(); it!= accounts.end(); it++){
            cout<<"Account: "<<it->first<<endl<<it->second <<endl;
        }
        
    }
    ~Bank(){
        ofstream out("Bankdata.txt",ios::trunc);
        map < long,Account >::iterator itr;
        for (itr = accounts.begin (); itr != accounts.end (); itr++){
            out << itr->second;
        }
        out.close();
    }
};

ofstream & operator<<(ofstream &ofs,Account &acc){
    ofs<<acc.accountNumber<<endl;
    ofs<<acc.firstName<<endl;
    ofs<<acc.lastName<<endl;
    ofs<<acc.balance<<endl;
    return ofs;
}
ifstream & operator>>(ifstream &ifs,Account &acc){
    ifs>>acc.accountNumber;
    ifs>>acc.firstName;
    ifs>>acc.lastName;
    ifs>>acc.balance;
    return ifs;

}
ostream & operator<<(ostream &os,Account &acc){
    os<<"First Name:"<<acc.getFirstName()<<endl;
    os<<"Last Name:"<<acc.getLastName()<<endl;
    os<<"Account Number:"<<acc.getAccount()<<endl;
    os<<"Balance:"<<acc.getBalance()<<endl;
    return os;
}

void WelcomeNote(){
    // system("pause");
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t@@|                                  WELCOME TO                                           |@@\n";
cout<<"\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t@@|                                  ABCD  BANK                                           |@@\n";
cout<<"\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";

}
int main(){
    WelcomeNote();
    string fname,lname;
    float balance,amount;
    int choice;
    long accountNumber;
    Bank b;
    Account acc;
    do{
        system("pause");
system("cls");
        cout<<"\n\n\n\n\t\t\t\t\t******************   Banking System   ******************\n";
        cout<<"\t\t\t\t\t*                                                      *\n";
        cout<<"\t\t\t\t\t*               Select an option below*                *\n";
        cout<<"\t\t\t\t\t*                                                      *\n";
        cout<<"\t\t\t\t\t*               1. Open an account*                    *\n";
        cout<<"\t\t\t\t\t*               2. Balance enquiry*                    *\n";
        cout<<"\t\t\t\t\t*               3. Deposit                             *\n";
        cout<<"\t\t\t\t\t*               4. Withdrawal                          *\n";
        cout<<"\t\t\t\t\t*               5. Close an account                    *\n";
        cout<<"\t\t\t\t\t*               6. Show all accounts                   *\n";
        cout<<"\t\t\t\t\t*               7. Quit                                *\n";
        cout<<"\t\t\t\t\t*                                                      *\n";
        cout<<"\t\t\t\t\t*               ENTER YOUR CHOICE (1-7)                *\n";
        cout<<"\t\t\t\t\t*                                                      *\n";
        cout<<"\t\t\t\t\t********************************************************\n";
        cin>>choice;
        switch(choice){

            case 1:
            cout<<"Enter First Name: ";
            cin>>fname;
            cout<<"Enter Last Name: ";
            cin>>lname;
            cout<<"Enter initial Balance: ";
            cin>>balance;
            acc=b.openAccount(fname,lname,balance);
            cout<<"Account created\n";
            cout<<acc;
            break;

            case 2:
            cout<<"Enter Account Number\n";
            cin>>accountNumber;
            acc=b.balanceEnquiry(accountNumber);
            cout << endl << "Your Account Details" << endl;
	        cout << acc;
            break;

            case 3:
            cout<<"Enter Account Number";
            cin>>accountNumber;
            cout<<"Enter Balance\n";
            cin>>balance;
            acc=b.deposit(accountNumber,amount);
            cout << endl << "Amount is Deposited" << endl;
	        cout << acc;
            break;

            case 4:
            cout<<"Enter Account Number";
            cin>>accountNumber;
            cout<<"Enter Amount to withdraw\n";
            cin>>amount;
            acc=b.withdraw(accountNumber,amount);
            cout << endl << "Amount Withdrawn" << endl;
            cout << acc;
            break;

            case 5:
            cout<<"Enter Account Number";
            cin>>accountNumber;
            b.closeAccount(accountNumber);
            cout << endl << "Account is Closed" << endl;
            cout << acc;
            break;

            case 6:
            b.showAccounts();
            break;

            case 7:
            exit(0);
            break;
            default:
            cout<<"Enter correct option\n";

        }
    }while(choice!=7);

    return 0;
}