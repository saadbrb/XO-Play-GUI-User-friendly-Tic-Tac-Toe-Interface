#include "scene.h"
#include <cmath>
#include <QDebug>

void Scene::addObjkt(GraphObjkt* objkt){

    graphikObjekten.push_back(objkt);
    qDebug()<<"Objekt added Secessful!\n";

    qDebug()<<"Size is: "<<graphikObjekten.size();
}
void Scene::paintAllObjects(QPainter* event){

    for(int i=0; i<graphikObjekten.size(); i++){
        graphikObjekten[i]->mallen(event);
    }
}



void Scene::removeAllObjects(){
//    if(graphikObjekten.size() > 0){
//        for (GraphObjkt* object : graphikObjekten) {
//            delete object;
//        }
        graphikObjekten.clear();
   // }
}


QVector<GraphObjkt *> &Scene::getGraphObjkts() {
    return graphikObjekten;
}


