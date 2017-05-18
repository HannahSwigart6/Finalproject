//Dusty Beehler and Hannah Swigart
//May 30, 2017
//Color Guesser

#include <iostream>
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <deque>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>
#include "math.h"

int colorNum, wordNum, score, play;
int scoresHigh[10], oldSubscript[10], newSubscript[10];
std::string nameHigh[10];
bool gameOver;

//this are the menu, just displays a menu and asks for input
int Menu(){
	std::cout << "****************************************" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "*           PRESS 1 TO PLAY            *" << std::endl;
	std::cout << "*       *LIGHT BLUE IS CYAN!!!!*       *" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "*       PRESS 2 FOR HIGHSCORES         *" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "****************************************" << std::endl;
	std::cin >> play;
	return play;
}

//asks user for name for later use and personalization
std::string Name(){
	std::string name;
	std::cout << "What is your name? ";
	std::cin >> name;
	return name;
}

//this will setup the game and initialize some variables
void setup(){
	gameOver = false;
}

//picks the color between 1 and 5 "randomly" for the SetConsoleTextAttribute function
int ColorCode(){
		int random;
		srand(static_cast<int>(time(NULL)));
		random = rand();
		colorNum = (random % 6) + 1;
		return colorNum;
}

//gets a random number to determin a number
int WordRandom(){
	int random1;
		srand(static_cast<int>(time(NULL)));
		random1 = rand();
		wordNum = (random1 % 9);
		return wordNum;
}

//says the color of the work ie. the word can be green, but the color is red
std::string ColorWord(){
	std::string colorWord[] = { "black", "blue", "green", "cyan", "red", "pink", "yellow" }; //string of colors for words
	return colorWord[colorNum];
}

//the actual word, not the color
std::string wordChooser(){
	std::string wordWord[10] = { "black", "blue", "green", "cyan", "red", "pink", "orange", "yellow", "purple", "white" }; //string of available text to display
	std::string word = wordWord[rand() % 10];
	return word;
}

//checks if the word, and color are the same
int checker(std::string ColorWord, std::string name){
	std::string input, again;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //sets the user input text color to white for less confusion
	std::cin >> input;
	if (input == ColorWord){
		std::cout << " " << std::endl;
		std::cout << " " << std::endl;
		++score;
	}
	else{ //else clause that runs if the word does not equal
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //same thing as above
		std::cout << "too bad " << name << " you lost!" << std::endl;
		std::cout << "The word you were supposed to type was " << ColorWord << std::endl;
		std::cout << "your score was " << score << std::endl;
		std::cout << "Would you like to play again? ";
		std::cin >> again;
		//if statment either ending the game or restarting it
		if (again == "yes" || again == "Y" || again == "Yes"){
			score = 0;
			gameOver = false;
		}
		else{
			std::cout << " " << std::endl;
			gameOver = true;
		}
	}
	return score;
}

//simply makes the text
void textMaker(std::string word){
	do{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //sets the color of text to white to make less confusion
		std::cout << "your score is " << score << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum); //this sets the color of the text to the word decided from the array
		std::cout << word << std::endl;
	} while (gameOver = false);
}

//Should Import info
void ImportScore(){
	std::string line, stringScores;
	int n = 0;
	std::ifstream file("highscoreScores.txt"); //makes the file
	if (file.is_open()){ //opens file
		while (!file.eof()){
			for (int i = 0; i < 11; ++i)
				oldSubscript[i];
			std::cout << oldSubscript << std::endl;
			file >> scoresHigh[n];
			n++;
		}
	}
	else{
		std::cout << "There was a problem reading the file!" << std::endl;
	}
	int i = 0;
	std::ifstream fileN("highscoreName.txt"); //makes the file
	if (fileN.is_open()){ //opens file
		while (!fileN.eof()){
			fileN >> nameHigh[i];
			i++;
		}
	}
	else{
		std::cout << "There was a problem reading the file!" << std::endl;
	}
	fileN.close();
	file.close();
}

//This exports the scores and name entered by the user to a text file.
void ExportScore(int score, std::string name){

	if (score > scoresHigh[0]){

	}
	std::ofstream highScore("highscoreScores.txt", std::ios_base::app | std::ios_base::out);//makes the name of file and where to export the info
	if (highScore.is_open()){
		highScore  << score << '\n'; //this writes to the file
		highScore << std::endl;
	}
	else{
		std::cout << "Something went wrong with writing to the file!"; //else statment to see if it works, and it does.
	}
		highScore.close(); //closes the file

	std::ofstream highName("highscoreName.txt", std::ios_base::app | std::ios_base::out);//makes the name of file and where to export the info
	if (highName.is_open()){
		highName << name << '\n'; //this writes to the file
		highName << std::endl;
	}
	else{
		std::cout << "Something went wrong with writing to the file!"; //else statment to see if it works, and it does.
	}
	highScore.close(); //closes the file
}


//this just lists the highscores from top to bottom
void Highscores(){
	std::cout << "Here are some scores set by people" << std::endl;
	for (int i = 0; i < 11; i++){
		std::cout << i << ". " << nameHigh[i] << " set a score of " << scoresHigh[i] << std::endl;
	}
}

void Sorter(){

}

//runs the game
int main(){
	int colorCode, play;
	std::string colorWord, WWord, name;
	name = Name(); //sets name
	play = Menu();
	if (play == 2){
		do{
			ImportScore();//imports score
			Highscores();
			play = Menu();
		} while (play == 2); //sets the one way flag for playing
	}
	if (play == 1){//if statement for the do-while loop
		setup();
		do{ //do while loop that runs the game.
			colorCode = ColorCode();
			colorWord = ColorWord();
			WWord = wordChooser();
			textMaker(WWord);
			checker(colorWord, name);
		} while (!gameOver);
	
		ExportScore(score, name);
		//shuts game down after do-while loop is done
		std::cout << "The game will now close";
		Sleep(3000);
		system("exit");
	}
}