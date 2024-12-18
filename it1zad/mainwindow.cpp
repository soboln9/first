#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    clearchartb = new QPushButton(this);
    clearchartb->setGeometry(100,600,130,90);
    clearchartb->setText("Source and clear s");
    clearchartb->setPalette(Qt::yellow);
    clearchartb->setEnabled(false);
    connect(clearchartb, SIGNAL(clicked(bool)), this, SLOT(clearchart()));

    startb = new QPushButton(this);
    startb->setGeometry(200,500,90,90);
    QString pusht = tr("Start");
    startb->setText(pusht);
    startb ->setPalette(Qt::green);
    connect(startb, SIGNAL(clicked()),this,SLOT(source_and_shum()));

    furiepb = new QPushButton(this);
    furiepb->setEnabled(false);
    furiepb->setGeometry(200,600,90,90);
    furiepb->setText(tr("Furie"));
    furiepb->setPalette(Qt::darkBlue);
    connect(furiepb, SIGNAL(clicked(bool)), this, SLOT(furiefunc()));

    defaultpar = new QPushButton(this);
    defaultpar->setGeometry(100,500,110,90);
    defaultpar->setText("Default \n parameters");
    defaultpar->setPalette(Qt::darkCyan);
    defaultpar->setEnabled(true);
    connect(defaultpar, SIGNAL(clicked(bool)), this, SLOT(def()));
//график(х(т))
    graph1 = new QChart();
    v1= new QChartView(this);
    ui->verticalLayout->addWidget(v1);
    v1->setPalette(Qt::black);
    v1->setChart(graph1);

    ln1 = new QLineSeries();
    lnshum = new QLineSeries();
    graph1->addSeries(ln1);
    graph1->addSeries(lnshum);
    graph1->setTitle("График x(t)");
    axisT1 = new QValueAxis();
    axisX1 = new QValueAxis();
    axisT1->setTitleText("T");
    axisX1->setTitleText("X");
    graph1->addAxis(axisT1, Qt::AlignBottom);
    graph1->addAxis(axisX1, Qt::AlignLeft);

    ln1->attachAxis(axisT1);
    ln1->attachAxis(axisX1);
    lnshum->attachAxis(axisX1);
    lnshum->attachAxis(axisT1);
//names
    ln1->setName("Source signal");
    lnshum->setName("Signal with shum");

//фурье график
    graphfurie = new QChart();
    v2g= new QChartView(this);
    ui->verticalLayout_3->addWidget(v2g);
    v2g->setPalette(Qt::black);
    v2g->setChart(graphfurie);
    ln2 = new QLineSeries();
    lnfurieshum = new QLineSeries();
    lnfurieclearshum = new QLineSeries();
    graphfurie->addSeries(ln2);
    graphfurie->addSeries(lnfurieshum);
    graphfurie->addSeries(lnfurieclearshum);
    graphfurie->setTitle("График A(w)");
    axisAg = new QValueAxis();
    axischastg = new QValueAxis();
    axisAg->setTitleText("A");
    axischastg->setTitleText("w");
    graphfurie->addAxis(axisAg, Qt::AlignLeft);
    graphfurie->addAxis(axischastg, Qt::AlignBottom);
    ln2->attachAxis(axisAg);
    ln2->attachAxis(axischastg);
    lnfurieshum->attachAxis(axisAg);
    lnfurieshum->attachAxis(axischastg);
    lnfurieclearshum->attachAxis(axisAg);
    lnfurieclearshum->attachAxis(axischastg);
//names
    ln2->setName("Source");
    lnfurieshum->setName("S+Shum");
    lnfurieclearshum->setName("Clear signal");

// 3 график clear signal after furie_1
    graphclear = new QChart();
    v3 = new QChartView(this);
    ui->verticalLayout_4->addWidget(v3);
    v3->setPalette(Qt::black);
    v3->setChart(graphclear);

    lnsources3 = new QLineSeries();
    lnclear3 = new QLineSeries();
    graphclear->addSeries(lnsources3);
    graphclear->addSeries(lnclear3);
    graphclear->setTitle("Graph of source and clear signal");
    axisT3 = new QValueAxis();
    axisX3 = new QValueAxis();
    axisT3->setTitleText("T");
    axisX3->setTitleText("X");
    graphclear->addAxis(axisT3, Qt::AlignBottom);
    graphclear->addAxis(axisX3, Qt::AlignLeft);

    lnsources3->attachAxis(axisX3);
    lnsources3->attachAxis(axisT3);
    lnclear3->attachAxis(axisT3);
    lnclear3->attachAxis(axisX3);


//фурье гистограмма
    graphgist = new QChart();
    v2 = new QChartView(this);
    ui->verticalLayout_2->addWidget(v2);
    bset = new QBarSet("A");
    bser = new QBarSeries();
    graphgist->addSeries(bser);
    //graphgist->setTitle("График A(w)");
    axisA = new QValueAxis();
    axischast = new QBarCategoryAxis(this);
    graphgist->addAxis(axisA,Qt::AlignLeft);
    bser->attachAxis(axisA);
    graphgist->addAxis(axischast, Qt::AlignBottom);
    bser->attachAxis(axischast);
    v2->setChart(graphgist);
    graphgist->setAnimationOptions(QChart::SeriesAnimations);
}

void MainWindow::source_and_shum(){
    furiepb->setEnabled(true);
    ln1->clear();
    lnshum->clear();
    dis.clear();
    t.clear();
    shumn.clear();
    N = ui->N->text().toInt();
    dis.resize(N);
    t.resize(N);

    double fd = ui->fd->text().toDouble();
    double f1 = ui->f1->text().toDouble();
    double f2 = ui->f2->text().toDouble();
    double f3 = ui->f3->text().toDouble();
    double xmax = 0;
    double tmax = 0;
    double tmin = 0;
    double xmin = 0;
    double dt = 1 / fd;

    double S_2 =0.0;

    for(int i = 0;i < N; ++i){
        t[i] = i * dt;
        dis[i] = ui->A1->text().toDouble() * qCos(2 * M_PI * f1 * t[i] + ui->fi1->text().toDouble()) + ui->A2->text().toDouble() * qCos(2 * M_PI * f2 * t[i] + ui->fi2->text().toDouble()) + ui->A3->text().toDouble() * qCos(2 * M_PI * f3 * t[i] + ui->fi3->text().toDouble());

        S_2 += pow(dis[i],2);

        xmax = std::max(xmax, dis[i]);
        tmax = std::max(tmax, t[i]);
        tmin = std::min(tmin,t[i]);
        xmin = std::min(xmin, dis[i]);
    }




    double _n_2 = 0.0;
    shumn.resize(N);
    double a = ui->shum->text().toDouble();
    for(int i = 0; i < N;++i){
        for(int j = 0;j < 12;++j){
            shumn[i] += static_cast<double>(rand())-RAND_MAX/2;
        }
        _n_2 += pow(shumn[i],2);
    }
    double b = 0.0;
    b = sqrt((a*S_2)/(_n_2));


    for(int i = 0;i < N; ++i){
        ln1->append(t[i], dis[i]);
    }
    for(int i = 0;i < N; ++i){
        shumn[i] *= b;
        lnshum->append(t[i], dis[i]+shumn[i]);
        xmax = std::max(xmax, dis[i]+shumn[i]);
        xmin = std::min(xmin, dis[i]+shumn[i]);
    }
    axisX1->setRange(xmin+(xmin/10),xmax+(xmax/10));
    axisT1->setRange(tmin-(0.01), tmax+(tmax/10));

}

void MainWindow::furiefunc(){
    int N = ui->N->text().toInt();

    chastoti.clear();
    vecfurcomp.clear();
    amplitudeabs.clear();
    vecfurcomp_shum.clear();
    amplitudeabs_shum.clear();


    ln2->clear();
    lnfurieshum->clear();
    lnfurieclearshum->clear();

    fftw_plan my_plan;
    fftw_plan my_plan_shum;
    fftw_plan my_plan_clear;

    fftw_complex *in, *out;
    fftw_complex *inshum, *outshum;
    fftw_complex *inclear, *outclear;

    chastoti.resize(N);
    vecfurcomp.resize(N);
    amplitudeabs.resize(N);
    vecfurcomp_shum.resize(N);
    amplitudeabs_shum.resize(N);

    in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);

    inshum = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
    outshum = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);

    inclear = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
    outclear = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);


    my_plan = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    my_plan_shum = fftw_plan_dft_1d(N, inshum, outshum, FFTW_FORWARD, FFTW_ESTIMATE);
    my_plan_clear = fftw_plan_dft_1d(N, outclear, inclear, FFTW_BACKWARD, FFTW_ESTIMATE);
    for(int i = 0;i < N;i++){
        in[i][0] = dis[i];
        in[i][1] = 0.0;
    }

    for(int i = 0;i < N;i++){
        inshum[i][0] = dis[i]+shumn[i];
        inshum[i][1] = 0.0;
    }

    fftw_execute(my_plan);
    fftw_execute(my_plan_shum);

    for(int i = 0;i < N;i++){
        vecfurcomp[i] = std::complex(out[i][0],out[i][1]);
        vecfurcomp_shum[i] = std::complex(outshum[i][0], outshum[i][1]);
    }



    QStringList list;//для гистограммы
    double Amin = 0;
    double Amax = 0;
    double wmin = 0;
    double wmax = 0;
    for(int i = 0;i < N;i++){
        chastoti[i] = ((i)*(ui->fd->text().toDouble())/N);

        amplitudeabs[i] = sqrt(pow(out[i][0],2)+pow(out[i][1],2));
        amplitudeabs_shum[i] = sqrt(pow(outshum[i][0],2)+pow(outshum[i][1],2));

        Amax = std::max(amplitudeabs_shum[i],std::max(Amax, amplitudeabs[i]));
        Amin = std::min(amplitudeabs_shum[i],std::min(Amin, amplitudeabs[i]));

        wmin = std::min(wmin,chastoti[i]);
        wmax = std::max(wmax,chastoti[i]);

        //гистограмма
        bset->append(amplitudeabs[i]);
        list<<QString::number(chastoti[i]);

    }

    //обычные графики
    axisAg->setRange(Amin - (Amin/10),Amax+(Amax/10));
    axischastg->setRange(wmin-(wmin/10), wmax+(wmax/10));
    for(int i = 0;i < N;i++){
        ln2->append(chastoti[i],amplitudeabs[i]);
        lnfurieshum->append(chastoti[i], amplitudeabs_shum[i]);
    }


    double Y = ui->Y->text().toDouble();
    double Esum = 0.0;

    for(auto &i: amplitudeabs_shum){
        Esum += std::pow(i,2);
    }
    if(Y == 0){

    }
    double Es = Y * Esum;
    double Ecur = 0.0;
    int th = 0;
    for(int i = 0;i < N;i++){
        Ecur += pow(amplitudeabs_shum[i],2) + pow(amplitudeabs_shum[N-i-1],2);
        if (Ecur > Es){
            th = i;
            break;
        }
    }

    if(ui->shum->text().toDouble()!=0){
    for(int c = th; c < N-th;c++){
        amplitudeabs_shum[c] = 0.0;
        outshum[c][0] = 0.0;
        outshum[c][1] = 0.0;
    }
    }

    for(int i = 0;i < N;i++){
        lnfurieclearshum->append(chastoti[i], amplitudeabs_shum[i]);
        //заполнили для обратного фурье
        outclear[i][0] = outshum[i][0];
        outclear[i][1] = outshum[i][1];
    }
    fftw_execute(my_plan_clear);

    clearsignalafterF_1.clear();
    clearsignalafterF_1.resize(N);

    for(int i = 0;i < N;i++){
        clearsignalafterF_1[i] = std::complex<double>(inclear[i][0], inclear[i][1]);
        clearsignalafterF_1[i] /= static_cast<double>(N);
    }

    //гистограмма
    bser->append(bset);
    axischast->append(list);

    axisA->setRange(Amin - (Amin/10),Amax+(Amax/10));
    axischast->setRange(QString::number(wmin-(wmin/10)), QString::number(wmax+(wmax/10)));

    clearchartb->setEnabled(true);
    //clean memory

    fftw_destroy_plan(my_plan);
    fftw_free(in);
    fftw_free(out);
    fftw_destroy_plan(my_plan_shum);
    fftw_free(inshum);
    fftw_free(outshum);
    fftw_destroy_plan(my_plan_clear);
    fftw_free(inclear);
    fftw_free(outclear);

    furiepb->setEnabled(false);
}

void MainWindow::clearchart(){
    lnclear3->clear();
    lnsources3->clear();
    double xmax = 0;
    double xmin = 0;
    double tmin = 0;
    double tmax = 0;
    for(int i = 0;i < N; ++i){
        xmax = std::max(xmax, dis[i]);
        xmax = std::max(clearsignalafterF_1[i].real(), xmax);
        xmin = std::min(xmin, dis[i]);
        xmin = std::min(clearsignalafterF_1[i].real(), xmin);
        tmax = std::max(tmax, t[i]);
        tmin = std::min(tmin,t[i]);
    }
    axisX3->setRange(xmin+(xmin/10),xmax+(xmax/10));
    axisT3->setRange(tmin-(0.01), tmax+(tmax/10));

    for(int i = 0;i < N; ++i){
        lnsources3->append(t[i], dis[i]);
        lnclear3->append(t[i], clearsignalafterF_1[i].real());
    }

    double Edelta = 0.;
    for(int i = 0;i < N;++i){
        Edelta += pow(dis[i] - clearsignalafterF_1[i].real(), 2);
    }
    double Es = 0.0;
    for(auto &i: dis){
        Es += std::pow(i,2);//source E
    }
    ui->delta->setText(QString::number(Edelta/Es));
    clearchartb->setEnabled(false);
}

void MainWindow::def()
{
    ui->A1->setText(QString::number(7));
    ui->A2->setText(QString::number(12));
    ui->A3->setText(QString::number(10));
    ui->f1->setText(QString::number(20));
    ui->f2->setText(QString::number(15));
    ui->f3->setText(QString::number(10));
    ui->fi1->setText(QString::number(9));
    ui->fi2->setText(QString::number(7));
    ui->fi3->setText(QString::number(5));
    ui->N->setText(QString::number(50));
    ui->fd->setText(QString::number(100));
    ui->shum->setText(QString::number(0.7));
    ui->Y->setText(QString::number(0.58));

}
MainWindow::~MainWindow()
{
    delete ui;
    delete startb;
    delete clearchartb;
    delete defaultpar;
    delete lnshum;
    delete graph1;
    delete v1;
    delete ln1;
    delete axisX1;
    delete axisT1;
    delete furiepb;
    delete axisA;
    delete axischast;
    delete bser;
    delete bset;
    delete graphgist;
    delete v2;
    delete graphfurie;
    delete v2g;
    delete ln2;
    delete axisAg;
    delete axischastg;
    delete lnfurieshum;
    delete lnfurieclearshum;
    delete graphclear;
    delete v3;
    delete lnsources3;
    delete lnclear3;
    delete axisX3;
    delete axisT3;
}

