#ifndef PIXELGROUP_H
#define PIXELGROUP_H
#include <QColor>
#include <QPoint>
#include <vector>

class PixelGroup
{
public:
    PixelGroup();
    PixelGroup Move(QPoint vector);
    PixelGroup Move(int x, int y);
private:
    vector <QColor, QPoint> group;
};

#endif // PIXELGROUP_H
