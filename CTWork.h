#pragma once
#include <string>
using namespace std;

namespace CSC234 {
	class CTWork {
	public:
		CTWork();
		double payDay();
		string getJobTitle();
		double getSalary();
		void changeSalary(double);
		void addBonusDollars(double);
		void addBonusPercent(double);
		void payPenalty(double);
		int getJobLevel();
		void incrementJobLevel();
		void resetWeeksAtJob();
		void leaveOfAbsense();
		void endLeaveOfAbsence();
	private:
		int payPeriod = 5;
		string jobTitle;
		int jobLevel;
		double salary;
		double holdingSalary;
		int weeksAtJob;
		void setJobTitle(string);
		void setSalary(double);
		void setJobLevel(int);
		void incrementWeeksAtJob();
	};
}
