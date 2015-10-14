//
//  main.cpp
//  CGProj
//

#include "Common.h"
#include "GameManager.h"
#include "Logger.h"
#include "Car.h"
#include "Table.h"
#include "Roadside.h"
#include "Orange.h"
#include "butter.h"


int main(int argc, char * argv[]) {
	
	GameManager* gameMgr = new GameManager();

	Car* car = new Car();
    Butter* butter = new Butter();
    Table* table = new Table();
	Orange* orange = new Orange();
    Roadside* roadside = new Roadside();
	Logger::printf("Initializing Game Manager");
	gameMgr->setCamera(new Camera(5, 200));
	gameMgr->setCar(car);
	gameMgr->addGameObject(car);
    gameMgr->addGameObject(table);
	gameMgr->addGameObject(orange);
    gameMgr->addGameObject(butter);
    gameMgr->addGameObject(roadside);
	gameMgr->init(argc, argv);
	return 0;

}
