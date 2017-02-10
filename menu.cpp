#include "menu.h"
#include "setup.h"
#include "menu_button.h"
#include <QGraphicsScene>

Menu::Menu()
{
    start();
}

void Menu::start()
{
    scene = new QGraphicsScene();
    this->setup = NULL;
    QImage pim(":/images/menu.png");
    scene->setBackgroundBrush(pim.scaled(1000, 700, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    view = new QGraphicsView();
    view->setScene(scene);
    view->setFixedSize(1000, 700);
    scene->setSceneRect(0,0, 1000, 700);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    buttons[0] = new menu_button(650, 152, PLAY, -8.3);
    buttons[1] = new menu_button(650, 280, HIGHSCORES, -7);
    buttons[2] = new menu_button(650, 420, CREDITS, -8);
    buttons[3] = new menu_button(650, 550, EXIT, -7);
    scene->addItem(buttons[0]);
    scene->addItem(buttons[1]);
    scene->addItem(buttons[2]);
    scene->addItem(buttons[3]);
    connect(buttons[0], SIGNAL(playclicked()), this, SLOT(play()));
    connect(buttons[1], SIGNAL(scoresclicked()), this, SLOT(score()));
    connect(buttons[2], SIGNAL(creditsclicked()), this, SLOT(credits()));
    connect(buttons[3], SIGNAL(exitclicked()), this, SLOT(quit()));
}

QGraphicsScene *Menu::getScene()
{
    return scene;
}

Menu::~Menu()
{
    delete buttons[0];
    delete buttons[1];
    delete buttons[2];
    delete buttons[3];
    delete setup;
    delete scene;
    delete view;
}

void Menu::play()
{
    delete scene;
    delete view;
    Setup *setup = new Setup();
    setup->start();
    setup->makeEnemies();
}

void Menu::score()
{

}

void Menu::credits()
{
    delete buttons[0];
    delete buttons[1];
    delete buttons[2];
    delete buttons[3];
    delete setup;
    delete scene;
    delete view;
    scene = new QGraphicsScene();
    QImage pim(":/images/creditsmenu.png");
    scene->setBackgroundBrush(pim.scaled(1000, 700, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    view = new QGraphicsView();
    view->setScene(scene);
    view->setFixedSize(1000, 700);
    scene->setSceneRect(0,0, 1000, 700);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    menu_button *backbtn = new menu_button(120, 590, BACK, 0);
    scene->addItem(backbtn);
    connect(backbtn, SIGNAL(backclicked()), this, SLOT(back()));
}

void Menu::quit()
{
    if(setup != NULL)
        setup->exitGame();
    delete this;
    exit(0);
}

void Menu::back()
{
    delete scene;
    delete view;
    this->start();
}

