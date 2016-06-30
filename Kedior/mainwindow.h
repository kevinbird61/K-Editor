#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <fstream>
#include <QString>
#include <QMenu>
#include <QAction>
#include <QSound>
#include <codeeditor.h>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void CreateAction();
    void CreateMenu();
    void Lexical_analysis();

public slots:
    void Lexer();

    void newFile();
    void saveFile();

private:
    Ui::MainWindow *ui;
    QString *cur_str;
    int cur_state;
    QSound *type_music;
    LineNumberArea *editArea;
    CodeEditor *codeArea;

    QMenu *fileBar;
    QAction *new_file;
    QAction *save_file;
};

#endif // MAINWINDOW_H
