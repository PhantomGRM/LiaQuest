#include <iostream>
#include <graphics.h>
using namespace std;

class Player{
	private:
		static const int SIZE  = 50;
		static const int OUTLINE_COLOR = WHITE;
		static const int FILL_COLOR = YELLOW;

		int x, y;

		// a helper method
		void draw(int outline, int fill) const{
			setcolor(outline);
			setfillstyle(SOLID_FILL, fill);
			fillellipse(x,y, SIZE, SIZE);
		}

	public:
		Player(int _x=0, int _y=0){
			x = _x; y=_y;
		}

	void show() const{draw(OUTLINE_COLOR, FILL_COLOR); }
	void clear() const{draw(BLACK, BLACK); }

	void setPos(int _x=0, int _y=0){ x = _x; y=_y;}

	void move(int dx=0, int dy=0){
		clear();
		x += dx; y += dy;
		show();
	}

};

int main()
{
	int width = 800;
	int height = 600;
	char gamename[] = "Lia's Quest";
	initwindow(width, height, gamename);

	bool playing = false;
	setvisualpage(0);

	setactivepage(0);
	char welcome[] = "Welcome to Lia's Quest, press C to continue or escape to quit the game";
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(width/2, height/2, welcome);

	setactivepage(1);
	char page1[] = "Pretend you are playing lol, press P to go to main menu";
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(width/2, height/2, page1);
	Player lia(0, height / 2);
	lia.show();



	char key = 0;
	while(key != 27) {
		if(kbhit()) {
			key = getch();
			if (key > 0) {
				key = toupper(key);
				if(key == 'C')
				{
					setvisualpage(1);
					playing = true;
				}
				if(key == 'P')
				{
					setvisualpage(0);
					playing = false;
				}
				 if (key == 27)
					break;
			}
			if (playing == true)
			{
				if (key > 0)
				{
					if (key == 'A')
						lia.move(-10, 0);
					else if (key == 'D')
						lia.move(10, 0);
				} else {
					key = getch();
					cout << "clicked: " << key;
					if(key == 75)
						lia.move(-10, 0);
					else if(key == 77)
						lia.move(10, 0);
				}
			}
		}
	}
	getch();
	return 0;
}