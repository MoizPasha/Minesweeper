#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class tile
{
public:
	tile();
	~tile();
	sf::Sprite *Tile;
	sf::Texture texture;
};

tile::tile()
{
	Tile = nullptr;
}

tile::~tile()
{
	delete Tile;
}

class unclicked : public tile
{
public:
	unclicked();
	~unclicked();
};

unclicked::unclicked()
{
	texture.loadFromFile("0.jpg");
	Tile = new sf::Sprite(texture);
}

unclicked::~unclicked()
{
}

class clicking : public tile
{
public:
	clicking();
	~clicking();

private:

};

clicking::clicking()
{
	texture.loadFromFile("5.jpg");
	Tile = new sf::Sprite(texture);
}

clicking::~clicking()
{
}
class mine : public tile
{
public:
	mine();
	~mine();

private:

};

mine::mine()
{
	texture.loadFromFile("1.jpg");
	Tile = new sf::Sprite(texture);
}

mine::~mine()
{
}

class mine_hit : public tile
{
public:
	mine_hit();
	~mine_hit();

private:

};

mine_hit::mine_hit()
{
	texture.loadFromFile("2.jpg");
	Tile = new sf::Sprite(texture);
}

mine_hit::~mine_hit()
{
}


class flag : public tile
{
public:
	flag();
	~flag();

private:

};

flag::flag()
{
	texture.loadFromFile("4.jpg");
	Tile = new sf::Sprite(texture);
}

flag::~flag()
{
}

class flag_true : public tile
{
public:
	flag_true();
	~flag_true();

private:

};

flag_true::flag_true()
{
	texture.loadFromFile("3.jpg");
	Tile = new sf::Sprite(texture);
}

flag_true::~flag_true()
{
}



