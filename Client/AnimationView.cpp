#include "AnimationView.h"
#include <typeinfo>

GraphicsBush::GraphicsBush(QObject *parent)
  :  QObject(parent) {
  //this->setBrush(QColor(0, 255, 0));
}

QPainterPath GraphicsBush::shape() const {
    QPainterPath path;
    path.addEllipse(15,25,0,0);
    return path;
}

GraphicsThreeBush::GraphicsThreeBush(QObject *parent)
  :  QObject(parent) {
  //this->setBrush(QColor(0, 255, 0));
}

QPainterPath GraphicsThreeBush::shape() const {
    QPainterPath path;
    path.addEllipse(20,30,2,1);
    return path;
}

GraphicsTree::GraphicsTree(QObject *parent)
  :  QObject(parent) {
  //this->setBrush(QColor(0, 255, 0));
}

QPainterPath GraphicsTree::shape() const {
    QPainterPath path;
    path.addEllipse(32,100,3,3);
    return path;
}

GraphicsTreeTwo::GraphicsTreeTwo(QObject *parent)
  :  QObject(parent) {
  //this->setBrush(QColor(0, 255, 0));
}

QPainterPath GraphicsTreeTwo::shape() const {
    QPainterPath path;
    path.addEllipse(53,128,20,4);
    return path;
}
// stone
GraphicsStone::GraphicsStone(QObject *parent)
  :  QObject(parent) {
  //this->setBrush(QColor(0, 255, 0));
}

QPainterPath GraphicsStone::shape() const {
    QPainterPath path;
    path.addEllipse(53,128,20,4);
    return path;
}
// stone

// house
GraphicsHouse::GraphicsHouse(QObject *parent)
  :  QObject(parent) {
  //this->setBrush(QColor(0, 255, 0));
}

QPainterPath GraphicsHouse::shape() const {
    QPainterPath path;
    path.addEllipse(0,100,166,70);
    return path;
}
// house

// cafe
GraphicsCafe::GraphicsCafe(QObject *parent)
  :  QObject(parent) {
  //this->setBrush(QColor(0, 255, 0));
}

QPainterPath GraphicsCafe::shape() const {
    QPainterPath path;
    path.addEllipse(0,175,166,1);
    return path;
}
// cafe

// taverna
GraphicsTaverna::GraphicsTaverna(QObject *parent)
  :  QObject(parent) {
  //this->setBrush(QColor(0, 255, 0));
}

QPainterPath GraphicsTaverna::shape() const {
    QPainterPath path;
    path.addEllipse(0,100,166,70);
    return path;
}
// taverna

// house_man
GraphicsHouseMan::GraphicsHouseMan(QObject *parent)
  :  QObject(parent) {
  //this->setBrush(QColor(0, 255, 0));
}

QPainterPath GraphicsHouseMan::shape() const {
    QPainterPath path;
    path.addEllipse(30,30,35,50);
    return path;
}
// house_man

// cook
GraphicsCook::GraphicsCook(QObject *parent)
  :  QObject(parent) {
  //this->setBrush(QColor(0, 255, 0));
}

QPainterPath GraphicsCook::shape() const {
    QPainterPath path;
    path.addEllipse(30,30,35,50);
    return path;
}
// cook

// security
GraphicsSecurity::GraphicsSecurity(QObject *parent)
  :  QObject(parent) {
  //this->setBrush(QColor(0, 255, 0));
}

QPainterPath GraphicsSecurity::shape() const {
    QPainterPath path;
    path.addEllipse(30,40,35,35);
    return path;
}
// security

// еда
GraphicsFood::GraphicsFood(QObject *parent)
  :  QObject(parent) {
  //this->setBrush(QColor(0, 255, 0));
}

QPainterPath GraphicsFood::shape() const {
    QPainterPath path;
    path.addEllipse(0,0,16,16);
    return path;
}
// еда
AnimationView::AnimationView(QWidget *parent) :
    QGraphicsView(parent)
{
    setRenderHint(QPainter::Antialiasing);

    setCacheMode(QGraphicsView::CacheNone);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setWindowTitle("FriendTube");
    setFrameStyle(0);
    setSceneRect(0, 0, 1280, 720);
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    setFixedSize(1280, 720);

    setFrameStyle(0);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету


    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720);
    this->setScene(scene);
    timer_update_scene = new QTimer();

    connect(timer_update_scene, SIGNAL(timeout()), this, SLOT(update()));
    timer_update_scene->start(3);

    init_background_item();
}

void AnimationView::init_background_item(){
    QBrush *ibrush = new QBrush;
    ibrush->setTextureImage(QImage(":/images/background1.png")); // background scene
    scene->setBackgroundBrush(*ibrush);

    // houses

    // house
        QPixmap texture_house(":/pics/background_item/green_room/more_texture/buildings/building2_1.png");
        GraphicsHouse *house = new GraphicsHouse;
        house->setPixmap(texture_house);
        house->setPos(15,10);
        house->setZValue(+7);
        scene->addItem(house);

        GraphicsHouseMan *house_man = new GraphicsHouseMan;
        house_man->setPixmap(QPixmap(":/pics/background_item/green_room/house_man.png"));
        house_man->setPos(20,150);
        house_man->setZValue(+8);
        scene->addItem(house_man);
    // house

    // taverna
        QPixmap texture_taverna(":/pics/background_item/green_room/more_texture/buildings/building3_1.png");
        GraphicsTaverna *taverna = new GraphicsTaverna;
        taverna->setPixmap(texture_taverna);
        taverna->setPos(1080,500);
        taverna->setZValue(+4);
        scene->addItem(taverna);

        GraphicsSecurity *security = new GraphicsSecurity;
        security->setPixmap(QPixmap(":/pics/background_item/green_room/security.png"));
        security->setPos(1020,575);
        security->setZValue(+4);
        scene->addItem(security);
    // taverna

    // cafe
        QPixmap texture_cafe(":/pics/background_item/green_room/more_texture/buildings/building1_1.png");
        GraphicsCafe *cafe = new GraphicsCafe;
        cafe->setPixmap(texture_cafe);
        cafe->setPos(1080,10);
        cafe->setZValue(+9);
        scene->addItem(cafe);

        GraphicsCook *cook = new GraphicsCook;
        cook->setPixmap(QPixmap(":/pics/background_item/green_room/cook.png"));
        cook->setPos(1100,160);
        cook->setZValue(+9);
        scene->addItem(cook);
    // cafe

    // houses



    // по бокам ограда
    for(int i = 0; i < 26; i++){ // сверху
        QPixmap texture(":/pics/background_item/green_room/fence_12gorizontal.png");
        QGraphicsPixmapItem *fence_vertical = new QGraphicsPixmapItem(texture);
        fence_vertical->setPos(48 * i + 3, 3);
        fence_vertical->setZValue(+5);
        scene->addItem(fence_vertical);
    }
    for(int i = 0; i < 26; i++){ // снизу
        QPixmap texture(":/pics/background_item/green_room/fence_12gorizontal.png");
        QGraphicsPixmapItem *fence_vertical = new QGraphicsPixmapItem(texture);
        fence_vertical->setPos(48*i + 3, 720 - 48 + 3);
        fence_vertical->setZValue(+5);
        scene->addItem(fence_vertical);
    }
    for(int i = 0; i < 14; i++){ // слева
        QPixmap texture(":/pics/background_item/green_room/fence_11vertikal.png");
        QGraphicsPixmapItem *fence_vertical = new QGraphicsPixmapItem(texture);
        fence_vertical->setPos(0, 48 * i);
        fence_vertical->setZValue(+5);
        scene->addItem(fence_vertical);
    }
    for(int i = 0; i < 14; i++){ // справа
        QPixmap texture(":/pics/background_item/green_room/fence_11vertikal.png");
        QGraphicsPixmapItem *fence_vertical = new QGraphicsPixmapItem(texture);
        fence_vertical->setPos(1280 - 24 - 8, 48 * i);
        fence_vertical->setZValue(+5);
        scene->addItem(fence_vertical);
    }
    // по бокам ограда

    // ограда плеера
    QString path_to_texture = ":/pics/background_item/green_room/tilestonebricks32.png";
    for(int i_1 = 0; i_1 < 13; i_1++){
        for(int i = 9; i < 31; i++){
            QPixmap texture(path_to_texture);
            QGraphicsPixmapItem *fence_vertical = new QGraphicsPixmapItem(texture);
            fence_vertical->setPos(32 * i, 48 * 3 + 32*i_1);
            scene->addItem(fence_vertical);
            if(i_1 == 0){
                QGraphicsPixmapItem *grass = new QGraphicsPixmapItem(QPixmap(":/pics/background_item/green_room/more_texture/land/land_4_32px.png"));
                grass->setPos(fence_vertical->x(), fence_vertical->y());
                scene->addItem(grass);
            }
            if(i == 9){
                QGraphicsPixmapItem *grass_vertical_left = new QGraphicsPixmapItem(QPixmap(":/pics/background_item/green_room/more_texture/land/land_5_32px.png"));
                grass_vertical_left->setPos(fence_vertical->x(), fence_vertical->y());
                scene->addItem(grass_vertical_left);
            }
            if(i == 30){
                QGraphicsPixmapItem *grass_vertical_right = new QGraphicsPixmapItem(QPixmap(":/pics/background_item/green_room/more_texture/land/land_6_32px.png"));
                grass_vertical_right->setPos(fence_vertical->x(), fence_vertical->y());
                scene->addItem(grass_vertical_right);
            }
        }
    }

    for(int i = 9; i < 31; i++){
        QPixmap texture(path_to_texture);
        QGraphicsPixmapItem *fence_vertical = new QGraphicsPixmapItem(texture);
        fence_vertical->setPos(32*i, 720 - 48 * 3 - 24);
        scene->addItem(fence_vertical);

        QGraphicsPixmapItem *grass = new QGraphicsPixmapItem(QPixmap(":/pics/background_item/green_room/more_texture/land/land_3_32px.png"));
        grass->setPos(32*i, 720 - 48 * 3 - 24);
        scene->addItem(grass);

        if(i == 9){
            QGraphicsPixmapItem *grass_vertical_left = new QGraphicsPixmapItem(QPixmap(":/pics/background_item/green_room/more_texture/land/land_5_32px.png"));
            grass_vertical_left->setPos(32*i, 720 - 48 * 3 - 24);
            scene->addItem(grass_vertical_left);
        }

        if(i == 30){
            QGraphicsPixmapItem *grass_vertical_right = new QGraphicsPixmapItem(QPixmap(":/pics/background_item/green_room/more_texture/land/land_6_32px.png"));
            grass_vertical_right->setPos(32*i, 720 - 48 * 3 - 24);
            scene->addItem(grass_vertical_right);
        }
    }
    // ограда плеера

    // дополнительные item
    QPixmap texture_tree_two(":/pics/background_item/green_room/GrassObject_32_29_1.png"); // подкорректировать расположение изображения, чтобы прям над персонажем
    QPixmap texture_three_bush(":/pics/background_item/green_room/GrassObjects_32_06.png");
    QPixmap texture_bush(":/pics/background_item/green_room/GrassObjects_32_04.png"); // подкорректировать расположение изображения, чтобы прям над персонажем

    // деревья с кустиками по бокам
    int x_move, y_move;
    // 1
    x_move = 10, y_move = 0;
    GraphicsTreeTwo *megatree_011 = new GraphicsTreeTwo;
    megatree_011->setPixmap(texture_tree_two);
    megatree_011->setZValue(+8);
    megatree_011->setPos(100 + x_move, 100 + y_move);
    scene->addItem(megatree_011);

    GraphicsBush *megatree_012 = new GraphicsBush;
    megatree_012->setPixmap(texture_bush);
    megatree_012->setZValue(+8);
    megatree_012->setPos(170 + x_move, 200 + y_move);
    scene->addItem(megatree_012);

    GraphicsThreeBush *megatree_013 = new GraphicsThreeBush;
    megatree_013->setPixmap(texture_three_bush);
    megatree_013->setZValue(+9);
    megatree_013->setPos(170 + x_move, 200 + y_move);
    scene->addItem(megatree_013);

    GraphicsThreeBush *megatree_014 = new GraphicsThreeBush;
    megatree_014->setPixmap(texture_three_bush);
    megatree_014->setZValue(+9);
    megatree_014->setPos(130 + x_move, 200 + y_move);
    scene->addItem(megatree_014);
    // 1
    // 2
    x_move = 1000, y_move = -120;
    GraphicsTreeTwo *megatree_021 = new GraphicsTreeTwo;
    megatree_021->setPixmap(texture_tree_two);
    megatree_021->setZValue(+7);
    megatree_021->setPos(100 + x_move, 100 + y_move);
    scene->addItem(megatree_021);

    GraphicsBush *megatree_022 = new GraphicsBush;
    megatree_022->setPixmap(texture_bush);
    megatree_022->setZValue(+7);
    megatree_022->setPos(170 + x_move, 200 + y_move);
    scene->addItem(megatree_022);

    GraphicsThreeBush *megatree_023 = new GraphicsThreeBush;
    megatree_023->setPixmap(texture_three_bush);
    megatree_023->setZValue(+8);
    megatree_023->setPos(170 + x_move, 200 + y_move);
    scene->addItem(megatree_023);

    GraphicsThreeBush *megatree_024 = new GraphicsThreeBush;
    megatree_024->setPixmap(texture_three_bush);
    megatree_024->setZValue(+8);
    megatree_024->setPos(130 + x_move, 200 + y_move);
    scene->addItem(megatree_024);
    // 2
    // 3
    x_move = -194, y_move = -80;
    GraphicsTreeTwo *megatree_031 = new GraphicsTreeTwo;
    megatree_031->setPixmap(texture_tree_two);
    megatree_031->setZValue(+7);
    megatree_031->setPos(100 + x_move, 100 + y_move);
    scene->addItem(megatree_031);

    GraphicsBush *megatree_032 = new GraphicsBush;
    megatree_032->setPixmap(texture_bush);
    megatree_032->setZValue(+7);
    megatree_032->setPos(170 + x_move, 200 + y_move);
    scene->addItem(megatree_032);

    GraphicsThreeBush *megatree_033 = new GraphicsThreeBush;
    megatree_033->setPixmap(texture_three_bush);
    megatree_033->setZValue(+8);
    megatree_033->setPos(170 + x_move, 200 + y_move);
    scene->addItem(megatree_033);

    GraphicsThreeBush *megatree_034 = new GraphicsThreeBush;
    megatree_034->setPixmap(texture_three_bush);
    megatree_034->setZValue(+8);
    megatree_034->setPos(130 + x_move, 200 + y_move);
    scene->addItem(megatree_034);
    // 3
    // деревья с кустиками по бокам

    // деревья

    GraphicsTreeTwo *tree_two2 = new GraphicsTreeTwo;
    tree_two2->setPixmap(texture_tree_two);
    tree_two2->setZValue(+6);
    tree_two2->setPos(-90, 200);
    scene->addItem(tree_two2);

    // лес слева снизу
    GraphicsTreeTwo *tree_two3 = new GraphicsTreeTwo;
    tree_two3->setPixmap(texture_tree_two);
    tree_two3->setZValue(+6);
    tree_two3->setPos(100, 620);
    scene->addItem(tree_two3);

    GraphicsTreeTwo *tree_two4 = new GraphicsTreeTwo;
    tree_two4->setPixmap(texture_tree_two);
    tree_two4->setZValue(+6);
    tree_two4->setPos(10, 610);
    scene->addItem(tree_two4);

    GraphicsTreeTwo *tree_two5 = new GraphicsTreeTwo;
    tree_two5->setPixmap(texture_tree_two);
    tree_two5->setZValue(+4);
    tree_two5->setPos(70, 570);
    scene->addItem(tree_two5);

    GraphicsTreeTwo *tree_two6 = new GraphicsTreeTwo;
    tree_two6->setPixmap(texture_tree_two);
    tree_two6->setZValue(+3);
    tree_two6->setPos(100, 530);
    scene->addItem(tree_two6);

    GraphicsTreeTwo *tree_two7 = new GraphicsTreeTwo;
    tree_two7->setPixmap(texture_tree_two);
    tree_two7->setZValue(+2);
    tree_two7->setPos(64, 500);
    scene->addItem(tree_two7);

    GraphicsTreeTwo *tree_two8 = new GraphicsTreeTwo;
    tree_two8->setPixmap(texture_tree_two);
    tree_two8->setZValue(+6);
    tree_two8->setPos(-80, 500);
    scene->addItem(tree_two2);

    GraphicsTreeTwo *tree_two9 = new GraphicsTreeTwo;
    tree_two9->setPixmap(texture_tree_two);
    tree_two9->setZValue(+6);
    tree_two9->setPos(-100, 510);
    scene->addItem(tree_two9);

    GraphicsTreeTwo *tree_two10 = new GraphicsTreeTwo;
    tree_two10->setPixmap(texture_tree_two);
    tree_two10->setZValue(+6);
    tree_two10->setPos(-70, 607);
    scene->addItem(tree_two10);

    GraphicsTreeTwo *tree_two11 = new GraphicsTreeTwo;
    tree_two11->setPixmap(texture_tree_two);
    tree_two11->setZValue(+6);
    tree_two11->setPos(-80, 617);
    scene->addItem(tree_two11);

    GraphicsTreeTwo *tree_two12 = new GraphicsTreeTwo;
    tree_two12->setPixmap(texture_tree_two);
    tree_two12->setZValue(+5);
    tree_two12->setPos(-10, 453);
    scene->addItem(tree_two12);

    GraphicsTreeTwo *tree_two13 = new GraphicsTreeTwo;
    tree_two13->setPixmap(texture_tree_two);
    tree_two13->setZValue(+5);
    tree_two13->setPos(-3, 543);
    scene->addItem(tree_two13);
    // лес слева снизу

    // деревья снизу экрана
    GraphicsTreeTwo *tree_two01 = new GraphicsTreeTwo;
    tree_two01->setPixmap(texture_tree_two);
    tree_two01->setZValue(+5);
    tree_two01->setPos(230, 653);
    scene->addItem(tree_two01);

    GraphicsTreeTwo *tree_two02 = new GraphicsTreeTwo;
    tree_two02->setPixmap(texture_tree_two);
    tree_two02->setZValue(+5);
    tree_two02->setPos(450, 630);
    scene->addItem(tree_two02);

    GraphicsTreeTwo *tree_two021 = new GraphicsTreeTwo;
    tree_two021->setPixmap(texture_tree_two);
    tree_two021->setZValue(+5);
    tree_two021->setPos(560, 615);
    scene->addItem(tree_two021);

    GraphicsTreeTwo *tree_two03 = new GraphicsTreeTwo;
    tree_two03->setPixmap(texture_tree_two);
    tree_two03->setZValue(+5);
    tree_two03->setPos(727, 650);
    scene->addItem(tree_two03);

    GraphicsTreeTwo *tree_two04 = new GraphicsTreeTwo;
    tree_two04->setPixmap(texture_tree_two);
    tree_two04->setZValue(+5);
    tree_two04->setPos(830, 620);
    scene->addItem(tree_two04);

    GraphicsTreeTwo *tree_two05 = new GraphicsTreeTwo;
    tree_two05->setPixmap(texture_tree_two);
    tree_two05->setZValue(+5);
    tree_two05->setPos(920, 670);
    scene->addItem(tree_two05);

    GraphicsTreeTwo *tree_two06 = new GraphicsTreeTwo;
    tree_two06->setPixmap(texture_tree_two);
    tree_two06->setZValue(+5);
    tree_two06->setPos(975, 630);
    scene->addItem(tree_two06);

    GraphicsTreeTwo *tree_two07 = new GraphicsTreeTwo;
    tree_two07->setPixmap(texture_tree_two);
    tree_two07->setZValue(+5);
    tree_two07->setPos(1200, 670);
    scene->addItem(tree_two07);

    GraphicsTreeTwo *tree_two08 = new GraphicsTreeTwo;
    tree_two08->setPixmap(texture_tree_two);
    tree_two08->setZValue(+5);
    tree_two08->setPos(1059, 663);
    scene->addItem(tree_two08);
    // деревья снизу экрана

    // деревья справа экрана
    GraphicsTreeTwo *tree_two001 = new GraphicsTreeTwo;
    tree_two001->setPixmap(texture_tree_two);
    tree_two001->setZValue(+5);
    tree_two001->setPos(1250, 0);
    scene->addItem(tree_two001);

    GraphicsTreeTwo *tree_two002 = new GraphicsTreeTwo;
    tree_two002->setPixmap(texture_tree_two);
    tree_two002->setZValue(+5);
    tree_two002->setPos(1223, 70);
    scene->addItem(tree_two002);

    GraphicsTreeTwo *tree_two003 = new GraphicsTreeTwo;
    tree_two003->setPixmap(texture_tree_two);
    tree_two003->setZValue(+5);
    tree_two003->setPos(1235, 147);
    scene->addItem(tree_two003);

    GraphicsTreeTwo *tree_two004 = new GraphicsTreeTwo;
    tree_two004->setPixmap(texture_tree_two);
    tree_two004->setZValue(+5);
    tree_two004->setPos(1263, 243);
    scene->addItem(tree_two004);

    GraphicsTreeTwo *tree_two005 = new GraphicsTreeTwo;
    tree_two005->setPixmap(texture_tree_two);
    tree_two005->setZValue(+5);
    tree_two005->setPos(1243, 400);
    scene->addItem(tree_two005);

    GraphicsTreeTwo *tree_two006 = new GraphicsTreeTwo;
    tree_two006->setPixmap(texture_tree_two);
    tree_two006->setZValue(+5);
    tree_two006->setPos(1234, 520);
    scene->addItem(tree_two006);
    // деревья снизу экрана

    // деревья сверху экрана
    GraphicsTreeTwo *tree_two0001 = new GraphicsTreeTwo;
    tree_two0001->setPixmap(texture_tree_two);
    tree_two0001->setZValue(+4);
    tree_two0001->setPos(0, -100);
    scene->addItem(tree_two0001);

    GraphicsTreeTwo *tree_two0002 = new GraphicsTreeTwo;
    tree_two0002->setPixmap(texture_tree_two);
    tree_two0002->setZValue(+4);
    tree_two0002->setPos(120, -90);
    scene->addItem(tree_two0002);

    GraphicsTreeTwo *tree_two0003 = new GraphicsTreeTwo;
    tree_two0003->setPixmap(texture_tree_two);
    tree_two0003->setZValue(+4);
    tree_two0003->setPos(264, -93);
    scene->addItem(tree_two0003);

    GraphicsTreeTwo *tree_two0004 = new GraphicsTreeTwo;
    tree_two0004->setPixmap(texture_tree_two);
    tree_two0004->setZValue(+4);
    tree_two0004->setPos(390, -91);
    scene->addItem(tree_two0004);

    GraphicsTreeTwo *tree_two0005 = new GraphicsTreeTwo;
    tree_two0005->setPixmap(texture_tree_two);
    tree_two0005->setZValue(+4);
    tree_two0005->setPos(570, -95);
    scene->addItem(tree_two0005);

    GraphicsTreeTwo *tree_two0006 = new GraphicsTreeTwo;
    tree_two0006->setPixmap(texture_tree_two);
    tree_two0006->setZValue(+4);
    tree_two0006->setPos(780, -98);
    scene->addItem(tree_two0006);

    GraphicsTreeTwo *tree_two0007 = new GraphicsTreeTwo;
    tree_two0007->setPixmap(texture_tree_two);
    tree_two0007->setZValue(+4);
    tree_two0007->setPos(907, -96);
    scene->addItem(tree_two0007);

    GraphicsTreeTwo *tree_two0008 = new GraphicsTreeTwo;
    tree_two0008->setPixmap(texture_tree_two);
    tree_two0008->setZValue(+4);
    tree_two0008->setPos(1070, -103);
    scene->addItem(tree_two0008);

    GraphicsTreeTwo *tree_two0009 = new GraphicsTreeTwo;
    tree_two0009->setPixmap(texture_tree_two);
    tree_two0009->setZValue(+4);
    tree_two0009->setPos(1190, -97);
    scene->addItem(tree_two0009);

    GraphicsTreeTwo *tree_two0010 = new GraphicsTreeTwo;
    tree_two0010->setPixmap(texture_tree_two);
    tree_two0010->setZValue(+4);
    tree_two0010->setPos(1000, -110);
    scene->addItem(tree_two0010);

    GraphicsTreeTwo *tree_two0011 = new GraphicsTreeTwo;
    tree_two0011->setPixmap(texture_tree_two);
    tree_two0011->setZValue(+4);
    tree_two0011->setPos(470, -113);
    scene->addItem(tree_two0011);

    GraphicsTreeTwo *tree_two0012 = new GraphicsTreeTwo;
    tree_two0012->setPixmap(texture_tree_two);
    tree_two0012->setZValue(+4);
    tree_two0012->setPos(850, -107);
    scene->addItem(tree_two0012);

    GraphicsTreeTwo *tree_two0013 = new GraphicsTreeTwo;
    tree_two0013->setPixmap(texture_tree_two);
    tree_two0013->setZValue(+4);
    tree_two0013->setPos(620, -115);
    scene->addItem(tree_two0013);

    GraphicsTreeTwo *tree_two0014 = new GraphicsTreeTwo;
    tree_two0014->setPixmap(texture_tree_two);
    tree_two0014->setZValue(+4);
    tree_two0014->setPos(50, -112);
    scene->addItem(tree_two0014);
    // деревья сверху экрана

    // деревья

}

void AnimationView::add_players(QVector<PlayerView *> &last_frame, QVector<PlayerView *> &next_frame, QString local_id){
    if(next_frame.size() > 1){

        bool draw_local_player = false;
        int id = -1;

        for(int i = 0; i < next_frame.size(); i++){
            if(next_frame[i]->client_id != local_id || draw_local_player){
                next_frame[i]->update_state();
                scene->addItem(next_frame[i]);
                    if(i != next_frame.size() - 1){
                        scene->addItem(next_frame[i]->name);
                        display_message(next_frame[i]);
                    }
            } else {
                id = i;
                draw_local_player = true;
            }
        }

        clear_vector(last_frame, local_id);

        int i = 0;

        while(colliding_with_player(next_frame) > 0){
            next_frame[next_frame.size() - 1]->setPos(local_player->position_movement_last_frame[i].first,
                                                      local_player->position_movement_last_frame[i].second);
            next_frame[next_frame.size() - 1]->name->setPos(local_player->position_name_movement_last_frame[i].first,
                                                            local_player->position_name_movement_last_frame[i].second);

            local_player->setPos(local_player->position_movement_last_frame[i].first,
                                 local_player->position_movement_last_frame[i].second);

            local_player->name->setPos(local_player->position_name_movement_last_frame[i].first,
                                       local_player->position_name_movement_last_frame[i].second);
            i++;

        }

        next_frame[i]->update_state();
        add_tables(next_frame[next_frame.size() - 1]);
        scene->addItem(next_frame[next_frame.size() - 1]->name);
        display_message(next_frame[next_frame.size() - 1]);

        local_player->position_movement_last_frame.clear();
        local_player->position_name_movement_last_frame.clear();

        last_frame = std::move(next_frame);
    }
    next_frame.clear();
}

void AnimationView::add_tables(PlayerView *player){
    //std::cout<<"hello"<<std::endl;
    if(sleap.xl <= player->x()&& player->x() <= sleap.xr && sleap.yl <= player->y()&& player->y() <= sleap.yr){
        std::cout<<"hellosleap"<<std::endl;
        // хочу поспать!
        tablet_want_sleap = new QGraphicsPixmapItem(QPixmap(":/pics/background_item/green_room/more_texture/tablet_want_sleap.png"));
        tablet_want_sleap->setPos(50, 140);
        tablet_want_sleap->setZValue(+15);
        scene->addItem(tablet_want_sleap);
    } else if(want_or_dont_eat.xl <= player->x()&& player->x() <= want_or_dont_eat.xr && want_or_dont_eat.yl <= player->y()&& player->y() <= want_or_dont_eat.yr){
        if(local_player->saturation > 100){
            // хватит есть!
            table_stop_eating = new QGraphicsPixmapItem();
            table_stop_eating->setPos(1130, 150);
            table_stop_eating->setPixmap(QPixmap(":/pics/background_item/green_room/more_texture/tablet_stor_eating.png"));
            table_stop_eating->setZValue(+15);
            scene->addItem(table_stop_eating);
        } else{
            // хочу поесть!
            tablet_want_eating = new QGraphicsPixmapItem();
            tablet_want_eating->setPos(1130, 150);
            tablet_want_eating->setPixmap(QPixmap(":/pics/background_item/green_room/more_texture/tablet_want_eat.png"));
            tablet_want_eating->setZValue(+15);
            scene->addItem(tablet_want_eating);
        }
    } else if(enter_close_to_taverna.xl <= player->x()&& player->x() <= enter_close_to_taverna.xr && enter_close_to_taverna.yl <= player->y()&& player->y() <= enter_close_to_taverna.yr){
        // сюда нельзя!
        std::cout<<"hellotaverna"<<std::endl;
        tablet_stop = new QGraphicsPixmapItem();
        tablet_stop->setPos(1045, 570);
        tablet_stop->setPixmap(QPixmap(":/pics/background_item/green_room/more_texture/tablet_entry_close.png"));
        tablet_stop->setZValue(+15);
        scene->addItem(tablet_stop);
    } else if(first_course_alive.xl <= player->x()&& player->x() <= first_course_alive.xr && first_course_alive.yl <= player->y()&& player->y() <= first_course_alive.yr){
        // первый курс жив!
        tablet_fist_course_alive = new QGraphicsPixmapItem();
        tablet_fist_course_alive->setPos(50, 600);
        tablet_fist_course_alive->setPixmap(QPixmap(":/pics/background_item/green_room/more_texture/table_first_course_alive.png"));
        tablet_fist_course_alive->setZValue(+15);
        scene->addItem(tablet_fist_course_alive);
    }
}

void AnimationView::delete_tables(PlayerView *player){
    if(sleap.xl <= player->x()&& player->x() <= sleap.xr && sleap.yl <= player->y()&& player->y() <= sleap.yr){
        scene->removeItem(tablet_want_sleap);
        delete tablet_want_sleap;
    } else if(want_or_dont_eat.xl <= player->x()&& player->x() <= want_or_dont_eat.xr && want_or_dont_eat.yl <= player->y()&& player->y() <= want_or_dont_eat.yr){
        if(player->saturation > 100){
            scene->removeItem(table_stop_eating);
            delete table_stop_eating;
        } else{
            scene->removeItem(tablet_want_eating);
            delete tablet_want_eating;
        }
    } else if(enter_close_to_taverna.xl <= player->x()&& player->x() <= enter_close_to_taverna.xr && enter_close_to_taverna.yl <= player->y()&& player->y() <= enter_close_to_taverna.yr){
        scene->removeItem(tablet_stop);
        delete tablet_stop;
    } else if(first_course_alive.xl <= player->x()&& player->x() <= first_course_alive.xr && first_course_alive.yl <= player->y()&& player->y() <= first_course_alive.yr){
        scene->removeItem(tablet_fist_course_alive);
        delete tablet_fist_course_alive;
    }
}

int AnimationView::colliding_with_player(QVector<PlayerView *> &next_frame){
    int id = next_frame.size() - 1;
    int count = 0;
    QList<QGraphicsItem *> colliding = scene->collidingItems(next_frame[id]);
    for(QGraphicsItem* item: colliding){
        int count_i = 1;
//        if(dynamic_cast<GraphicsFood *>(item)){
//            count_i = 0;
//            delete item;
//        }
        for(int i = 0; i <= id; i++){
            if(item == next_frame[i]){
                count_i = 0;
            }
            if(item == next_frame[i]->name){
                count_i = 0;
            }
            if(next_frame[i]->player_message.type == "emoji" && item == next_frame[i]->player_message.emoji){
                count_i = 0;
            }
            if(count_i == 0){
                break;
            }
        }
        count += count_i;
        // delete item; нужно если при пересечении удалять объект
    }
    return count;
}

void AnimationView::display_message(PlayerView *player){
    if(player->player_message.send_message != ""){
        if(player->player_message.type == "text"){
            player->message->setPos(player->pos().x() + 24 - player->message->boundingRect().width()/2, player->pos().y() - 30);     // чтобы не было глюков при замене direction нужно,
            scene->addItem(player->message);
        } else {
            QPixmap emoji(player->player_message.send_message); // подкорректировать расположение изображения, чтобы прям над персонажем
            emoji = emoji.scaled(36,36,Qt::KeepAspectRatio);
            player->player_message.emoji = new QGraphicsPixmapItem(emoji);
            player->player_message.emoji->setPos(player->pos().x() + 6, player->pos().y() - 48);
            scene->addItem(player->player_message.emoji);
        }
    }
}

void AnimationView ::clear_vector(QVector<PlayerView *> &last_frame, QString local_id){
    bool clear_local_player = false;
    for(int i = 0; i < last_frame.size(); i++){
        if(last_frame[i]->client_id != local_id || clear_local_player){
            scene->removeItem(last_frame[i]); // тут скорее всего нужно удалять элемент
            scene->removeItem(last_frame[i]->name); // тут скорее всего нужно удалять элемент
            if(last_frame[i]->player_message.send_message != ""){
                if(last_frame[i]->player_message.type == "text"){
                    scene->removeItem(last_frame[i]->message); // тут скорее всего нужно удалять элемент
                } else {
                    scene->removeItem(last_frame[i]->player_message.emoji); // тут скорее всего нужно удалять элемент
                    delete last_frame[i]->player_message.emoji;
                }
            }
        } else {
            delete_tables(last_frame[last_frame.size() - 1]);
            clear_local_player = true;
        }
        delete last_frame[i];
    }
}



