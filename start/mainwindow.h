#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mysetwindow.h"
#include"victory.h"
QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //重写paintEvent事件 画背景图
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    mysetwindow *msw = NULL;
};
#endif // MAINWINDOW_H
