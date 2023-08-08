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
    ~Scene(){
        if(graphikObjekten.size() > 0){
            for (GraphObjkt* object : graphikObjekten) {
                delete object;
            }
            graphikObjekten.clear();
        }
    }

};
#endif // SCENE_H
