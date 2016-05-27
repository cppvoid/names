#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "savefile.h"
#include "qruntimeerror.h"

#include <QMessageBox>
#include <QStringListModel>
#include <QCloseEvent>
#include <QPoint>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        m_safeFile("text.txt"),
        m_model(nullptr)
{
    ui->setupUi(this);

    setWindowTitle("Test");

    ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    try
    {
        m_model = new QStringListModel(m_safeFile.getData());

        ui->listView->setModel(m_model);
    }
    catch(const QRuntimeError& error)
    {
        QMessageBox::critical(this, "Error", error.qwhat());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    try
    {
        m_safeFile.override(m_model->stringList());

        event->accept();
    }
    catch(const QRuntimeError& error)
    {
        auto replay = QMessageBox::critical(this, "Error", error.qwhat() + " </br>cannot save data, exit anyway?", QMessageBox::Yes, QMessageBox::No);

        if(replay == QMessageBox::Yes)
        {
            event->accept();
        }
        else
        {
            event->ignore();
        }
    }
}

void MainWindow::showContextMenu(const QPoint& pos)
{
    auto globalPos = ui->listView->mapToGlobal(pos);

    QMenu menu;

    menu.addAction("delete", this, SLOT(deleteItem()));

    menu.exec(globalPos);
}

void MainWindow::on_addButton_clicked()
{
    auto input = ui->lineEdit->text();

    if(!input.isEmpty())
    {
        auto list = m_model->stringList();
        list.append(input);
        m_model->setStringList(list);

        ui->lineEdit->clear();
    }
}

void MainWindow::deleteItem()
{
    auto list = ui->listView->selectionModel()->selectedIndexes();

    for(const auto& index : list)
    {
        m_model->removeRow(index.row());
    }
}
