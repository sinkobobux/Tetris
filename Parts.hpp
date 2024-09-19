#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Parts{
	private:
		vector<vector<vector<bool>>> parts;
	public:
		Parts();
		vector<vector<bool>> ConsultPart(int ind);
		void RotatePart(int ind);
		void DerotatePart(int ind);
		static int from_bag();
		static vector<int> bag;
		static vector<int> tmp_bag;
};
