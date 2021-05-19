#include "PlayerView.h"

PlayerView::PlayerView(Player& player){
    name->setPlainText(player.name->toPlainText());
    message->setPlainText(player.message->toPlainText());
    setPos(player.pos().x(), player.pos().y());
    color_player = player.color_player;
    client_id = player.client_id;
    player_message = player.player_message;
    direction = player.direction;
    state = player.state;
    current_frame = player.current_frame;
    spriteData = player.spriteData;
    Pixmaps = player.Pixmaps;
}

PlayerView::PlayerView(Player&& player){
    name->setPlainText(player.name->toPlainText());
    setPos(player.pos().x(), player.pos().y());
    message->setPlainText(player.message->toPlainText());
    color_player = std::move(player.color_player);
    client_id = std::move(player.client_id);
    player_message = std::move(player.player_message);
    direction = std::move(player.direction);
    state = std::move(player.state);
    current_frame = std::move(player.current_frame);
    spriteData = std::move(player.spriteData);
    Pixmaps = std::move(player.Pixmaps);
}

PlayerView::PlayerView(const PlayerView& player_view){
    name = player_view.name;
    setPos(player_view.pos().x(), player_view.pos().y());
    message = player_view.message;
    color_player = player_view.color_player;
    client_id = player_view.client_id;
    player_message = player_view.player_message;
    direction = player_view.direction;
    state = player_view.state;
    current_frame = player_view.current_frame;
    spriteData = player_view.spriteData;
    Pixmaps = player_view.Pixmaps;
}

QRectF PlayerView::boundingRect() const{
    return QRectF(0,0,48,48);
}

void PlayerView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){ // почему-то не работает ж(
    if(this->direction == "right"){
        QPixmap icon = Pixmaps[static_cast<int>(state)].first.copy((csd().offset*current_frame + csd().border),0,csd().width,csd().height);
        icon = icon.transformed(QTransform().scale(-1,1).translate(icon.width(), 0));
        painter->drawPixmap(0,0,icon);
    } else {
        painter->drawPixmap(0,0,Pixmaps[static_cast<int>(state)].first,(csd().offset*current_frame + csd().border),0,csd().width,csd().height);
    }
}

const sprite_data& PlayerView::csd() const {
    return Pixmaps[static_cast<int>(state)].second;
}

QPainterPath PlayerView::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void PlayerView::update_state(){
    //this->update_direction();
    this->update_position_name();
}

void PlayerView::update_position_name(){
    //if(direction == "left"){
        int left_x = 24;                        // не знаю костыль ли это или нормальное решение.
        name->setPos(pos().x() + left_x  - name->boundingRect().width()/2, pos().y() - 15);     // чтобы не было глюков при замене direction нужно,
        message->setPos(pos().x() + left_x  - name->boundingRect().width()/2, pos().y() - 30);
//    }else{                                                              // чтобы left_x + right_x = 48 (размеру перснонажа)
//        int right_x = 24;
//        name->setPos(pos().x() - right_x - name->boundingRect().width()/2, pos().y() - 15); // -  boundingRect().height()/2
//        message->setPos(pos().x() - right_x - name->boundingRect().width()/2, pos().y() - 30);
//    }
}

void PlayerView::update_direction(){
    if(this->direction == "right"){
        this->change_direction();
    }
}

void PlayerView::change_direction(){
    // Get the current position
    QRectF itemRectOld = this->sceneBoundingRect();

    // Get the current transform
    QTransform transform(this->transform());
    qreal m11 = transform.m11(); // Horizontal scaling
    qreal m12 = transform.m12(); // Vertical shearing
    qreal m13 = transform.m13(); // Horizontal Projection
    qreal m21 = transform.m21(); // Horizontal shearing
    qreal m22 = transform.m22(); // vertical scaling
    qreal m23 = transform.m23(); // Vertical Projection
    qreal m31 = transform.m31(); // Horizontal Position (DX)
    qreal m32 = transform.m32(); // Vertical Position (DY)
    qreal m33 = transform.m33(); // Addtional Projection Factor

    // Horizontal flip
    m11 = -m11;

    // Write back to the matrix
    transform.setMatrix(m11, m12, m13, m21, m22, m23, m31, m32, m33);

    // Set the items transformation
    setTransform(transform);

    // Re-position back to origin
    QRectF itemRectNew = this->sceneBoundingRect();
    qreal dx = itemRectOld.center().x()-itemRectNew.center().x();
    qreal dy = itemRectOld.center().y()-itemRectNew.center().y();
    this->moveBy(dx, dy);
}

PlayerView::~PlayerView(){

}
