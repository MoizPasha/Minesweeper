#include "Console.h"

class game
{
public:
	game();
	void render();
	void draw();
	bool running();
	~game();

private:
	sf::RenderWindow* window;
	sf::Event event;
	console play;
	int redraw ;
	sf::Font font;
};

game::game() : event(),play(8,8)
{
	font.loadFromFile("GoldenWings.ttf");
	redraw = 2;
	window = new sf::RenderWindow(sf::VideoMode(800, 800), "Tetris",sf::Style::Titlebar|sf::Style::Close);
	window->setFramerateLimit(24);
	draw();
}
void game::draw()
{
	window->clear(sf::Color::Black);
	float x = 100, y = 70;
	if (redraw != -1)
	{
		play.arr = new unclicked;
		for (int i = 0; i < play.rows; i++)
		{
			for (int j = 0; j < play.cols; j++)
			{

				if (play.screen[i][j] >= 0 && play.screen[i][j] < 10)
				{
					delete play.arr;
					play.arr = new clicking;
					play.arr->Tile->setPosition(x, y);
					window->draw(*play.arr->Tile);
					if (play.screen[i][j] > 0)
					{
						sf::Text text;

						text.setFont(font);
						text.setString(to_string(play.screen[i][j]));
						text.setPosition(x, y);
						if (play.screen[i][j] == 1)
							text.setPosition(x + 5, y);
						window->draw(text);
					}
					delete play.arr;
					play.arr = new unclicked;
				}
				else if (play.screen[i][j] >= 20 || play.screen[i][j] ==-2)
				{
					delete play.arr;
					play.arr = new flag;
					play.arr->Tile->setPosition(x, y);
					window->draw(*play.arr->Tile);
					delete play.arr;
					play.arr = new unclicked;
				}
				else
				{
					play.arr->Tile->setPosition(x, y);
					window->draw(*play.arr->Tile);
				}
				x += 30;
			}
			y += 30;
			x = 100;
		}
	}
	else
	{
		play.arr = new unclicked;
		for (int i = 0; i < play.rows; i++)
		{
			for (int j = 0; j < play.cols; j++)
			{

				if (play.screen[i][j] >= 0 && play.screen[i][j] < 10)
				{
					delete play.arr;
					play.arr = new clicking;
					play.arr->Tile->setPosition(x, y);
					window->draw(*play.arr->Tile);
					if (play.screen[i][j] > 0)
					{
						sf::Text text;

						text.setFont(font);
						text.setString(to_string(play.screen[i][j]));
						text.setPosition(x, y);
						if (play.screen[i][j] == 1)
							text.setPosition(x + 5, y);
						window->draw(text);
					}
					delete play.arr;
					play.arr = new unclicked;
				}
				else if (play.screen[i][j] == -20)
				{
					delete play.arr;
					play.arr = new mine_hit;
					play.arr->Tile->setPosition(x, y);
					window->draw(*play.arr->Tile);
					delete play.arr;
					play.arr = new unclicked;
				}
				else if (play.screen[i][j] >= 20)
				{
					delete play.arr;
					play.arr = new flag;
					play.arr->Tile->setPosition(x, y);
					window->draw(*play.arr->Tile);
					delete play.arr;
					play.arr = new unclicked;
				}
				else if (play.screen[i][j] == -2)
				{
					delete play.arr;
					play.arr = new flag_true;
					play.arr->Tile->setPosition(x, y);
					window->draw(*play.arr->Tile);
					delete play.arr;
					play.arr = new unclicked;
				}
				else if (play.screen[i][j] == -1)
				{

					delete play.arr;
					play.arr = new mine;
					play.arr->Tile->setPosition(x, y);
					window->draw(*play.arr->Tile);
					delete play.arr;
					play.arr = new unclicked;
				}
				else
				{
					play.arr->Tile->setPosition(x, y);
					window->draw(*play.arr->Tile);
				}
				x += 30;
			}
			y += 30;
			x = 100;
		}
	}
	sf::Text text;
	text.setFont(font);
	text.setString("Reveal");
	text.setPosition(100, y+20);
	window->draw(text);
	text.setString("Reset");
	text.setPosition(40+x+((play.cols/2) *30), y+20);
	window->draw(text);

	window->display();
}
void game::render()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		else if (event.key.code == sf::Keyboard::Escape)
			window->close();

		else if (event.key.code == sf::Mouse::Left && sf::Mouse::isButtonPressed(sf::Mouse::Left) == 0)
		{
			int x = (sf::Mouse::getPosition(*window).x - 100) / 30;
			int y = (sf::Mouse::getPosition(*window).y - 70) / 30;
			if (redraw == 2&&x>=0&&x<play.cols&&y>=0&&y<play.rows)
			{
				play.fill(y,x);
				redraw = 1;
			}
			else if (redraw == 1&&y<play.rows)
			{
				if (play.screen[y][x] == -1)
				{
					play.screen[y][x] = -20;
					redraw = -1;
				}
				else if(play.screen[y][x]>=10)
				{
					play.screen[y][x] -= 10;
				}
			}
			else if (redraw == -1 || redraw == 1&&(y==play.rows+1||y==play.rows+2))
			{
				if (x < (play.cols+1)/2)
				{
					redraw = -1;
				}
				else if (x < play.cols)
				{
					play.reset();
					redraw = 2;
				}
			}
		}
		else if (event.key.code == sf::Mouse::Right&&redraw!=2&&sf::Mouse::isButtonPressed(sf::Mouse::Right)==0)
		{

			int x = (sf::Mouse::getPosition(*window).x - 100) / 30;
			int y = (sf::Mouse::getPosition(*window).y - 70) / 30;
			if (play.screen[y][x] >= 10)
			{
				play.screen[y][x] += 10;
			}
			else if (play.screen[y][x] == -1)
			{
				play.screen[y][x] = -2;
			}
			else if (play.screen[y][x] == -2)
			{
				play.screen[y][x] = -1;
			}

		}
		draw();
	}

}
bool game::running()
{
	return window->isOpen();

}
game::~game()
{
	delete window;
}
