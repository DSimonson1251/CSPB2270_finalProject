#ifndef MYTHIC_H
#define MYTHIC_H

#include <string>
#include <memory>
#include <cmath>

using namespace std;
 #define NPC 0
 #define BARBARIAN 1
 #define BARD 2
 #define CLERIC 3
 #define DRUID 4
 #define FIGHTER 5
 #define MONK 6
 #define PALADIN 7
 #define RANGER 8
 #define ROGUE 9
 #define SORCERER 10
 #define WARLOCK 11
 #define WIZARD 12
 
 #define WEIGHTS 13
 #define DANCING 14
 #define SWIMMING 15
 #define YOGA 16
 #define MIXEDCARDIO 17
 #define MARTIALARTS 18
 #define CYCLING 19
 #define RUNNING 20
 #define FUNCTIONAL 21


struct workout {
  int time;       
  bool location; //false is inside, true is outside.
  int calories;
  int type;     
  shared_ptr<workout> next;  
};

class Experience {
public:

  Experience(int dataInit=0, Experience* nextLoc=nullptr);


  ~Experience();

  shared_ptr<workout> InitNodeInput();

  shared_ptr<workout> InitNode(int time, bool location,int calories, int type);//done
  int CleanType(int type_);

  void Report();
  void workout_xp(int time, bool location,int calories, int type);
  bool ClassBoost(bool location, int type);
  void Append(shared_ptr<workout> new_workout);//done
  int Size();//done
  void SetTop(shared_ptr<workout> top_ptr);//done
  void Class_Decide();
  void SetClass(int class_val);
  void AddXP(int newXP);
  shared_ptr<workout> GetTop();//done
  int GetXP();
  int GetLevel();
  int GetClass();
  void SetLevel(int new_level);
  void CalculateLevel();


private:
    shared_ptr<workout> top_ptr_;
    shared_ptr<workout> tail_ptr_;
    int workout_data;
    Experience* nextNodePtr;
    int ch_class;
    int XP;
    int Level;
 
};

#endif 