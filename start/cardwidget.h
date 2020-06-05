#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>
#include <QString>
#include <qpainter.h>
#include "QMouseEvent"

class CardWidget : public QWidget
{
    Q_OBJECT
private:
    bool isShow;
    bool isClick;
    bool isSelected;
    int id;    // 0-14, for 0-9 and Drawtwo, Reverse, Skip
               // 13 for Wild, 14 for DrawFour
    int color; // 0-3, for blue, green, red, yellow
    QPixmap backpix;
    QPixmap pix;

public:
    explicit CardWidget(QWidget *parent = nullptr);
    CardWidget(int id, int color, bool isShow, QWidget *parent = nullptr);
    void setClick(bool b);
    void setSelected(bool b);

    bool getIsClick() const;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent* event);
signals:

public slots:

};

#endif // CARDWIDGET_H
