#include "Room.h"
#include "PlayerView.h"
#include "ui_Room.h"


Room::Room(Player *player_, QVector<PlayerView> &players_, QWidget *parent):
    QWidget(parent),
    ui(new Ui::Room) {
    ui->setupUi(this);
    this->resize(1280,720);
    this->setFixedSize(1280,720);
    //this->showFullScreen();

    scene = new QGraphicsScene();
    local_player =  player_;        // создаём персонажа

    players.clear();
    players = players_;
    QTimer *update_draw_timer = new QTimer();
    connect(update_draw_timer, SIGNAL(timeout()), this, SLOT(update()));
    update_draw_timer->start(1000/FPS);

}

void Room::paintEvent(QPaintEvent *event){
    qDebug() << "paintEvent";
    draw_scene();
}

void Room::draw_scene(){ // event сам и не нужен
    qDebug() << "draw_scene";
    QPainter painter(this);
    main_window->client->request_get_scene_on_the_server();
    update_local_player_position(); // обновляем позицию игрока

    for(std::size_t i = 0; i < players.size(); i++){
        if(players[i].client_id == local_player->client_id){
            if(local_player->player_message.metka_message && !local_player->player_message.metka_message_painter){
                local_player->player_message.metka_message_painter = true;
                local_player->timer_message->stop();
                local_player->timer_message->start(5000);
                connect(local_player->timer_message, SIGNAL(timeout()), this, SLOT(no_message()));
            }
        }
        if(players[i].player_message.metka_message_painter){
            painter.drawText(-55 + local_player->x,-40 + local_player->y,110,20,Qt::AlignRight,local_player->player_message.send_message);
        }
        players[i].draw(painter);
    }
}


void Room::update_local_player_position(){
    //main_window->client->socket->wa
    //qDebug() << "test";
    main_window->client->update_state_on_the_server(local_player->to_json());
    for(int i = 0; i < players.size(); i++){
        if(players[i].client_id == local_player->client_id){
            players[i].x = local_player->x;
            players[i].y = local_player->y;
            players[i].player_message = local_player->player_message;
            break;
        }
    }
}

void Room::keyPressEvent(QKeyEvent *apKeyEvent)
{
    qDebug() << "KeyPressEvent";
    if(apKeyEvent->key() == Qt::Key_Escape) {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "", "Do you want to leave?",
                              QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes){
            //CreateMainWidget(local_player->player_name);
            this->close();
        }
    }else if(apKeyEvent->key() == Qt::Key_Q){
        local_player->movement = {0,0};                       // при вводе сообщения игрок останавливается

        while(true){
            bool click = false;
            QString message = "Your message....";
            QString str = QInputDialog::getText(0, "Enter message!", message, QLineEdit::Normal, "", &click);
            if(!click){ // была нажата кнопка Cancel
                break;
            }
            if(str.size() == 0){ // если ничего не ввёл, то ничего непроизошло
                break;
            }else if(0 < str.size() && str.size() < 17 && str!="") {
                    local_player->player_message.send_message = str;
                    local_player->player_message.metka_message = true;
                    local_player->player_message.metka_message_painter = false;
                    break;
            }// TODO: эксперименты с размером сообщения и если нужно, то отредактировать
        }
    }else {
        local_player->keyPressEvent(apKeyEvent);
    }
}

void Room::keyReleaseEvent(QKeyEvent *apKeyEvent){
    qDebug() << "KeyReleaseEvent";

    local_player->keyReleaseEvent(apKeyEvent);
}


Room::~Room()
{
    delete ui;
}