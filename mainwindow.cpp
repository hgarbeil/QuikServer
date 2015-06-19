#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int i ;

    ui->setupUi(this);

    startPort = 8890 ;
    nServers = 4 ;
    for (i=0; i<nServers; i++) {

        server[i] = new MyTcpServer (this) ;
        connect(server[i], SIGNAL(newConnection()), server[i], SLOT(acceptConnection()));
        connect (server[i], SIGNAL (gotData(QString)), this, SLOT (addData(QString))) ;

        //connFlag [i] = false ;
    }
    for (i=0; i<nServers; i++)server[i]->listen (QHostAddress::Any, startPort+i) ;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::addData (QString str) {

    if (ui->textList->count () > 50) ui->textList->clear() ;
    QStringList str0 = str.split ("\r") ;
    ui->textList->addItem(str0[0]);

    ui->textList->scrollToItem(ui->textList->currentItem()) ;

}
