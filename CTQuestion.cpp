#include "CTQuestion.h"
#include <iostream>
using namespace std;

namespace CSC234 {

	// Default CTQuestion constructor
	CTQuestion::CTQuestion() {
		setQuestion("");
		setOptionOne("");
		setOptionTwo("");
		setOptionThree("");
		setOptionFour("");
		setAnswer(0);
	}
	// Alt CTQuestion constructor
	CTQuestion::CTQuestion(string quest, string one, string two, int ans) {
		setQuestion(quest);
		setOptionOne(one);
		setOptionTwo(two);
		setOptionThree("");
		setOptionFour("");
		setAnswer(ans);
	}
	// Alt CTQuestion constructor
	CTQuestion::CTQuestion(string quest, string one, string two, string three, int ans) {
		setQuestion(quest);
		setOptionOne(one);
		setOptionTwo(two);
		setOptionThree(three);
		setOptionFour("");
		setAnswer(ans);
	}
	// Alt CTQuestion constructor
	CTQuestion::CTQuestion(string quest, string one, string two, string three, string four, int ans) {
		setQuestion(quest);
		setOptionOne(one);
		setOptionTwo(two);
		setOptionThree(three);
		setOptionFour(four);
		setAnswer(ans);
	}
	// Alt CTQuestion constructor
	CTQuestion::CTQuestion(int date, string quest, string one, string two, string three, string four, int ans, string description) {
		dateID = date;
		setQuestion(quest);
		setOptionOne(one);
		setOptionTwo(two);
		setOptionThree(three);
		setOptionFour(four);
		setAnswer(ans);
		desc = description;
	}

	// Question prompt for each user
	void CTQuestion::askQuestions(CTPlayer player) {
		cout << player.getName() << " your turn to answer a question about what you read..." << endl;
		cout << getQuestion() << endl;
		cout << "[1] " << getOptionOne() << endl;
		cout << "[2] " << getOptionTwo() << endl;
		if (optionthree != "") {
			cout << "[3] " << getOptionThree() << endl;
		}
		if (optionfour != "") {
			cout << "[4] " << getOptionFour() << endl;
		}
		int ans;
		cin >> ans;
		while (ans != 1 && ans != 2 && ans != 3 && ans != 4) {
			cout << "Invalid answer, please try again (ex. 1) ";
			cin >> ans;
		}
		if (checkAnswer(ans)) {
			cout << " C O R R E C T   A N S W E R !" << endl << "Increasing your luck..." << endl;
			player.increaseLuck();
		}
		else {
			cout << "Sorry wrong answer, the correct answer is " << answer << ". Decreasing your luck..." << endl;
			player.decreaseLuck();
		}
		cout << endl << getDesc() << endl << endl;
	}

	// Check the answer input by player
	bool CTQuestion::checkAnswer(int ans) {
		if (answer == ans) return true;
		else return false;
	}

	// Question maintenence
	void CTQuestion::setQuestion(string q) { question = q; }
	string CTQuestion::getQuestion() { return question; }
	void CTQuestion::setOptionOne(string o) { optionone = o; }
	string CTQuestion::getOptionOne() { return optionone; }
	void CTQuestion::setOptionTwo(string o) { optiontwo = o; }
	string CTQuestion::getOptionTwo() { return optiontwo; }
	void CTQuestion::setOptionThree(string o) { optionthree = o; }
	string CTQuestion::getOptionThree() { return optionthree; }
	void CTQuestion::setOptionFour(string o) { optionfour = o; }
	string CTQuestion::getOptionFour() { return optionfour; }
	void CTQuestion::setAnswer(int a) { answer = a; }
	int CTQuestion::getAnswer() { return answer; }
	void CTQuestion::setDesc(string newDesc) { desc = newDesc; }
	string CTQuestion::getDesc() { return desc; }
}
