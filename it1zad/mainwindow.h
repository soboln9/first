#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVector>
#include <QtMath>
#include <cmath>
#include <complex>
#include <QString>
#include <iomanip>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <fftw3.h>
#include <cstdlib> //for rand
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
    int N;
    //void find_b()
    ~MainWindow();
public slots:
    void source_and_shum(/*QVector<double>& diskre*/);
    void furiefunc();
    void clearchart();

    void def();
private:
    Ui::MainWindow *ui;
    QPushButton* startb;
    QPushButton* clearchartb;
    QPushButton* defaultpar;
    QVector<double> dis;
    QVector<std::complex<double>> clearsignalafterF_1;
    QVector<double> t;

    QVector<double> shumn;
    QLineSeries* lnshum;
    //QLineSeries* lnclearsignal;

    QChart* graph1;
    QChartView* v1;
    QLineSeries* ln1;
    QValueAxis* axisX1;
    QValueAxis* axisT1;

    //furie
    QPushButton* furiepb;
    QVector<double> chastoti;

    QVector<std::complex<double>> vecfurcomp;
    QVector<double> amplitudeabs;
    QVector<std::complex<double>> vecfurcomp_shum;
    QVector<double> amplitudeabs_shum;

    //furie gisto
    QValueAxis* axisA;
    QBarCategoryAxis* axischast;
    QBarSeries* bser;
    QBarSet* bset;
    QChart* graphgist;
    QChartView* v2;

    //furie graph
    QChart* graphfurie;
    QChartView* v2g;
    QLineSeries* ln2;
    QValueAxis* axisAg;
    QValueAxis* axischastg;
    QLineSeries* lnfurieshum;
    QLineSeries* lnfurieclearshum;

    //3 график
    QChart* graphclear;
    QChartView* v3;
    QLineSeries* lnsources3;
    QLineSeries* lnclear3;
    QValueAxis* axisX3;
    QValueAxis* axisT3;
};
#endif // MAINWINDOW_H
