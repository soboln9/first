#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    genkey = new QPushButton("gen key");
    genkey->setParent(this);
    genkey->setGeometry(50,260,100,100);
    genkey->setAutoDefault(true);
    connect(genkey, SIGNAL(clicked()),this,SLOT(generickey()));

    encrip = new QPushButton("enc>>");
    encrip->setParent(this);
    encrip->setGeometry(QRect(150, 360,100,100));
    connect(encrip, SIGNAL(clicked(bool)), this,SLOT(encslot()));

    decrip = new QPushButton("<<dec");
    decrip->setParent(this);
    decrip->setGeometry(QRect(50, 360,100,100));
    connect(decrip, SIGNAL(clicked(bool)), this,SLOT(decslot()));

    loadop = new QPushButton("load op");
    loadop->setParent(this);
    loadop->setGeometry(270,260,100,100);
    connect(loadop, SIGNAL(clicked()),this,SLOT(loadopslot()));

    loadcl = new QPushButton("load cl");
    loadcl->setParent(this);
    loadcl->setGeometry(270,370,100,100);
    connect(loadcl, SIGNAL(clicked()),this,SLOT(loadclslot()));

    loadkey = new QPushButton("load key");
    loadkey->setParent(this);
    loadkey->setGeometry(270,480,100,100);
    connect(loadkey, SIGNAL(clicked()),this,SLOT(loadkeyslot()));

    unloadop = new QPushButton("unload op");
    unloadop->setParent(this);
    unloadop->setGeometry(380,260,100,100);
    connect(unloadop, SIGNAL(clicked()),this,SLOT(unloadopslot()));

    unloadcl = new QPushButton("unload cl");
    unloadcl->setParent(this);
    unloadcl->setGeometry(380,370,100,100);
    connect(unloadcl, SIGNAL(clicked()),this,SLOT(unloadclslot()));

    unloadkey = new QPushButton("unload key");
    unloadkey->setParent(this);
    unloadkey->setGeometry(380,480,100,100);
    connect(unloadkey, SIGNAL(clicked()),this,SLOT(unloadkeyslot()));
}


void MainWindow::generickey(){
    //as for ssh genkey
}



static QVector<int> IP_Table = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};//start


bitset<64> MainWindow::IP(bitset<64>& block){
    bitset<64> tmp;
    for(int c = 0; c < block.size();c++){
        tmp[c] = block[IP_Table[c] - 1];
    }return tmp;
}

static QVector<int> IP_1_Table={
    40, 8 ,48 ,16 ,56 ,24 ,64 ,32 ,
    39 ,7 ,47 ,15 ,55 ,23 ,63 ,31 ,
    38 ,6 ,46 ,14 ,54 ,22 ,62 ,30 ,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59,
    27, 34, 2, 42, 10, 50, 18, 58,
    26, 33, 1, 41, 9, 49, 17, 57, 25
};

bitset<64> MainWindow::IP_1(bitset<64> &block){
    bitset<64> tmp;
    for(int c = 0; c < block.size();c++){
        tmp[c] = block[IP_1_Table[c] - 1];
    }
    return tmp;
}//end
static QVector<int> Expanded_Table = {
    32 ,1 ,2 ,3 ,4 ,5 ,
    4 ,5 ,6 ,7 ,8 ,9 ,
    8 ,9 ,10 ,11 ,12 ,13 ,
    12 ,13 ,14 ,15 ,16 ,17 ,
    16 ,17 ,18 ,19 ,20 ,21 ,
    20 ,21 ,22 ,23 ,24 ,25 ,
    24 ,25 ,26 ,27 ,28 ,29 ,
    28 ,29 ,30 ,31 ,32, 1
};
bitset<48> MainWindow::Expand(bitset<32>& halfblock){
    bitset<48> expandset;
    for(int i = 0;i < expandset.size();i++){
        expandset[i] = halfblock[Expanded_Table[i]-1];
    }return expandset;
}//E

static QVector<int> P_Table = {
    16, 7, 20, 21,
    29, 12, 28, 17,
    1, 15, 23, 26,
    5, 18, 31, 10,
    2, 8, 24, 14,
    32, 27, 3, 9,
    19, 13, 30, 6,
    22, 11, 4, 25
};

bitset<32> MainWindow::P(bitset<32>& input){
    bitset<32> output;
    for(int i = 0; i < P_Table.size(); i++){
        output[i] = input[P_Table[i] - 1];
    }  return output;
}

QVector<bitset<64>> MainWindow::stringiinbinary(QString &input)
{
    QVector<std::bitset<64>> bitvec;
    std::string str= input.toLatin1().constData();
    std::vector<unsigned char> vec (str.begin(),str.end());
    for(int i = 0;i < vec.size();i+=8){
        bitset<64> bits;
        for(int j = 0;j < 8;j++){
            bits|=bitset<64>(vec[i+j])<<(56-j*8);
        }
        bitset<64>swap;
        for(int q = 0;q < 64;q++){
            swap[q] = bits[63-q];
        }
        bitvec.push_back(swap);
    }return bitvec;
}

bitset<64> MainWindow::keyiinbinary(QString &key)
{
    bitset<64> bits;
    std::string str = key.toStdString();
    std::vector<unsigned char> vec(str.begin(), str.end());
    for(int i = 0;i < vec.size();i++){
        for(int j = 0;j < 8;j++){
            bits[i*8+j] = vec[i] >> (7-j)&1;
        }
    }
    return bits;
}

static QVector<int> K1_Table = {
    57, 49, 41, 33, 25, 17, 9, 1,
    58, 50, 42, 34, 26, 18, 10, 2,
    59, 51, 43, 35, 27, 19, 11, 3,
    60, 52, 44, 36, 63, 55, 47, 39,
    31, 23, 15, 7, 62, 54, 46, 38, 30,
    22, 14, 6, 61, 53, 45, 37, 29, 21, 13,
    5, 28, 20, 12, 4
};
static QVector<int> K2_Table = {
    14 ,17 ,11 ,24 ,1 ,5 ,
    3 ,28 ,15 ,6 ,21 ,10 ,
    23 ,19 ,12 ,4 ,26 ,8 ,
    16 ,7 ,27 ,20 ,13 ,2 ,
    41 ,52 ,31 ,37 ,
    47 ,55 ,30 ,40 ,
    51 ,45 ,33 ,48 ,
    44 ,49 ,39 ,56 ,
    34 ,53 ,46, 42, 50, 36, 29, 32
};
const int shifts[16] = {1 ,1 ,2 ,2 ,
                        2 ,2 ,2 ,2 ,
                        1 ,2 ,2 ,2 ,
                        2 ,2 ,2 ,1};

QVector<bitset<48>> MainWindow::generate_round_keys(bitset<64> &key)
{
    bitset<56> k1;
    for(int i = 0;i < k1.size();i++){
        k1[i] = key[K1_Table[i] - 1];
    }
    std::bitset<28> C, D;
    for (int i = 0; i < C.size(); ++i)
    {
        C[i] = k1[i];
        D[i] = k1[i + 28];
    }
    QVector<bitset<48>> round_keys(16);
    for(int round = 0; round < 16;round++){
        if(shifts[round] == 1){
            bool firstC = C[0];
            bool firstD = D[0];
            for(int i = 0;i < C.size()-1;i++){
                C[i] = C[i+1];
                D[i] = D[i+1];
            }
            C[27] = firstC;
            D[27] = firstD;
            D[27] = firstD;
            C[27] = firstC;

        }else if(shifts[round] == 2){
            bool firstC = C[0];
            bool secondC = C[1];

            bool firstD = D[0];
            bool secondD = D[1];
            for(int i = 0;i < C.size()-2;i++){
                C[i] = C[i+2];
                D[i] = D[i+2];
            }
            C.set(26, firstC);
            C.set(27, secondC);
            D.set(26, firstD);
            D.set(27, secondD);
        }
        bitset<56> CiDi;
        for(int i = 0; i < 28; ++i) {
            CiDi[i] = C[i];
            CiDi[i + 28] = D[i];
        }
        for(int i = 0; i < 48; i++){
            round_keys[round][i] = CiDi[K2_Table[i] - 1];
        }
    } return round_keys;
}
QVector<QVector<QVector<int>>> S_Table =
    {
        {
            { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
            { 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
            { 4, 1, 4, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 },
            { 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 }
        },
        {
            { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 },
            { 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
            { 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 },
            { 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 }
        },
        {
            { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 },
            { 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 },
            { 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7 },
            { 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 }
        },
        {
            { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 },
            { 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },
            { 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 },
            { 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 }
        },
        {
            { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 },
            { 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
            { 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 },
            { 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 }
        },
        {
            { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11 },
            { 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8 },
            { 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 1, 6 },
            { 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 }
        },
        {
            { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 },
            { 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 },
            { 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 },
            { 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 }
        },
        {
            { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 },
            { 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2 },
            { 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8 },
            { 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 }
        }
};

bitset<32> MainWindow::S(bitset<48> & afterxor){
    bitset<32> output;
    for(int i = 0;i < S_Table.size();i++){
        bitset<6> Si;
        for (int j = 0; j < 6; j++)
        {
            Si[j] = afterxor[i * 6 + j];
        }
        int a = Si[0] * pow(2, 1) + Si[5] * pow(2, 0);
        int b = Si[1] * pow(2, 3) + Si[2] * pow(2, 2) + Si[3] * pow(2, 1) + Si[4] * pow(2, 0);
        int c = S_Table[i][a][b];
        for (int k = 3; k >= 0; k--)
        {
            output[i * 4 + k] = c % 2;
            c /= 2;
        }
    }
    return output;
}



bitset<64> MainWindow::encdes(bitset<64> &sourcetxt, bitset<64>& key)
{
    bitset<64> InitialP = IP(sourcetxt);

    bitset<32> L;
    bitset<32> R;
    for(int i = 0;i < 32;i++){
        L[i] = InitialP[i];
        R[i] = InitialP[32+i];
    }

    QVector<bitset<48>> keys = generate_round_keys(key);
    for(int round = 0;round < 16;round++){
        bitset<48> E_out = Expand(R);
        bitset<48> Afterxor;
        for(int i=0;i<E_out.size();i++){
            Afterxor[i] = E_out[i]^keys[round][i];
        }
        bitset<32> S_out = S(Afterxor);

        bitset<32> P_out = P(S_out);

        bitset<32> temp;
        for(int i = 0; i < 32;i++){
            temp[i] = L[i];
            L[i] = R[i];
        }
        for(int i = 0; i < 32;i++){
            R[i] = temp[i] ^ P_out[i];
        }
    }

    bitset<64> combined;
    for(int i = 0;i < 32;++i){
        combined[i] = L[i];
        combined[i+32] = R[i];
    }
    combined = IP_1(combined);
    for(int i = 0;i < 64;++i){
    }
    return combined;
}

bitset<64> MainWindow::decdes(bitset<64> &sourcetxt, bitset<64> &key)
{
    bitset<64> InitialP = IP(sourcetxt);

    bitset<32> L;
    bitset<32> R;
    for(int i = 0;i < 32;i++){
        L[i] = InitialP[i];
        R[i] = InitialP[32+i];
    }
    QVector<bitset<48>> keys = generate_round_keys(key);
    for(int round = 15;round >= 0;round--){
        bitset<48> E_out = Expand(L);
        bitset<48> Afterxor;
        for(int i = 0; i < E_out.size();i++){
            Afterxor[i] = E_out[i] ^ keys[round][i];
        }
        bitset<32> S_out = S(Afterxor);

        bitset<32> P_out = P(S_out);

        bitset<32> temp;
        for(int i = 0; i < 32;i++){
            temp[i] = R[i];
            R[i] = L[i];
        }
        for(int i = 0; i < 32;i++){
            L[i] = temp[i] ^ P_out[i];
        }
    }

    bitset<64> combined;
    for(int i = 0;i < 32;++i){
        combined[i] = L[i];
        combined[i+32] = R[i];
    }
    combined = IP_1(combined);
    return combined;
}




void MainWindow::encslot(){
    QString data = ui->opentext->toPlainText()/*text()*/;
    QString key = ui->key->text();

    QVector<bitset<64>> input = stringiinbinary(data);

    QVector<bitset<64>> output;
    bitset<64> k = keyiinbinary(key);
    for(int i = 0;i < input.size();++i){
        bitset<64> outbit = encdes(input[i], k);
        output.push_back(outbit);
    }


    std::vector<unsigned char> vec;
    for(const auto& bits : output) {
        for(int char_ind = 0; char_ind < 8; char_ind++){
            unsigned char byte = 0;
            for(int bitindex = 0; bitindex<8; bitindex++){
                byte|= bits[char_ind*8 + bitindex] << (7 - bitindex);
            }
            vec.push_back(byte);
        }
    }
    std::string str(vec.begin(), vec.end());
    QString result = QString::fromLatin1(str);
    //QString result = QString::fromUtf8(str.c_str(),str.length());
    o = output;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    qDebug()<< data.size();
    qDebug()<< result.size()<< Qt::endl;
    ui->closetext->setPlainText(result);
    ui->opentext->clear();
}

void MainWindow::decslot(){
    QString data = ui->closetext->toPlainText()/*text()*/;
    QString key = ui->key->text();

    QVector<bitset<64>> input = stringiinbinary(data);

    QVector<bitset<64>> output;
    bitset<64> k = keyiinbinary(key);
    for(int i = 0;i < input.size();++i){
        bitset<64> outbit = decdes(input[i], k);
        output.push_back(outbit);
    }
    std::vector<unsigned char> vec;
    for(const auto& bits : output) {
        for(int char_ind = 0; char_ind < 8; char_ind++){
            unsigned char byte = 0;
            for(int bitindex = 0; bitindex<8; bitindex++){
                byte|= bits[char_ind*8 + bitindex] << (7 - bitindex);
            }
            vec.push_back(byte);
        }
    }
    std::string str(vec.begin(), vec.end());
    QString result = QString::fromLatin1(str);
    //QString result = QString::fromUtf8(str.c_str(),str.length());

    qDebug()<< data.size();
    qDebug()<< result.size()<< Qt::endl;
    ui->opentext->setPlainText(result);
}

void MainWindow::loadopslot(){
    //genkey->setText("hi");
    QString filepath = "/home/nikita/itqt/txtforib/loadunloadopen.txt";//load to ui-opentext from file
    QFile loadopenfile(filepath);
    if (!loadopenfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл:" << loadopenfile.errorString();
    }
    QTextStream in(&loadopenfile);
    QString opentext = in.readAll();
    loadopenfile.close();
    ui->opentext->setPlainText(opentext);
}

void MainWindow::loadclslot(){
    genkey->setText("hi");
    QString filepath = "/home/nikita/itqt/txtforib/loadunloadclose.txt";//load in ui-closetext from file
    QFile loadclosefile(filepath);
    if (!loadclosefile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл:" << loadclosefile.errorString();
    }
    QTextStream in(&loadclosefile);
    in.setEncoding(QStringConverter::Latin1);
    QString closetext = in.readAll();
    loadclosefile.close();
    ui->closetext->setPlainText(closetext);
}

void MainWindow::loadkeyslot(){
    genkey->setText("hi");//load in ui-key from file
    QString filepath = "/home/nikita/itqt/txtforib/loadkey.txt";
    QFile keyfile(filepath);
    if (!keyfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл:" << keyfile.errorString();
    }
    QTextStream in(&keyfile);
    in.setEncoding(QStringConverter::Latin1);
    QString keytext = in.readAll();
    keyfile.close();
    ui->key->setText(keytext);
}

void MainWindow::unloadopslot(){
    QString filepath = "/home/nikita/itqt/txtforib/loadunloadopen.txt";//from ui-opentext load to file
    QFile loadopenfile(filepath);
    if (!loadopenfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл:" << loadopenfile.errorString();
    }
    QTextStream out(&loadopenfile);
    out.setEncoding(QStringConverter::Latin1);
    out << ui->opentext->toPlainText()/*text()*/;
    loadopenfile.close();
}

void MainWindow::unloadclslot(){
    //from ui-opentext load to file
    QString fileName = "/home/nikita/itqt/txtforib/loadunloadclose.txt";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qFatal("Не удалось открыть файл для записи");
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Latin1);
    out << ui->closetext->toPlainText()/*text()*/;
    file.close();
    ui->closetext->clear();
}

void MainWindow::unloadkeyslot(){
    genkey->setText("hi");
}
MainWindow::~MainWindow()
{
    delete ui;
}
