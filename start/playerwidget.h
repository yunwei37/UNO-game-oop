#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QString>
#include <qpainter.h>

class PlayerWidget : public QWidget
{
    Q_OBJECT
private:
    QPixmap bgpix;
    QPixmap playerImg;
    int currentCardCount;
    QString playerID;
    bool isTurned;

public:
    explicit PlayerWidget(QWidget *parent = nullptr);
    explicit PlayerWidget(QString id, QPixmap playerImg, QWidget *parent = nullptr);

    int getCurrentCardCount() const;
    void setCurrentCardCount(int value);

    void setIsTurned(bool value);

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // PLAYERWIDGET_H
