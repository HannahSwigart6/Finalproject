#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <conio.h>

int colorNum, wordNum, score, play;
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
		wordNum = (random1 % 9) + 1;
		return wordNum;
}

//says the color of the work ie. the word can be green, but the color is red
std::string ColorWord(){
	std::string colorWord[] = { "black", "blue", "green", "cyan", "red", "pink", "yellow" };
	return colorWord[colorNum];
}

//the actual word, not the color
std::string wordChooser(){
	std::string wordWord[10] = { "black", "blue", "green", "cyan", "red", "pink", "orange", "yellow", "purple", "white" };
	std::string word = wordWord[rand() % 10];
	return word;
}

//checks if the word, and color are the same
int checker(std::string ColorWord, std::string name){
	std::string input, again;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cin >> input;
	if (input == ColorWord){
		std::cout << " " << std::endl;
		std::cout << " " << std::endl;
		++score;
	}
	else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "too bad " << name << " you lost!" << std::endl;
		std::cout << "The word you were supposed to type was " << ColorWord << std::endl;
		std::cout << "your score was " << score << std::endl;
		std::cout << "Would you like to play again? ";
		std::cin >> again;

		if (again == "yes"){
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
		std::cout << word << std::endl;
	} while (gameOver = false);
}

//runs the game
int main(){
	int colorCode, play;
	std::string colorWord, WWord, name;
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
		} while (!gameOver); \
		std::cout << "The game will now close";
		Sleep(3000);
		system("exit");
	}
}