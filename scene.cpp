#include <cmath>
#include <QDebug>
#include "scene.h"
void Scene::addObjkt(GraphikObjkt* objkt){
    graphikObjekten.push_back(objkt);
}
void Scene::paintAllObjects(QPainter* event){
    if(graphikObjekten.size() > 0){
        for(int i=0; i<graphikObjekten.size(); i++){
            graphikObjekten[i]->mallen(event);
        }
    }
}



void Scene::removeAllObjects(){
    if(graphikObjekten.size() > 0){
        for (int i=0; i<graphikObjekten.size(); i++) {
            delete graphikObjekten[i];
        }
        graphikObjekten.clear();
    }
}


QVector<GraphikObjkt *> &Scene::getGraphObjkts() {
    return graphikObjekten;
}


