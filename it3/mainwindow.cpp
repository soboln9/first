#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //default
    ui->fd->setText(QString::number(4));
    ui->N->setText(QString::number(50));
    ui->A1->setText(QString::number(4));
    ui->A2->setText(QString::number(10));
    ui->A3->setText(QString::number(7));
    ui->sigma1->setText(QString::number(0.7));
    ui->sigma2->setText(QString::number(1.1));
    ui->sigma3->setText(QString::number(1.5));
    ui->mu1->setText(QString::number(1));
    ui->mu2->setText(QString::number(4));
    ui->mu3->setText(QString::number(7));
    ui->Ah->setText(QString::number(4));
    ui->sigmah->setText(QString::number(0.2));


    graph_x = new QChart();
    v_x = new QChartView(this);
    ui->layout_x->addWidget(v_x);
    v_x->setPalette(Qt::green);
    v_x->setChart(graph_x);
    axisv_xa = new QValueAxis();
    axisv_xt = new QValueAxis();
    graph_x->setTitle("x(t)");
    graph_x->addAxis(axisv_xa, Qt::AlignLeft);
    graph_x->addAxis(axisv_xt, Qt::AlignBottom);
    ln_x1 = new QLineSeries();
    ln_x2 = new QLineSeries();
    graph_x->addSeries(ln_x1);
    ln_x1->attachAxis(axisv_xa);
    ln_x1->attachAxis(axisv_xt);
    ln_x1->setName("Source");
    graph_x->addSeries(ln_x2);
    ln_x2->attachAxis(axisv_xa);
    ln_x2->attachAxis(axisv_xt);
    ln_x2->setName("After F_1");

    graph_h = new QChart();
    v_h = new QChartView(this);
    ui->layout_h->addWidget(v_h);
    v_h->setPalette(Qt::green);
    v_h->setChart(graph_h);
    axisv_ha = new QValueAxis();
    axisv_ht = new QValueAxis();
    graph_h->setTitle("h(t)");
    graph_h->addAxis(axisv_ha, Qt::AlignLeft);
    graph_h->addAxis(axisv_ht, Qt::AlignBottom);
    ln_h = new QLineSeries();
    graph_h->addSeries(ln_h);
    ln_h->attachAxis(axisv_ha);
    ln_h->attachAxis(axisv_ht);
    ln_h->setName("Импульсная характеристика");

    graph_y = new QChart();
    v_y = new QChartView(this);
    ui->layout_y->addWidget(v_y);
    v_y->setPalette(Qt::green);
    v_y->setChart(graph_y);
    axisv_ya = new QValueAxis();
    axisv_yt = new QValueAxis();
    graph_y->setTitle("y(t)");
    graph_y->addAxis(axisv_ya, Qt::AlignLeft);
    graph_y->addAxis(axisv_yt, Qt::AlignBottom);
    ln_y = new QLineSeries();
    graph_y->addSeries(ln_y);
    ln_y->attachAxis(axisv_ya);
    ln_y->attachAxis(axisv_yt);
    ln_y->setName("Свертка");

    graph_Y = new QChart();
    v_Y = new QChartView(this);
    ui->layout_Y->addWidget(v_Y);
    v_Y->setPalette(Qt::yellow);
    v_Y->setChart(graph_Y);
    axisv_Ya = new QValueAxis();
    axisv_Yt = new QValueAxis();
    graph_Y->setTitle("Y(f)");
    graph_Y->addAxis(axisv_Ya, Qt::AlignLeft);
    graph_Y->addAxis(axisv_Yt, Qt::AlignBottom);
    ln_Y = new QLineSeries();
    graph_Y->addSeries(ln_Y);
    ln_Y->attachAxis(axisv_Ya);
    ln_Y->attachAxis(axisv_Yt);
    ln_Y->setName("АЧС Y");

    graph_H = new QChart();
    v_H  = new QChartView(this);
    ui->layout_H->addWidget(v_H);
    v_H->setPalette(Qt::yellow);
    v_H->setChart(graph_H);
    axisv_Ha = new QValueAxis();
    axisv_Ht = new QValueAxis();
    graph_H->setTitle("H(f)");
    graph_H->addAxis(axisv_Ha, Qt::AlignLeft);
    graph_H->addAxis(axisv_Ht, Qt::AlignBottom);
    ln_H = new QLineSeries();
    graph_H->addSeries(ln_H);
    ln_H->attachAxis(axisv_Ha);
    ln_H->attachAxis(axisv_Ht);
    ln_H->setName("АЧС H");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    const int N = ui->N->text().toInt();
    x_1.clear();
    h.clear();
    y.clear();
    Y.clear();
    H.clear();
    f.clear();
    t.clear();
    x_1.resize(N);
    t.resize(N);
    h.resize(N);
    y.resize(N);
    f.resize(N);
    Y.resize(N);
    H.resize(N);
    ln_x1->clear();
    ln_h->clear();
    ln_y->clear();
    ln_Y->clear();
    ln_H->clear();
    ln_x2->clear();


    //backcomp.resize(N);

    double fd = ui->fd->text().toDouble();
    double dt = 1 / fd;
    double A1 = ui->A1->text().toDouble();
    double A2 = ui->A2->text().toDouble();
    double A3 = ui->A3->text().toDouble();
    double sigma1 = ui->sigma1->text().toDouble();
    double sigma2 = ui->sigma2->text().toDouble();
    double sigma3 = ui->sigma3->text().toDouble();
    double mu1 = ui->mu1->text().toDouble();
    double mu2 = ui->mu2->text().toDouble();
    double mu3 = ui->mu3->text().toDouble();
    double Ah = ui->Ah->text().toDouble();
    double sigmah = ui->sigmah->text().toDouble();
//const range
    double tmax = 0.;
    double tmin = 0.;
    double fmin = 0.;
    double fmax = 0.;

//range
    double xmin = 0.;
    double xmax = 0.;
    double hmin = 0.;
    double hmax = 0.;
    double ymin = 0.;
    double ymax = 0.;
    double Ymin = 0.;
    double Ymax = 0.;
    double Hmin = 0.;
    double Hmax = 0.;

    for(int i = 0;i < N; ++i)
    {
        t[i] = i * dt;
        x_1[i] = A1 * exp(-pow((t[i] - mu1), 2) / (2 * pow(sigma1, 2))) + A2 * exp(-pow((t[i] - mu2), 2) / (2 * pow(sigma2, 2))) + A3 * exp(-pow((t[i] - mu3), 2) / (2 * pow(sigma3, 2)));
        h[i] =  Ah * exp(-pow((t[i]), 2) / (2 * pow(sigmah, 2)));
        tmax = std::max(tmax, t[i]);
        tmin = std::min(tmin, t[i]);

        xmax = std::max(xmax, x_1[i]);
        xmin = std::min(xmin, x_1[i]);
        hmax = std::max(hmax, h[i]);
        hmin = std::min(hmin, h[i]);
    }

    int mid = N/2;
    for(int i = mid;i < N; ++i)
    {
        h[i] = h[N/2 + mid - i];
    }

    for(int c = 0;c < N;++c)
    {
        for(int i = 0;i < N;++i)
        {
            if (c - i >= 0 && c - i < N)
                y[c] += x_1[i] * h[c - i];
        }
        ymax = std::max(ymax, y[c]);
        ymin = std::min(ymin, y[c]);
    }
//фурье
    fftw_plan plany;
    fftw_plan planh;
    fftw_plan planback;
    fftw_complex *yin, *yout;
    fftw_complex *hin, *hout;
    fftw_complex *xin, *xout;

    yin = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
    yout = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
    hin = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
    hout = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
    xin = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
    xout = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);

    plany = fftw_plan_dft_1d(N, yin, yout, FFTW_FORWARD, FFTW_ESTIMATE);
    planh = fftw_plan_dft_1d(N, hin, hout, FFTW_FORWARD, FFTW_ESTIMATE);
    planback = fftw_plan_dft_1d(N, xout, xin, FFTW_BACKWARD, FFTW_ESTIMATE);

    for(int i = 0;i < N;i++)
    {
        yin[i][0] = y[i];
        yin[i][1] = 0.0;
        hin[i][0] = h[i];
        hin[i][1] = 0.0;
    }

    fftw_execute(plany);
    fftw_execute(planh);

    for(int i = 0;i < N;i++){
        f[i] = (i*(ui->fd->text().toDouble())/N);
        Y[i] = sqrt(pow(yout[i][0], 2) + pow(yout[i][1],  2));
        H[i] = sqrt(pow(hout[i][0], 2) + pow(hout[i][1],  2));

        Ymax = std::max(Ymax, Y[i]);
        Ymin = std::min(Ymin, Y[i]);
        Hmax = std::max(Hmax, H[i]);
        Hmin = std::min(Hmin, H[i]);

        fmin = std::min(fmin, f[i]);
        fmax = std::max(fmax, f[i]);
    }
//обратное фурье
    QVector<std::complex<double>> yo(N);
    QVector<std::complex<double>> ho(N);

    for(int i = 0;i < N;i++)
    {
        yo[i] = std::complex(yout[i][0], yout[i][1]);
        ho[i] = std::complex(hout[i][0], hout[i][1]);
        //xout[i][0] = yout[i][0] / (hout[i][0]);//F{Y}/F{H};
        //xout[i][1] = yout[i][1] / (hout[i][1]);//или нужно амплитуды делить
        yo[i] /= ho[i];
    }
    for(int i = 0;i < N;i++)
    {
        xout[i][0] = yo[i].real();
        xout[i][1] = yo[i].imag();
    }
    fftw_execute(planback);
    for(int i = 0;i < N;i++)
    {
        xin[i][0] /= static_cast<double>(N);//нормализация
        xin[i][1] /= static_cast<double>(N);
    }

    for(int c = 0;c < N;c++)
    {
        xmax = std::max(xmax, xin[c][0]);
        xmin = std::min(xmin, xin[c][0]);
    }


    axisv_xa->setRange(xmin+(xmin/10), xmax+(xmax/10));
    axisv_xt->setRange(tmin-(0.01), tmax);
    axisv_ha->setRange(hmin+(hmin/10), hmax+(hmax/10));
    axisv_ht->setRange(tmin, tmax);
    axisv_ya->setRange(ymin+(ymin/10), ymax+(ymax/10));
    axisv_yt->setRange(tmin, tmax);
    axisv_Ya->setRange(Ymin - (Ymin/10), Ymax+(Ymax/10));
    axisv_Yt->setRange(fmin, fmax);
    axisv_Ha->setRange(Hmin - (Hmin/10), Hmax+(Hmax/10));
    axisv_Ht->setRange(fmin, fmax);


    for(int i = 0;i < N; ++i){
        ln_x1->append(t[i], x_1[i]);
        ln_h->append(t[i], h[i]);
        ln_y->append(t[i], y[i]);
        ln_Y->append(f[i], Y[i]);
        ln_H->append(f[i], H[i]);
        ln_x2->append(t[i], xin[i][0]);
    }



    fftw_destroy_plan(plany);
    fftw_free(yin);
    fftw_free(yout);
    fftw_destroy_plan(planh);
    fftw_free(hin);
    fftw_free(hout);
    fftw_destroy_plan(planback);
    fftw_free(xin);
    fftw_free(xout);
}

