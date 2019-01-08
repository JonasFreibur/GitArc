/**
* This class is a graphic view which contains all the game's grapical item.
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GAVIEWGAME_H
#define GAVIEWGAME_H

#include <QGraphicsView>
#include <QMap>
#include "constants.h"
#include "gagamerightpannel.h"
#include "gascore.h"

class GAVerticalNotes;
class GAHorizontalNotesBar;
class QGraphicsLinearLayout;
class QGraphicsWidget;
class QByteArray;
class QLabel;
class GANote;
class QTimer;
class QPushButton;
class QHBoxLayout;
class QGraphicsTextItem;

class GAViewGame : public QGraphicsView
{
    Q_OBJECT

public:
    GAViewGame(QSize layoutSize,QWidget * _left, QWidget * _right, QGraphicsView *_parent = nullptr);
    ~GAViewGame();

public slots:
    void drawNoteLine(QByteArray notesLine);
    void timerGame();
    void closeGame();
    void toMenu();

signals:
    void wrongNotePlayed(int);
    void quitGameSig();
    void backToMenuSig();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QGraphicsScene *scene;
    GAVerticalNotes *verticalNotes;
    GAHorizontalNotesBar *horizontalNotes;   
    QLabel *left;
    GAGameRightPannel *right;
    QList<QList<GANote*>*> * strips;
    QTimer *gameTimer;
    GAScore *scoreSaver;
    int score;
    QPushButton *btnQuit;
    QPushButton *btnBackToMenu;

    bool isFirst = true;

    int getChordId(int);
    qreal result;

    QGraphicsTextItem *endGame;
    QGraphicsTextItem *scoreUser;
    QGraphicsTextItem *bestScoreEver;
    QGraphicsTextItem *endText;
};

#endif // GAVIEWGAME_H
