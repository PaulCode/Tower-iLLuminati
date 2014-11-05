#ifndef PIXELGROUP_H
#define PIXELGROUP_H
#include <QColor>
#include <QPoint>
#include <vector>

using namespace std;

class PixelGroup
{
public:
    PixelGroup();
    PixelGroup Move(QPoint vector);
    PixelGroup Move(int x, int y);
private:
    typedef struct pixel{
        QColor color;
        QPoint point;
    } pixel;

    vector <pixel> group;
};

#endif // PIXELGROUP_H
