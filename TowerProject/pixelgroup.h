#ifndef PIXELGROUP_H
#define PIXELGROUP_H
#include <QColor>
#include <QPoint>
#include <QList>
#include "pixel.h"

using namespace std;

class PixelGroup
{
public:
    PixelGroup();
    PixelGroup Move(QPoint vector);
    PixelGroup Move(int x, int y);
    void addPixel(Pixel p);
private:
    QList <Pixel> group;
    void setGroup(QList<Pixel> g);
};

#endif // PIXELGROUP_H
