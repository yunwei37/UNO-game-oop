#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <QWidget>
#include<cardwidget.h>
class transformation : public QWidget
{
    Q_OBJECT
public:
    int id;//10 for Drawtwo, 11 for Reverse, 12 for Skip,13 for Wild, 14 for DrawFour
    int color;//color
    QVector<CardWidget *> trans;
    QPixmap pix;
    explicit transformation(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:

};

#endif // TRANSFORMATION_H
