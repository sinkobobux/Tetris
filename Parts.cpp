#include "Parts.hpp"

Parts::Parts(){
	parts= {{{1,1},
			 {1,1}},
			 
			{{0,0,0,0,0},
			 {0,0,1,0,0},
			 {0,0,1,1,0},
			 {0,0,0,1,0},
			 {0,0,0,0,0}},
			 
			{{0,0,0,0,0},
			 {0,0,0,1,0},
			 {0,0,1,1,0},
			 {0,0,1,0,0},
			 {0,0,0,0,0}},
			 
			{{0,0,0,0,0},
			 {0,0,1,1,0},
			 {0,0,1,0,0},
			 {0,0,1,0,0},
			 {0,0,0,0,0}},
			 
			{{0,0,0,0,0},
			 {0,1,1,0,0},
			 {0,0,1,0,0},
			 {0,0,1,0,0},
			 {0,0,0,0,0}},
			 
		    {{0,0,0,0,0},
			 {0,0,1,0,0},
			 {0,0,1,1,0},
			 {0,0,1,0,0},
			 {0,0,0,0,0}},
			 
			{{0,0,1,0},
			 {0,0,1,0},
			 {0,0,1,0},
			 {0,0,1,0}}};
}

vector<int> Parts::bag={0,1,2,3,4,5,6};
vector<int> Parts::tmp_bag={};

vector<vector<bool>> Parts::ConsultPart(int ind){
	return parts[ind];
}


void Parts::RotatePart(int ind){
	vector<vector<bool>> vAux=parts[ind];
	int indI=0,indJ=0;
	int sz=(int)parts[ind].size();
	for(int i = 0; i < sz; i++){
		for(int j = sz-1; j>=0; j--){
			parts[ind][indI][indJ]=vAux[j][i];
			indJ++;
		}
		indI++;
		indJ=0;
	}
}

void Parts::DerotatePart(int ind){
	vector<vector<bool>> vAux=parts[ind];
	int indI=0,indJ=0;
	int sz=(int)parts[ind].size();
	for(int i = sz-1; i>=0; i--){
		for(int j = 0; j < sz; j++){
			parts[ind][indI][indJ]=vAux[j][i];
			indJ++;
		}
		indI++;
		indJ=0;
	}
}

int Parts::from_bag(){
	srand(time(NULL));
	if(tmp_bag.empty())	tmp_bag=bag;
	int picker = rand() % tmp_bag.size();
	int content = tmp_bag[picker];
	tmp_bag.erase(tmp_bag.begin()+picker);
	return content;
}
