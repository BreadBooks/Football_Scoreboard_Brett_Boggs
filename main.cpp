#include <iostream>
#include <string> 
#include <iomanip>
#include <unistd.h>
#include "Input_Validation_Extended.h"
using namespace std; 

class Team 
{
  private:
    int score; 
    bool homeStatus; 
    string name; 
   
    string coachName; 
  public:
      Team() //default constructor 
      {
        score = 0; 
        homeStatus = false; //visitor = false, home = true
        // name = "DefaultTeamName"; 
        
        // coachName = "DefaultCoachName"; 
      }
      void setScore (int s) { score = s; }
      void setHomeStatus(bool hs) { homeStatus = hs; }
      void setName(string n) { name = n; }
      void setCoachName(string sCN) { coachName = sCN; }
      int getScore() const { return score; }
      bool getHomeStatus() const { return homeStatus; }
      string getName() const { return name; }
      string getCoachName() const { return coachName; }
};

class Scoreboard
{
  private:
    int half; 
    Team home; //object that is a member of another object
    Team visitor; 
  public: 
    Scoreboard()
    {
      half = 0; 
    }  
    void setHalf(int h) { half = h; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    int getHalf() const { return half; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[35m"; //magenta 
      string score = "\x1b[36;1m"; //score color 
      cout << color << "Football Scoreboard" << reset << endl; 
      cout << home.getName() << "\t\t" << visitor.getName() << endl; 
      cout << "\t" << score << home.getScore() << reset << "\t\t\t\t\t\t" << visitor.getScore() << endl; 
      cout << score << home.getCoachName() << reset << setw(7) << "\t\t" << visitor.getCoachName() << endl; 
      for(int i = 0; i < 47; i++) { cout << "*"; } cout << endl;
       
       //proces to show the home team status
       cout << "Current Home Team - \t"; 
       if(home.getHomeStatus() == true)
       {
         cout << "Team 1: " << home.getName() << "*"; 
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << "Team 2: " << visitor.getName() << "*"; 
       }
       else
       {
         cout << "Error: "; 
       }
       
       cout  << endl; 
    }
};

int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName = ""; 
  string userChoice = ""; 
  string newCoachName = ""; 
  int homeTeamQuestion = 0; 
  int newScore = 0; 

  //Set the home team 
  tOne.setHomeStatus(true); //tOne is the Home Team now 
  

  // Default Team One 
  tOne.setName("Dallas Cowboys");
  tOne.setCoachName("Mark M.");

  // Default Team two
  tTwo.setName("Patriots");
  tTwo.setCoachName("Bill B.");

  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  //Loop this to make it an interactive menu

  do 
  {
      system("clear"); //clear the screen of previous content 
      s.showScoreboard(); //show the current scoreboard data
      //menu choices 
      cout << "A = Update Home Status" << endl; 
      cout << "B = Update Home Team Score" << endl; 
      cout << "C = Update Home Team Name" << endl; 
      cout << "D = Update Home Team Coach" << endl;
      cout << "F = Update Vistior Team Name" << endl; 
      cout << "G = Update Visitor Team Score" << endl; 
      cout << "H = Update Visitor Coach Name" << endl;
      cout << "E = Exit" << endl;
      cout << ">"; 
      cin >> userChoice; 
      if(userChoice == "A" || userChoice == "a")
      {
        cout << "\nUpdate Home Status Module****" << endl; 
        cout << "\nWho is the current home team: 1 = Team 1, 2 = Team 2: "; 
        homeTeamQuestion = validateInt(homeTeamQuestion); 
       // cin >> homeTeamQuestion; 
        if(homeTeamQuestion == 1)
        {
          tOne.setHomeStatus(true); 
          tTwo.setHomeStatus(false); 
        }
        else if(homeTeamQuestion == 2)
        {
          tOne.setHomeStatus(false); 
          tTwo.setHomeStatus(true);
        }
        else
        {
          cout << "\nInvalid Input!" << endl;
          sleep(2); 
        }
      }
      else if(userChoice == "B" || userChoice == "b")
      {
        cout << "\nUpdate Home Score Module****" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        cin >> newScore; 
        tOne.setScore(newScore);  //set the new score for tOne        
      }
     else if(userChoice == "C" || userChoice == "c")
      {
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Home Team module*** " << endl; 
        cout << "\nPlease enter a new name for the home team: ";
        cin >> newName; 
        //change that home team's default name
        tOne.setName(newName); //set tOne's data to the new desired name
      }
      else if(userChoice == "D" || userChoice == "d")
      {
          cout << "\nUpdate Home Coach Module****" << endl; 
          cout << "\nPlease enter the home coach Name: "; 
          cin >> newCoachName; 
          tOne.setCoachName(newCoachName); 
      }
      else if(userChoice == "F" || userChoice == "f")
      {
          cout << "\nUpdate Visitor Team Name Module****" << endl; 
          cout << "\nPlease enter the visitor team Name: "; 
          cin >> newName; 
          tTwo.setName(newName); 
      }
      else if(userChoice == "G" || userChoice == "g")
      {
        cout << "\nUpdate Visitor Score Module****" << endl; 
        cout << "\nPlease enter a new score for the visitor team: "; 
        cin >> newScore; 
        tTwo.setScore(newScore);  //set the new score for tOne        
      }
      else if(userChoice == "H" || userChoice == "h")
      {
          cout << "\nUpdate Visitor Coach Module****" << endl; 
          cout << "\nPlease enter the visitor coach Name: "; 
          cin >> newCoachName; 
          tTwo.setCoachName(newCoachName); 
      }
      
      else if(userChoice == "E" || userChoice == "e")
      {
        cout << "Exit chosen." << endl; 
      }
      else //invalid input: default clause
      {
        cout << "\nInvalid input." << endl; 
        sleep(2); //wait two seconds, go to the next process 
      }

      s.setHome(tOne); //refresh the data in s to the new updates...
      s.setVisitor(tTwo); //refresh the data
  
  }while(userChoice != "E" && userChoice != "e");


  return 0; 
}