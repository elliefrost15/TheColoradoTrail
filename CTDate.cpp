#include "CTDate.h"
#include "CTCity.h"
#include <Windows.h>

namespace CSC234 {
	// Default constructor
	CTDate::CTDate() {
		dayOfWeek = '.';
		mo = 0;
		day = 0;
		year = 0;
	}

	// Date with day of the week, month, day, year
	CTDate::CTDate(char ddow, int dmo, int dday, int dyear) {
		dayOfWeek = ddow;
		mo = dmo;
		day = dday;
		year = dyear;
	}

	// Date with day of the week, month, day, year, news article
	CTDate::CTDate(char ddow, int dmo, int dday, int dyear, CTNews* dnews) {
		dayOfWeek = ddow;
		mo = dmo;
		day = dday;
		year = dyear;
		news = dnews;
	}

	// Date with day of the week, month, day, year, news article, city
	CTDate::CTDate(char ddow, int dmo, int dday, int dyear, CTNews* dnews, CTCity* dcity) {
		dayOfWeek = ddow;
		mo = dmo;
		day = dday;
		year = dyear;
		news = dnews;
		city = dcity;
	}
	// Date with day of the week, month, day, year, news article, city
	CTDate::CTDate(char ddow, int dmo, int dday, int dyear, CTNews* dnews, CTCity* dcity, CTAskQuestions* dquestions) {
		dayOfWeek = ddow;
		mo = dmo;
		day = dday;
		year = dyear;
		news = dnews;
		city = dcity;
		questions = dquestions;
	}

	// Date with day of the week, month, day, year, news article, city, action
	CTDate::CTDate(char ddow, int dmo, int dday, int dyear, CTNews* dnews, CTCity* dcity, CTAction* daction) {
		dayOfWeek = ddow;
		mo = dmo;
		day = dday;
		year = dyear;
		news = dnews;
		city = dcity;
		action = daction;
	}

	// Date with day of the week, month, day, year, news article, city, action, event
	CTDate::CTDate(char ddow, int dmo, int dday, int dyear,
		CTNews* dnews, CTCity* dcity,
		CTAction* daction, CTEvent* devent) {
		dayOfWeek = ddow;
		mo = dmo;
		day = dday;
		year = dyear;
		event = devent;
		news = dnews;
		city = dcity;
		action = daction;
	}

	// Display month based on the numeric input
	string CTDate::getMonth() {
		switch (mo) {
		case 1: return "January";
		case 2: return "February";
		case 3: return "March";
		case 4: return "April";
		case 5: return "May";
		case 6: return "June";
		case 7: return "July";
		case 8: return "August";
		case 9: return "September";
		case 10: return "October";
		case 11: return "November";
		case 12: return "December";
		default: return "";
		}
	}

	// Display day of week based on numeric input
	string CTDate::getDayOfWeek() {
		switch (dayOfWeek) {
		case 'M': return "Monday";
		case 'T': return "Tuesday";
		case 'W': return "Wednesday";
		case 'H': return "Thursday";
		case 'F': return "Friday";
		case 'S': return "Saturday";
		case 'U': return "Sunday";
		default: return "";
		}
	}

	// Return information from the date
	int CTDate::getDay() { return day; }
	int CTDate::getYear() { return year; }
	CTEvent* CTDate::getEvent() { return event; }
	CTNews* CTDate::getNews() { return news; }
	CTCity* CTDate::getCity() { return city; }
	CTAction* CTDate::getAction() { return action; }
	string CTDate::getMonologue() { return monologueFilename; }
	CTAskQuestions* CTDate::getQuestions() { return questions; }

	// Play through the date timeline 
	void CTDate::launch(CTDate timeline[], vector<CTPlayer> players) {
		for (int i = 0; i < sizeof(timeline); i++) {
			CTDate* temp = &timeline[i];
			temp->printDate(); // Run CTDate::printDate()
			CTNews* tempnews = temp->getNews();
			tempnews->printNews(); // Run CTNews::printNews()
			CTCity* tempcity = temp->getCity();
			tempcity->printCity(players); // Run CTCity::printCity()
			//CTAction* tempaction = temp->getAction();
			//tempaction->printAction(); 
			CTAskQuestions* tempqs = temp->getQuestions();
			tempqs->testTime(players);
		}
	}

	// Display date information
	void CTDate::printDate() {
		cout << getDayOfWeek() << ", " << getMonth() << " " << day << ", " << year << endl;
		Sleep(1500);
	}
}

