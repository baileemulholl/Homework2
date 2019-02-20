#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#include "Store.h"
#include "TextUI.h"
#include "Item.h"

int main(int argc, char *argv[]){
	if(argc == 2){
		TextUI menu;
		Store s(argv[1]);
		string choice;
		while(choice != "Leave"){
			choice = menu.MainMenu();
			menu.RouteChoice(s,choice);
		}
	}
	return 0;
}