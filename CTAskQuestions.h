#pragma once
#include "CTQuestion.h"
using namespace std;

namespace CSC234 {
	class CTAskQuestions {
	public:
		CTAskQuestions();
		CTAskQuestions(int);
		void testTime(vector<CTPlayer>);
	private:
		vector<CTQuestion*> questions;
	};
}
