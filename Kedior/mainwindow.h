#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <fstream>
#include <string>
#include <QString>
#include <QMenu>
#include <QAction>
#include <codeeditor.h>
#include <lexer.h>
#include <highlighter.h>

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
    // For menu bar setting
    void CreateAction();
    void CreateMenu();

public slots:
    // For Content
    void Content();

    // For menu bar setting
    void newFile();
    void saveFile();

private:
    Ui::MainWindow *ui;
    LineNumberArea *editArea;
    CodeEditor *codeArea;
    Highlighter *highlighter;
    Lexer *lex;

    // For menu bar
    QMenu *fileBar;
    QAction *new_file;
    QAction *save_file;
};

#endif // MAINWINDOW_H
