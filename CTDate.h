#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "CTEvent.h"
#include "CTNews.h"
#include "CTCity.h"
#include "CTAction.h"
#include "CTAskQuestions.h"
#include "CTInventory.h"
using namespace std;

namespace CSC234 {
	class CTDate {
	public:
		CTDate();
		CTDate(char, int, int, int);
		CTDate(char, int, int, int, CTNews*);
		CTDate(char, int, int, int, CTNews*, CTCity*);
		CTDate(char, int, int, int, CTNews*, CTCity*, CTAskQuestions*);
		CTDate(char, int, int, int, CTNews*, CTCity*, CTAction*);
		CTDate(char, int, int, int, CTNews*, CTCity*, CTAction*, CTEvent*);
		void launch(CTDate[], vector<CTPlayer>);
	private:
		char dayOfWeek;
		string getDayOfWeek();
		int mo;
		string getMonth();
		int day;
		int getDay();
		int year;
		int getYear();
		CTEvent* event = new CTEvent();
		CTEvent* getEvent();
		CTNews* news = new CTNews();
		CTNews* getNews();
		CTCity* city = new CTCity();
		CTCity* getCity();
		CTAction* action = new CTAction();
		CTAction* getAction();
		CTAskQuestions* questions = new CTAskQuestions();
		CTAskQuestions* getQuestions();
		string monologueFilename;
		string getMonologue();
		void printDate();
	};
}