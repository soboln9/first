#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QtMath>
#include <cmath>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <fftw3.h>
#include <complex>
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
    ~MainWindow();

private slots:
    void on_start_clicked();

private:
    Ui::MainWindow *ui;

    QVector<double> x_1;
    QVector<double> h;
    QVector<double> t;
    QVector<double> y;
    QVector<double> f;
    QVector<double> Y;
    QVector<double> H;
    //QVector<std::complex<double>> backcomp;

    QChart* graph_x;
    QChartView* v_x;
    QLineSeries* ln_x1;
    QLineSeries* ln_x2;
    QValueAxis* axisv_xa;
    QValueAxis* axisv_xt;

    QChart* graph_h;
    QChartView* v_h;
    QLineSeries* ln_h;
    QValueAxis* axisv_ha;
    QValueAxis* axisv_ht;

    QChart* graph_y;
    QChartView* v_y;
    QLineSeries* ln_y;
    QValueAxis* axisv_ya;
    QValueAxis* axisv_yt;

    QChart* graph_Y;
    QChartView* v_Y;
    QLineSeries* ln_Y;
    QValueAxis* axisv_Ya;
    QValueAxis* axisv_Yt;

    QChart* graph_H;
    QChartView* v_H;
    QLineSeries* ln_H;
    QValueAxis* axisv_Ha;
    QValueAxis* axisv_Ht;
};
#endif // MAINWINDOW_H
