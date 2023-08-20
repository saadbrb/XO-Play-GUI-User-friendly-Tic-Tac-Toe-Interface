#ifndef SCENE_H
#define SCENE_H

#include <QVector>
#include <iostream>
#include <QPainter>

#include "graphikobjkt.h"

class Scene
{
private:
    QVector <GraphikObjkt*> graphikObjekten;

public:
    Scene(){}
    void addObjkt(GraphikObjkt* objkt);
    void paintAllObjects(QPainter* event);
    void removeAllObjects();
    QVector<GraphikObjkt*>& getGraphObjkts();
    ~Scene(){
        if(graphikObjekten.size() > 0){
            for (GraphikObjkt* object : graphikObjekten) {
                delete object;
            }
            graphikObjekten.clear();
        }
    }

};
#endif // SCENE_H
