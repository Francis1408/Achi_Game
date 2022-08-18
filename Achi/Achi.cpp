#include "Achi.h"
#include "ui_Achi.h"

#include <QDebug>
#include <QSignalMapper>
#include <QMessageBox>

Achi::Player state2player(Hole::State state){
    switch (state) {
    case Hole::Red:
        return Achi::RedPlayer;
    case Hole::Blue:
        return Achi::BluePlayer;
    default:
        Q_UNREACHABLE();
    }
}

Hole::State player2state(Achi::Player player) {
    return player == Achi::RedPlayer ? Hole::Red : Hole::Blue;
}

Achi::Achi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Achi),
      m_player(Achi::RedPlayer),
      m_phase(Achi::DropPhase),
      m_dropCount(0),
      m_selected(nullptr){

   ui->setupUi(this);

   QObject::connect(ui->actionSair, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
   QObject::connect(ui->actionNovo, SIGNAL(triggered(bool)), this, SLOT(reset()));
   QObject::connect(ui->actionAjuda, SIGNAL(triggered(bool)),this, SLOT(showAbout()));
   QObject::connect(this, SIGNAL(gameOver(Player)), this, SLOT(showGameOver(Player)));
   QObject::connect(this, SIGNAL(gameOver(Player)), this, SLOT(reset()));

   QSignalMapper* map = new QSignalMapper(this);
   for(int id = 0; id < 9; id++){
       int r = id / 3;
       int c = id % 3;

       Hole* hole = this->findChild<Hole*>(QString("hole%1%2").arg(r).arg(c));
       Q_ASSERT(hole != 0);

       m_holes[id] = hole;
       map->setMapping(hole, id);
       QObject::connect(hole, SIGNAL(clicked(bool)), map, SLOT(map()));
   }
   QObject::connect(map, SIGNAL(mappedInt(int)), this, SLOT(play(int)));

   this->updateStatusBar();

   this->adjustSize();
   this->setFixedSize(this->size());
}

Achi::~Achi() {

    delete ui;
}

Hole* Achi::holeAt(int row, int col) const {
    if (row >= 0 && row < 3 &&
        col >= 0 && col < 3) {
        int index = row * 3 + col;
        return m_holes[index];
    } else {
        return 0;
    }
}

void Achi::play(int id){
    Hole* hole = m_holes[id];

    switch (m_phase) {
        case Achi::DropPhase:
            drop(hole);
            break;
        case Achi::MovePhase:
            move(hole);
            break;
        default:
            Q_UNREACHABLE();
    }
}

void Achi::drop(Hole* hole){
    if (hole->state() == Hole::Empty) {
        hole->setState(player2state(m_player));

        if (isGameOver(hole))
            emit gameOver(m_player);
        else {
            ++m_dropCount;
            if (m_dropCount == 6)
                m_phase = Achi::MovePhase;

            this->switchPlayer();
           }
       }
}

void Achi::move(Hole* hole) {
    QPair<Hole*,Hole*>* movement = nullptr;

    if (hole->state() == Hole::Selectable) {
        Q_ASSERT(m_selected != 0);
        movement = new QPair<Hole*,Hole*>(m_selected, hole);
    } else {
        if (hole->state() == player2state(m_player)) {
            QList<Hole*> selectable = this->findSelectable(hole);
            if (selectable.count() == 1) {
                movement = new QPair<Hole*,Hole*>(hole, selectable.at(0));
            } else if (selectable.count() > 1) {
                this->clearSelectable();
                foreach (Hole* tmp, selectable)
                    tmp->setState(Hole::Selectable);

                m_selected = hole;
            }
        }
    }

    if (movement != nullptr) {
        this->clearSelectable();
        m_selected = 0;

        Q_ASSERT(movement->first->state() == player2state(m_player));
        Q_ASSERT(movement->second->state() == Hole::Empty);

        movement->first->setState(Hole::Empty);
        movement->second->setState(player2state(m_player));

        if (isGameOver(movement->second))
            emit gameOver(m_player);
        else
            this->switchPlayer();

        delete movement;
    }
}
void Achi::switchPlayer() {
    m_player = m_player == Achi::RedPlayer ?
                    Achi::BluePlayer : Achi::RedPlayer;
    this->updateStatusBar();
}


bool isSelectable(Hole* hole) {
    return hole != nullptr &&
            (hole->state() == Hole::Empty ||
             hole->state() == Hole::Selectable);
}

void Achi::clearSelectable() {
    for (int id = 0; id < 9; id++) {
        Hole* hole = m_holes[id];
        if (hole->state() == Hole::Selectable)
            hole->setState(Hole::Empty);
    }
}

QList<Hole*> Achi::findSelectable(Hole* hole) {
    QList<Hole*> list;

    Hole* left = this->holeAt(hole->row() - 1, hole->col());
    if (isSelectable(left))
        list << left;

    Hole* up = this->holeAt(hole->row(), hole->col() - 1);
    if (isSelectable(up))
        list << up;

    Hole* right = this->holeAt(hole->row() + 1, hole->col());
    if (isSelectable(right))
        list << right;

    Hole* bottom = this->holeAt(hole->row(), hole->col() + 1);
    if (isSelectable(bottom))
        list << bottom;

    if(((hole->row()*3 + hole->col()))%2 == 0){

    Hole* DigRightUp = this->holeAt(hole->row()-1, hole->col()+1);
    if (isSelectable(DigRightUp))
        list << DigRightUp;

    Hole* DigRightBottom = this->holeAt(hole->row()+1, hole->col()+1);
    if (isSelectable(DigRightBottom))
        list << DigRightBottom;

    Hole* DigLeftUp = this->holeAt(hole->row()-1, hole->col()-1);
    if (isSelectable(DigLeftUp))
        list << DigLeftUp;

    Hole* DigLeftBottom = this->holeAt(hole->row()+1, hole->col()-1);
    if (isSelectable(DigLeftBottom))
        list << DigLeftBottom;
    }
    return list;
}

bool Achi::checkRow(Player player, int col) {
    Hole::State state = player2state(player);
    for (int r = 0; r < 3; r++) {
        Hole* tmp = this->holeAt(r, col);
        Q_ASSERT(tmp != 0);

        switch (tmp->state()) {
            case Hole::Red:
            case Hole::Blue:
                if (state != tmp->state())
                    return false;

                break;
            default:
                return false;
        }
    }

    return true;
}

bool Achi::checkCol(Player player, int row) {
    Hole::State state = player2state(player);
    for (int c = 0; c < 3; c++) {
        Hole* tmp = this->holeAt(row, c);
        Q_ASSERT(tmp != 0);

        switch (tmp->state()) {
            case Hole::Red:
            case Hole::Blue:
                if (state != tmp->state())
                    return false;

                break;
            default:
                return false;
        }
    }

    return true;
}

bool Achi::checkDig1(Player player, int row, int col){
    Hole::State state = player2state(player);
    if((row*3 + col)%2 == 0){
        for(int c = 0, r = 0; c < 3 && r < 3; c++, r++){
            Hole* tmp = this->holeAt(c, r);
            Q_ASSERT(tmp != 0);

            switch (tmp->state()){
                case Hole::Red:
                case Hole::Blue:
                    if(state != tmp->state())
                        return false;

                    break;
                default:
                    return false;
            }
        }

    }else{
        return false;
    }
    return true;
}

bool Achi::checkDig2(Player player, int row, int col){
    Hole::State state = player2state(player);
    if((row*3 + col)%2 == 0){
        for(int c = 2, r = 0; c>= 0 && r < 3; c--, r++){
            Hole* tmp = this->holeAt(c, r);
            Q_ASSERT(tmp != 0);

            switch (tmp->state()){
                case Hole::Red:
                case Hole::Blue:
                    if(state != tmp->state())
                        return false;

                    break;
                default:
                    return false;
            }
        }
    }else{
        return false;
    }
    return true;
}

bool Achi::isGameOver(Hole* hole) {
    Achi::Player player = state2player(hole->state());
    return this->checkRow(player, hole->col()) || this->checkCol(player, hole->row()) || this->checkDig1(player, hole->row(),hole->col()) ||
           this->checkDig2(player, hole->row(),hole->col());
}

void Achi::reset() {
    for (int id = 0; id < 9; id++) {
        Hole* hole = m_holes[id];
        hole->reset();
    }

    m_player = Achi::RedPlayer;
    m_phase = Achi::DropPhase;
    m_dropCount = 0;
    m_selected = nullptr;

    this->updateStatusBar();
}

void Achi::showAbout(){
    QMessageBox::information(this, tr("About"), tr("Achi Game\n\nBy Francisco Abreu Gonçalves\nComputer Engineering student @ CEFET/MG\n\nEmail: franciscoabreu1408@gmail.com"));
}

void Achi::showGameOver(Player player) {
    switch (player) {
        case Achi::RedPlayer:
            QMessageBox::information(this, tr("Winner!"), tr("Congrats, Red player has won!"));
            break;
        case Achi::BluePlayer:
            QMessageBox::information(this, tr("Winner!"), tr("Congrats, Blue player has won!"));
            break;
        default:
            Q_UNREACHABLE();
    }
}

void Achi::updateStatusBar() {
    QString player(m_player == Achi::RedPlayer ? "Red" : "Blue");
    QString phase(m_phase == Achi::DropPhase ? "Placing" : "Moving");

    ui->statusbar->showMessage(tr("%1 phase: %2 player's turn").arg(phase).arg(player));
}
