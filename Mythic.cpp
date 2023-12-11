#include "Mythic.h"
#include <iostream>
#include <cmath>
using namespace std;


Experience::Experience(int dataInit, Experience* nextLoc){

    top_ptr_=nullptr;
    tail_ptr_=nullptr;
    Level=1;
    ch_class=NPC;

}

Experience::~Experience(){
}

shared_ptr<workout> Experience::InitNodeInput(){
  
  int t,c;
  string loc;
  int ty;
  bool ins=false;
  cout<<"Recording New Workout"<<endl;
  cout<<"How many minutes was the workout?"<<endl;
  cin>>t;
  cout<<endl<<"How many calories were burned?"<<endl;
  cin>>c;
  cout<<endl<<"Did you workout outside? Enter 'Y' for yes 'N' for No."<<endl;
  cin>>loc;
  if(loc=="y"||loc=="Y"){
    ins=true;
  }
  cout<<endl<<"What type of workout was it?"<<endl;
  cout<<"For weightlifting enter 1"<<endl;
  cout<<"For dancing enter 2"<<endl;
  cout<<"For swimming enter 3"<<endl;
  cout<<"For yoga or any other mind-body exercise enter 4"<<endl;
  cout<<"For mixed cardio such as crossfit enter 5"<<endl;
  cout<<"For any form of martial arts enter 6"<<endl;
  cout<<"For cycling both real bike or stationary enter 7"<<endl;
  cout<<"For running or walking enter 8"<<endl;
  cout<<"For functional or bodyweight training enter 9"<<endl;
  


  cin>>ty;

  while (cin.fail() || ty > 9 || ty < 1) {
    cin.clear(); // clear the error state
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid input in the buffer
    cout << "Invalid entry, Please try again" << endl;
    cin >> ty;
}
  int Type=CleanType(ty);
  return InitNode(t,ins,c,Type);
}

shared_ptr<workout> Experience::InitNode(int time, bool location,int calories, int type){
  shared_ptr<workout> ret(new workout);
  ret->time=time;
  ret->location=location;
  ret->calories=calories;
  ret->type=type;
  ret->next=nullptr; 
  return ret;

}
int Experience::CleanType(int type_){
  if(type_=1){
    return WEIGHTS;
  }
  else if(type_=2){
    return DANCING;
  }
  else if(type_=3){
    return SWIMMING;
  }
  else if(type_=4){
    return YOGA;
  }
  else if(type_=5){
    return MIXEDCARDIO;
  }
  else if(type_=6){
    return MARTIALARTS;
  }
  else if(type_=7){
    return CYCLING;
  }
  else if(type_=8){
    return RUNNING;
  }
  else if(type_=9){
    return FUNCTIONAL;
  }
  
return 0;
}


  void Experience::Report(){ 
    int outdoor=0;
    int indoor=0;
    int total_cal;
    int total_workouts=Size();
    int weight=0;
    int dance=0;
    int swim=0;
    int yoga=0;
    int cardio=0;
    int martial=0;
    int cycle=0;
    int run=0;
    int function=0;
    string local;
    int xp=GetXP();
    int level=GetLevel();
    if(!top_ptr_){
      cout<<"You have no workouts yet!"<<endl<<"Please record your first workout to start your fitness journey!"<<endl;
      return;
    }
    else{
      shared_ptr<workout> currNode=GetTop();
      while(currNode->next){
        total_cal=total_cal+currNode->calories;
        if(currNode->location==true){
          outdoor++;
        }
        else{
          indoor++;
        }
        if(currNode->type==WEIGHTS){
          weight++;
        }
        else if(currNode->type==DANCING){
          dance++;
        }
        else if(currNode->type==SWIMMING){
          swim++;
        }
        else if(currNode->type==YOGA){
          yoga++;
        }
        else if(currNode->type==MIXEDCARDIO){
          cardio++;
        }
        else if(currNode->type==MARTIALARTS){
          martial++;
        }
        else if(currNode->type==CYCLING){
          cycle++;
        }
        else if(currNode->type==RUNNING){
          run++;
        }
        else if(currNode->type==FUNCTIONAL){
          function++;
        }
        currNode=currNode->next;
      }
    }
    if(outdoor>indoor){
      local="outside";
    }
    else{
      local="inside";
    }
    cout<<"Brave warrior, You have completed "<<total_workouts<<" workouts and through those you have bruned "<<total_cal<<" calories"<<endl;
    cout<<"You prefered to workout "<<local<<"!"<<endl;
    cout<<"You have lifted weights "<<weight<<" times"<<endl;
    cout<<"You have gone dancing "<<dance<<" times"<<endl;
    cout<<"You have gone swimming "<<swim<<" times"<<endl;
    cout<<"You have done yoga "<<yoga<<" times"<<endl;
    cout<<"You have participated in mixed cardio "<<cardio<<" times"<<endl;
    cout<<"You have gone for a bike ride "<<cycle<<" times"<<endl;
    cout<<"You have found your inner black belt "<<martial<<" times"<<endl;
    cout<<"You have gone for a run "<<run<<" times"<<endl;
    cout<<"You have done some body weight exercise "<<function<<" times"<<endl;
    cout<<"Trough these you have earned "<<xp<<" experience points and a charachter level of "<<level<<endl;
    cout<<"Now get out there and get moving to find that next level!"<<endl;
  
  }


void Experience::workout_xp(int time, bool location,int calories, int type){
  int xp;
  bool classboost=ClassBoost(location, type);
  
  xp=time*log10(calories);
  if(xp>801){
    xp=800;
  }
  if (classboost==true){
    xp=xp*1.1;
  }
  cout<<"Congratulations, You earned "<<xp<<" experience points."<<endl;
  AddXP(xp);
}
bool Experience::ClassBoost(bool location, int type){
  int Class=GetClass();
  if (Class==BARBARIAN){
    if(type==WEIGHTS){
      return true;
    }
  }
  if (Class==BARD){
    if(type==DANCING){
      return true;
    }
  }
  if (Class==CLERIC){
    if(type==SWIMMING||type==YOGA){
      return true;
    }
  }
  if (Class==DRUID){
    if(location==true){
      return true;
    }
  }
  if (Class==FIGHTER){
    if(type==MIXEDCARDIO){
      return true;
    }
  }
  if (Class==MONK){
    if(type==MARTIALARTS){
      return true;
    }
  }
  if (Class==PALADIN){
    if(type==CYCLING){
      return true;
    }
  }
  if (Class==RANGER){
    if(type==RUNNING){
      return true;
    }
  }
  if (Class==ROGUE){
    if(type==FUNCTIONAL){
      return true;
    }
  }

 return false;
}
void Experience::Append(shared_ptr<workout> new_workout){

    if (!top_ptr_) {
        top_ptr_ = new_workout;
        tail_ptr_ = new_workout;  // Set tail_ptr_ for the first node
    } else {
        tail_ptr_->next = new_workout;
        tail_ptr_ = new_workout;
    }
    workout_xp(new_workout->time,new_workout->location,new_workout->calories,new_workout->type);
    CalculateLevel();
    int temp=GetClass();
    while(temp==NPC){
      int lvl=GetLevel();
      if(lvl==5){
        Class_Decide();
        temp=GetClass();
      }
      else{
        break;
      }
    }
}

int Experience::Size(){
  int ret;
    if(!top_ptr_){
        ret=0;
        //if empty, size is 0
    }
    else{
        ret=0;
        shared_ptr<workout>currNode=Experience::GetTop();
        //start at top
        while(currNode){
            ret=ret+1;
            //increase counter and move to next value
            currNode=currNode->next;
        }
    }

      
  return ret-1;
}

void Experience::SetTop(shared_ptr<workout> top_ptr){
  top_ptr_ = top_ptr;
}

void Experience::Class_Decide(){
  int class_val=-1;
    cout<<"Congratulations on reaching level 5! You may now pick a class!"<<endl;
    cout<<"Each Class gets a unique boost when finishing specific workout types"<<endl;
    cout<<"Please choose from the following Classes"<<endl;
    cout<<"1.Barbarians get extra experience when lifting weights!"<<endl;
    cout<<"2.Bards get extra experience when dancing!"<<endl;
    cout<<"3.Clerics get extra experience when Swiming or doing Yoga!"<<endl;
    cout<<"4.Druids get extra experience when excersising outside!"<<endl;
    cout<<"5.Fighters get extra experience when doing mixed cardio such as crossfit!"<<endl;
    cout<<"6.Monks get extra experience when doing any form of martial arts!"<<endl;
    cout<<"7.Paladins get extra experience when cycling both stationary and mobile!"<<endl;
    cout<<"8.Rangers get extra experience when running or walking!"<<endl;
    cout<<"9.Rogues get extra experience when doing functional or bodyweight training!"<<endl;
    //cout<<"Sorcerers get extra experience when completing a workout type they have not done in a while!"<<endl
    //cout<<"Warlocks get extra experience when working out with a friend !"<<endl
    //cout<<"Wizards get extra experience when committing to lift the day before!"<<endl
    //These are classes that will be added if time permits
    cout<<"Please enter the number of the class you would like to choose: ";
    cin>>class_val;
    while (class_val<0||class_val>9){
      cout<<"Invalid Option, Please select again"<<endl;
      cin>>class_val;
    }      
  SetClass(class_val);
}

void Experience::SetClass(int class_val){ 
  if (class_val=1){
    ch_class=BARBARIAN;
  } 
  else if(class_val=2){
    ch_class=BARD;
  }
  else if(class_val=3){
    ch_class=CLERIC;
  }
  else if(class_val=4){
    ch_class=DRUID;
  }
  else if(class_val=5){
    ch_class=FIGHTER;
  }
  else if(class_val=6){
    ch_class=MONK;
  }
  else if(class_val=7){
    ch_class=PALADIN;
  }
  else if(class_val=8){
    ch_class=RANGER;
  }
  else if(class_val=9){
    ch_class=ROGUE;
  }
}

void Experience::AddXP(int newXP){
    XP=XP+newXP;

}
shared_ptr<workout> Experience::GetTop(){
  return top_ptr_;
}

int Experience::GetXP(){
  return XP;
}

int Experience::GetLevel(){
  return Level;
}
int Experience::GetClass(){
  return ch_class;
}
void Experience::SetLevel(int new_level){
  Level=new_level;
}
void Experience::CalculateLevel(){
  int xp=GetXP();
  int level=1;
  if(xp>= 1080000){
    level=20;
  }
  else if(xp>880000){
    level=19;
  }
  else if(xp>720000){
    level=18;
  }
  else if(xp>576000){
    level=17;
  }
    else if(xp>440000){
    level=16;
  }
    else if(xp>320000){
    level=15;
  }
    else if(xp>248000){
    level=14;
  }
    else if(xp>184000){
    level=13;
  }
    else if(xp>128000){
    level=12;
  }
    else if(xp>93600){
    level=11;
  }
    else if(xp>63200){
    level=10;
  }
    else if(xp>44000){
    level=9;
  }
    else if(xp>36800){
    level=8;
  }
    else if(xp>30400){
    level=7;
  }
    else if(xp>24000){
    level=6;
  }
    else if(xp>17600){
    level=5;
  }
    else if(xp>12000){
    level=4;
  }
    else if(xp>7200){
    level=3;
  }
    else if(xp>3200){
    level=2;
  }
SetLevel(level);
}

