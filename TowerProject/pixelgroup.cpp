#include "pixelgroup.h"

PixelGroup::PixelGroup()
{
}

void PixelGroup::addPixel(Pixel p){
    group.push_back(p);
}

PixelGroup PixelGroup::Move(int x, int y){
    int length = group.size();
    for(int i = 0; i < length; i++){
        group[i].applyVector(x,y);
    }
    PixelGroup temp;
    temp.setGroup(group);
    return temp;
}

PixelGroup PixelGroup::Move(QPoint vector){
    int length = group.size();
    const int x = vector.x();
    const int y = vector.y();
    for(int i = 0; i < length; i++){
        group[i].applyVector(x,y);
    }
    PixelGroup temp;
    temp.setGroup(group);
    return temp;
}

void PixelGroup::setGroup(QList<Pixel> g){
    group = g;
}
