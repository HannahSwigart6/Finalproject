#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <conio.h>
#include "math.h"

int colorNum, wordNum, score, play;
int scoresHigh[10] = {};
std::string nameHigh[10] = {};
bool gameOver;

//this are the menu, just displays a menu and asks for input
int Menu(){
	std::cout << "****************************************" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "*           PRESS 1 TO PLAY            *" << std::endl;
	std::cout << "*       *LIGHT BLUE IS CYAN!!!!*       *" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "*                                      *" << std::endl;
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //sets the user input text color to white for niceness
	std::cin >> input;
	if (input == ColorWord){
		std::cout << " " << std::endl;
		std::cout << " " << std::endl;
		++score;
	}
	else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //same thing as above
		std::cout << "too bad " << name << " you lost!" << std::endl;
		std::cout << "The word you were supposed to type was " << ColorWord << std::endl;
		std::cout << "your score was " << score << std::endl;
		std::cout << "Would you like to play again? ";
		std::cin >> again;

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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "your score is " << score << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum); //this sets the color of the text to the word decided from the array
		std::cout << word << std::endl;
	} while (gameOver = false);
}

void Import(){
	int highScoreArray = 0;
	std::ifstream HighScoreFile;
	HighScoreFile.open("highscores.txt");
	if (HighScoreFile.is_open()){
		for (int i = 0; i < 11; ++i){
			HighScoreFile >> scoresHigh[i];
			std::cout << scoresHigh[i] << std::endl;

		}
	}
}

void Export(int score, std::string name){
	int highScorePH = 0;
	if (score > highScorePH){
		highScorePH = score;
	}
	std::ofstream highScore("highscores.txt", std::ios_base::app | std::ios_base::out);
	if (highScore.is_open()){
		highScore << highScorePH << name << std::endl;
		highScore << std::endl;
	}
	else{
		std::cout << "Something went wrong with opening the file!";
	}
		highScore.close();
}

//runs the game
int main(){
	int colorCode, play;
	std::string colorWord, WWord, name;
	Import();
	play = Menu();
	name = Name();
	if (play == 1){
		setup();
		do{
			colorCode = ColorCode();
			colorWord = ColorWord();
			WWord = wordChooser();
			textMaker(WWord);
			checker(colorWord, name);
		} while (!gameOver);
		Export(score,name);
		std::cout << "The game will now close";
		Sleep(3000);
		system("exit");
	}
}