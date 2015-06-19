#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mytcpserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int startPort ;
    int nServers ;
    MyTcpServer *server[10] ;

protected:
    void changeEvent(QEvent *e);
    
private:
    Ui::MainWindow *ui;
public slots :
    void addData (QString) ;
};

#endif // MAINWINDOW_H
