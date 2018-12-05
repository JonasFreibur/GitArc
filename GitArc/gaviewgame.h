/**
* This class is a graphic view which contains all the game's grapical item.
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GAVIEWGAME_H
#define GAVIEWGAME_H

#include <QGraphicsView>

class GAVerticalNotes;
class GAHorizontalNotesBar;
class QGraphicsLinearLayout;
class QGraphicsWidget;
class QByteArray;

class GAViewGame : public QGraphicsView
{
    Q_OBJECT

public:
    GAViewGame(QSize layoutSize, QGraphicsView *parent = nullptr);

public slots:
    void drawNoteLine(QByteArray notesLine);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QGraphicsScene *scene;
    QRect mySceneRect;
    GAVerticalNotes *verticalNotes;
    GAHorizontalNotesBar *horizontalNotes;

    int getChordId(int);
};

#endif // GAVIEWGAME_H
