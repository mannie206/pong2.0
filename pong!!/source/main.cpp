#include "AIE.h"
#include <iostream>
using namespace std;


//const int......

const int  IsKeyDown;

void UpdateGmae()
{
	if ( IsKeyDown ('A'))
	{
		padle -= 2.f;
		if (padle < (SCREEN_WIDTH*.5f) )
		  {
			padle = (SCREEN_WIDTH*.5F);
	      }
   }
}

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

struct Ball
{
	float postionX;
	float postionY;
	float speedX;
	float speedY;
	unsigned int spriteID = CreateSprite("./images/ball.png", 30, 30, true);

	void Move(float a_fDeltaTime)
	{
		postionX += speedX * a_fDeltaTime;
		postionY += speedY * a_fDeltaTime;
		MoveSprite(spriteID, postionX, postionY);
	}

	void Draw()
	{
		DrawSprite(spriteID);
	}

};

struct Padle
{
	float postionX;
	float postionY;
	float speedX;
	float speedY;
	unsigned int spriteID = CreateSprite("./images/padle.png", 40, 40, true);

	void Move(float a_fDeltaTime)
	{
		postionX += speedX *a_fDeltaTime;
		postionY += speedY *a_fDeltaTime;
		MoveSprite(spriteID, postionX, postionY);
	}
	void Draw()
	{
		DrawSprite(spriteID);
	}
};


int main(int argc, char* argv[])
{
	Initialise(SCREEN_WIDTH, SCREEN_HEIGHT, false, "pong");

	Ball joe;
	joe.postionX = (float)(SCREEN_WIDTH / 2);
	joe.postionY = (float)(SCREEN_HEIGHT / 2);
	joe.speedX = -1.0f;
	joe.speedY = -1.0f;

	Padle may;
	may.postionX = 50.0f;
	may.postionY = 300.0f;
	may.speedX = 0.0f;
	may.speedY = 0.0f;


	//ball = CreateSprite ( "./images/ball.png",37,340, true );
	//padle = CreateSprite ( "./images/padle.png", 32, 325, true);
	//padle2 = CreateSprite  ( "./images/padle2.png",34,326, true );
	//MoveSprite(padle, 35, 32);
	//MoveSprite(padle2, 38, 50);
	SetBackgroundColour(SColour(14, 18, 24, 78));



	//GameLoop...
	do
	{
		/*	ballSpeedx = ballSpeedx  * 30;
		ballSpeedy = ballSpeedy * 30;


		MoveSprite(ball, ballX, ballY);
		DrawSprite(ball);
		DrawSprite(padle);
		DrawSprite(padle2);*/
		ClearScreen();
		joe.Move(GetDeltaTime() * 100);
		joe.Draw();
		may.Move(GetDeltaTime() * 100);
		may.Draw();
	} while (!FrameworkUpdate());

	Shutdown();

	return 0;
}
