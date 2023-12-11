# CSPB2270_finalProject
Mythic Fitness final project 

Just to start, the code got pushed into the master branch of the git environment but the read me was in the main, I could not get them to merge,
I hope you were able to find the information

To save time, once you have all of the files in the project folder, the code to compile and run is 
'g++ Mythic.cpp Project.cpp -o my_program && ./my_program'


The data Structure I worked with was a Linked List, I extended on the linked list from the course work by adding 
more components to the nodes and adding more customized functions to achieve the desired program. 

The linked list is called Experience as the whole purpose of this was to create a gamified workout tracker inspired by Dungeons and Dragons. 
Each node, titled Workout, is a different workout recording the time, calories, location and style of the workout. 
Through this experience points are tallied and added through functions to a private variable of Experience. 
As the user progresses they can chose a class that will give boosts to certain styles of  workout. 

Once you have loaded in the Project.cpp, Mythic.cpp and Mythic.h you can run the program. 
It will prompt you to either enter a workout, get a summary of past workouts, or quit. 
The program itself locks each workout at 800xp as to not reward burnout, but if you would like to test the selecting a class function you can void out line 194 of the Mythic.cpp 
program. To get to level 5 very quickly set the time of workout to 18000 and calories to 10 or higher, 
This will get you to jump up in level very quickly. After you select a class you can enter the prefered workout type and see a 10% boost in expereince gained for that workout. 

I always like to add a "With more time and Experience" section. 
You will notice that Sorcere, Warlock, and Wizard have been voided out. 
Their boosts were dependet on variables that were too difficult or time consuming for me to figure out. 
The Sorcerer is rewareded for doing a workout that had not been done for the past 5 workouts encouraging variety. This would have been easier to code with a doubly linked list
as I could move backward easier. 
The Warlock is rewarded for working out with a partner. This could have been another Bool variable similar to location but it started to get messy and there were too many questions per 
workout so I decided to skip it for now. 
The wizard is rewarded for planning ahead, and I could not think of a good way to pre record a commitment of a workout, then later add the details of the workout. 

This was made because my wife and I are fitness enthusiasts with nerdy friends and we want to create a way to encourage people to try new things and get moving. 
In the future we would like to also add a nutrition component but that has yet to be flushed out. 

Hopefully you use past workouts to play around with this as it will make it more fun! 
