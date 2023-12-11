#include<iostream>



#include "Mythic.h"
using namespace std;

int main(){
    Experience test_case;
    cout<<"Welcome to your Mythic Journey, What would you like to do?"<<endl;
    cout<<"To record a workout, enter 1"<<endl;
    cout<<"To see your lifetime stats, enter 2"<<endl;
    cout<<"To quit, enter 0"<<endl;
    char cont;
    cin>>cont;
    while(cont!='0'){
        if (cont=='1'){
            test_case.Append(test_case.InitNodeInput());
            cout<< "Your new total is: "<<test_case.GetXP()<<" Experience Points"<<endl;
            cout<<"Your new level is: "<<test_case.GetLevel()<<endl;
            cout<<"To record a workout, enter 1"<<endl;
            cout<<"To see your lifetime stats, enter 2"<<endl;
            cout<<"To quit, enter 0"<<endl;
            cin>>cont;
        }
        else if (cont=='2'){
            test_case.Report();
            cout<<"To record a workout, enter 1"<<endl;
            cout<<"To see your lifetime stats, enter 2"<<endl;
            cout<<"To quit, enter 0"<<endl;
            cin>>cont;
        }
        else{
        
            cout<<"Please try again with a valid entry."<<endl;
            cout<<"To record a workout, enter 1"<<endl;
            cout<<"To see your lifetime stats, enter 2"<<endl;
            cout<<"To quit, enter 0"<<endl;
             cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>cont;
            
        }

    }


    return 0;
}