#ifndef SCENE_H
#define SCENE_H

#include <QVector>
#include <iostream>
#include "graphikobjkt.h"

class Scene
{
private:
    QVector <GraphObjkt*> graphikObjekten;

public:
    Scene(){}
    void addObjkt(GraphObjkt* objkt);
    void paintAllObjects(QPainter* event);
    void removeAllObjects();
    QVector<GraphObjkt*>& getGraphObjkts();

};
#endif // SCENE_H
