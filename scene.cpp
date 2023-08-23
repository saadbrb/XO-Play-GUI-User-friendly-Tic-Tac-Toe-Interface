#include <cmath>
#include <QDebug>
#include "scene.h"
void Scene::addObjkt(GraphikObjkt* objkt){
    graphikObjekten.push_back(objkt);
}
void Scene::paintAllObjects(QPainter* event){
    for(int i=0; i<graphikObjekten.size(); i++){
        graphikObjekten[i]->mallen(event);
    }
}


void Scene::setPointsAllObjekt(double ratioX, double ratioY){
    for(int i=0; i<graphikObjekten.size(); i++){
        graphikObjekten[i]->setFirstPunkt(ratioX, ratioY);
        graphikObjekten[i]->setLastPunkt(ratioX, ratioY);
    }
}

void Scene::removeAllObjects(){
    for (int i=0; i<graphikObjekten.size(); i++) {
        delete graphikObjekten[i];
    }
    graphikObjekten.clear();

}


QVector<GraphikObjkt *> &Scene::getGraphObjkts() {
    return graphikObjekten;
}


