#ifndef FIGURE_HPP
#define FIGURE_HPP
class figure{
public:
	virtual void move() = 0;
	virtual bool isFin() = 0;
	virtual int getY() = 0;
	virtual int getX() = 0;
	virtual bool isExplode() = 0;
};
#endif