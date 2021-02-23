#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QSet>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QTextOption>
//
struct player_move{
    int x;
    int y;
};

class Player : public QObject, public QGraphicsItem
{
    Q_OBJECT

public slots:
    void no_message();
    void move();

public:
    explicit Player(const QString& player_name_ = "YOUR_NAME_PLAYER", const QString& color_ = "RED_PLAYER", QObject *parent = 0); // записывание имени
    void keyPressEvent(QKeyEvent *)      override;  // зажимание клавиши
    void keyReleaseEvent(QKeyEvent *)    override;  // отжимание клавиши
    void update_movement(int sign, QKeyEvent *apKeyEvent);
    ~Player();

protected:
    QRectF boundingRect() const override; // чекнуть про override    
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

public:

    QString player_name = "YOUR_PLAYER_NAME"; // имя игрока
    player_move movement = {0,0};
    const int move_distance = 3;
    bool direction = false; // направление: false - смотрит влево, true - смотрит вправо.

    QString color_square = "RED";

    QString message = "";           // сообщение
    bool metka_message = false;     // есть ли сообщение

    bool metka_message_painter = false; // чтобы заново таймер не запускать - скажем нет бесконечности
    QTimer *timer_move = new QTimer(this);
    QTimer *timer_message = new QTimer(this);

private:
    QSet<int> setPressKey;
};

#endif // PLAYER_H
