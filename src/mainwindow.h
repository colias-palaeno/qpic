#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void render_file(QString* file_path);

    void enable_navigation();

private slots:

    void on_actionOpen_triggered();

    void on_actionShow_Menu_Bar_toggled(bool checked);

    void navigate_dir(bool next);

    void on_actionNext_Image_triggered();

    void on_actionPrevious_Image_triggered();

    void zoom(float sf);

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
