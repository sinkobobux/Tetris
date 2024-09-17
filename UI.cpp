#include "UI.hpp"

UI::UI(){
	if(!font.loadFromFile("ka1.ttf")){
		cout<<"Error loading font"<<endl;
	}
	
	scoreTextTitle.setFont(font);
	scoreTextTitle.setFillColor(Color::White);
	scoreTextTitle.setPosition(Vector2f(330,25));
	scoreTextTitle.setString("Score");
	
	maxScoreTextTitle.setFont(font);
	maxScoreTextTitle.setFillColor(Color::White);
	maxScoreTextTitle.setPosition(Vector2f(320,200));
	maxScoreTextTitle.setString("Max Score");
	maxScoreTextTitle.setCharacterSize(22);
	
	scoreText.setFont(font);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(Vector2f(345,70));
	
	maxScoreText.setFont(font);
	maxScoreText.setFillColor(Color::White);
	maxScoreText.setPosition(Vector2f(345,245));
	
	byText.setFont(font);
	byText.setFillColor(Color::Red);
	byText.setPosition(Vector2f(90,610));
	byText.setString("by Dit and SB");
	byText.setCharacterSize(40);

	gameOverText.setFont(font);
	gameOverText.setFillColor(Color::White);
	gameOverText.setPosition(Vector2f(70,200));
	gameOverText.setString("Game\nOver");
	gameOverText.setCharacterSize(50);	

	restartText.setFont(font);
	restartText.setFillColor(Color::White);
	restartText.setPosition(Vector2f(45,350));
	restartText.setString("\tPress 'R' \nto play again");
	restartText.setCharacterSize(25);
	
	newScoreText.setFont(font);
	newScoreText.setFillColor(Color::White);
	newScoreText.setPosition(Vector2f(45,200));
	newScoreText.setString("   New\nScore");
	newScoreText.setCharacterSize(50);	
	
	pausedText.setFont(font);
	pausedText.setFillColor(Color::White);
	pausedText.setPosition(Vector2f(35,200));
	pausedText.setString("Paused");
	pausedText.setCharacterSize(45);
}

void UI::SetScore(int x){
	if(x<=9) scoreText.setString("000"+to_string(x));
	else if(x<=99) scoreText.setString("00"+to_string(x));
	else if(x<=999) scoreText.setString("0"+to_string(x));
	else if(x<=9999) scoreText.setString(to_string(x));
	else scoreText.setString("9999");
}


void UI::SetMaxScore(int x){
	if(x<=9) maxScoreText.setString("000"+to_string(x));
	else if(x<=99) maxScoreText.setString("00"+to_string(x));
	else if(x<=999) maxScoreText.setString("0"+to_string(x));
	else if(x<=9999) maxScoreText.setString(to_string(x));
	else maxScoreText.setString("9999");
}

void UI::GameOver(bool g_over){
	gameOver=g_over;
}


void UI::NewScore(bool newscr){
	newScore=newscr;
}

void UI::gPaused(bool state){
	gamepaused=state;
}

void UI::draw(RenderTarget &rt,RenderStates rs) const{
	rt.draw(scoreTextTitle,rs);
	rt.draw(scoreText,rs);
	rt.draw(maxScoreTextTitle,rs);
	rt.draw(maxScoreText,rs);
	rt.draw(byText,rs);
	if(gameOver) {rt.draw(gameOverText,rs);rt.draw(restartText,rs);}
	if(newScore) {rt.draw(newScoreText,rs);rt.draw(restartText,rs);}
	if(gamepaused) rt.draw(pausedText,rs);
}

