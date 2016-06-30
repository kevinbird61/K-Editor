#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    codeArea = new CodeEditor(this);
    codeArea->setFont(QFont("Monospace",12));
    codeArea->setTabStopWidth(codeArea->tabStopWidth()/2);
    editArea = new LineNumberArea(codeArea);
    this->setCentralWidget(codeArea);
    connect(codeArea,SIGNAL(textChanged()),this,SLOT(Lexer()));

    cur_str = new QString("");
    type_music = new QSound(":/baby_cry.wav");
    cur_state = 0;

    CreateAction();
    CreateMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateAction()
{
    // Create for new page
    new_file = new QAction(tr("&New"),this);
    new_file->setShortcuts(QKeySequence::New);
    new_file->setStatusTip(tr("Create a new file"));
    connect(new_file , &QAction::triggered , this , &MainWindow::newFile);
    // Create for save page
    save_file = new QAction(tr("&Save"),this);
    save_file->setShortcuts(QKeySequence::Save);
    save_file->setStatusTip(tr("Create a save file"));
    connect(save_file , &QAction::triggered , this , &MainWindow::saveFile);
}

void MainWindow::CreateMenu()
{
    fileBar = menuBar()->addMenu("&File");
    fileBar->addAction(new_file);
    fileBar->addAction(save_file);

}

void MainWindow::Lexical_analysis()
{
    QStringList StrList = cur_str->split(' ',QString::SkipEmptyParts);

    if(cur_state >= StrList.size())
        if(cur_state > 0) cur_state--;

    for(int i = cur_state ; i < StrList.size() ; i++){
        if(StrList.at(i) == "kevin"){
            cout << "He is awesome" << endl;
            type_music->play();
            cur_state = i+1;
        }
    }
    //cout << cur_str->toStdString() << endl; For debug
}

void MainWindow::Lexer()
{
    QString *str = new QString(codeArea->toPlainText());
    cur_str = str;
    Lexical_analysis();
}

void MainWindow::newFile()
{
    cout << "New file" << endl;
    codeArea->clear();
}

void MainWindow::saveFile()
{
    cout << "Save file" << endl;
    // Store the currently file into file
    ofstream outputFile;
    outputFile.open("/storage/save.txt");
    QString str = codeArea->toPlainText();
    outputFile << str.toStdString();
}
