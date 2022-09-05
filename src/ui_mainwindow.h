/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionShow_Menu_Bar;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionNext_Image;
    QAction *actionPrevious_Image;
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuDisplay;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(510, 600);
        MainWindow->setMaximumSize(QSize(510, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/src/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionShow_Menu_Bar = new QAction(MainWindow);
        actionShow_Menu_Bar->setObjectName(QString::fromUtf8("actionShow_Menu_Bar"));
        actionShow_Menu_Bar->setCheckable(true);
        actionShow_Menu_Bar->setChecked(true);
        actionShow_Menu_Bar->setVisible(true);
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
	  actionZoom_In->setEnabled(false);
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
	  actionZoom_Out->setEnabled(false);
        actionNext_Image = new QAction(MainWindow);
        actionNext_Image->setObjectName(QString::fromUtf8("actionNext_Image"));
        actionNext_Image->setEnabled(false);
        actionPrevious_Image = new QAction(MainWindow);
        actionPrevious_Image->setObjectName(QString::fromUtf8("actionPrevious_Image"));
        actionPrevious_Image->setEnabled(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 510, 580));
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(0);
        label->setPixmap(QPixmap(QString::fromUtf8(":/src/qimg.png")));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 510, 20));
        menuBar->setNativeMenuBar(true);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuDisplay = new QMenu(menuBar);
        menuDisplay->setObjectName(QString::fromUtf8("menuDisplay"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuDisplay->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionNext_Image);
        menuFile->addAction(actionPrevious_Image);
        menuDisplay->addAction(actionShow_Menu_Bar);
        menuDisplay->addAction(actionZoom_In);
        menuDisplay->addAction(actionZoom_Out);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "qImg", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionShow_Menu_Bar->setText(QCoreApplication::translate("MainWindow", "Show Menu Bar", nullptr));
#if QT_CONFIG(shortcut)
        actionShow_Menu_Bar->setShortcut(QCoreApplication::translate("MainWindow", "Alt+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoom_In->setText(QCoreApplication::translate("MainWindow", "Zoom In", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_In->setShortcut(QCoreApplication::translate("MainWindow", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoom_Out->setText(QCoreApplication::translate("MainWindow", "Zoom Out", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_Out->setShortcut(QCoreApplication::translate("MainWindow", "_", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNext_Image->setText(QCoreApplication::translate("MainWindow", "Next Image", nullptr));
#if QT_CONFIG(shortcut)
        actionNext_Image->setShortcut(QCoreApplication::translate("MainWindow", "Right", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPrevious_Image->setText(QCoreApplication::translate("MainWindow", "Previous Image", nullptr));
#if QT_CONFIG(shortcut)
        actionPrevious_Image->setShortcut(QCoreApplication::translate("MainWindow", "Left", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuDisplay->setTitle(QCoreApplication::translate("MainWindow", "Display", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
