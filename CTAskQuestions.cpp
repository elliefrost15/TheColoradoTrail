#include "CTAskQuestions.h"
#include <ctime>
#include "CTFunctions.h"
using namespace std;

namespace CSC234 {

	// Default CTAskQuestions constructor
	CTAskQuestions::CTAskQuestions() { questions = {}; }

	// Make a set of questions based on a number input
	CTAskQuestions::CTAskQuestions(int id) {
		CTQuestion* w1q1 = new CTQuestion(1011859, "What first sent explorers searching for gold in the Rockies in the early 1850s?", "Reports from miners returning from California", "Rumors from Indians", "Old treasure maps", "European legends", 2, "The first two main parties to go searching for gold were following stories from Indian tribes of gold found on the riverbanks. One of the parties, lead by William Russell, followed Cherokee stories from Georgia to the South Platte River, while the secondary Lawrence party was in pursuit of leads from a Delaware Indian US Army scout.");
		CTQuestion* w1q2 = new CTQuestion(1011859, "About how many people lived in Colorado in 1858?", "1200", "10000", "500", "100", 3, "In one year, Colorado's population soared from 500 up into the tens of thousands in 1859.");
		CTQuestion* w1q3 = new CTQuestion(1011859, "What mode of transportation was best for getting to the mountains?", "Mules", "Horses", "Buffalo", "Oxen", 4, "While mules and horses were preferred for travel in the mountains, oxen were the most reliable way to move people and their belongings across the plains.");
		CTQuestion* w1q4 = new CTQuestion(1011859, "Was it better to go to the mines - ", "A group of four or more men", "With one's wife and children", "Alone", "", 1, "The most successful prospectors came out in groups of four or more with the supplies and provisions they would need for up to 6 months. Families with older children were more successful than families with younger children unable to help the family work.");
		CTQuestion* w1q5 = new CTQuestion(1011859, "In 1859 Colorado was", "A state", "Part of the Kansas Territory", "Part of the Utah Territory", "Part of several territories", 4, "The current boundaries of Colorado, in 1859, were parts of the Kansas Territory, Utah Territory, and the New Mexico Territory. Colorado did not become a state until 1876.");
		CTQuestion* w1q6 = new CTQuestion(1011859, "The first town established in Colorado was", "Denver", "Auraria City", "Montana City", "Russellville", 3, "Montana City was established at the northern confluence of Little Dry Creek with the South Platte River in 1858. At present day, the spot is located just off the exit of I25 and Evans Road in Englewood.");
		CTQuestion* w1q7 = new CTQuestion(1011859, "Auraria City and Denver City were divided by the", "South Platte River", "Little Dry Creek", "Cherry Creek", "North Platte River", 3, "Denver City turned into modern day downtown Denver, merging with Auraria City, which made up the area now bordered by Colfax on the south, Speer on the east, I25 and the South Platte River on the west and north.");
		CTQuestion* w1q8 = new CTQuestion(1011859, "The most common way to refer to the front range area in 1859 was", "Colorado", "Pike's Peak", "Colona", "Denver", 2, "Starting in the winter of 1858, newspapers across the country featured headlines about Pike's Peak and the gold discoveries out west. Pike's Peak or Bust was the popular slogan, and there was an entire industry of Pike's Peak companies to get one out to the mines.");
		CTQuestion* w1q9 = new CTQuestion(1011859, "The Civil War had already occurred by 1859.", "True", "False", "", "", 2, "The Civil War began April 12, 1861, following mounting tension among the states over slavery, commerce,  lifestyle, and a host of other factors.");
		CTQuestion* w1q10 = new CTQuestion(1011859, "Travelers were best off", "Bringing what they needed with them", "Buying what they needed when they arrived", "", "", 1, "Despite the reports across the nation about the new mining opportunities in the west, many went out on the trail thinking there would be opportunities for commerce, but they found little along the way and sparce, overpriced goods when they arrived. Unprepared travelers were often caught off guard and suffered the consequences with death or a swift return to whence they came.");
		CTQuestion* w2q1 = new CTQuestion(1151859, "The trip out to the gold region took about", "5 days", "6 months", "45 days", "90 days", 3, "Every trip was different, with different routes and points of origin but the average time from St. Louis to Denver was around 45 days.");
		CTQuestion* w2q2 = new CTQuestion(1151859, "Denver was named after", "John Denver", "The governor of Kansas in 1858", "A city in California", "A monkey's uncle", 2, "James W. Denver was appointed Commissioner of Indian Affairs in the spring of 1857, then Secretary of the Kansas Territory in the summer, and Territorial Governor in the winter. He retired from the position the following year, but not before land speculator, William Larimer Jr. named Denver City in hopes of securing the townseat of Arapaho County.");
		CTQuestion* w2q3 = new CTQuestion(1151859, "Which country was pushing for slave trade to be declared piracy?", "United States", "France", "Spain", "England", 4, "After losing millions in assets in the New World due to the American Revolution, England set her sights on destroying the newly formed American economy by forming a new war against the slave trade, working to get other countries in Europe to ban together to make the slave trade illegal.");
		CTQuestion* w2q4 = new CTQuestion(1151859, "What country reported the deaths of an American family by Musselmans in 1858?", "Servia", "India", "Turkey", "Iran", 3, "The Americans have threatened to bombard Jaffa if justice be not executed, and if they keep their word they will have to come to that extremity. The guilty parties are all at Beyrout, and may possibly escape.");
		CTQuestion* w2q5 = new CTQuestion(1151859, "In the beginning of 1859, the emigrants hadn't made it into the mountains yet.", "True", "False", "", "", 2, "There were gold discoveries in Idaho Springs and Central City in 1858, and the pioneers were quickly exploring the foothills looking for ways into the Rockies.");
		CTQuestion* w2q6 = new CTQuestion(1151859, "The winter of 1858/59 was wet and brutal.", "True", "False", "", "", 2, "Though rivers to the east were overflowing as they worked south, the winter boasted bare ground, little snow and rain.");
		CTQuestion* w2q7 = new CTQuestion(1151859, "Silver was also discovered when they started digging in the 1850s.", "True", "False", "", "", 2, "Silver was found in later discoveries but the original digging was focused around gold, finding quartz, gypsum, marble, and coal along the way.");
		CTQuestion* w2q8 = new CTQuestion(1151859, "Wyandott, Kansas, sitting at the confluence of the Kansas and Missouri Rivers is now known as", "Wichita", "Omaha", "Columbia", "Kansas City", 4, "Formed around the same time as Denver, it's position on the Missouri River gave rise to the creation of modern day Kansas City.");
		CTQuestion* w3q1 = new CTQuestion(2061859, "The northern pass through Colorado towards Colorado was", "Bridger's Pass", "Cochatope Pass", "Loveland Pass", "Guanella Pass", 1, "Now a part of Wyoming, Bridger's Pass became a part of the northern route to California.");
		CTQuestion* w3q2 = new CTQuestion(2061859, "The president of the United States in 1859 was", "Abraham Lincoln", "James Buchanan", "Andrew Johnson", "Franklin Pierce", 2, "Buchanan was elected as a democrat in 1856, as the pro-slavery party of the time, against anti-slavery Republican Millard Filmore. Some suggest that his victory came from spending the preceeding years as an ambassador in London, and had not be associated with any of the slavery issues in the country at the time.");
		CTQuestion* w3q3 = new CTQuestion(2061859, "Which of the following was not a name for the area now known as Colorado in 1859?", "Jefferson", "Colona", "Colorado", "Texas", 4, "Although a large swath of Colorado once was part of the Texas Territory, the land had been divided up in earlier parts of the 1800s, as Spain left the Americas and Mexican borders shifted.");
		CTQuestion* w3q4 = new CTQuestion(2061859, "How much was an ounce of pure gold worth in 1859?", "$100", "$10", "$24", "$50", 3, "Gold prices varied across the country and depending on the purity. California gold was said to be worth about $16 per ounce and was examined by the national mint in Philadelphia.");
		CTQuestion* w3q5 = new CTQuestion(2061859, "The main river where people were searching for gold in 1859 around Colorado was", "North Platte River", "Arkansas River", "South Platte River", "Missouri River", 3, "Explorers traced the South Platte River up into the Rockies in search of the origins of the specks of gold they found through its banks downstream.");
		vector<CTQuestion*> week1questions = { w1q1, w1q2, w1q3, w1q4, w1q5, w1q6, w1q7, w1q8,
			w1q9, w1q10 };
		vector<CTQuestion*> week2questions = { w1q1, w1q2, w1q3, w1q4, w1q5, w1q6, w1q7, w1q8,
			w1q9, w1q10, w2q1, w2q2, w2q3, w2q4, w2q5, w2q6, w2q7, w2q8 };
		vector<CTQuestion*> week3questions = { w1q1, w1q2, w1q3, w1q4, w1q5, w1q6, w1q7, w1q8,
			w1q9, w1q10, w2q1, w2q2, w2q3, w2q4, w2q5, w2q6, w2q7, w2q8, w3q1, w3q2, w3q3, w3q4, w3q5 };
		switch (id) {
		case 1: questions = week1questions; break;
		case 2: questions = week2questions; break;
		case 3: questions = week3questions; break;
		default:break;
		}
	}

	// Loop through players to ask questions about what they have read
	void CTAskQuestions::testTime(vector<CTPlayer> players) {
		srand((unsigned)time(0));
		int qlength = (int)questions.size();
		for (auto player : players) {
			int rand1 = rand() % qlength;
			int rand2 = rand() % qlength;
			int rand3 = rand() % qlength;
			int rand4 = rand() % qlength;
			int rand5 = rand() % qlength;
			int random = (rand1 + rand2 + rand3 + rand4 + rand5) % 5;
			questions.at(random)->askQuestions(player);
		}
		clearScreen();
	}
}