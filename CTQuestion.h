#pragma once
#include <string>
#include "CTPlayer.h"
using namespace std;

namespace CSC234 {

	class CTQuestion {
	public:
		CTQuestion();
		CTQuestion(string, string, string, int);
		CTQuestion(string, string, string, string, int);
		CTQuestion(string, string, string, string, string, int);
		CTQuestion(int, string, string, string, string, string, int, string);
		void askQuestions(CTPlayer);

	private:
		CTQuestion* activeQuestion;
		string question;
		string optionone;
		string optiontwo;
		string optionthree = "";
		string optionfour = "";
		string desc = "";
		int dateID = 0;
		int answer;
		int id;
		bool checkAnswer(int);
		void setQuestion(string);
		string getQuestion();
		void setOptionOne(string);
		string getOptionOne();
		void setOptionTwo(string);
		string getOptionTwo();
		void setOptionThree(string);
		string getOptionThree();
		void setOptionFour(string);
		string getOptionFour();
		void setAnswer(int);
		int getAnswer();
		void setDesc(string);
		string getDesc();
	};
}
