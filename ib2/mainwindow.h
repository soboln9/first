#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
using namespace std;
#include <iomanip>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QVector<unsigned char> convertfromsource(QString& source_text);
    unsigned char crc8(QVector<unsigned char>& uns);
    QString converttohex(unsigned char crc8);
    ~MainWindow();

private slots:
    void on_sum_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
