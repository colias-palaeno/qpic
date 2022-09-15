#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtMath>

#include <QFileInfo>
#include <QFileDialog>
#include <QPixmap>
#include <QDir>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionShow_Menu_Bar_toggled(bool checked)
{
    ui->menuBar->setVisible(checked);

    auto dims = new QSize(this->width(), this->height() + (checked ? 24 : -24));
    ui->label->resize(*dims);
    setMaximumSize(*dims);
    resize(*dims);
}

int zoom_count = 0;

void MainWindow::zoom(bool change_zoom, bool zooming_in)
{
    if (change_zoom) {
        if (abs(zoom_count) > 5 && zooming_in == (zoom_count > 0))
            return;

        zoom_count += zooming_in ? 1 : -1;
    }

    auto current_file = new QPixmap(windowTitle());
    double sf = qPow(1.25, zoom_count);
    auto dims = new QSize(
        current_file->width() * sf,
        current_file->height() * sf + (ui->menuBar->isVisible() ? 24 : 0)
    );

    auto label = ui->label;

    label->setPixmap(current_file->scaled(*dims, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    delete current_file;

    label->resize(*dims);
    setMaximumSize(*dims);
    resize(*dims);
}

void MainWindow::render_file(QString* file_path)
{
    setWindowTitle(*file_path);
    auto file = new QPixmap(*file_path);
    delete file_path;

    auto dims = new QSize(file->width(), file->height() + (ui->menuBar->isVisible() ? 24 : 0));
    setMaximumSize(*dims);
    resize(*dims);
    ui->label->resize(*dims);

    delete dims;
    ui->label->setPixmap(*file);

    delete file;

    zoom(false, true);
}

void MainWindow::enable_navigation()
{
    // used in main.cpp
    ui->actionZoom_In->setEnabled(true);
    ui->actionZoom_Out->setEnabled(true);
    ui->actionNext_Image->setEnabled(true);
    ui->actionPrevious_Image->setEnabled(true);
}

void MainWindow::on_actionOpen_triggered()
{
    auto file_path = new QString(QFileDialog::getOpenFileName(
        this,
        tr("Open Image"),
        "/",
        tr("Image Files (*.bmp *.gif *.jpg *.jpeg *.png)")
    ));

    if (*file_path == "") {
        delete file_path;
        return;
    }

    render_file(file_path);
    enable_navigation();
}

void MainWindow::navigate_dir(bool next)
{
    // setting this in the MainWindow namespace to easily resize the window. I did this with the zoom function too
    auto file_path = new QString(windowTitle());
    auto file_name = new QString(QFileInfo(*file_path).fileName());
    auto file_dir = std::make_shared<QString>(file_path->remove(*file_name));

    delete file_path;

    auto dir = new QDir(*file_dir);
    dir->setNameFilters({"*.bmp", "*.gif", "*.jpg", "*.jpeg", "*.png"});
    dir->setSorting((ui->actionName->isChecked()) ? QDir::Name : QDir::Time);

    QStringList images = dir->entryList();
    delete dir;

    if (images.size() == 1) {
        ui->actionNext_Image->setEnabled(false);
        ui->actionPrevious_Image->setEnabled(false);
        return;
    }

    int idx = images.indexOf(*file_name) + (next ? 1 : -1);
    delete file_name;

    if (idx == images.size())
        idx = 0;
    else if (idx == -1)
        idx = images.size() - 1;

    render_file(new QString(*file_dir + images[idx]));
}

void MainWindow::on_actionNext_Image_triggered()
{
    navigate_dir(true);
}

void MainWindow::on_actionPrevious_Image_triggered()
{
    navigate_dir(false);
}

void MainWindow::on_actionZoom_In_triggered()
{
    zoom(true, true);
}

void MainWindow::on_actionZoom_Out_triggered()
{
    zoom(true, false);
}

void MainWindow::toggle_sort(bool date)
{
    ui->actionDate->setEnabled(!date);
    ui->actionDate->setChecked(date);

    ui->actionName->setEnabled(date);
    ui->actionName->setChecked(!date);
}

void MainWindow::on_actionDate_triggered()
{
    toggle_sort(true);
}


void MainWindow::on_actionName_triggered()
{
    toggle_sort(false);
}

