#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPainter>
#include <QDebug>
#include "Player.h"
#include "Client.h"
#include "HSL.h"
#include "Room.h"
#include <QThread>
#include <QRegExp>
#include <QMovie>


QT_BEGIN_NAMESPACE
namespace Ui { struct Menu;}
QT_END_NAMESPACE

struct Client;

struct Menu : public QMainWindow {
    Q_OBJECT

public:
    Menu(Client *client_, QWidget *parent = nullptr);
    ~Menu();
    void paintEvent(QPaintEvent *event) override;

public slots:
    void on_h_slider_sliderMoved(int len);
    void on_s_slider_sliderMoved(int len);
    void on_l_slider_sliderMoved(int len);
    void on_connectButton_clicked();
    void make_advert(const QString &advert);

public:
    Ui::Menu *ui;
    Client *client;
    QColor circle_color = Qt::red;
    Player *player;
    QMovie  gif_animation_dino;

private slots:
    void on_nameEdit_textChanged(const QString &arg1);
    void on_RedDino_clicked();
    void on_BlueDino_clicked();
    void on_YellowDino_clicked();
    void on_GreenDino_clicked();

};
#endif // MENU_H
