 /************************************************************
 * ** program:adventure.cpp 
 * ** Author:Sonia Camacho
 * ** Date:1-18-18
 * ** Description:In this program we are making a game with 5 paths that also has one random path 
 * ** Input:
 * ** Output: 
 * *********************************************************/


#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    beginning:
    int var1;
    cout<<endl;
    cout<<endl;
    cout<<"Tonight is the spring dance! which means it's the last dance before school ends. This is your chance to dance with your crush Joey. The dance starts at 6pm and its 4pm which means...its time to get ready!!!  It's time to play the game and to see how your night will end!"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"You're going through your closet and find two outfits, the first one is a dress and the other option is some jeans with a tank top"<<endl;     
   
    cout<<"[1]Dress  [2]Jeans and a tank top"<<endl;
    cout<<endl;
    cin>>var1;


    if (var1==2){
        cout<<endl;
        cout<<"So you went with the jeans and tank top...sorry at dances you must look formal so you wont be let in wearing that"<<endl;
        
        cout<<"do you want to restart the game? [1]again [2]stop"<<endl;
        int restart;
        cin>>restart;
            if (restart==1){
                goto beginning; 
            }
            else if (restart==2){
                cout<<endl;
                cout<<"It's okay there is always next years dance"<<endl;
                cout<<endl;
            }

    }   
    else if (var1==1){
        cout<<endl;
        cout<<"Nice choice the dress will look great on you!"<<endl;
        cout<<endl;
        cout<<"Okay next step to getting ready!"<<endl;
        cout<<endl;
        cout<<"Will you wear heels or your converse?"<<endl;
        
        cout<<"[1] heels [2]converse"<<endl;
        int var2;
        cin>>var2;
            if (var2==2){
                cout<<endl;
                cout<<"You chose your converse but they have mud all over them and leave footprints all over the dance floor and you are asked to leave."<<endl;
                
                cout<<"do you want to restart the game? [1]again [2]stop"<<endl;
                int restart;
                cin>>restart;
                    if (restart==1){
                        goto beginning;
                    }
                    else if (restart==2){
                        cout<<endl;
                        cout<<"it's okay Joey wasn't there yet to see !"<<endl;
                        cout<<endl;
                    }
            }
    
            else if (var2==1){
                cout<<endl;
                cout<<"Those heels will be perfect with the dress!"<<endl;
                cout<<endl;
                cout<<"Time for makeup! will you wear your water-proof mascara or non water-proof?"<<endl;
                
                cout<<"[1]water-proof [2]non water-proof"<<endl;
                int var3;
                cin>>var3;
                    if (var3==2){
                    cout<<endl;     
                    cout<<"Oh man you wore non water-proof mascara and you didn't look at the forecast! it is raining.While waiting in like your mascara ran down your face so you had to go home."<<endl;
                         
                    cout<<"do you want to restart the game?[1] again [2] stop"<<endl;
                        int restart;
                        cin>>restart;
                            if (restart==1){
                                goto beginning;
                            }
                            else if (restart==2){
                                cout<<endl;
                                cout<<"next time check the weather"<<endl;
                                cout<<endl;
                            }
                    }
            
                    else if (var3==1){
                        cout<<endl;
                        cout<<"Good choice your mascara didn't smudge a bit!"<<endl;
                        cout<<endl;
                        cout<<"Alright! you are almost ready. The last step is to do your hair! Are you going to wear it in a nice up-do or wear it down and not style it?"<<endl;
                        
                        cout<<"[1] Put it up in an up-do [2] Wear it down and not style it"<<endl;
                        int var4;
                        cin>>var4;
                            if (var4==2){
                                cout<<endl;
                                cout<<"YIKES! you wore your hair down and it started pouring while you were waiting in line to get into the dance! you end up going home since your look is ruined"<<endl;
                               
                                cout<<"do you want to restart the game?[1] again [2]stop"<<endl;
                                int restart;
                                cin>>restart;
                                    if (restart==1){
                                        goto beginning;
                                    }
                                    else if (restart==2){
                                        cout<<endl;
                                        cout<<"Bring an umbrella next time!"<<endl;
                                        cout<<endl;
                                    }
                            } 
                               
                            else if (var4==1){
                                cout<<endl;
                                cout<<"An up-do is the perfect hairstyle for this event!"<<endl;
                                cout<<endl;
                                cout<<"The time has come 5:45! It's time to leave for the dance.Oh no you start to feel so nervous!Are you going to get in the car and go? or chicken out?"<<endl;
                                
                                cout<<"[1]Get in the car and GO! [2] chicken out"<<endl;
                                int var5;
                                cin>>var5;
                                    if (var5==2){
                                        cout<<endl;
                                        cout<<"You chickend out! what a bummer you spent so long getting ready!"<<endl;
                                        
                                        cout<<"do you want to restart the game?[1] agian [2] stop"<<endl;
                                        int restart;
                                        cin>>restart;
                                        if (restart==1){
                                            goto beginning;
                                        }
                                        else if (restart==2){
                                            cout<<endl;
                                            cout<<"I guess you'll never know if Joey went to the dance"<<endl;
                                            cout<<endl;
                                        }

                                    }        
                            
                                    int randNumb; 
                                    srand(time(NULL));
                                    randNumb = rand() % 3;
                                    if (randNumb ==0){
                                        cout<<endl;
                                        cout<<"You came to the dance! Unfortunately Joey got sick and never showed up to the dance.Looks like no dance for you"<<endl;
                                        cout<<endl;
                                        cout<<"you have made it through the entire game would you like to play again?"<<endl;
                                        
                                        cout<<"[1]again [2]stop"<<endl;
                                        int restart;
                                        cin>>restart;
                                    
                                            if (restart==1){
                                                goto beginning;
                                            }
                                            else{
                                                cout<<endl;
                                                cout<<"the end!"<<endl;
                                                cout<<endl;
                                            }

                                    }
                                    else if (randNumb==1){
                                        cout<<endl;
                                        cout<<"You came to the dance! Look who is walking in right now...it's Joey but it looks like he is holding hands with Becky. I guess they came as a date. Looks like no dance for you " <<endl;
                                        cout<<endl;
                                        cout<<"you have made it through the entire game would you like to play again?"<<endl;
                                        
                                        cout<<"[1]again [2]stop"<<endl;
                                        int restart;
                                        cin>>restart;
                                        
                                            if (restart==1){
                                                goto beginning;
                                            }
                                            else {
                                                cout<<endl;
                                                cout<<"the end!"<<endl;
                                                cout<<endl;
                                            }
                                    }
                                    else {
                                        cout<<endl;
                                        cout<<"You came to the dance! Right as you walk in Joey grabs you and compliments how nice you look! Then he asks you to dance.All that getting ready was worth it, the night went perfectly!"<<endl;
                                        cout<<endl;
                                        cout<<"you have made it through  the game would you like to play again?"<<endl;
                                        cout<<"[1]again [2]stop"<<endl;
                                        int restart;
                                        cin>>restart;
                                            if (restart==1){
                                                goto beginning;
                                            }
                                            else{
                                                cout<<endl;
                                                cout<<"the end!"<<endl;
                                                cout<<endl;
                                            }
                                    }    
                            }       
                    }
            }
    }
    
return 0;
}
