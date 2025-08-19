#include <iostream>   
#include <string>
#include <math.h>   
#include <cstdlib>  
#include <ctime>    

using namespace std;
enum enGame {Rock=1, Paper=2, Scissors=3};
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
int readrounds()
{
   int round=0;
   cout << "how many rounds do you want to play?"<<endl;
   cin >>round;
   return round;
}
void printroundheader(int round)
{
cout << "round "<<"["<<round<<"] "<<"begins: "<<endl;
}
enGame readplayerchoices()
{
  cout << "your choice: [1]rock, [2]paper,[3]scissors? ";
  int player1choice;
  cin >> player1choice;
  return enGame(player1choice);
}
enGame generatecomputerchoice()
{
    int computerchoice=RandomNumber(1,3);
    return enGame(computerchoice);
}
string DecideWinner(enGame player, enGame computer)
{
  if(player == computer)
  {
    return "[no winner]";
  }
  else if(player == Rock && computer == Scissors)
    {
     return "player wins";
    }
 else if(player == Paper && computer == Rock)
 {
    return "player wins";
 }
 else if (player == Scissors && computer == Paper)
 {
    return"player wins";
 }
 else
  {
    return"computer wins";
  }
}
string choicetostring(enGame choice)
{
  if(choice==1)
  {
    return"rock\n";
  }
  else if(choice==2)
  {
    return"paper\n";
  }
  
    return"scissors\n";
  
}
void roundresults(int round,enGame player, enGame computer)
{
    cout <<"_____________"<<"round "<<"["<<round<<"]"<<"_____________"<<endl;
    cout <<"player choice: "<< choicetostring(player)<<endl;
    cout <<"computer choice: "<<choicetostring(computer)<<endl;
    cout <<"round winner: "<<DecideWinner(player,computer)<<endl;
    cout<<"________________________________________________\n";
}

void printfinalresults(int round,int playerwins,int computerwins,int draws)
{
cout <<"________________________________________________________"<<endl;
cout<<"                   +++ Game Over +++                      "<<endl;
cout<<"____________________________________________________________"<<endl;
cout<<"____________________[Game Results]__________________________"<<endl;
cout << "Game rounds    : "<<round<<endl;
cout <<"player wins     : "<<playerwins<<endl;
cout <<"computer wins   : "<<computerwins<<endl;
cout <<"draws           : "<<draws<<endl;
if(playerwins==computerwins)
{
cout <<"final winner    : "<<"no winner"<<endl;
}
else if(playerwins>computerwins)
{
 cout <<"final winner   : "<<"player wins"<<endl;
}
else if(playerwins<computerwins)
{
 cout <<"final winner   : "<<"computer wins"<<endl;
}
}
int main()
{
   srand((unsigned)time(NULL));
   int playerWins = 0, computerWins = 0, draws = 0;
   int rounds=readrounds();
  for (int i = 1; i <= rounds; i++) {
    printroundheader(i);
    enGame player = readplayerchoices();
    enGame computer = generatecomputerchoice();
    roundresults(i, player, computer);

    string result = DecideWinner(player, computer);

    if (result == "player wins") playerWins++;
    else if (result == "computer wins") computerWins++;
    else draws++;
}
printfinalresults(rounds,playerWins, computerWins, draws);
cout<<endl;
char playagain;
cout << "do you want to play again y/n? ";
cin>>playagain;
do
{
    int playerWins = 0, computerWins = 0, draws = 0;
   int rounds=readrounds();
  for (int i = 1; i <= rounds; i++) {
    printroundheader(i);
    enGame player = readplayerchoices();
    enGame computer = generatecomputerchoice();
    roundresults(i, player, computer);

    string result = DecideWinner(player, computer);

    if (result == "player wins") playerWins++;
    else if (result == "computer wins") computerWins++;
    else draws++;
}
printfinalresults(rounds,playerWins, computerWins, draws);
cout << "do you want to play again y/n? ";
    cin>>playagain;
} while (playagain=='y'||playagain=='Y');
}
