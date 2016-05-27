#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "savefile.h"

#include <QMainWindow>
#include <QStringListModel>
#include <QCloseEvent>
#include <QPoint>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:
    void closeEvent(QCloseEvent *);

private slots:
    void on_addButton_clicked();

    void showContextMenu(const QPoint&);

    void deleteItem();

private:
    Ui::MainWindow *ui;

    SaveFile m_safeFile;

    QStringListModel *m_model;
};

#endif // MAINWINDOW_H
