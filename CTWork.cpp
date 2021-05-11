#include "CTWork.h"
using namespace std;

namespace CSC234 {

	// Default CTWork constructor
	CTWork::CTWork() {
		jobTitle = "";
		jobLevel = 0;
		salary = 0.0;
		weeksAtJob = 0;
	}

	// Job payday
	double CTWork::payDay() {
		incrementWeeksAtJob();
		return salary;
	}

	// Get work information
	void CTWork::setJobTitle(string newTitle) { jobTitle = newTitle; }
	string CTWork::getJobTitle() { return jobTitle; }
	double CTWork::getSalary() { return salary; }
	void CTWork::setJobLevel(int newLevel) { jobLevel = newLevel; }
	void CTWork::incrementWeeksAtJob() { weeksAtJob++; }

	// Salary maintenence 
	void CTWork::setSalary(double newSalary) { salary = newSalary; }
	void CTWork::changeSalary(double newsalary) { salary = newsalary * payPeriod; }
	void CTWork::addBonusDollars(double bonus) { salary = salary + bonus; }
	void CTWork::addBonusPercent(double bonus) { salary = salary * bonus; }
	void CTWork::payPenalty(double penalty) { salary = salary - penalty; }

	// Job level maintenence
	int CTWork::getJobLevel() { return jobLevel; }
	void CTWork::incrementJobLevel() { jobLevel++; }
	void CTWork::resetWeeksAtJob() { weeksAtJob = 0; }

	// Leave of absence
	void CTWork::leaveOfAbsense() {
		holdingSalary = salary;
		salary = 0;
		// add conditional to stop incrementWeeksAtJob
	}

	// Stop leave of absence
	void CTWork::endLeaveOfAbsence() {
		salary = holdingSalary;
		holdingSalary = 0;
	}


}
