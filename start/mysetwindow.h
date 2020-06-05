#ifndef SETWINDOW_H
#define SETWINDOW_H

#include <QMainWindow>

class mysetwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit mysetwindow(QWidget *parent = nullptr);
      void paintEvent(QPaintEvent *);

signals:
    //自定义信号 使得主场景得知返回
      void mysetBack();
};

#endif // SETWINDOW_H
