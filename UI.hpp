#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class UI : public Drawable{
	private:
		Font font;
		Text scoreTextTitle;
		Text scoreText;
		Text maxScoreTextTitle;
		Text maxScoreText;
		Text byText;
		Text gameOverText;
		Text newScoreText;
		Text pausedText;
		Text restartText;
		bool newScore=false;
		bool gameOver=false;
		bool gamepaused=false;
	public:
		UI();
		void SetScore(int);
		void SetMaxScore(int);
		void GameOver(bool);
		void NewScore(bool);
		void gPaused(bool);
		virtual void draw(RenderTarget&,RenderStates) const;
};
